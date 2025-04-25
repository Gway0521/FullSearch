#include "MainForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    FullSearchDEMO::MainForm form;
    Application::Run(% form);
}

namespace FullSearchDEMO {

    // 按鈕執行
    System::Void MainForm::Execute_button_Click(System::Object^ sender, System::EventArgs^ e) {
        // 宣告變數
        FILE* fptr = NULL;
        std::string selectFilePath;
        imgWidth = System::Convert::ToInt32(width_tb->Text);
        imgHeight = System::Convert::ToInt32(height_tb->Text);
        blockSize = System::Convert::ToInt32(blockSize_tb->Text);
        searchRange = System::Convert::ToInt32(searchRange_tb->Text);
        frameNumber = System::Convert::ToInt32(frameNumber_tb->Text);

        // 清空 PSNR、SSIM 的 TextBox
        PSNR_tb1->Clear();
        PSNR_tb2->Clear();
        SSIM_tb1->Clear();
        SSIM_tb2->Clear();

        // 一些 openFileDialog1 的設定
        openFileDialog1->InitialDirectory = "C:/";
        openFileDialog1->RestoreDirectory = true;

        // 取得檔案路徑
        if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
            selectFilePath = msclr::interop::marshal_as<std::string>(openFileDialog1->FileName);

        // 開檔，如果錯誤或沒讀到就退出
        if (fopen_s(&fptr, selectFilePath.c_str(), "rb") || !fptr)
            return;
        fp = fptr;

        // 交給其他 Thread，不要卡 UI 主執行緒
        System::Threading::Tasks::Task::Factory->StartNew(gcnew Action(this, &MainForm::Execute));
    }

    // 因為 UI 的更新不能寫在其他執行緒，因此寫成一個函數交給 Invoke
    System::Void MainForm::UpdateTextBox(double PSNR, double avgPSNR, double SSIM, double avgSSIM)
    {
        // 更新 textBox
        PSNR_tb1->AppendText(PSNR.ToString());
        PSNR_tb2->AppendText(avgPSNR.ToString());
        SSIM_tb1->AppendText(SSIM.ToString());
        SSIM_tb2->AppendText(avgSSIM.ToString());
    }

    // ping-pong buffer，交換 past 和 now 的 Y Cb Cr，目的是為了把 now 移到 past (now 變成 past)，讓 past 寫入新資料 (past 變成 now)
    System::Void  MainForm::ExchangeYCbCrBuffers()
    {
        unsigned char* tempY = pastY;
        unsigned char* tempCb = pastCb;
        unsigned char* tempCr = pastCr;
        pastY = nowY;
        pastCb = nowCb;
        pastCr = nowCr;
        nowY = tempY;
        nowCb = tempCb;
        nowCr = tempCr;
    }

    // 把 Y Cb Cr 轉換為 R G B
    System::Void MainForm::YCbCr2RGB(const int& Y, const int& Cb, const int& Cr, int& R, int& G, int& B)
    {
        // 像素 (x, y) 的 R G B
        R = Y + 1.402 * (Cr - 128);
        G = Y + 0.34414 * (Cb - 128) - 0.71414 * (Cr - 128);
        B = Y + 1.772 * (Cb - 128);

        // 邊界檢查
        R = ((R < 0) ? 0 : R);
        R = ((R > 255) ? 255 : R);
        G = ((G < 0) ? 0 : G);
        G = ((G > 255) ? 255 : G);
        B = ((B < 0) ? 0 : B);
        B = ((B > 255) ? 255 : B);
    }

