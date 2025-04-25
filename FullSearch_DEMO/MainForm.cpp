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

    // ���s����
    System::Void MainForm::Execute_button_Click(System::Object^ sender, System::EventArgs^ e) {
        // �ŧi�ܼ�
        FILE* fptr = NULL;
        std::string selectFilePath;
        imgWidth = System::Convert::ToInt32(width_tb->Text);
        imgHeight = System::Convert::ToInt32(height_tb->Text);
        blockSize = System::Convert::ToInt32(blockSize_tb->Text);
        searchRange = System::Convert::ToInt32(searchRange_tb->Text);
        frameNumber = System::Convert::ToInt32(frameNumber_tb->Text);

        // �M�� PSNR�BSSIM �� TextBox
        PSNR_tb1->Clear();
        PSNR_tb2->Clear();
        SSIM_tb1->Clear();
        SSIM_tb2->Clear();

        // �@�� openFileDialog1 ���]�w
        openFileDialog1->InitialDirectory = "C:/";
        openFileDialog1->RestoreDirectory = true;

        // ���o�ɮ׸��|
        if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
            selectFilePath = msclr::interop::marshal_as<std::string>(openFileDialog1->FileName);

        // �}�ɡA�p�G���~�ΨSŪ��N�h�X
        if (fopen_s(&fptr, selectFilePath.c_str(), "rb") || !fptr)
            return;
        fp = fptr;

        // �浹��L Thread�A���n�d UI �D�����
        System::Threading::Tasks::Task::Factory->StartNew(gcnew Action(this, &MainForm::Execute));
    }

    // �]�� UI ����s����g�b��L������A�]���g���@�Ө�ƥ浹 Invoke
    System::Void MainForm::UpdateTextBox(double PSNR, double avgPSNR, double SSIM, double avgSSIM)
    {
        // ��s textBox
        PSNR_tb1->AppendText(PSNR.ToString());
        PSNR_tb2->AppendText(avgPSNR.ToString());
        SSIM_tb1->AppendText(SSIM.ToString());
        SSIM_tb2->AppendText(avgSSIM.ToString());
    }

    // ping-pong buffer�A�洫 past �M now �� Y Cb Cr�A�ت��O���F�� now ���� past (now �ܦ� past)�A�� past �g�J�s��� (past �ܦ� now)
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

    // �� Y Cb Cr �ഫ�� R G B
    System::Void MainForm::YCbCr2RGB(const int& Y, const int& Cb, const int& Cr, int& R, int& G, int& B)
    {
        // ���� (x, y) �� R G B
        R = Y + 1.402 * (Cr - 128);
        G = Y + 0.34414 * (Cb - 128) - 0.71414 * (Cr - 128);
        B = Y + 1.772 * (Cb - 128);

        // ����ˬd
        R = ((R < 0) ? 0 : R);
        R = ((R > 255) ? 255 : R);
        G = ((G < 0) ? 0 : G);
        G = ((G > 255) ? 255 : G);
        B = ((B < 0) ? 0 : B);
        B = ((B > 255) ? 255 : B);
    }

    // ��l�� Bitmap �BLockBits �è��o DataPtr
    System::Void MainForm::InitBitmap()
    {
        // Bitmap ���t�O����
        nowBmp = gcnew Bitmap(imgWidth, imgHeight);
        pastBmp = gcnew Bitmap(imgWidth, imgHeight);
        differenceBmp = gcnew Bitmap(imgWidth, imgHeight);
        residualBmp = gcnew Bitmap(imgWidth, imgHeight);
        reconstructionBmp = gcnew Bitmap(imgWidth, imgHeight);
        motionVectorBmp = gcnew Bitmap(imgWidth, imgHeight);

        // �H Bitmap �إ� Graphic
        motionVectorGra = Graphics::FromImage(motionVectorBmp);

        // Lock Bitmap ���o BitmapData
        nowBmpData = nowBmp->LockBits(System::Drawing::Rectangle(0, 0, nowBmp->Width, nowBmp->Height), Imaging::ImageLockMode::ReadWrite, nowBmp->PixelFormat);
        pastBmpData = pastBmp->LockBits(System::Drawing::Rectangle(0, 0, pastBmp->Width, pastBmp->Height), Imaging::ImageLockMode::ReadWrite, pastBmp->PixelFormat);
        residualBmpData = residualBmp->LockBits(System::Drawing::Rectangle(0, 0, residualBmp->Width, residualBmp->Height), Imaging::ImageLockMode::ReadWrite, residualBmp->PixelFormat);
        differenceBmpData = differenceBmp->LockBits(System::Drawing::Rectangle(0, 0, differenceBmp->Width, differenceBmp->Height), Imaging::ImageLockMode::ReadWrite, differenceBmp->PixelFormat);
        reconstructionBmpData = reconstructionBmp->LockBits(System::Drawing::Rectangle(0, 0, reconstructionBmp->Width, reconstructionBmp->Height), Imaging::ImageLockMode::ReadWrite, reconstructionBmp->PixelFormat);

        // ���o DataPtr
        nowDataPtr = reinterpret_cast<unsigned char*>(nowBmpData->Scan0.ToPointer());
        pastDataPtr = reinterpret_cast<unsigned char*>(pastBmpData->Scan0.ToPointer());
        resiDataPtr = reinterpret_cast<unsigned char*>(residualBmpData->Scan0.ToPointer());
        diffDataPtr = reinterpret_cast<unsigned char*>(differenceBmpData->Scan0.ToPointer());
        recoDataPtr = reinterpret_cast<unsigned char*>(reconstructionBmpData->Scan0.ToPointer());
    }

    // Unlock Bitmap�B�R���W�@�� Bitmap�A����ܷs�� Bitmap
    System::Void MainForm::UnlockAndShowBitmap()
    {
        // Unlock Bitmap
        nowBmp->UnlockBits(nowBmpData);
        pastBmp->UnlockBits(pastBmpData);
        residualBmp->UnlockBits(residualBmpData);
        differenceBmp->UnlockBits(differenceBmpData);
        reconstructionBmp->UnlockBits(reconstructionBmpData);

        // �R���W�@�� Bitmap ������O����
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

        // ��ܷs�� Bitmap
        // �o�Ө�����ӭn�g���@�Ө�ƥ浹 Invoke�A�]�� UI ����s����g�b��L�����
        // ���O�b PictureBox �ݩʬ� Zoom �����p�U�A�{�����G�٬O�����A�ҥH������
        currentFrame_pb->Image = nowBmp;
        previousFrame_pb->Image = pastBmp;
        difference_pb->Image = differenceBmp;
        residual_pb->Image = residualBmp;
        reconstruction_pb->Image = reconstructionBmp;
        motionVector_pb->Image = motionVectorBmp;
    }

    // Motion Estimation with Full Search
    // �b Previous Frame ���M��P Current Frame ���� macroblock (Block_x, Block_y) �̹�(SAD�̤p)����m�A��M���d�� SearchRange�A�̫�o���̪������V�q min_sad_x �P�����V�q min_sad_y
    System::Void MainForm::MotionEstimation(const int& Block_x, const int& Block_y, int& min_sad_x, int& min_sad_y)
    {
        int sad = 0, min_sad = 99999999;
        int pelDiff;

        // �H�����I�V�~(�W�U���k)���� searchrange ���ת��d��A�C�첾1�湳���K�i�� SAD �p��
        for (int j = -searchRange; j < searchRange; j++)
        {
            for (int i = -searchRange; i < searchRange; i++)
            {
                // ����y�קK��ɰ��D
                if (Block_x + i < 0 || Block_x + blockSize + i > imgWidth || Block_y + j < 0 || Block_y + blockSize + j > imgHeight)
                    continue;

                // �b�g�L searchrange �첾�᪺ blocksize �d�򤺶i�� SAD �p��
                for (int n = 0; n < blockSize && sad < min_sad; n++)
                {
                    for (int m = 0; m < blockSize && sad < min_sad; m++)
                    {
                        // �{�b�e���� (x+m, y+n) ���� �P �W�@�i�e���� (x+m+i, y+n+j) ���� ���G��(Y)���ۮt�����
                        // �֥[��� blocksize �d�򪺮t�A�H�o���Ӱϰ쪺 SAD
                        pelDiff = *(nowY + (Block_y + n) * imgWidth + Block_x + m) - *(pastY + (Block_y + n + j) * imgWidth + Block_x + m + i);
                        // �۷�� sad += abs(pelDiff) �A���O abs �ӺC�F�ҥH��Φ줸�B��
                        sad += (pelDiff ^ (pelDiff >> 31)) - (pelDiff >> 31);

                        // �Ƶ��A�o�̬O��ӵ{���b���檺�ɭԳ��W�c�X�ݪ��a��A�Q���Ӱj��]�ۡA�]���n�ɥi�઺��̰ܳ��Ĳv�����k�A�קK�{����O�L�����ɶ�
                        // �o�̥u�n sad < min_sad �ɴN Early Terminate�A�åB��Φ줸�B��N���Ĳv���C�� abs()�A�i�H�j�T�Y�u�p��ɶ�
                    }
                }

                // �x�s�̤p�� SAD ����m�M��
                // ���B�� i, j �۷��� macroblock �� motion vector
                if (sad < min_sad)
                {
                    min_sad = sad;
                    min_sad_x = i;
                    min_sad_y = j;
                }

                // �M�� SAD�A�öi��U�@�Ӧ�l�� SAD �p��
                sad = 0;
            }
        }
    }

    // Motion Compensation
    // �p�� Difference (Current Frame - Previous Frame)�BResidual (Current Frame - ���ժ��e��) �M Reconstruction (���ժ��e��) �� pixel �ȡA��ܹϤ�
    System::Void MainForm::MotionCompensation(const int& Block_x, const int& Block_y, const int& min_sad_x, const int& min_sad_y)
    {
        int RecPelY, RecPelCb, RecPelCr, RecPelR, RecPelG, RecPelB, residual, difference;
        int pelIndex, offset;

        for (int n = 0; n < blockSize; n++)
        {
            for (int m = 0; m < blockSize; m++)
            {
                pelIndex = (Block_y + n) * imgWidth + Block_x + m;

                // �s���e���� Y Cb Cr�A�O�q�W�@�i�e���� macroblock ��m�A�[�W���V�Ѧҵe�����V�q (��~�o�쪺 motion vector) �ӱo��
                RecPelY = pastY[(Block_y + n + min_sad_y) * imgWidth + Block_x + m + min_sad_x];
                RecPelCb = pastCb[(Block_y + n + min_sad_y) / 2 * imgWidth / 2 + (Block_x + m + min_sad_x) / 2];
                RecPelCr = pastCr[(Block_y + n + min_sad_y) / 2 * imgWidth / 2 + (Block_x + m + min_sad_x) / 2];
                RecY[pelIndex] = RecPelY;
                RecCb[pelIndex] = RecPelCb;
                RecCr[pelIndex] = RecPelCr;

                // �p�� residual �P difference
                residual = abs(nowY[pelIndex] - RecPelY) + 128;
                difference = abs(nowY[pelIndex] - pastY[pelIndex]) + 128;

                // ����ˬd
                residual = ((residual > 255) ? 255 : residual);
                residual = ((residual < 0) ? 0 : residual);
                difference = ((difference > 255) ? 255 : difference);
                difference = ((difference < 0) ? 0 : difference);

                YCbCr2RGB(RecPelY, RecPelCb, RecPelCr, RecPelR, RecPelG, RecPelB);

                // �n�g�b DataPtr ������
                offset = (Block_y + n) * nowBmpData->Stride + (Block_x + m) * 4;

                // ø�s Residual�BDifference �M Reconstruction
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

    // �p�� PSNR
    double MainForm::CalculatePSNR()
    {
        // �ŧi�ܼ�
        double MSE = 0.0, PSNR;

        // ���p�� MSE
        for (int y = 0; y < imgHeight; y++)
            for (int x = 0; x < imgWidth; x++)
                MSE += pow(nowY[y * imgWidth + x] - RecY[y * imgWidth + x], 2);

        MSE = MSE / imgHeight / imgWidth;

        // �p�� PSNR
        PSNR = 10 * log10(pow(255, 2) / MSE);
        PSNR = round(PSNR * 100) / 100;

        return PSNR;
    }

    // �p�� SSIM
    double MainForm::CalculateSSIM()
    {
        // �ŧi�ܼ�
        int sizeOfImage = imgWidth * imgHeight;
        double u_x = 0.0, u_y = 0.0;
        double c1 = pow(0.01 * 255, 2), c2 = pow(0.03 * 255, 2);
        double sigma2_x = 0, sigma2_y = 0, sigma_xy = 0;
        double SSIM;

        // �p�� u_x �M u_y
        for (int y = 0; y < imgHeight; y++)
        {
            for (int x = 0; x < imgWidth; x++)
            {
                // �֥[��l�e�����U���� Y
                u_x += nowY[y * imgWidth + x];
                // �֥[���s�e�����ӹ��� Y
                u_y += RecY[y * imgWidth + x];
            }
        }

        // ����
        u_x /= sizeOfImage;
        u_y /= sizeOfImage;

        // �N�J����
        for (int y = 0; y < imgHeight; y++)
        {
            for (int x = 0; x < imgWidth; x++)
            {
                sigma2_x += pow(nowY[y * imgWidth + x] - u_x, 2);
                sigma2_y += pow(RecY[y * imgWidth + x] - u_y, 2);
            }
        }

        // �~��N�J����
        for (int y = 0; y < imgHeight; y++)
        {
            for (int x = 0; x < imgWidth; x++)
            {
                sigma_xy += (nowY[y * imgWidth + x] - u_x) * (RecY[y * imgWidth + x] - u_y);
            }
        }

        // �̫�N�J����
        sigma2_x /= (sizeOfImage - 1);
        sigma2_y /= (sizeOfImage - 1);
        sigma_xy /= (sizeOfImage - 1);
        SSIM = (2 * u_x * u_y + c1) * (2 * sigma_xy + c2) / (u_x * u_x + u_y * u_y + c1) / (sigma2_x + sigma2_y + c2);
        SSIM = round(SSIM * 100) / 100;

        return SSIM;
    }

    // ��s TextBox
    System::Void MainForm::UpdateText(TextBox^ tb, String^ text)
    {
        // �ˬd�O�_�ݭn�z�L Invoke �ӧ�s���
        // Action<T> �O�x���e�U�A�� void delegate �@�ˡA���k(���)�@���Ѽƶǻ��A�� delegate �b CLR ���A��t�ƥ󪺩��h����
        if (tb->InvokeRequired)
            this->Invoke(gcnew Action<TextBox^, String^>(this, &MainForm::UpdateText), tb, text);
        else
            tb->AppendText(text + "\r\n");
    }

    // �D�{��
    System::Void MainForm::Execute()
    {
        // �p�ɡADebug �Ϊ�
        std::clock_t start = std::clock();

        // �ŧi�ܼ�
        int sizeofimage = imgWidth * imgHeight;
        int pelY, pelCb, pelCr, pelR, pelG, pelB;
        int residual, difference;
        double PSNR, SSIM, totalPSNR = 0, totalSSIM = 0;


        // �U�e�� ���t�O����
        nowY = new unsigned char[sizeofimage];
        nowCb = new unsigned char[sizeofimage / 4];
        nowCr = new unsigned char[sizeofimage / 4];
        pastY = new unsigned char[sizeofimage];
        pastCb = new unsigned char[sizeofimage / 4];
        pastCr = new unsigned char[sizeofimage / 4];
        RecY = new unsigned char[sizeofimage];
        RecCb = new unsigned char[sizeofimage];
        RecCr = new unsigned char[sizeofimage];

        // Pen ���t�O����
        Pen^ pen = gcnew Pen(Color::Black, 1.0f);


        // Ū���C�i�e��
        for (int z = 0; z < frameNumber; z++)
        {
            ExchangeYCbCrBuffers();

            // �N file_open ��}��Ū����1�դj�p��: sizeof(unsigned char)*sizeofimage ����Ƽg�J nowY, nowCb, nowCr ��}
            // �o��Ū���覡�u�A�Φb YCbCr �O planar ���x�s�榡�A�o�خ榡��ƬO�s���x�s�Ҧ�������Y�A�A�x�sCb�A�̫�OCr�A�D packed ����x�s�榡
            fread(nowY, sizeof(unsigned char) * sizeofimage, 1, fp);
            fread(nowCb, sizeof(unsigned char) * (sizeofimage / 4), 1, fp);
            fread(nowCr, sizeof(unsigned char) * (sizeofimage / 4), 1, fp);

            // ���Ҧ� Bitmap �è��o BitmapData�A�����ק� BitmapData �|�� SetPixel �󦳮Ĳv
            InitBitmap();


            // ø�s Current Frame �M Previous Frame
            for (int y = 0; y < imgHeight; y++)
            {
                for (int x = 0; x < imgWidth; x++)
                {
                    // �n�g�b DataPtr ������
                    int offset = y * nowBmpData->Stride + x * 4;

                    // current Frame ���� (x, y) �� Y Cb Cr
                    pelY = *(nowY + y * imgWidth + x);
                    pelCb = *(nowCb + y / 2 * imgWidth / 2 + x / 2);
                    pelCr = *(nowCr + y / 2 * imgWidth / 2 + x / 2);

                    // �N YCbCr �ഫ�� RGB�A�e�b Bitmap �W
                    YCbCr2RGB(pelY, pelCb, pelCr, pelR, pelG, pelB);
                    nowDataPtr[offset + 3] = 255;
                    nowDataPtr[offset + 2] = pelR;
                    nowDataPtr[offset + 1] = pelG;
                    nowDataPtr[offset] = pelB;

                    // �p�G���O�Ĥ@�i Frame �N�~�򩹤U��
                    if (z == 0)
                        continue;

                    // past Frame ���� (x, y) �� Y Cb Cr
                    pelY = *(pastY + y * imgWidth + x);
                    pelCb = *(pastCb + y / 2 * imgWidth / 2 + x / 2);
                    pelCr = *(pastCr + y / 2 * imgWidth / 2 + x / 2);

                    // �N YCbCr �ഫ�� RGB�A�e�b Bitmap �W
                    YCbCr2RGB(pelY, pelCb, pelCr, pelR, pelG, pelB);
                    pastDataPtr[offset + 3] = 255;
                    pastDataPtr[offset + 2] = pelR;
                    pastDataPtr[offset + 1] = pelG;
                    pastDataPtr[offset] = pelB;
                }
            }

            // �p�G���O�Ĥ@�i Frame �N�~�򩹤U��
            if (z == 0)
            {
                UnlockAndShowBitmap();
                continue;
            }

            // �����̤p SAD �������V�q�P�����V�q
            int min_sad_x = 0, min_sad_y = 0;

            // �N��i�e����������� blocksize �� macroblocks
            for (int Block_y = 0; Block_y < imgHeight; Block_y += blockSize)
            {
                for (int Block_x = 0; Block_x < imgWidth; Block_x += blockSize)
                {
                    // ���ʦ��p�A�ϥ� Full Search ��X min_sad_x �M min_sad_y
                    MotionEstimation(Block_x, Block_y, min_sad_x, min_sad_y);

                    // �e�X Motion Vector
                    Point startPoint(Block_x, Block_y);
                    Point endPoint(Block_x + min_sad_x, Block_y + min_sad_y);
                    motionVectorGra->DrawLine(pen, startPoint, endPoint);

                    // �e�X Difference�BResidual �M Reconstruction
                    MotionCompensation(Block_x, Block_y, min_sad_x, min_sad_y);
                }
            }

            // ��ܦb paintBox �W
            UnlockAndShowBitmap();

            // ��ı�~�����
            PSNR = CalculatePSNR();
            UpdateText(PSNR_tb1, PSNR.ToString());
            totalPSNR += PSNR;
            UpdateText(PSNR_tb2, (round(totalPSNR / z * 100) / 100).ToString());

            SSIM = CalculateSSIM();
            UpdateText(SSIM_tb1, SSIM.ToString());
            totalSSIM += SSIM;
            UpdateText(SSIM_tb2, (round(totalSSIM / z * 100) / 100).ToString());

            // �קK�{���B��L��
            System::Threading::Thread::Sleep(30);
        }

        // ����O����
        fclose(fp);
        delete nowY, nowCb, nowCr, pastY, pastCb, pastCr, RecY, RecCb, RecCr, pen;

        std::cout << (std::clock() - start) / (double)CLOCKS_PER_SEC << std::endl;
    }
}