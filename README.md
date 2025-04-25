# FullSearch

https://github.com/Gway0521/FullSearch/assets/112754491/beb877e2-e9f7-47f6-96c3-d3a022869548

## 前言

這是實驗室新生訓練的內容，藉由實作簡單的動態影像編解碼，了解當中的一些基礎影像壓縮編碼技術。

## 描述

本專案的目標是實作基於 Full Search 演算法的動態影像編解碼技術。
輸入一個 QCIF、YUV(4:2:0) 格式的影像檔案，程式將以 Full Search 進行區塊比對，並使用 Motion estimation 和 Motion compensation 的方式進行影像壓縮。最後，程式會輸出重建畫面、Motion Vector、Difference、Residual，以及每張重建畫面與原始畫面的 PSNR、SSIM 評估指標。

## 需求

- 支援 Windows 作業系統
- C++ 環境支援 CLI/CLR\
  到 Visual Studio Installer 檢查 使用 C++ 的桌面開發　>> 適用於 vXXX 建置工具的 C++/CLI 支援

## 啟動方法（二擇一）

### 1. Visual Studio Build

- FullSearch_DEMO.sln >> 專案 >> 專案屬性 >> 連結器 >> 進階 >> 進入點 設置為 main
- 用 release 建置並執行程式

### 2. Windows PowerShell

```
cd FullSearch

msbuild FullSearch_DEMO.sln /p:Configuration=Release

.\x64\Release\FullSearch_DEMO.exe
```

## 操作

1. 開啟程式後，輸入你要進行編碼的影像長寬、編碼畫面數、MacroBlock 大小、搜尋範圍
2. 點選 Open File 按鈕，並選擇編碼的 QCIF、YUV(4:2:0) 檔案
3. 程式將自動進行影像編碼，並顯示相關的輸出結果

## 注意事項

- 程式僅支援 YUV(4:2:0) 格式的影像檔案
- 若欲開啟的影像較大，程式會明顯花費較久的運行時間