    // 初始化 Bitmap 、LockBits 並取得 DataPtr
    System::Void MainForm::InitBitmap()
    {
        // Bitmap 分配記憶體
        nowBmp = gcnew Bitmap(imgWidth, imgHeight);
        pastBmp = gcnew Bitmap(imgWidth, imgHeight);
        differenceBmp = gcnew Bitmap(imgWidth, imgHeight);
        residualBmp = gcnew Bitmap(imgWidth, imgHeight);
        reconstructionBmp = gcnew Bitmap(imgWidth, imgHeight);
        motionVectorBmp = gcnew Bitmap(imgWidth, imgHeight);

        // 以 Bitmap 建立 Graphic
        motionVectorGra = Graphics::FromImage(motionVectorBmp);

        // Lock Bitmap 取得 BitmapData
        nowBmpData = nowBmp->LockBits(System::Drawing::Rectangle(0, 0, nowBmp->Width, nowBmp->Height), Imaging::ImageLockMode::ReadWrite, nowBmp->PixelFormat);
        pastBmpData = pastBmp->LockBits(System::Drawing::Rectangle(0, 0, pastBmp->Width, pastBmp->Height), Imaging::ImageLockMode::ReadWrite, pastBmp->PixelFormat);
        residualBmpData = residualBmp->LockBits(System::Drawing::Rectangle(0, 0, residualBmp->Width, residualBmp->Height), Imaging::ImageLockMode::ReadWrite, residualBmp->PixelFormat);
        differenceBmpData = differenceBmp->LockBits(System::Drawing::Rectangle(0, 0, differenceBmp->Width, differenceBmp->Height), Imaging::ImageLockMode::ReadWrite, differenceBmp->PixelFormat);
        reconstructionBmpData = reconstructionBmp->LockBits(System::Drawing::Rectangle(0, 0, reconstructionBmp->Width, reconstructionBmp->Height), Imaging::ImageLockMode::ReadWrite, reconstructionBmp->PixelFormat);

        // 取得 DataPtr
        nowDataPtr = reinterpret_cast<unsigned char*>(nowBmpData->Scan0.ToPointer());
        pastDataPtr = reinterpret_cast<unsigned char*>(pastBmpData->Scan0.ToPointer());
        resiDataPtr = reinterpret_cast<unsigned char*>(residualBmpData->Scan0.ToPointer());
        diffDataPtr = reinterpret_cast<unsigned char*>(differenceBmpData->Scan0.ToPointer());
        recoDataPtr = reinterpret_cast<unsigned char*>(reconstructionBmpData->Scan0.ToPointer());
    }

    // Unlock Bitmap、刪除上一個 Bitmap，並顯示新的 Bitmap
    System::Void MainForm::UnlockAndShowBitmap()
    {
        // Unlock Bitmap
        nowBmp->UnlockBits(nowBmpData);
        pastBmp->UnlockBits(pastBmpData);
        residualBmp->UnlockBits(residualBmpData);
        differenceBmp->UnlockBits(differenceBmpData);
        reconstructionBmp->UnlockBits(reconstructionBmpData);

        // 刪除上一個 Bitmap 並釋放記憶體
        if (currentFrame_pb->Image)
            delete currentFrame_pb->Image;
        if (previousFrame_pb->Image)
            delete previousFrame_pb->Image;
        if (difference_pb->Image)
            delete difference_pb->Image;
        if (residual_pb->Image)
            delete residual_pb->Image;
        if (reconstruction_pb->Image)
            delete reconstruction_pb->Image;
        if (motionVector_pb->Image)
        {
            delete motionVector_pb->Image;
            delete motionVectorGra;
        }

        // 顯示新的 Bitmap
        // 這個其實應該要寫成一個函數交給 Invoke，因為 UI 的更新不能寫在其他執行緒
        // 但是在 PictureBox 屬性為 Zoom 的情況下，程式似乎還是能執行，所以先不動
        currentFrame_pb->Image = nowBmp;
        previousFrame_pb->Image = pastBmp;
        difference_pb->Image = differenceBmp;
        residual_pb->Image = residualBmp;
        reconstruction_pb->Image = reconstructionBmp;
        motionVector_pb->Image = motionVectorBmp;
    }

