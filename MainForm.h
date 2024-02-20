#pragma once
#include <string>
#include <iostream>
#include <algorithm>
#include <msclr/marshal_cppstd.h>

namespace FullSearchTest {

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
	private: System::Windows::Forms::Button^ button1;
	protected:

	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::PictureBox^ pictureBox4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::PictureBox^ pictureBox5;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::PictureBox^ pictureBox6;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::TextBox^ textBox8;
	private: System::Windows::Forms::TextBox^ textBox9;




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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->BeginInit();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"�L�n������", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button1->Location = System::Drawing::Point(643, 278);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(142, 35);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Open File";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"�L�n������", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->textBox1->Location = System::Drawing::Point(122, 30);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(39, 25);
			this->textBox1->TabIndex = 2;
			this->textBox1->Text = L"144";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::Window;
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(176, 144);
			this->pictureBox1->TabIndex = 3;
			this->pictureBox1->TabStop = false;
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"�L�n������", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->textBox2->Location = System::Drawing::Point(122, 61);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(39, 25);
			this->textBox2->TabIndex = 4;
			this->textBox2->Text = L"176";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"�L�n������", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label1->Location = System::Drawing::Point(16, 33);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(49, 17);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Height";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"�L�n������", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label2->Location = System::Drawing::Point(16, 64);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(45, 17);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Width";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->textBox5);
			this->groupBox1->Controls->Add(this->label9);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->textBox4);
			this->groupBox1->Controls->Add(this->textBox3);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"�L�n������", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->groupBox1->Location = System::Drawing::Point(624, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(181, 243);
			this->groupBox1->TabIndex = 7;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Setting";
			// 
			// textBox5
			// 
			this->textBox5->Font = (gcnew System::Drawing::Font(L"�L�n������", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->textBox5->Location = System::Drawing::Point(122, 92);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(39, 25);
			this->textBox5->TabIndex = 12;
			this->textBox5->Text = L"12";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"�L�n������", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label9->Location = System::Drawing::Point(16, 95);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(97, 17);
			this->label9->TabIndex = 11;
			this->label9->Text = L"Frame number";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"�L�n������", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label4->Location = System::Drawing::Point(16, 179);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(86, 17);
			this->label4->TabIndex = 10;
			this->label4->Text = L"Search range";
			// 
			// textBox4
			// 
			this->textBox4->Font = (gcnew System::Drawing::Font(L"�L�n������", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->textBox4->Location = System::Drawing::Point(122, 176);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(39, 25);
			this->textBox4->TabIndex = 9;
			this->textBox4->Text = L"7";
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"�L�n������", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->textBox3->Location = System::Drawing::Point(122, 145);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(39, 25);
			this->textBox3->TabIndex = 8;
			this->textBox3->Text = L"16";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"�L�n������", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label3->Location = System::Drawing::Point(16, 148);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(65, 17);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Block size";
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::SystemColors::Window;
			this->pictureBox2->Location = System::Drawing::Point(213, 12);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(176, 144);
			this->pictureBox2->TabIndex = 8;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackColor = System::Drawing::SystemColors::Window;
			this->pictureBox3->Location = System::Drawing::Point(213, 191);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(176, 144);
			this->pictureBox3->TabIndex = 9;
			this->pictureBox3->TabStop = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->BackColor = System::Drawing::SystemColors::Window;
			this->pictureBox4->Location = System::Drawing::Point(213, 368);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(176, 144);
			this->pictureBox4->TabIndex = 10;
			this->pictureBox4->TabStop = false;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"�L�n������", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label5->Location = System::Drawing::Point(39, 157);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(112, 17);
			this->label5->TabIndex = 11;
			this->label5->Text = L"�� Current Frame";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"�L�n������", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label6->Location = System::Drawing::Point(243, 157);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(117, 17);
			this->label6->TabIndex = 12;
			this->label6->Text = L"�� Previous Frame";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"�L�n������", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label7->Location = System::Drawing::Point(261, 338);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(74, 17);
			this->label7->TabIndex = 13;
			this->label7->Text = L"�� Residual";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"�L�n������", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label8->Location = System::Drawing::Point(243, 515);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(112, 17);
			this->label8->TabIndex = 14;
			this->label8->Text = L"�� Motion Vector";
			// 
			// pictureBox5
			// 
			this->pictureBox5->BackColor = System::Drawing::SystemColors::Window;
			this->pictureBox5->Location = System::Drawing::Point(12, 191);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(176, 144);
			this->pictureBox5->TabIndex = 15;
			this->pictureBox5->TabStop = false;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"�L�n������", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label10->Location = System::Drawing::Point(57, 338);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(85, 17);
			this->label10->TabIndex = 16;
			this->label10->Text = L"�� Difference";
			// 
			// pictureBox6
			// 
			this->pictureBox6->BackColor = System::Drawing::SystemColors::Window;
			this->pictureBox6->Location = System::Drawing::Point(12, 368);
			this->pictureBox6->Name = L"pictureBox6";
			this->pictureBox6->Size = System::Drawing::Size(176, 144);
			this->pictureBox6->TabIndex = 17;
			this->pictureBox6->TabStop = false;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"�L�n������", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label11->Location = System::Drawing::Point(39, 515);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(115, 17);
			this->label11->TabIndex = 18;
			this->label11->Text = L"�� Reconstruction";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(6, 28);
			this->textBox6->Multiline = true;
			this->textBox6->Name = L"textBox6";
			this->textBox6->ReadOnly = true;
			this->textBox6->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox6->Size = System::Drawing::Size(85, 229);
			this->textBox6->TabIndex = 19;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->textBox8);
			this->groupBox2->Controls->Add(this->textBox6);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"�L�n������", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->groupBox2->Location = System::Drawing::Point(410, 12);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(96, 323);
			this->groupBox2->TabIndex = 20;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"PSNR";
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(6, 263);
			this->textBox8->Multiline = true;
			this->textBox8->Name = L"textBox8";
			this->textBox8->ReadOnly = true;
			this->textBox8->Size = System::Drawing::Size(85, 48);
			this->textBox8->TabIndex = 20;
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->textBox9);
			this->groupBox3->Controls->Add(this->textBox7);
			this->groupBox3->Font = (gcnew System::Drawing::Font(L"�L�n������", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->groupBox3->Location = System::Drawing::Point(512, 12);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(97, 323);
			this->groupBox3->TabIndex = 21;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"SSIM";
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(6, 263);
			this->textBox9->Multiline = true;
			this->textBox9->Name = L"textBox9";
			this->textBox9->ReadOnly = true;
			this->textBox9->Size = System::Drawing::Size(85, 48);
			this->textBox9->TabIndex = 1;
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(6, 27);
			this->textBox7->Multiline = true;
			this->textBox7->Name = L"textBox7";
			this->textBox7->ReadOnly = true;
			this->textBox7->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox7->Size = System::Drawing::Size(85, 230);
			this->textBox7->TabIndex = 0;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(826, 551);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->pictureBox6);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->pictureBox5);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->pictureBox4);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button1);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		
// ======================================================================================================== 
// ==================================== ��� current �P previous frame ==================================== 
// ======================================================================================================== 

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

			// �ŧi�ܼ�
			FILE* fp = NULL;
			String^ filePath;
			std::string selectedFilePath;

			int pelY, pelCb, pelCr, RecPelY, RecPelCb, RecPelCr, residual, difference;
			float r, g, b, MSE = 0, PSNR = 0, SSIM = 0, avg_PSNR, avg_SSIM;
			float total_PSNR = 0, total_SSIM = 0;

			int height = System::Convert::ToInt32(textBox1->Text);
			int width  = System::Convert::ToInt32(textBox2->Text);
			int blockSize = System::Convert::ToInt32(textBox3->Text);
			int searchRange = System::Convert::ToInt32(textBox4->Text);
			int frameNumber = System::Convert::ToInt32(textBox5->Text);
			int sizeofimage = height * width;

			unsigned char* nowY = new unsigned char[sizeofimage];
			unsigned char* nowCb = new unsigned char[sizeofimage / 4];
			unsigned char* nowCr = new unsigned char[sizeofimage / 4];
			unsigned char* pastY = new unsigned char[sizeofimage];
			unsigned char* pastCb = new unsigned char[sizeofimage / 4];
			unsigned char* pastCr = new unsigned char[sizeofimage / 4];
			unsigned char* RecY = new unsigned char[sizeofimage];
			unsigned char* RecCb = new unsigned char[sizeofimage];
			unsigned char* RecCr = new unsigned char[sizeofimage];


			Graphics^ gra1 = pictureBox1->CreateGraphics();
			Graphics^ gra2 = pictureBox2->CreateGraphics();
			Graphics^ gra3 = pictureBox3->CreateGraphics();
			Graphics^ gra4 = pictureBox4->CreateGraphics();
			Graphics^ gra5 = pictureBox5->CreateGraphics();
			Graphics^ gra6 = pictureBox6->CreateGraphics();
			Pen^ pen = gcnew Pen(Color::Black, 1.0f);
			SolidBrush^ color = gcnew SolidBrush(Color::FromArgb(0, 0, 0));
			
			
			// �}�ҿ���ɮ�
			openFileDialog1->InitialDirectory = "D:/VTM_banchmark/ClassD";
			openFileDialog1->RestoreDirectory = true;

			// ���o�ҿ��ɮת�������|�A�ñN .NET String �ഫ�� C++ �r�� 
			if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				selectedFilePath = msclr::interop::marshal_as<std::string>(openFileDialog1->FileName);

			// ���ж}��
			errno_t err = fopen_s(&fp, selectedFilePath.c_str(), "rb+");

			// �Y�L�kŪ�ɫh���X�{��
			if (err != 0)
				return;

			// Ū���C�i�e��
			for (int z = 0; z < frameNumber; z++)
			{
				// �����洫���� ��s�e�@�i�e���� Y Cb Cr (pastY, pastCb, pastCr)
				unsigned char* tempY = pastY;
				unsigned char* tempCb = pastCb;
				unsigned char* tempCr = pastCr;
				pastY = nowY;
				pastCb = nowCb;
				pastCr = nowCr;
				nowY = tempY;
				nowCb = tempCb;
				nowCr = tempCr;

				// �N file_open ��}��Ū����1�դj�p��: sizeof(unsigned char)*sizeofimage ����Ƽg�J nowY, nowCb, nowCr ��}
				// �o��Ū���覡�u�A�Φb YCbCr �O planar ���x�s�榡�A�o�خ榡��ƬO�s���x�s�Ҧ�������Y�A�A�x�sCb�A�̫�OCr�A�D packed ����x�s�榡
				fread(nowY, sizeof(unsigned char) * sizeofimage, 1, fp);
				fread(nowCb, sizeof(unsigned char) * (sizeofimage / 4), 1, fp);
				fread(nowCr, sizeof(unsigned char) * (sizeofimage / 4), 1, fp);

				// �}�lø�s�e��
				for (int y = 0; y < height; y++)
				{
					for (int x = 0; x < width; x++)
					{
						// ======================= current frame ======================= 
						
						// ���� (x, y) �� Y Cb Cr
						pelY = *(nowY + y * width + x);
						pelCb = *(nowCb + y / 2 * width / 2 + x / 2);
						pelCr = *(nowCr + y / 2 * width / 2 + x / 2);

						// ���� (x, y) �� R G B
						r = pelY + 1.402 * (pelCr - 128);
						g = pelY + 0.34414 * (pelCb - 128) - 0.71414 * (pelCr - 128);
						b = pelY + 1.772 * (pelCb - 128);

						// ����ˬd
						r = ((r < 0) ? 0 : r);
						r = ((r > 255) ? 255 : r);
						g = ((g < 0) ? 0 : g);
						g = ((g > 255) ? 255 : g);
						b = ((b < 0) ? 0 : b);
						b = ((b > 255) ? 255 : b);

						// ø�s�e��
						color->Color = Color::FromArgb(r, g, b);
						gra1->FillRectangle(color, x, y, 1, 1);

						// ======================= current frame ======================= 

						// ======================= previous frame ====================== 

						if (z == 0)
							continue;

						// ���� (x, y) �� Y Cb Cr
						pelY = *(pastY + y * width + x);
						pelCb = *(pastCb + y / 2 * width / 2 + x / 2);
						pelCr = *(pastCr + y / 2 * width / 2 + x / 2);

						// ���� (x, y) �� R G B
						r = pelY + 1.402 * (pelCr - 128);
						g = pelY + 0.34414 * (pelCb - 128) - 0.71414 * (pelCr - 128);
						b = pelY + 1.772 * (pelCb - 128);

						// ����ˬd
						r = ((r < 0) ? 0 : r);
						r = ((r > 255) ? 255 : r);
						g = ((g < 0) ? 0 : g);
						g = ((g > 255) ? 255 : g);
						b = ((b < 0) ? 0 : b);
						b = ((b > 255) ? 255 : b);

						// ø�s�e��
						color->Color = Color::FromArgb(r, g, b);
						gra2->FillRectangle(color, x, y, 1, 1);

						// ======================= previous frame ====================== 
					}
				}

// ======================================================================================================== 
// ======================================= Motion Estimation ���o MV ======================================
// ======================================================================================================== 

				// �p�G���O�Ĥ@�i Frame �N�|�~�򩹤U��
				if (z == 0)
					continue;

				// �M�� MV ��
				for (int y = 0; y < height; y++)
					for (int x = 0; x < width; x++)
					{
						color->Color = Color::FromArgb(255, 255, 255);
						gra4->FillRectangle(color, x, y, 1, 1);
					}
						

				// �p�� SAD
				int sad = 0, min_sad = 99999999;
				int min_sad_x = 0, min_sad_y = 0;

				// �N��i�e����������� blocksize �� macroblocks
				for (int Block_y = 0; Block_y < height; Block_y += blockSize)
				{
					for (int Block_x = 0; Block_x < width; Block_x += blockSize)
					{
						// �H�����I�V�~(�W�U���k)���� searchrange ���ת��d��A�C�첾1�湳���K�i�� SAD �p��
						for (int j = -searchRange; j < searchRange; j++)
						{
							for (int i = -searchRange; i < searchRange; i++)
							{
								// ����y�קK��ɰ��D
								if (Block_x + i < 0 || Block_x + blockSize + i > width || Block_y + j < 0 || Block_y + blockSize + j > height)
									continue;

								// �b�g�L searchrange �첾�᪺ blocksize �d�򤺶i�� SAD �p��
								for (int n = 0; n < blockSize; n++)
								{
									for (int m = 0; m < blockSize; m++)
									{
											// �{�b�e���� (x+m, y+n) ���� �P �W�@�i�e���� (x+m+i, y+n+j) ���� ���G��(Y)���ۮt�����
											// �֥[��� blocksize �d�򪺮t�A�H�o���Ӱϰ쪺 SAD
											sad += abs(*(nowY + (Block_y + n) * width + Block_x + m) - *(pastY + (Block_y + n + j) * width + Block_x + m + i));
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

						// �w�q�u�q���_�I�M���I�y��
						Point startPoint(Block_x, Block_y);
						Point endPoint(Block_x + min_sad_x, Block_y + min_sad_y);
						gra4->DrawLine(pen, startPoint, endPoint);

						// �b�g�L searchrange �첾�᪺ blocksize �d�򤺶i�� SAD �p��
						for (int n = 0; n < blockSize; n++)
						{
							for (int m = 0; m < blockSize; m++)
							{
								// �s���e���� Y Cb Cr�A�O�q�W�@�i�e���� macroblock ��m�A�[�W���V�Ѧҵe�����V�q (��~�o�쪺 motion vector) �ӱo��
								RecPelY = pastY[(Block_y + n + min_sad_y) * width + Block_x + m + min_sad_x];
								RecPelCb = pastCb[(Block_y + n + min_sad_y) / 2 * width / 2 + (Block_x + m + min_sad_x) / 2];
								RecPelCr = pastCr[(Block_y + n + min_sad_y) / 2 * width / 2 + (Block_x + m + min_sad_x) / 2];
								RecY[(Block_y + n) * width + Block_x + m] = RecPelY;
								RecCb[(Block_y + n) * width + Block_x + m] = RecPelCb;
								RecCr[(Block_y + n) * width + Block_x + m] = RecPelCr;

								// �p�� residual �P difference
								residual = abs(nowY[(Block_y + n) * width + Block_x + m] - RecPelY) + 128;
								difference = abs(nowY[(Block_y + n) * width + Block_x + m] - pastY[(Block_y + n) * width + Block_x + m]) + 128;
								
								// ����ˬd
								residual = ((residual > 255) ? 255 : residual);
								residual = ((residual < 0) ? 0 : residual);
								difference = ((difference > 255) ? 255 : difference);
								difference = ((difference < 0) ? 0 : difference);

								// ø�s�e��
								color->Color = Color::FromArgb(residual, residual, residual);
								gra3->FillRectangle(color, Block_x + m, Block_y + n, 1, 1);
								color->Color = Color::FromArgb(difference, difference, difference);
								gra5->FillRectangle(color, Block_x + m, Block_y + n, 1, 1);

								// ���� (x, y) �� R G B
								r = RecPelY + 1.402 * (RecPelCr - 128);
								g = RecPelY + 0.34414 * (RecPelCb - 128) - 0.71414 * (RecPelCr - 128);
								b = RecPelY + 1.772 * (RecPelCb - 128);

								// ����ˬd
								r = ((r < 0) ? 0 : r);
								r = ((r > 255) ? 255 : r);
								g = ((g < 0) ? 0 : g);
								g = ((g > 255) ? 255 : g);
								b = ((b < 0) ? 0 : b);
								b = ((b > 255) ? 255 : b);

								// ø�s�e��
								color->Color = Color::FromArgb(r, g, b);
								gra6->FillRectangle(color, Block_x + m, Block_y + n, 1, 1);
							}
						}

						// �M�ų̤p SAD ����m�M�ȡA�öi��U�@�� macroblock ���p��
						min_sad = 99999999;
						min_sad_x = 0;
						min_sad_y = 0;
					}
				}
// ======================================================================================================== 
// ========================================== �p�� PSNR �P SSIM  ==========================================
// ======================================================================================================== 

				// ======================= �p�� PSNR =======================
				
				// ���p�� MSE
				for (int y = 0; y < height; y++)
					for (int x = 0; x < width; x++)
						MSE += pow(nowY[y * width + x] - RecY[y * width + x], 2);

				MSE = MSE / height / width;

				// �p�� PSNR
				PSNR = 10 * log10(pow(255, 2) / MSE);
				total_PSNR += PSNR;
				PSNR = round(PSNR*100) / 100;
				avg_PSNR = total_PSNR / z;
				avg_PSNR = round(avg_PSNR * 100) / 100;

				// �L�X�|�ˤ��J�ܤp���I��ĤG�쪺���G
				textBox6->AppendText(PSNR.ToString() + "\r\n");
				textBox8->AppendText(avg_PSNR.ToString() + "\r\n");

				// ======================= �p�� PSNR =======================

				// ======================= �p�� SSIM =======================

				// �w�q�Ѽ�
				int u_x = 0;
				int u_y = 0;
				float c1 = 0.01 * 255;
				float c2 = 0.03 * 255;
				float sigma_x = 0;
				float sigma_y = 0;
				float sigma_xy = 0;
				float avg_SSIM = 0;

				// �p�� u_x �M u_y
				for (int y = 0; y < height; y++)
				{
					for (int x = 0; x < width; x++)
					{
						// �֥[��l�e�����U���� Y
						u_x += nowY[y * width + x];
						// �֥[���s�e�����ӹ��� Y
						u_y += RecY[y * width + x];
					}
				}

				// ����
				u_x /= sizeofimage;
				u_y /= sizeofimage;

				// �N�J����
				for (int y = 0; y < height; y++)
				{
					for (int x = 0; x < width; x++)
					{
						sigma_x += pow(nowY[y * width + x] - u_x, 2);
						sigma_y += pow(RecY[y * width + x] - u_y, 2);
					}
				}

				// �~��N�J����
				for (int y = 0; y < height; y++)
				{
					for (int x = 0; x < width; x++)
					{
						sigma_xy += (nowY[y * width + x] - u_x) * (RecY[y * width + x] - u_y);
					}
				}

				// �̫�N�J����
				sigma_x /= (sizeofimage - 1);
				sigma_x = pow(sigma_x, 0.5);
				sigma_y /= (sizeofimage - 1);
				sigma_y = pow(sigma_y, 0.5);
				sigma_xy /= (sizeofimage - 1);
				SSIM = (2 * u_x * u_y + c1) * (2 * sigma_xy + c2) / (u_x * u_x + u_y * u_y + c1) / (sigma_x * sigma_x + sigma_y * sigma_y + c2);
				total_SSIM += SSIM;
				avg_SSIM = total_SSIM / z;
				SSIM = round(SSIM * 100) / 100;
				avg_SSIM = round(avg_SSIM * 100) / 100;

				// �L�X�L����˥h�p���I��ĤT�쪺���G
				textBox7->AppendText(SSIM.ToString() + "\r\n");
				textBox9->AppendText(avg_SSIM.ToString() + "\r\n");

				// ======================= �p�� SSIM =======================
			}

			fclose(fp);
			delete nowY, nowCb, nowCr, pastY, pastCb, pastCr, RecY, RecCb, RecCr, pen, color;
		}
};
}
