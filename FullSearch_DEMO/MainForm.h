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
	/// MainForm ���K�n
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO:  �b���[�J�غc�禡�{���X
			//
		}

	protected:
		/// <summary>
		/// �M������ϥΤ����귽�C
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
		/// �]�p�u��һݪ��ܼơC
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����]�p�u��䴩�һݪ���k - �ФŨϥε{���X�s�边�ק�
		/// �o�Ӥ�k�����e�C
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
			this->label1->Text = L"�� Current Frame";
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
			this->label2->Text = L"�� Previous Frame";
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
			this->label3->Text = L"�� Difference";
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
			this->label4->Text = L"�� Residual";
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
			this->label5->Text = L"�� Reconstruction";
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
			this->label6->Text = L"�� Motion Vector";
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
			this->height_tb->Text = L"240";
			// 
			// width_tb
			// 
			this->width_tb->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->width_tb->Location = System::Drawing::Point(120, 65);
			this->width_tb->Name = L"width_tb";
			this->width_tb->Size = System::Drawing::Size(40, 22);
			this->width_tb->TabIndex = 24;
			this->width_tb->Text = L"416";
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


	// ���s����
	private: System::Void Execute_button_Click(System::Object^ sender, System::EventArgs^ e) {

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
	private: System::Void UpdateTextBox(double PSNR, double avgPSNR, double SSIM, double avgSSIM)
	{
		// ��s textBox
		PSNR_tb1->AppendText(PSNR.ToString());
		PSNR_tb2->AppendText(avgPSNR.ToString());
		SSIM_tb1->AppendText(SSIM.ToString());
		SSIM_tb2->AppendText(avgSSIM.ToString());
	}

	// ping-pong buffer�A�洫 past �M now �� Y Cb Cr�A�ت��O���F�� now ���� past (now �ܦ� past)�A�� past �g�J�s��� (past �ܦ� now)
	System::Void ExchangeYCbCrBuffers()
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
	System::Void YCbCr2RGB(const int& Y, const int& Cb, const int& Cr, int& R, int& G, int& B)
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
	System::Void InitBitmap()
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
	System::Void UnlockAndShowBitmap()
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
	System::Void MotionEstimation(const int& Block_x, const int& Block_y, int& min_sad_x, int& min_sad_y)
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
	System::Void MotionCompensation(const int& Block_x, const int& Block_y, const int& min_sad_x, const int& min_sad_y)
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
	double CalculatePSNR()
	{
		// �ŧi�ܼ�
		double MSE, PSNR;

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
	double CalculateSSIM()
	{
		// �ŧi�ܼ�
		int sizeOfImage = imgWidth * imgHeight;
		int u_x = 0, u_y = 0;
		double c1 = 0.01 * 255, c2 = 0.03 * 255;
		double sigma_x = 0, sigma_y = 0, sigma_xy = 0;
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
				sigma_x += pow(nowY[y * imgWidth + x] - u_x, 2);
				sigma_y += pow(RecY[y * imgWidth + x] - u_y, 2);
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
		sigma_x /= (sizeOfImage - 1);
		sigma_x = pow(sigma_x, 0.5);
		sigma_y /= (sizeOfImage - 1);
		sigma_y = pow(sigma_y, 0.5);
		sigma_xy /= (sizeOfImage - 1);
		SSIM = (2 * u_x * u_y + c1) * (2 * sigma_xy + c2) / (u_x * u_x + u_y * u_y + c1) / (sigma_x * sigma_x + sigma_y * sigma_y + c2);
		SSIM = round(SSIM * 100) / 100;

		return SSIM;
	}

	// ��s TextBox
	System::Void UpdateText(TextBox^ tb, String^ text)
	{
		// �ˬd�O�_�ݭn�z�L Invoke �ӧ�s���
		// Action<T> �O�x���e�U�A�� void delegate �@�ˡA���k(���)�@���Ѽƶǻ��A�� delegate �b CLR ���A��t�ƥ󪺩��h����
		if (tb->InvokeRequired)
			this->Invoke(gcnew Action<TextBox^, String^>(this, &MainForm::UpdateText), tb, text);
		else
			tb->AppendText(text + "\r\n");
	}


	// �D�{��
	System::Void Execute()
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
};
}