    // Motion Estimation with Full Search
    // 在 Previous Frame 中尋找與 Current Frame 中的 macroblock (Block_x, Block_y) 最像(SAD最小)的位置，找尋的範圍為 SearchRange，最後得到兩者的水平向量 min_sad_x 與垂直向量 min_sad_y
    System::Void MainForm::MotionEstimation(const int& Block_x, const int& Block_y, int& min_sad_x, int& min_sad_y)
    {
        int sad = 0, min_sad = 99999999;
        int pelDiff;

        // 以中心點向外(上下左右)延伸 searchrange 長度的範圍，每位移1格像素便進行 SAD 計算
        for (int j = -searchRange; j < searchRange; j++)
        {
            for (int i = -searchRange; i < searchRange; i++)
            {
                // 條件句避免邊界問題
                if (Block_x + i < 0 || Block_x + blockSize + i > imgWidth || Block_y + j < 0 || Block_y + blockSize + j > imgHeight)
                    continue;

                // 在經過 searchrange 位移後的 blocksize 範圍內進行 SAD 計算
                for (int n = 0; n < blockSize && sad < min_sad; n++)
                {
                    for (int m = 0; m < blockSize && sad < min_sad; m++)
                    {
                        // 現在畫面的 (x+m, y+n) 像素 與 上一張畫面的 (x+m+i, y+n+j) 像素 的亮度(Y)做相差絕對值
                        // 累加整個 blocksize 範圍的差，以得到整個區域的 SAD
                        pelDiff = *(nowY + (Block_y + n) * imgWidth + Block_x + m) - *(pastY + (Block_y + n + j) * imgWidth + Block_x + m + i);
                        // 相當於 sad += abs(pelDiff) ，但是 abs 太慢了所以改用位元運算
                        sad += (pelDiff ^ (pelDiff >> 31)) - (pelDiff >> 31);

                        // 備註，這裡是整個程式在執行的時候最頻繁訪問的地方，被六個迴圈包著，因此要盡可能的選擇最高效率的做法，避免程式花費過長的時間
                        // 這裡只要 sad < min_sad 時就 Early Terminate，並且改用位元運算代替效率較低的 abs()，可以大幅縮短計算時間
                    }
                }

                // 儲存最小的 SAD 的位置和值
                // 此處的 i, j 相當於該 macroblock 的 motion vector
                if (sad < min_sad)
                {
                    min_sad = sad;
                    min_sad_x = i;
                    min_sad_y = j;
                }

                // 清空 SAD，並進行下一個位子的 SAD 計算
                sad = 0;
            }
        }
    }

    // Motion Compensation
    // 計算 Difference (Current Frame - Previous Frame)、Residual (Current Frame - 重組的畫面) 和 Reconstruction (重組的畫面) 的 pixel 值，顯示圖片
    System::Void MainForm::MotionCompensation(const int& Block_x, const int& Block_y, const int& min_sad_x, const int& min_sad_y)
    {
        int RecPelY, RecPelCb, RecPelCr, RecPelR, RecPelG, RecPelB, residual, difference;
        int pelIndex, offset;

        for (int n = 0; n < blockSize; n++)
        {
            for (int m = 0; m < blockSize; m++)
            {
                pelIndex = (Block_y + n) * imgWidth + Block_x + m;

                // 新的畫面的 Y Cb Cr，是從上一張畫面的 macroblock 位置再加上指向參考畫面的向量 (剛才得到的 motion vector) 來得到
                RecPelY = pastY[(Block_y + n + min_sad_y) * imgWidth + Block_x + m + min_sad_x];
                RecPelCb = pastCb[(Block_y + n + min_sad_y) / 2 * imgWidth / 2 + (Block_x + m + min_sad_x) / 2];
                RecPelCr = pastCr[(Block_y + n + min_sad_y) / 2 * imgWidth / 2 + (Block_x + m + min_sad_x) / 2];
                RecY[pelIndex] = RecPelY;
                RecCb[pelIndex] = RecPelCb;
                RecCr[pelIndex] = RecPelCr;

                // 計算 residual 與 difference
                residual = abs(nowY[pelIndex] - RecPelY) + 128;
                difference = abs(nowY[pelIndex] - pastY[pelIndex]) + 128;

                // 邊界檢查
                residual = ((residual > 255) ? 255 : residual);
                residual = ((residual < 0) ? 0 : residual);
                difference = ((difference > 255) ? 255 : difference);
                difference = ((difference < 0) ? 0 : difference);

                YCbCr2RGB(RecPelY, RecPelCb, RecPelCr, RecPelR, RecPelG, RecPelB);

                // 要寫在 DataPtr 的哪裡
                offset = (Block_y + n) * nowBmpData->Stride + (Block_x + m) * 4;

                // 繪製 Residual、Difference 和 Reconstruction
                resiDataPtr[offset + 3] = 255;
                resiDataPtr[offset + 2] = residual;
                resiDataPtr[offset + 1] = residual;
                resiDataPtr[offset] = residual;

                diffDataPtr[offset + 3] = 255;
                diffDataPtr[offset + 2] = difference;
                diffDataPtr[offset + 1] = difference;
                diffDataPtr[offset] = difference;

                recoDataPtr[offset + 3] = 255;
                recoDataPtr[offset + 2] = RecPelR;
                recoDataPtr[offset + 1] = RecPelG;
                recoDataPtr[offset] = RecPelB;
            }
        }
    }

