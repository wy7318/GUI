#include "rs232_linux.h"
#include "ITLA.h"
#include <windows.h>
#include <iostream>
#include <iomanip>
#include <string>
#include "globalFunc.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "gnuplot.h"
#include "ftd2xx.h"
#include <chrono> 
#include <ctime> 
#include <fstream>




#define REGSIZE 100

#pragma once

namespace TWL_GUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm1
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:
		MyForm1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^  tabControl1;
	protected:
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  tabPage2;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button1;


	private: System::Windows::Forms::RichTextBox^  richTextBox2;


	private: System::Windows::Forms::RichTextBox^  richTextBox3;












	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::PictureBox^  pictureBox1;
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm1::typeid));
			System::Windows::Forms::PictureBox^  pictureBox2;
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->richTextBox3 = (gcnew System::Windows::Forms::RichTextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(pictureBox2))->BeginInit();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			pictureBox1->Location = System::Drawing::Point(3, 9);
			pictureBox1->Name = L"pictureBox1";
			pictureBox1->Size = System::Drawing::Size(579, 281);
			pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			pictureBox1->TabIndex = 2;
			pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			pictureBox2->Location = System::Drawing::Point(3, 7);
			pictureBox2->Name = L"pictureBox2";
			pictureBox2->Size = System::Drawing::Size(579, 281);
			pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			pictureBox2->TabIndex = 4;
			pictureBox2->TabStop = false;
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Location = System::Drawing::Point(27, 76);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(593, 555);
			this->tabControl1->TabIndex = 0;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(pictureBox1);
			this->tabPage1->Controls->Add(this->richTextBox2);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(585, 529);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"CW Setting";
			this->tabPage1->UseVisualStyleBackColor = true;
			this->tabPage1->Click += gcnew System::EventHandler(this, &MyForm1::tabPage1_Click);
			// 
			// richTextBox2
			// 
			this->richTextBox2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richTextBox2->Location = System::Drawing::Point(6, 296);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->ReadOnly = true;
			this->richTextBox2->Size = System::Drawing::Size(573, 227);
			this->richTextBox2->TabIndex = 1;
			this->richTextBox2->Text = resources->GetString(L"richTextBox2.Text");
			this->richTextBox2->TextChanged += gcnew System::EventHandler(this, &MyForm1::richTextBox2_TextChanged);
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(pictureBox2);
			this->tabPage2->Controls->Add(this->richTextBox3);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(585, 529);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Fixed Frequency";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// richTextBox3
			// 
			this->richTextBox3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richTextBox3->Location = System::Drawing::Point(6, 294);
			this->richTextBox3->Name = L"richTextBox3";
			this->richTextBox3->ReadOnly = true;
			this->richTextBox3->Size = System::Drawing::Size(573, 227);
			this->richTextBox3->TabIndex = 3;
			this->richTextBox3->Text = resources->GetString(L"richTextBox3.Text");
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(131, 38);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(401, 25);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Please select cateogry from folloings";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(478, 637);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(142, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Close";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm1::button1_Click);
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(649, 672);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->tabControl1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm1";
			this->Text = L"Optilab TWL GUI v1.0  Help Center";
			this->Load += gcnew System::EventHandler(this, &MyForm1::MyForm1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(pictureBox2))->EndInit();
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage2->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void tabPage1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

		this->Hide();

	}
private: System::Void MyForm1_Load(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void tabPage4_Click(System::Object^  sender, System::EventArgs^  e) {
}

private: System::Void dataGridView1_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
}
private: System::Void richTextBox4_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void pictureBox3_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void richTextBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
};
}
