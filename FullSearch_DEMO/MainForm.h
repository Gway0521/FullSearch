#pragma once

#include <iostream>
#include <string>
#include <ctime>
#include <msclr/marshal_cppstd.h>
#include <math.h>

namespace FullSearchDEMO {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MainForm 的摘要
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO:  在此加入建構函式程式碼
			//
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ currentFrame_pb;
	protected:
	private: System::Windows::Forms::PictureBox^ previousFrame_pb;
	private: System::Windows::Forms::PictureBox^ difference_pb;
	private: System::Windows::Forms::PictureBox^ residual_pb;
	private: System::Windows::Forms::PictureBox^ reconstruction_pb;
	private: System::Windows::Forms::PictureBox^ motionVector_pb;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ PSNR_tb1;
	private: System::Windows::Forms::TextBox^ SSIM_tb1;
	private: System::Windows::Forms::TextBox^ PSNR_tb2;
	private: System::Windows::Forms::TextBox^ SSIM_tb2;
	private: System::Windows::Forms::GroupBox^ PSNR_gb;
	private: System::Windows::Forms::GroupBox^ SSIM_gb;
	private: System::Windows::Forms::Label^ height_lb;
	private: System::Windows::Forms::Label^ width_lb;
	private: System::Windows::Forms::Label^ frameNumber_lb;
	private: System::Windows::Forms::Label^ blockSize_lb;
	private: System::Windows::Forms::Label^ searchRange_lb;
	private: System::Windows::Forms::TextBox^ height_tb;
	private: System::Windows::Forms::TextBox^ width_tb;
	private: System::Windows::Forms::TextBox^ frameNumber_tb;
	private: System::Windows::Forms::TextBox^ blockSize_tb;
	private: System::Windows::Forms::TextBox^ searchRange_tb;
	private: System::Windows::Forms::Button^ Execute_button;
	private: System::Windows::Forms::GroupBox^ setting_gb;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;

	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
		/// 這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->currentFrame_pb = (gcnew System::Windows::Forms::PictureBox());
			this->previousFrame_pb = (gcnew System::Windows::Forms::PictureBox());
			this->difference_pb = (gcnew System::Windows::Forms::PictureBox());
			this->residual_pb = (gcnew System::Windows::Forms::PictureBox());
			this->reconstruction_pb = (gcnew System::Windows::Forms::PictureBox());
			this->motionVector_pb = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->PSNR_tb1 = (gcnew System::Windows::Forms::TextBox());
			this->SSIM_tb1 = (gcnew System::Windows::Forms::TextBox());
			this->PSNR_tb2 = (gcnew System::Windows::Forms::TextBox());
			this->SSIM_tb2 = (gcnew System::Windows::Forms::TextBox());
			this->PSNR_gb = (gcnew System::Windows::Forms::GroupBox());
			this->SSIM_gb = (gcnew System::Windows::Forms::GroupBox());
			this->height_lb = (gcnew System::Windows::Forms::Label());
			this->width_lb = (gcnew System::Windows::Forms::Label());
			this->frameNumber_lb = (gcnew System::Windows::Forms::Label());
			this->blockSize_lb = (gcnew System::Windows::Forms::Label());
			this->searchRange_lb = (gcnew System::Windows::Forms::Label());
			this->height_tb = (gcnew System::Windows::Forms::TextBox());
			this->width_tb = (gcnew System::Windows::Forms::TextBox());
			this->frameNumber_tb = (gcnew System::Windows::Forms::TextBox());
			this->blockSize_tb = (gcnew System::Windows::Forms::TextBox());
			this->searchRange_tb = (gcnew System::Windows::Forms::TextBox());
			this->Execute_button = (gcnew System::Windows::Forms::Button());
			this->setting_gb = (gcnew System::Windows::Forms::GroupBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->currentFrame_pb))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->previousFrame_pb))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->difference_pb))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->residual_pb))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->reconstruction_pb))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->motionVector_pb))->BeginInit();
			this->PSNR_gb->SuspendLayout();
			this->SSIM_gb->SuspendLayout();
			this->setting_gb->SuspendLayout();
			this->SuspendLayout();
			// 
			// currentFrame_pb
			// 
			this->currentFrame_pb->BackColor = System::Drawing::SystemColors::ControlLight;
			this->currentFrame_pb->Location = System::Drawing::Point(12, 12);
			this->currentFrame_pb->Name = L"currentFrame_pb";
			this->currentFrame_pb->Size = System::Drawing::Size(176, 144);
			this->currentFrame_pb->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->currentFrame_pb->TabIndex = 0;
			this->currentFrame_pb->TabStop = false;
			// 
			// previousFrame_pb
			// 
			this->previousFrame_pb->BackColor = System::Drawing::SystemColors::ControlLight;
			this->previousFrame_pb->Location = System::Drawing::Point(194, 12);
			this->previousFrame_pb->Name = L"previousFrame_pb";
			this->previousFrame_pb->Size = System::Drawing::Size(176, 144);
			this->previousFrame_pb->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->previousFrame_pb->TabIndex = 1;
			this->previousFrame_pb->TabStop = false;
			// 
			// difference_pb
			// 
			this->difference_pb->BackColor = System::Drawing::SystemColors::ControlLight;
			this->difference_pb->Location = System::Drawing::Point(12, 192);
			this->difference_pb->Name = L"difference_pb";
			this->difference_pb->Size = System::Drawing::Size(176, 144);
			this->difference_pb->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->difference_pb->TabIndex = 2;
			this->difference_pb->TabStop = false;
			// 
			// residual_pb
			// 
			this->residual_pb->BackColor = System::Drawing::SystemColors::ControlLight;
			this->residual_pb->Location = System::Drawing::Point(194, 192);
			this->residual_pb->Name = L"residual_pb";
			this->residual_pb->Size = System::Drawing::Size(176, 144);
			this->residual_pb->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->residual_pb->TabIndex = 3;
			this->residual_pb->TabStop = false;
			// 
			// reconstruction_pb
			// 
			this->reconstruction_pb->BackColor = System::Drawing::SystemColors::ControlLight;
			this->reconstruction_pb->Location = System::Drawing::Point(10, 372);
			this->reconstruction_pb->Name = L"reconstruction_pb";
			this->reconstruction_pb->Size = System::Drawing::Size(176, 144);
			this->reconstruction_pb->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->reconstruction_pb->TabIndex = 4;
			this->reconstruction_pb->TabStop = false;
			// 
			// motionVector_pb
			// 
			this->motionVector_pb->BackColor = System::Drawing::SystemColors::ControlLight;
			this->motionVector_pb->Location = System::Drawing::Point(194, 372);
			this->motionVector_pb->Name = L"motionVector_pb";
			this->motionVector_pb->Size = System::Drawing::Size(176, 144);
			this->motionVector_pb->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->motionVector_pb->TabIndex = 5;
			this->motionVector_pb->TabStop = false;
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 159);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(176, 16);
			this->label1->TabIndex = 6;
			this->label1->Text = L"▲ Current Frame";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label2
			// 
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(194, 159);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(176, 16);
			this->label2->TabIndex = 7;
			this->label2->Text = L"▲ Previous Frame";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label3
			// 
			this->label3->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(12, 339);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(176, 16);
			this->label3->TabIndex = 8;
			this->label3->Text = L"▲ Difference";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label4
			// 
			this->label4->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(194, 339);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(176, 16);
			this->label4->TabIndex = 9;
			this->label4->Text = L"▲ Residual";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label5
			// 
			this->label5->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(12, 519);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(176, 16);
			this->label5->TabIndex = 10;
			this->label5->Text = L"▲ Reconstruction";
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label6
			// 
			this->label6->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(194, 519);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(176, 16);
			this->label6->TabIndex = 11;
			this->label6->Text = L"▲ Motion Vector";
			this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// PSNR_tb1
			// 
			this->PSNR_tb1->Font = (gcnew System::Drawing::Font(L"Arial", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PSNR_tb1->Location = System::Drawing::Point(6, 35);
			this->PSNR_tb1->Multiline = true;
			this->PSNR_tb1->Name = L"PSNR_tb1";
			this->PSNR_tb1->ReadOnly = true;
			this->PSNR_tb1->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->PSNR_tb1->Size = System::Drawing::Size(100, 263);
			this->PSNR_tb1->TabIndex = 12;
			// 
			// SSIM_tb1
			// 
			this->SSIM_tb1->Font = (gcnew System::Drawing::Font(L"Arial", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SSIM_tb1->Location = System::Drawing::Point(6, 34);
			this->SSIM_tb1->Multiline = true;
			this->SSIM_tb1->Name = L"SSIM_tb1";
			this->SSIM_tb1->ReadOnly = true;
			this->SSIM_tb1->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->SSIM_tb1->Size = System::Drawing::Size(100, 264);
			this->SSIM_tb1->TabIndex = 13;
			// 
			// PSNR_tb2
			// 
			this->PSNR_tb2->Font = (gcnew System::Drawing::Font(L"Arial", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PSNR_tb2->Location = System::Drawing::Point(6, 304);
			this->PSNR_tb2->Multiline = true;
			this->PSNR_tb2->Name = L"PSNR_tb2";
			this->PSNR_tb2->ReadOnly = true;
			this->PSNR_tb2->Size = System::Drawing::Size(100, 47);
			this->PSNR_tb2->TabIndex = 14;
			// 
			// SSIM_tb2
			// 
			this->SSIM_tb2->Font = (gcnew System::Drawing::Font(L"Arial", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SSIM_tb2->Location = System::Drawing::Point(6, 304);
			this->SSIM_tb2->Multiline = true;
			this->SSIM_tb2->Name = L"SSIM_tb2";
			this->SSIM_tb2->ReadOnly = true;
			this->SSIM_tb2->Size = System::Drawing::Size(100, 47);
			this->SSIM_tb2->TabIndex = 15;
			// 
			// PSNR_gb
			// 
			this->PSNR_gb->Controls->Add(this->PSNR_tb2);
			this->PSNR_gb->Controls->Add(this->PSNR_tb1);
			this->PSNR_gb->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PSNR_gb->Location = System::Drawing::Point(410, 12);
			this->PSNR_gb->Name = L"PSNR_gb";
			this->PSNR_gb->Size = System::Drawing::Size(113, 357);
			this->PSNR_gb->TabIndex = 16;
			this->PSNR_gb->TabStop = false;
			this->PSNR_gb->Text = L"PSNR";
			// 
			// SSIM_gb
			// 
			this->SSIM_gb->Controls->Add(this->SSIM_tb1);
			this->SSIM_gb->Controls->Add(this->SSIM_tb2);
			this->SSIM_gb->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SSIM_gb->Location = System::Drawing::Point(529, 12);
			this->SSIM_gb->Name = L"SSIM_gb";
			this->SSIM_gb->Size = System::Drawing::Size(112, 357);
			this->SSIM_gb->TabIndex = 17;
			this->SSIM_gb->TabStop = false;
			this->SSIM_gb->Text = L"SSIM";
			// 
			// height_lb
			// 
			this->height_lb->AutoSize = true;
			this->height_lb->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->height_lb->Location = System::Drawing::Point(10, 35);
			this->height_lb->Name = L"height_lb";
			this->height_lb->Size = System::Drawing::Size(44, 16);
			this->height_lb->TabIndex = 18;
			this->height_lb->Text = L"Height";
			// 
			// width_lb
			// 
			this->width_lb->AutoSize = true;
			this->width_lb->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->width_lb->Location = System::Drawing::Point(10, 65);
			this->width_lb->Name = L"width_lb";
			this->width_lb->Size = System::Drawing::Size(41, 16);
			this->width_lb->TabIndex = 19;
			this->width_lb->Text = L"Width";
			// 
			// frameNumber_lb
			// 
			this->frameNumber_lb->AutoSize = true;
			this->frameNumber_lb->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->frameNumber_lb->Location = System::Drawing::Point(10, 95);
			this->frameNumber_lb->Name = L"frameNumber_lb";
			this->frameNumber_lb->Size = System::Drawing::Size(93, 16);
			this->frameNumber_lb->TabIndex = 20;
			this->frameNumber_lb->Text = L"Frame Number";
			// 
			// blockSize_lb
			// 
			this->blockSize_lb->AutoSize = true;
			this->blockSize_lb->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->blockSize_lb->Location = System::Drawing::Point(10, 155);
			this->blockSize_lb->Name = L"blockSize_lb";
			this->blockSize_lb->Size = System::Drawing::Size(70, 16);
			this->blockSize_lb->TabIndex = 21;
			this->blockSize_lb->Text = L"Block Size";
			// 
			// searchRange_lb
			// 
			this->searchRange_lb->AutoSize = true;
			this->searchRange_lb->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->searchRange_lb->Location = System::Drawing::Point(10, 185);
			this->searchRange_lb->Name = L"searchRange_lb";
			this->searchRange_lb->Size = System::Drawing::Size(89, 16);
			this->searchRange_lb->TabIndex = 22;
			this->searchRange_lb->Text = L"Search Range";
			// 
			// height_tb
			// 
			this->height_tb->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->height_tb->Location = System::Drawing::Point(120, 35);
			this->height_tb->Name = L"height_tb";
			this->height_tb->Size = System::Drawing::Size(40, 22);
			this->height_tb->TabIndex = 23;
			this->height_tb->Text = L"144";
			// 
			// width_tb
			// 
			this->width_tb->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->width_tb->Location = System::Drawing::Point(120, 65);
			this->width_tb->Name = L"width_tb";
			this->width_tb->Size = System::Drawing::Size(40, 22);
			this->width_tb->TabIndex = 24;
			this->width_tb->Text = L"176";
			// 
			// frameNumber_tb
			// 
			this->frameNumber_tb->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->frameNumber_tb->Location = System::Drawing::Point(120, 95);
			this->frameNumber_tb->Name = L"frameNumber_tb";
			this->frameNumber_tb->Size = System::Drawing::Size(40, 22);
			this->frameNumber_tb->TabIndex = 25;
			this->frameNumber_tb->Text = L"64";
			// 
			// blockSize_tb
			// 
			this->blockSize_tb->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->blockSize_tb->Location = System::Drawing::Point(120, 155);
			this->blockSize_tb->Name = L"blockSize_tb";
			this->blockSize_tb->Size = System::Drawing::Size(40, 22);
			this->blockSize_tb->TabIndex = 26;
			this->blockSize_tb->Text = L"16";
			// 
			// searchRange_tb
			// 
			this->searchRange_tb->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->searchRange_tb->Location = System::Drawing::Point(120, 185);
			this->searchRange_tb->Name = L"searchRange_tb";
			this->searchRange_tb->Size = System::Drawing::Size(40, 22);
			this->searchRange_tb->TabIndex = 27;
			this->searchRange_tb->Text = L"7";
			// 
			// Execute_button
			// 
			this->Execute_button->Font = (gcnew System::Drawing::Font(L"Arial", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Execute_button->Location = System::Drawing::Point(683, 318);
			this->Execute_button->Name = L"Execute_button";
			this->Execute_button->Size = System::Drawing::Size(143, 37);
			this->Execute_button->TabIndex = 28;
			this->Execute_button->Text = L"Open File";
			this->Execute_button->UseVisualStyleBackColor = true;
			this->Execute_button->Click += gcnew System::EventHandler(this, &MainForm::Execute_button_Click);
			// 
			// setting_gb
			// 
			this->setting_gb->Controls->Add(this->height_lb);
			this->setting_gb->Controls->Add(this->height_tb);
			this->setting_gb->Controls->Add(this->searchRange_tb);
			this->setting_gb->Controls->Add(this->width_lb);
			this->setting_gb->Controls->Add(this->searchRange_lb);
			this->setting_gb->Controls->Add(this->blockSize_tb);
			this->setting_gb->Controls->Add(this->width_tb);
			this->setting_gb->Controls->Add(this->frameNumber_tb);
			this->setting_gb->Controls->Add(this->blockSize_lb);
			this->setting_gb->Controls->Add(this->frameNumber_lb);
			this->setting_gb->Font = (gcnew System::Drawing::Font(L"Arial", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->setting_gb->Location = System::Drawing::Point(670, 12);
			this->setting_gb->Name = L"setting_gb";
			this->setting_gb->Size = System::Drawing::Size(168, 218);
			this->setting_gb->TabIndex = 29;
			this->setting_gb->TabStop = false;
			this->setting_gb->Text = L"Setting";
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(873, 543);
			this->Controls->Add(this->setting_gb);
			this->Controls->Add(this->Execute_button);
			this->Controls->Add(this->SSIM_gb);
			this->Controls->Add(this->PSNR_gb);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->motionVector_pb);
			this->Controls->Add(this->reconstruction_pb);
			this->Controls->Add(this->residual_pb);
			this->Controls->Add(this->difference_pb);
			this->Controls->Add(this->previousFrame_pb);
			this->Controls->Add(this->currentFrame_pb);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->currentFrame_pb))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->previousFrame_pb))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->difference_pb))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->residual_pb))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->reconstruction_pb))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->motionVector_pb))->EndInit();
			this->PSNR_gb->ResumeLayout(false);
			this->PSNR_gb->PerformLayout();
			this->SSIM_gb->ResumeLayout(false);
			this->SSIM_gb->PerformLayout();
			this->setting_gb->ResumeLayout(false);
			this->setting_gb->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	private:
		FILE* fp;
		Bitmap ^nowBmp, ^pastBmp, ^residualBmp, ^differenceBmp, ^reconstructionBmp, ^motionVectorBmp;
		Imaging::BitmapData^ nowBmpData, ^pastBmpData, ^residualBmpData, ^differenceBmpData, ^reconstructionBmpData;
		Graphics^ motionVectorGra;
		int imgWidth, imgHeight, blockSize, searchRange, frameNumber;
		unsigned char *nowY, *nowCb, *nowCr, *pastY, *pastCb, *pastCr, *RecY, * RecCb, *RecCr;
		unsigned char *nowDataPtr, *pastDataPtr, *diffDataPtr, *resiDataPtr, *recoDataPtr;


	private: 
		System::Void Execute_button_Click(System::Object^ sender, System::EventArgs^ e);

		System::Void UpdateTextBox(double PSNR, double avgPSNR, double SSIM, double avgSSIM);

		System::Void ExchangeYCbCrBuffers();

		System::Void YCbCr2RGB(const int& Y, const int& Cb, const int& Cr, int& R, int& G, int& B);

		System::Void InitBitmap();

		System::Void UnlockAndShowBitmap();

		System::Void MotionEstimation(const int& Block_x, const int& Block_y, int& min_sad_x, int& min_sad_y);

		System::Void MotionCompensation(const int& Block_x, const int& Block_y, const int& min_sad_x, const int& min_sad_y);

		double CalculatePSNR();

		double CalculateSSIM();

		System::Void UpdateText(TextBox^ tb, String^ text);

		System::Void Execute();
};
}