    // 計算 PSNR
    double MainForm::CalculatePSNR()
    {
        // 宣告變數
        double MSE = 0.0, PSNR;

        // 先計算 MSE
        for (int y = 0; y < imgHeight; y++)
            for (int x = 0; x < imgWidth; x++)
                MSE += pow(nowY[y * imgWidth + x] - RecY[y * imgWidth + x], 2);

        MSE = MSE / imgHeight / imgWidth;

        // 計算 PSNR
        PSNR = 10 * log10(pow(255, 2) / MSE);
        PSNR = round(PSNR * 100) / 100;

        return PSNR;
    }

    // 計算 SSIM
    double MainForm::CalculateSSIM()
    {
        // 宣告變數
        int sizeOfImage = imgWidth * imgHeight;
        double u_x = 0.0, u_y = 0.0;
        double c1 = pow(0.01 * 255, 2), c2 = pow(0.03 * 255, 2);
        double sigma2_x = 0, sigma2_y = 0, sigma_xy = 0;
        double SSIM;

        // 計算 u_x 和 u_y
        for (int y = 0; y < imgHeight; y++)
        {
            for (int x = 0; x < imgWidth; x++)
            {
                // 累加原始畫面的各像素 Y
                u_x += nowY[y * imgWidth + x];
                // 累加重製畫面的個像素 Y
                u_y += RecY[y * imgWidth + x];
            }
        }

        // 平均
        u_x /= sizeOfImage;
        u_y /= sizeOfImage;

        // 代入公式
        for (int y = 0; y < imgHeight; y++)
        {
            for (int x = 0; x < imgWidth; x++)
            {
                sigma2_x += pow(nowY[y * imgWidth + x] - u_x, 2);
                sigma2_y += pow(RecY[y * imgWidth + x] - u_y, 2);
            }
        }

        // 繼續代入公式
        for (int y = 0; y < imgHeight; y++)
        {
            for (int x = 0; x < imgWidth; x++)
            {
                sigma_xy += (nowY[y * imgWidth + x] - u_x) * (RecY[y * imgWidth + x] - u_y);
            }
        }

        // 最後代入公式
        sigma2_x /= (sizeOfImage - 1);
        sigma2_y /= (sizeOfImage - 1);
        sigma_xy /= (sizeOfImage - 1);
        SSIM = (2 * u_x * u_y + c1) * (2 * sigma_xy + c2) / (u_x * u_x + u_y * u_y + c1) / (sigma2_x + sigma2_y + c2);
        SSIM = round(SSIM * 100) / 100;

        return SSIM;
    }

    // 更新 TextBox
    System::Void MainForm::UpdateText(TextBox^ tb, String^ text)
    {
        // 檢查是否需要透過 Invoke 來更新控制項
        // Action<T> 是泛型委託，跟 void delegate 一樣，把方法(函數)作為參數傳遞，而 delegate 在 CLR 中，扮演事件的底層機制
        if (tb->InvokeRequired)
            this->Invoke(gcnew Action<TextBox^, String^>(this, &MainForm::UpdateText), tb, text);
        else
            tb->AppendText(text + "\r\n");
    }

    // 主程式
    System::Void MainForm::Execute()
    {
        // 計時，Debug 用的
        std::clock_t start = std::clock();

        // 宣告變數
        int sizeofimage = imgWidth * imgHeight;
        int pelY, pelCb, pelCr, pelR, pelG, pelB;
        int residual, difference;
        double PSNR, SSIM, totalPSNR = 0, totalSSIM = 0;


        // 各畫面 分配記憶體
        nowY = new unsigned char[sizeofimage];
        nowCb = new unsigned char[sizeofimage / 4];
        nowCr = new unsigned char[sizeofimage / 4];
        pastY = new unsigned char[sizeofimage];
        pastCb = new unsigned char[sizeofimage / 4];
        pastCr = new unsigned char[sizeofimage / 4];
        RecY = new unsigned char[sizeofimage];
        RecCb = new unsigned char[sizeofimage];
        RecCr = new unsigned char[sizeofimage];

        // Pen 分配記憶體
        Pen^ pen = gcnew Pen(Color::Black, 1.0f);


        // 讀取每張畫面
        for (int z = 0; z < frameNumber; z++)
        {
            ExchangeYCbCrBuffers();

            // 將 file_open 位址所讀取的1組大小為: sizeof(unsigned char)*sizeofimage 的資料寫入 nowY, nowCb, nowCr 位址
            // 這種讀取方式只適用在 YCbCr 是 planar 的儲存格式，這種格式資料是連續儲存所有像素的Y，再儲存Cb，最後是Cr，非 packed 交錯儲存格式
            fread(nowY, sizeof(unsigned char) * sizeofimage, 1, fp);
            fread(nowCb, sizeof(unsigned char) * (sizeofimage / 4), 1, fp);
            fread(nowCr, sizeof(unsigned char) * (sizeofimage / 4), 1, fp);

            // 鎖住所有 Bitmap 並取得 BitmapData，直接修改 BitmapData 會比 SetPixel 更有效率
            InitBitmap();


            // 繪製 Current Frame 和 Previous Frame
            for (int y = 0; y < imgHeight; y++)
            {
                for (int x = 0; x < imgWidth; x++)
                {
                    // 要寫在 DataPtr 的哪裡
                    int offset = y * nowBmpData->Stride + x * 4;

                    // current Frame 像素 (x, y) 的 Y Cb Cr
                    pelY = *(nowY + y * imgWidth + x);
                    pelCb = *(nowCb + y / 2 * imgWidth / 2 + x / 2);
                    pelCr = *(nowCr + y / 2 * imgWidth / 2 + x / 2);

                    // 將 YCbCr 轉換為 RGB，畫在 Bitmap 上
                    YCbCr2RGB(pelY, pelCb, pelCr, pelR, pelG, pelB);
                    nowDataPtr[offset + 3] = 255;
                    nowDataPtr[offset + 2] = pelR;
                    nowDataPtr[offset + 1] = pelG;
                    nowDataPtr[offset] = pelB;

                    // 如果不是第一張 Frame 就繼續往下做
                    if (z == 0)
                        continue;

                    // past Frame 像素 (x, y) 的 Y Cb Cr
                    pelY = *(pastY + y * imgWidth + x);
                    pelCb = *(pastCb + y / 2 * imgWidth / 2 + x / 2);
                    pelCr = *(pastCr + y / 2 * imgWidth / 2 + x / 2);

                    // 將 YCbCr 轉換為 RGB，畫在 Bitmap 上
                    YCbCr2RGB(pelY, pelCb, pelCr, pelR, pelG, pelB);
                    pastDataPtr[offset + 3] = 255;
                    pastDataPtr[offset + 2] = pelR;
                    pastDataPtr[offset + 1] = pelG;
                    pastDataPtr[offset] = pelB;
                }
            }

            // 如果不是第一張 Frame 就繼續往下做
            if (z == 0)
            {
                UnlockAndShowBitmap();
                continue;
            }

            // 紀錄最小 SAD 的水平向量與垂直向量
            int min_sad_x = 0, min_sad_y = 0;

            // 將單張畫面分成邊長為 blocksize 的 macroblocks
            for (int Block_y = 0; Block_y < imgHeight; Block_y += blockSize)
            {
                for (int Block_x = 0; Block_x < imgWidth; Block_x += blockSize)
                {
                    // 移動估計，使用 Full Search 找出 min_sad_x 和 min_sad_y
                    MotionEstimation(Block_x, Block_y, min_sad_x, min_sad_y);

                    // 畫出 Motion Vector
                    Point startPoint(Block_x, Block_y);
                    Point endPoint(Block_x + min_sad_x, Block_y + min_sad_y);
                    motionVectorGra->DrawLine(pen, startPoint, endPoint);

                    // 畫出 Difference、Residual 和 Reconstruction
                    MotionCompensation(Block_x, Block_y, min_sad_x, min_sad_y);
                }
            }

            // 顯示在 paintBox 上
            UnlockAndShowBitmap();

            // 視覺品質評估
            PSNR = CalculatePSNR();
            UpdateText(PSNR_tb1, PSNR.ToString());
            totalPSNR += PSNR;
            UpdateText(PSNR_tb2, (round(totalPSNR / z * 100) / 100).ToString());

            SSIM = CalculateSSIM();
            UpdateText(SSIM_tb1, SSIM.ToString());
            totalSSIM += SSIM;
            UpdateText(SSIM_tb2, (round(totalSSIM / z * 100) / 100).ToString());

            // 避免程式運行過快
            System::Threading::Thread::Sleep(30);
        }

        // 釋放記憶體
        fclose(fp);
        delete nowY, nowCb, nowCr, pastY, pastCb, pastCr, RecY, RecCb, RecCr, pen;

        std::cout << (std::clock() - start) / (double)CLOCKS_PER_SEC << std::endl;
    }
}