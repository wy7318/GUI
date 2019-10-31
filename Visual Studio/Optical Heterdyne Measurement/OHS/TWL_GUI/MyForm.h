//#include "RS232.h"
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
#include "MyForm1.h"




#define REGSIZE 100

#pragma once

int comportNum = 0;
int comportNum2 = 0;
bool laserStatus = false;
bool LowNoise = false;
bool dither = false;
bool realTime = false;

namespace TWL_GUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO::Ports;
	using namespace System::ComponentModel;
	using namespace std;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  groupBox_ComPort;
	private: System::Windows::Forms::Button^  button_init_Comport;
	private: System::Windows::Forms::Label^  label_Comport;













	private: System::Windows::Forms::ComboBox^  comboBox_Comport;




































	private: System::Windows::Forms::Button^  button_CloseComport;












	private: System::Windows::Forms::Button^  button_enable;


	private: System::Windows::Forms::Button^  button_SetWave;
	private: System::Windows::Forms::TextBox^  textBox_wave;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::ImageList^  imageList1;
	private: System::Windows::Forms::PictureBox^  pictureBox1;



	private: System::Windows::Forms::TextBox^  textBox_pw_level;
	private: System::Windows::Forms::Button^  button_pw_set;




private: System::Windows::Forms::ColorDialog^  colorDialog1;
private: System::Windows::Forms::ColorDialog^  colorDialog2;




private: System::Windows::Forms::Label^  label18;


private: System::Windows::Forms::Label^  label22;
private: System::Windows::Forms::TabControl^  textBox_Freq_user;

private: System::Windows::Forms::TabPage^  tabPage1;
private: System::Windows::Forms::TabPage^  tabPage2;


private: System::Windows::Forms::GroupBox^  groupBox_deviceInfo;


private: System::Windows::Forms::Label^  label26;

private: System::Windows::Forms::Label^  label24;
private: System::Windows::Forms::Label^  label23;
private: System::Windows::Forms::Label^  label16;




private: System::Windows::Forms::Label^  label36;
private: System::Windows::Forms::Label^  label37;
private: System::Windows::Forms::TextBox^  textBox_lowf;

private: System::Windows::Forms::Label^  label35;
private: System::Windows::Forms::TextBox^  textBox_highp;


private: System::Windows::Forms::Label^  label34;
private: System::Windows::Forms::Label^  label33;
private: System::Windows::Forms::TextBox^  textBox_lowp;
private: System::Windows::Forms::Label^  label38;
private: System::Windows::Forms::TextBox^  textBox_highf;







private: System::Windows::Forms::TextBox^  textBox_highft;
private: System::Windows::Forms::Label^  label42;
private: System::Windows::Forms::Label^  label43;
private: System::Windows::Forms::Label^  label44;
private: System::Windows::Forms::TextBox^  textBox_lowft;
private: System::Windows::Forms::GroupBox^  groupBox_Wavelength1;













private: System::Windows::Forms::Label^  label17;
private: System::Windows::Forms::GroupBox^  groupBox_Power1;
private: System::Windows::Forms::GroupBox^  groupBox_ds1;








private: System::Windows::Forms::Label^  label20;


private: System::Windows::Forms::Label^  label61;
private: System::Windows::Forms::Label^  label62;



private: System::Windows::Forms::TextBox^  textBox_cf;
private: System::Windows::Forms::TextBox^  textBox_cpw;

private:









private: System::Windows::Forms::Label^  label51;
private: System::Windows::Forms::Button^  button_sd;

private: System::Windows::Forms::Button^  button_su;











private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;


private:


private: System::ComponentModel::BackgroundWorker^  backgroundWorker2;
private: System::ComponentModel::BackgroundWorker^  backgroundWorker3;


private: System::ComponentModel::BackgroundWorker^  backgroundWorker4;








































private: System::ComponentModel::BackgroundWorker^  backgroundWorker5;






private: System::Windows::Forms::Label^  label67;
private: System::Windows::Forms::Label^  label68;
private: System::Windows::Forms::Label^  label70;
private: System::Windows::Forms::Label^  label72;
private: System::Windows::Forms::Label^  label73;
private: System::Windows::Forms::Label^  label75;
private: System::Windows::Forms::GroupBox^  groupBox10;
private: System::Windows::Forms::TextBox^  textBox_highft2;
private: System::Windows::Forms::Button^  button_CloseComport2;
private: System::Windows::Forms::Label^  label25;
private: System::Windows::Forms::ComboBox^  comboBox_Comport2;
private: System::Windows::Forms::Label^  label27;
private: System::Windows::Forms::Button^  button_init_Comport2;
private: System::Windows::Forms::TextBox^  textBox_highf2;
private: System::Windows::Forms::Label^  label28;
private: System::Windows::Forms::Label^  label29;
private: System::Windows::Forms::TextBox^  textBox_lowp2;
private: System::Windows::Forms::Label^  label30;
private: System::Windows::Forms::Label^  label31;
private: System::Windows::Forms::Label^  label32;
private: System::Windows::Forms::TextBox^  textBox_lowft2;
private: System::Windows::Forms::Label^  label39;
private: System::Windows::Forms::Label^  label40;
private: System::Windows::Forms::TextBox^  textBox_lowf2;
private: System::Windows::Forms::TextBox^  textBox_highp2;
private: System::Windows::Forms::Label^  label41;
private: System::Windows::Forms::Label^  label45;
private: System::Windows::Forms::Label^  label46;
private: System::Windows::Forms::Label^  label76;
private: System::Windows::Forms::TextBox^  textBox_wave2;
private: System::Windows::Forms::Button^  button_SetWave2;

private: System::Windows::Forms::Label^  label19;
private: System::Windows::Forms::Label^  label21;
private: System::Windows::Forms::GroupBox^  groupBox5;
private: System::Windows::Forms::Label^  label52;
private: System::Windows::Forms::TextBox^  textBox_beatpattern;
private: System::Windows::Forms::GroupBox^  groupBox4;
private: System::Windows::Forms::Label^  label47;
private: System::Windows::Forms::TextBox^  textBox_cpw2;
private: System::Windows::Forms::Label^  label48;
private: System::Windows::Forms::Label^  label49;
private: System::Windows::Forms::Label^  label50;
private: System::Windows::Forms::TextBox^  textBox_cf2;
private: System::Windows::Forms::GroupBox^  groupBox3;
private: System::Windows::Forms::Button^  button_su2;

private: System::Windows::Forms::GroupBox^  groupBox_Power2;
private: System::Windows::Forms::TextBox^  textBox_pw_level_ff;


private: System::Windows::Forms::Label^  label1;
private: System::Windows::Forms::Button^  button_Power2;
private: System::Windows::Forms::Button^  button_sd2;


private: System::Windows::Forms::Button^  button_enable2;

private: System::Windows::Forms::GroupBox^  groupBox_ds2;

private: System::Windows::Forms::GroupBox^  groupBox8;
private: System::Windows::Forms::Label^  label2;
private: System::Windows::Forms::TextBox^  textBox_beatpattern_ff;

private: System::Windows::Forms::GroupBox^  groupBox9;
private: System::Windows::Forms::Label^  label3;
private: System::Windows::Forms::TextBox^  textBox_cpw2_ff;

private: System::Windows::Forms::Label^  label4;
private: System::Windows::Forms::Label^  label5;
private: System::Windows::Forms::Label^  label6;
private: System::Windows::Forms::TextBox^  textBox_cf2_ff;

private: System::Windows::Forms::GroupBox^  groupBox11;
private: System::Windows::Forms::Label^  label7;
private: System::Windows::Forms::TextBox^  textBox_cpw_ff;


private: System::Windows::Forms::Label^  label8;
private: System::Windows::Forms::Label^  label9;
private: System::Windows::Forms::Label^  label10;
private: System::Windows::Forms::TextBox^  textBox_cf_ff;

private: System::Windows::Forms::GroupBox^  groupBox_Wavelength2;
private: System::Windows::Forms::TextBox^  textBox_set_beat;



private: System::Windows::Forms::Button^  button_Beat;

private: System::Windows::Forms::Label^  label11;
private: System::Windows::Forms::Label^  label12;
private: System::Windows::Forms::TextBox^  textBox_wave_ff;


private: System::Windows::Forms::Button^  button_Freq2;

private: System::Windows::Forms::Label^  label13;
private: System::Windows::Forms::Label^  label14;
private: System::Windows::Forms::MenuStrip^  menuStrip1;
private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  helpPageToolStripMenuItem;











































	private: System::ComponentModel::IContainer^  components;






	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->groupBox_ComPort = (gcnew System::Windows::Forms::GroupBox());
			this->textBox_highft = (gcnew System::Windows::Forms::TextBox());
			this->button_CloseComport = (gcnew System::Windows::Forms::Button());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->comboBox_Comport = (gcnew System::Windows::Forms::ComboBox());
			this->label38 = (gcnew System::Windows::Forms::Label());
			this->button_init_Comport = (gcnew System::Windows::Forms::Button());
			this->textBox_highf = (gcnew System::Windows::Forms::TextBox());
			this->label_Comport = (gcnew System::Windows::Forms::Label());
			this->label42 = (gcnew System::Windows::Forms::Label());
			this->textBox_lowp = (gcnew System::Windows::Forms::TextBox());
			this->label36 = (gcnew System::Windows::Forms::Label());
			this->label34 = (gcnew System::Windows::Forms::Label());
			this->label37 = (gcnew System::Windows::Forms::Label());
			this->textBox_lowft = (gcnew System::Windows::Forms::TextBox());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label44 = (gcnew System::Windows::Forms::Label());
			this->textBox_lowf = (gcnew System::Windows::Forms::TextBox());
			this->textBox_highp = (gcnew System::Windows::Forms::TextBox());
			this->label33 = (gcnew System::Windows::Forms::Label());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->label35 = (gcnew System::Windows::Forms::Label());
			this->label43 = (gcnew System::Windows::Forms::Label());
			this->textBox_wave = (gcnew System::Windows::Forms::TextBox());
			this->button_SetWave = (gcnew System::Windows::Forms::Button());
			this->button_enable = (gcnew System::Windows::Forms::Button());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->imageList1 = (gcnew System::Windows::Forms::ImageList(this->components));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->textBox_pw_level = (gcnew System::Windows::Forms::TextBox());
			this->button_pw_set = (gcnew System::Windows::Forms::Button());
			this->groupBox_Wavelength1 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox_wave2 = (gcnew System::Windows::Forms::TextBox());
			this->button_SetWave2 = (gcnew System::Windows::Forms::Button());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->groupBox_Power1 = (gcnew System::Windows::Forms::GroupBox());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->colorDialog2 = (gcnew System::Windows::Forms::ColorDialog());
			this->textBox_Freq_user = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->button_su = (gcnew System::Windows::Forms::Button());
			this->button_sd = (gcnew System::Windows::Forms::Button());
			this->groupBox_ds1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->label52 = (gcnew System::Windows::Forms::Label());
			this->textBox_beatpattern = (gcnew System::Windows::Forms::TextBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->label47 = (gcnew System::Windows::Forms::Label());
			this->textBox_cpw2 = (gcnew System::Windows::Forms::TextBox());
			this->label48 = (gcnew System::Windows::Forms::Label());
			this->label49 = (gcnew System::Windows::Forms::Label());
			this->label50 = (gcnew System::Windows::Forms::Label());
			this->textBox_cf2 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->label51 = (gcnew System::Windows::Forms::Label());
			this->textBox_cpw = (gcnew System::Windows::Forms::TextBox());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label62 = (gcnew System::Windows::Forms::Label());
			this->label61 = (gcnew System::Windows::Forms::Label());
			this->textBox_cf = (gcnew System::Windows::Forms::TextBox());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->button_su2 = (gcnew System::Windows::Forms::Button());
			this->groupBox_Power2 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox_pw_level_ff = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button_Power2 = (gcnew System::Windows::Forms::Button());
			this->button_sd2 = (gcnew System::Windows::Forms::Button());
			this->button_enable2 = (gcnew System::Windows::Forms::Button());
			this->groupBox_ds2 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox8 = (gcnew System::Windows::Forms::GroupBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox_beatpattern_ff = (gcnew System::Windows::Forms::TextBox());
			this->groupBox9 = (gcnew System::Windows::Forms::GroupBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox_cpw2_ff = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox_cf2_ff = (gcnew System::Windows::Forms::TextBox());
			this->groupBox11 = (gcnew System::Windows::Forms::GroupBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBox_cpw_ff = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->textBox_cf_ff = (gcnew System::Windows::Forms::TextBox());
			this->groupBox_Wavelength2 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox_set_beat = (gcnew System::Windows::Forms::TextBox());
			this->button_Beat = (gcnew System::Windows::Forms::Button());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->textBox_wave_ff = (gcnew System::Windows::Forms::TextBox());
			this->button_Freq2 = (gcnew System::Windows::Forms::Button());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->groupBox_deviceInfo = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox10 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox_highft2 = (gcnew System::Windows::Forms::TextBox());
			this->button_CloseComport2 = (gcnew System::Windows::Forms::Button());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->comboBox_Comport2 = (gcnew System::Windows::Forms::ComboBox());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->button_init_Comport2 = (gcnew System::Windows::Forms::Button());
			this->textBox_highf2 = (gcnew System::Windows::Forms::TextBox());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->textBox_lowp2 = (gcnew System::Windows::Forms::TextBox());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->textBox_lowft2 = (gcnew System::Windows::Forms::TextBox());
			this->label39 = (gcnew System::Windows::Forms::Label());
			this->label40 = (gcnew System::Windows::Forms::Label());
			this->textBox_lowf2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_highp2 = (gcnew System::Windows::Forms::TextBox());
			this->label41 = (gcnew System::Windows::Forms::Label());
			this->label45 = (gcnew System::Windows::Forms::Label());
			this->label46 = (gcnew System::Windows::Forms::Label());
			this->label76 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->backgroundWorker2 = (gcnew System::ComponentModel::BackgroundWorker());
			this->backgroundWorker3 = (gcnew System::ComponentModel::BackgroundWorker());
			this->backgroundWorker4 = (gcnew System::ComponentModel::BackgroundWorker());
			this->backgroundWorker5 = (gcnew System::ComponentModel::BackgroundWorker());
			this->label67 = (gcnew System::Windows::Forms::Label());
			this->label68 = (gcnew System::Windows::Forms::Label());
			this->label70 = (gcnew System::Windows::Forms::Label());
			this->label72 = (gcnew System::Windows::Forms::Label());
			this->label73 = (gcnew System::Windows::Forms::Label());
			this->label75 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpPageToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->groupBox_ComPort->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->groupBox_Wavelength1->SuspendLayout();
			this->groupBox_Power1->SuspendLayout();
			this->textBox_Freq_user->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->groupBox_ds1->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->groupBox_Power2->SuspendLayout();
			this->groupBox_ds2->SuspendLayout();
			this->groupBox8->SuspendLayout();
			this->groupBox9->SuspendLayout();
			this->groupBox11->SuspendLayout();
			this->groupBox_Wavelength2->SuspendLayout();
			this->groupBox_deviceInfo->SuspendLayout();
			this->groupBox10->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox_ComPort
			// 
			this->groupBox_ComPort->Controls->Add(this->textBox_highft);
			this->groupBox_ComPort->Controls->Add(this->button_CloseComport);
			this->groupBox_ComPort->Controls->Add(this->label24);
			this->groupBox_ComPort->Controls->Add(this->comboBox_Comport);
			this->groupBox_ComPort->Controls->Add(this->label38);
			this->groupBox_ComPort->Controls->Add(this->button_init_Comport);
			this->groupBox_ComPort->Controls->Add(this->textBox_highf);
			this->groupBox_ComPort->Controls->Add(this->label_Comport);
			this->groupBox_ComPort->Controls->Add(this->label42);
			this->groupBox_ComPort->Controls->Add(this->textBox_lowp);
			this->groupBox_ComPort->Controls->Add(this->label36);
			this->groupBox_ComPort->Controls->Add(this->label34);
			this->groupBox_ComPort->Controls->Add(this->label37);
			this->groupBox_ComPort->Controls->Add(this->textBox_lowft);
			this->groupBox_ComPort->Controls->Add(this->label23);
			this->groupBox_ComPort->Controls->Add(this->label44);
			this->groupBox_ComPort->Controls->Add(this->textBox_lowf);
			this->groupBox_ComPort->Controls->Add(this->textBox_highp);
			this->groupBox_ComPort->Controls->Add(this->label33);
			this->groupBox_ComPort->Controls->Add(this->label26);
			this->groupBox_ComPort->Controls->Add(this->label35);
			this->groupBox_ComPort->Controls->Add(this->label43);
			this->groupBox_ComPort->Location = System::Drawing::Point(6, 22);
			this->groupBox_ComPort->Name = L"groupBox_ComPort";
			this->groupBox_ComPort->Size = System::Drawing::Size(199, 255);
			this->groupBox_ComPort->TabIndex = 10;
			this->groupBox_ComPort->TabStop = false;
			this->groupBox_ComPort->Text = L"LASER 1";
			// 
			// textBox_highft
			// 
			this->textBox_highft->BackColor = System::Drawing::SystemColors::Control;
			this->textBox_highft->Location = System::Drawing::Point(111, 223);
			this->textBox_highft->Name = L"textBox_highft";
			this->textBox_highft->ReadOnly = true;
			this->textBox_highft->Size = System::Drawing::Size(47, 20);
			this->textBox_highft->TabIndex = 43;
			// 
			// button_CloseComport
			// 
			this->button_CloseComport->Location = System::Drawing::Point(99, 54);
			this->button_CloseComport->Name = L"button_CloseComport";
			this->button_CloseComport->Size = System::Drawing::Size(60, 25);
			this->button_CloseComport->TabIndex = 17;
			this->button_CloseComport->Text = L"Close";
			this->button_CloseComport->UseVisualStyleBackColor = true;
			this->button_CloseComport->Click += gcnew System::EventHandler(this, &MyForm::button_CloseComport_Click);
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label24->Location = System::Drawing::Point(38, 153);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(107, 13);
			this->label24->TabIndex = 13;
			this->label24->Text = L"Frequency Range";
			// 
			// comboBox_Comport
			// 
			this->comboBox_Comport->FormattingEnabled = true;
			this->comboBox_Comport->Location = System::Drawing::Point(99, 27);
			this->comboBox_Comport->Name = L"comboBox_Comport";
			this->comboBox_Comport->Size = System::Drawing::Size(60, 21);
			this->comboBox_Comport->TabIndex = 16;
			this->comboBox_Comport->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox_Comport_SelectedIndexChanged);
			// 
			// label38
			// 
			this->label38->AutoSize = true;
			this->label38->Location = System::Drawing::Point(163, 176);
			this->label38->Name = L"label38";
			this->label38->Size = System::Drawing::Size(27, 13);
			this->label38->TabIndex = 31;
			this->label38->Text = L"THz";
			// 
			// button_init_Comport
			// 
			this->button_init_Comport->Location = System::Drawing::Point(33, 54);
			this->button_init_Comport->Name = L"button_init_Comport";
			this->button_init_Comport->Size = System::Drawing::Size(60, 25);
			this->button_init_Comport->TabIndex = 12;
			this->button_init_Comport->Text = L"Connect";
			this->button_init_Comport->UseVisualStyleBackColor = true;
			this->button_init_Comport->Click += gcnew System::EventHandler(this, &MyForm::button_init_Comport_Click);
			// 
			// textBox_highf
			// 
			this->textBox_highf->BackColor = System::Drawing::SystemColors::Control;
			this->textBox_highf->Location = System::Drawing::Point(111, 173);
			this->textBox_highf->Name = L"textBox_highf";
			this->textBox_highf->ReadOnly = true;
			this->textBox_highf->Size = System::Drawing::Size(47, 20);
			this->textBox_highf->TabIndex = 30;
			// 
			// label_Comport
			// 
			this->label_Comport->AutoSize = true;
			this->label_Comport->Location = System::Drawing::Point(40, 30);
			this->label_Comport->Name = L"label_Comport";
			this->label_Comport->Size = System::Drawing::Size(53, 13);
			this->label_Comport->TabIndex = 11;
			this->label_Comport->Text = L"COM Port";
			this->label_Comport->Click += gcnew System::EventHandler(this, &MyForm::label_Comport_Click);
			// 
			// label42
			// 
			this->label42->AutoSize = true;
			this->label42->Location = System::Drawing::Point(164, 226);
			this->label42->Name = L"label42";
			this->label42->Size = System::Drawing::Size(29, 13);
			this->label42->TabIndex = 42;
			this->label42->Text = L"MHz";
			// 
			// textBox_lowp
			// 
			this->textBox_lowp->BackColor = System::Drawing::SystemColors::Control;
			this->textBox_lowp->Location = System::Drawing::Point(6, 119);
			this->textBox_lowp->Name = L"textBox_lowp";
			this->textBox_lowp->ReadOnly = true;
			this->textBox_lowp->Size = System::Drawing::Size(48, 20);
			this->textBox_lowp->TabIndex = 22;
			// 
			// label36
			// 
			this->label36->AutoSize = true;
			this->label36->Location = System::Drawing::Point(91, 176);
			this->label36->Name = L"label36";
			this->label36->Size = System::Drawing::Size(14, 13);
			this->label36->TabIndex = 29;
			this->label36->Text = L"~";
			this->label36->Click += gcnew System::EventHandler(this, &MyForm::label36_Click);
			// 
			// label34
			// 
			this->label34->AutoSize = true;
			this->label34->Location = System::Drawing::Point(91, 124);
			this->label34->Name = L"label34";
			this->label34->Size = System::Drawing::Size(14, 13);
			this->label34->TabIndex = 24;
			this->label34->Text = L"~";
			// 
			// label37
			// 
			this->label37->AutoSize = true;
			this->label37->Location = System::Drawing::Point(61, 176);
			this->label37->Name = L"label37";
			this->label37->Size = System::Drawing::Size(27, 13);
			this->label37->TabIndex = 28;
			this->label37->Text = L"THz";
			this->label37->Click += gcnew System::EventHandler(this, &MyForm::label37_Click);
			// 
			// textBox_lowft
			// 
			this->textBox_lowft->BackColor = System::Drawing::SystemColors::Control;
			this->textBox_lowft->Location = System::Drawing::Point(6, 223);
			this->textBox_lowft->Name = L"textBox_lowft";
			this->textBox_lowft->ReadOnly = true;
			this->textBox_lowft->Size = System::Drawing::Size(48, 20);
			this->textBox_lowft->TabIndex = 38;
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label23->Location = System::Drawing::Point(40, 100);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(101, 13);
			this->label23->TabIndex = 12;
			this->label23->Text = L"Power Capability";
			// 
			// label44
			// 
			this->label44->AutoSize = true;
			this->label44->Location = System::Drawing::Point(61, 226);
			this->label44->Name = L"label44";
			this->label44->Size = System::Drawing::Size(29, 13);
			this->label44->TabIndex = 39;
			this->label44->Text = L"MHz";
			// 
			// textBox_lowf
			// 
			this->textBox_lowf->BackColor = System::Drawing::SystemColors::Control;
			this->textBox_lowf->Location = System::Drawing::Point(6, 173);
			this->textBox_lowf->Name = L"textBox_lowf";
			this->textBox_lowf->ReadOnly = true;
			this->textBox_lowf->Size = System::Drawing::Size(48, 20);
			this->textBox_lowf->TabIndex = 27;
			this->textBox_lowf->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// textBox_highp
			// 
			this->textBox_highp->BackColor = System::Drawing::SystemColors::Control;
			this->textBox_highp->Location = System::Drawing::Point(111, 119);
			this->textBox_highp->Name = L"textBox_highp";
			this->textBox_highp->ReadOnly = true;
			this->textBox_highp->Size = System::Drawing::Size(47, 20);
			this->textBox_highp->TabIndex = 25;
			// 
			// label33
			// 
			this->label33->AutoSize = true;
			this->label33->Location = System::Drawing::Point(60, 122);
			this->label33->Name = L"label33";
			this->label33->Size = System::Drawing::Size(28, 13);
			this->label33->TabIndex = 23;
			this->label33->Text = L"dBm";
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label26->Location = System::Drawing::Point(36, 206);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(105, 13);
			this->label26->TabIndex = 15;
			this->label26->Text = L"Fine Tune Range";
			// 
			// label35
			// 
			this->label35->AutoSize = true;
			this->label35->Location = System::Drawing::Point(163, 122);
			this->label35->Name = L"label35";
			this->label35->Size = System::Drawing::Size(28, 13);
			this->label35->TabIndex = 26;
			this->label35->Text = L"dBm";
			// 
			// label43
			// 
			this->label43->AutoSize = true;
			this->label43->Location = System::Drawing::Point(91, 230);
			this->label43->Name = L"label43";
			this->label43->Size = System::Drawing::Size(14, 13);
			this->label43->TabIndex = 40;
			this->label43->Text = L"~";
			// 
			// textBox_wave
			// 
			this->textBox_wave->Location = System::Drawing::Point(15, 51);
			this->textBox_wave->Name = L"textBox_wave";
			this->textBox_wave->Size = System::Drawing::Size(77, 20);
			this->textBox_wave->TabIndex = 21;
			this->textBox_wave->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox_wave_TextChanged);
			// 
			// button_SetWave
			// 
			this->button_SetWave->Location = System::Drawing::Point(142, 47);
			this->button_SetWave->Name = L"button_SetWave";
			this->button_SetWave->Size = System::Drawing::Size(48, 24);
			this->button_SetWave->TabIndex = 20;
			this->button_SetWave->Text = L"Set";
			this->button_SetWave->UseVisualStyleBackColor = true;
			this->button_SetWave->Click += gcnew System::EventHandler(this, &MyForm::button_SetWave_Click);
			// 
			// button_enable
			// 
			this->button_enable->Location = System::Drawing::Point(81, 239);
			this->button_enable->Name = L"button_enable";
			this->button_enable->Size = System::Drawing::Size(65, 24);
			this->button_enable->TabIndex = 19;
			this->button_enable->Text = L"Enable";
			this->button_enable->UseVisualStyleBackColor = true;
			this->button_enable->Click += gcnew System::EventHandler(this, &MyForm::button_enable_Click);
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label15->Location = System::Drawing::Point(383, 104);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(76, 32);
			this->label15->TabIndex = 20;
			this->label15->Text = L"OHS";
			this->label15->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label15->Click += gcnew System::EventHandler(this, &MyForm::label15_Click);
			// 
			// imageList1
			// 
			this->imageList1->ColorDepth = System::Windows::Forms::ColorDepth::Depth8Bit;
			this->imageList1->ImageSize = System::Drawing::Size(16, 16);
			this->imageList1->TransparentColor = System::Drawing::Color::Transparent;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(65, 34);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(282, 97);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 21;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MyForm::pictureBox1_Click);
			// 
			// textBox_pw_level
			// 
			this->textBox_pw_level->Location = System::Drawing::Point(29, 18);
			this->textBox_pw_level->Name = L"textBox_pw_level";
			this->textBox_pw_level->Size = System::Drawing::Size(52, 20);
			this->textBox_pw_level->TabIndex = 23;
			this->textBox_pw_level->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox_pw_level_TextChanged);
			// 
			// button_pw_set
			// 
			this->button_pw_set->Location = System::Drawing::Point(127, 15);
			this->button_pw_set->Name = L"button_pw_set";
			this->button_pw_set->Size = System::Drawing::Size(52, 23);
			this->button_pw_set->TabIndex = 24;
			this->button_pw_set->Text = L"Set";
			this->button_pw_set->UseVisualStyleBackColor = true;
			this->button_pw_set->Click += gcnew System::EventHandler(this, &MyForm::button_pw_set_Click);
			// 
			// groupBox_Wavelength1
			// 
			this->groupBox_Wavelength1->Controls->Add(this->textBox_wave2);
			this->groupBox_Wavelength1->Controls->Add(this->button_SetWave2);
			this->groupBox_Wavelength1->Controls->Add(this->label19);
			this->groupBox_Wavelength1->Controls->Add(this->label21);
			this->groupBox_Wavelength1->Controls->Add(this->textBox_wave);
			this->groupBox_Wavelength1->Controls->Add(this->button_SetWave);
			this->groupBox_Wavelength1->Controls->Add(this->label17);
			this->groupBox_Wavelength1->Controls->Add(this->label18);
			this->groupBox_Wavelength1->Location = System::Drawing::Point(12, 66);
			this->groupBox_Wavelength1->Name = L"groupBox_Wavelength1";
			this->groupBox_Wavelength1->Size = System::Drawing::Size(206, 167);
			this->groupBox_Wavelength1->TabIndex = 33;
			this->groupBox_Wavelength1->TabStop = false;
			this->groupBox_Wavelength1->Text = L"Wavelength";
			// 
			// textBox_wave2
			// 
			this->textBox_wave2->Location = System::Drawing::Point(15, 122);
			this->textBox_wave2->Name = L"textBox_wave2";
			this->textBox_wave2->Size = System::Drawing::Size(77, 20);
			this->textBox_wave2->TabIndex = 36;
			// 
			// button_SetWave2
			// 
			this->button_SetWave2->Location = System::Drawing::Point(142, 118);
			this->button_SetWave2->Name = L"button_SetWave2";
			this->button_SetWave2->Size = System::Drawing::Size(48, 24);
			this->button_SetWave2->TabIndex = 35;
			this->button_SetWave2->Text = L"Set";
			this->button_SetWave2->UseVisualStyleBackColor = true;
			this->button_SetWave2->Click += gcnew System::EventHandler(this, &MyForm::button_SetWave2_Click);
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label19->Location = System::Drawing::Point(76, 93);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(58, 13);
			this->label19->TabIndex = 38;
			this->label19->Text = L"LASER 2";
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label21->Location = System::Drawing::Point(105, 123);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(29, 15);
			this->label21->TabIndex = 37;
			this->label21->Text = L"THz";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label17->Location = System::Drawing::Point(76, 25);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(58, 13);
			this->label17->TabIndex = 34;
			this->label17->Text = L"LASER 1";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label18->Location = System::Drawing::Point(105, 52);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(29, 15);
			this->label18->TabIndex = 26;
			this->label18->Text = L"THz";
			// 
			// groupBox_Power1
			// 
			this->groupBox_Power1->Controls->Add(this->textBox_pw_level);
			this->groupBox_Power1->Controls->Add(this->label22);
			this->groupBox_Power1->Controls->Add(this->button_pw_set);
			this->groupBox_Power1->Location = System::Drawing::Point(12, 9);
			this->groupBox_Power1->Name = L"groupBox_Power1";
			this->groupBox_Power1->Size = System::Drawing::Size(206, 49);
			this->groupBox_Power1->TabIndex = 32;
			this->groupBox_Power1->TabStop = false;
			this->groupBox_Power1->Text = L"Power";
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(90, 21);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(28, 13);
			this->label22->TabIndex = 31;
			this->label22->Text = L"dBm";
			this->label22->Click += gcnew System::EventHandler(this, &MyForm::label22_Click_1);
			// 
			// textBox_Freq_user
			// 
			this->textBox_Freq_user->Controls->Add(this->tabPage1);
			this->textBox_Freq_user->Controls->Add(this->tabPage2);
			this->textBox_Freq_user->Location = System::Drawing::Point(449, 143);
			this->textBox_Freq_user->Name = L"textBox_Freq_user";
			this->textBox_Freq_user->SelectedIndex = 0;
			this->textBox_Freq_user->Size = System::Drawing::Size(499, 298);
			this->textBox_Freq_user->TabIndex = 28;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->button_su);
			this->tabPage1->Controls->Add(this->groupBox_Power1);
			this->tabPage1->Controls->Add(this->button_sd);
			this->tabPage1->Controls->Add(this->button_enable);
			this->tabPage1->Controls->Add(this->groupBox_ds1);
			this->tabPage1->Controls->Add(this->groupBox_Wavelength1);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(491, 272);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"CW Setting";
			this->tabPage1->UseVisualStyleBackColor = true;
			this->tabPage1->Click += gcnew System::EventHandler(this, &MyForm::tabPage1_Click);
			// 
			// button_su
			// 
			this->button_su->Location = System::Drawing::Point(226, 239);
			this->button_su->Name = L"button_su";
			this->button_su->Size = System::Drawing::Size(92, 24);
			this->button_su->TabIndex = 43;
			this->button_su->Text = L"Status Update";
			this->button_su->UseMnemonic = false;
			this->button_su->UseVisualStyleBackColor = true;
			this->button_su->Click += gcnew System::EventHandler(this, &MyForm::button_su_Click);
			// 
			// button_sd
			// 
			this->button_sd->Location = System::Drawing::Point(407, 239);
			this->button_sd->Name = L"button_sd";
			this->button_sd->Size = System::Drawing::Size(71, 24);
			this->button_sd->TabIndex = 45;
			this->button_sd->Text = L"Save Data";
			this->button_sd->UseVisualStyleBackColor = true;
			this->button_sd->Click += gcnew System::EventHandler(this, &MyForm::button_sd_Click);
			// 
			// groupBox_ds1
			// 
			this->groupBox_ds1->Controls->Add(this->groupBox5);
			this->groupBox_ds1->Controls->Add(this->groupBox4);
			this->groupBox_ds1->Controls->Add(this->groupBox3);
			this->groupBox_ds1->Location = System::Drawing::Point(225, 9);
			this->groupBox_ds1->Name = L"groupBox_ds1";
			this->groupBox_ds1->Size = System::Drawing::Size(253, 224);
			this->groupBox_ds1->TabIndex = 27;
			this->groupBox_ds1->TabStop = false;
			this->groupBox_ds1->Text = L"Device Status";
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->label52);
			this->groupBox5->Controls->Add(this->textBox_beatpattern);
			this->groupBox5->Location = System::Drawing::Point(8, 164);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(236, 54);
			this->groupBox5->TabIndex = 56;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"BEAT PATTERN";
			// 
			// label52
			// 
			this->label52->AutoSize = true;
			this->label52->Location = System::Drawing::Point(149, 26);
			this->label52->Name = L"label52";
			this->label52->Size = System::Drawing::Size(28, 13);
			this->label52->TabIndex = 55;
			this->label52->Text = L"GHz";
			// 
			// textBox_beatpattern
			// 
			this->textBox_beatpattern->BackColor = System::Drawing::SystemColors::Control;
			this->textBox_beatpattern->Location = System::Drawing::Point(50, 23);
			this->textBox_beatpattern->Name = L"textBox_beatpattern";
			this->textBox_beatpattern->ReadOnly = true;
			this->textBox_beatpattern->Size = System::Drawing::Size(66, 20);
			this->textBox_beatpattern->TabIndex = 55;
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->label47);
			this->groupBox4->Controls->Add(this->textBox_cpw2);
			this->groupBox4->Controls->Add(this->label48);
			this->groupBox4->Controls->Add(this->label49);
			this->groupBox4->Controls->Add(this->label50);
			this->groupBox4->Controls->Add(this->textBox_cf2);
			this->groupBox4->Location = System::Drawing::Point(129, 21);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(115, 133);
			this->groupBox4->TabIndex = 55;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"LASER 2";
			// 
			// label47
			// 
			this->label47->AutoSize = true;
			this->label47->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label47->Location = System::Drawing::Point(28, 67);
			this->label47->Name = L"label47";
			this->label47->Size = System::Drawing::Size(57, 13);
			this->label47->TabIndex = 1;
			this->label47->Text = L"Frequency";
			// 
			// textBox_cpw2
			// 
			this->textBox_cpw2->BackColor = System::Drawing::SystemColors::Control;
			this->textBox_cpw2->Location = System::Drawing::Point(9, 38);
			this->textBox_cpw2->Name = L"textBox_cpw2";
			this->textBox_cpw2->ReadOnly = true;
			this->textBox_cpw2->Size = System::Drawing::Size(66, 20);
			this->textBox_cpw2->TabIndex = 48;
			// 
			// label48
			// 
			this->label48->AutoSize = true;
			this->label48->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label48->Location = System::Drawing::Point(39, 19);
			this->label48->Name = L"label48";
			this->label48->Size = System::Drawing::Size(37, 13);
			this->label48->TabIndex = 0;
			this->label48->Text = L"Power";
			// 
			// label49
			// 
			this->label49->AutoSize = true;
			this->label49->Location = System::Drawing::Point(81, 41);
			this->label49->Name = L"label49";
			this->label49->Size = System::Drawing::Size(28, 13);
			this->label49->TabIndex = 53;
			this->label49->Text = L"dBm";
			// 
			// label50
			// 
			this->label50->AutoSize = true;
			this->label50->Location = System::Drawing::Point(81, 95);
			this->label50->Name = L"label50";
			this->label50->Size = System::Drawing::Size(27, 13);
			this->label50->TabIndex = 54;
			this->label50->Text = L"THz";
			// 
			// textBox_cf2
			// 
			this->textBox_cf2->BackColor = System::Drawing::SystemColors::Control;
			this->textBox_cf2->Location = System::Drawing::Point(9, 91);
			this->textBox_cf2->Name = L"textBox_cf2";
			this->textBox_cf2->ReadOnly = true;
			this->textBox_cf2->Size = System::Drawing::Size(66, 20);
			this->textBox_cf2->TabIndex = 49;
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->label51);
			this->groupBox3->Controls->Add(this->textBox_cpw);
			this->groupBox3->Controls->Add(this->label20);
			this->groupBox3->Controls->Add(this->label62);
			this->groupBox3->Controls->Add(this->label61);
			this->groupBox3->Controls->Add(this->textBox_cf);
			this->groupBox3->Location = System::Drawing::Point(8, 21);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(115, 133);
			this->groupBox3->TabIndex = 46;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"LASER 1";
			// 
			// label51
			// 
			this->label51->AutoSize = true;
			this->label51->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label51->Location = System::Drawing::Point(28, 67);
			this->label51->Name = L"label51";
			this->label51->Size = System::Drawing::Size(57, 13);
			this->label51->TabIndex = 1;
			this->label51->Text = L"Frequency";
			// 
			// textBox_cpw
			// 
			this->textBox_cpw->BackColor = System::Drawing::SystemColors::Control;
			this->textBox_cpw->Location = System::Drawing::Point(9, 38);
			this->textBox_cpw->Name = L"textBox_cpw";
			this->textBox_cpw->ReadOnly = true;
			this->textBox_cpw->Size = System::Drawing::Size(66, 20);
			this->textBox_cpw->TabIndex = 48;
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label20->Location = System::Drawing::Point(39, 19);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(37, 13);
			this->label20->TabIndex = 0;
			this->label20->Text = L"Power";
			// 
			// label62
			// 
			this->label62->AutoSize = true;
			this->label62->Location = System::Drawing::Point(81, 41);
			this->label62->Name = L"label62";
			this->label62->Size = System::Drawing::Size(28, 13);
			this->label62->TabIndex = 53;
			this->label62->Text = L"dBm";
			// 
			// label61
			// 
			this->label61->AutoSize = true;
			this->label61->Location = System::Drawing::Point(81, 95);
			this->label61->Name = L"label61";
			this->label61->Size = System::Drawing::Size(27, 13);
			this->label61->TabIndex = 54;
			this->label61->Text = L"THz";
			// 
			// textBox_cf
			// 
			this->textBox_cf->BackColor = System::Drawing::SystemColors::Control;
			this->textBox_cf->Location = System::Drawing::Point(9, 91);
			this->textBox_cf->Name = L"textBox_cf";
			this->textBox_cf->ReadOnly = true;
			this->textBox_cf->Size = System::Drawing::Size(66, 20);
			this->textBox_cf->TabIndex = 49;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->button_su2);
			this->tabPage2->Controls->Add(this->groupBox_Power2);
			this->tabPage2->Controls->Add(this->button_sd2);
			this->tabPage2->Controls->Add(this->button_enable2);
			this->tabPage2->Controls->Add(this->groupBox_ds2);
			this->tabPage2->Controls->Add(this->groupBox_Wavelength2);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(491, 272);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Fixed Frequency";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// button_su2
			// 
			this->button_su2->Location = System::Drawing::Point(226, 239);
			this->button_su2->Name = L"button_su2";
			this->button_su2->Size = System::Drawing::Size(92, 24);
			this->button_su2->TabIndex = 50;
			this->button_su2->Text = L"Status Update";
			this->button_su2->UseMnemonic = false;
			this->button_su2->UseVisualStyleBackColor = true;
			this->button_su2->Click += gcnew System::EventHandler(this, &MyForm::button_su2_Click);
			// 
			// groupBox_Power2
			// 
			this->groupBox_Power2->Controls->Add(this->textBox_pw_level_ff);
			this->groupBox_Power2->Controls->Add(this->label1);
			this->groupBox_Power2->Controls->Add(this->button_Power2);
			this->groupBox_Power2->Location = System::Drawing::Point(12, 9);
			this->groupBox_Power2->Name = L"groupBox_Power2";
			this->groupBox_Power2->Size = System::Drawing::Size(206, 49);
			this->groupBox_Power2->TabIndex = 48;
			this->groupBox_Power2->TabStop = false;
			this->groupBox_Power2->Text = L"Power";
			// 
			// textBox_pw_level_ff
			// 
			this->textBox_pw_level_ff->Location = System::Drawing::Point(29, 18);
			this->textBox_pw_level_ff->Name = L"textBox_pw_level_ff";
			this->textBox_pw_level_ff->Size = System::Drawing::Size(52, 20);
			this->textBox_pw_level_ff->TabIndex = 23;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(90, 21);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(28, 13);
			this->label1->TabIndex = 31;
			this->label1->Text = L"dBm";
			// 
			// button_Power2
			// 
			this->button_Power2->Location = System::Drawing::Point(127, 15);
			this->button_Power2->Name = L"button_Power2";
			this->button_Power2->Size = System::Drawing::Size(52, 23);
			this->button_Power2->TabIndex = 24;
			this->button_Power2->Text = L"Set";
			this->button_Power2->UseVisualStyleBackColor = true;
			this->button_Power2->Click += gcnew System::EventHandler(this, &MyForm::button_Power2_Click);
			// 
			// button_sd2
			// 
			this->button_sd2->Location = System::Drawing::Point(407, 239);
			this->button_sd2->Name = L"button_sd2";
			this->button_sd2->Size = System::Drawing::Size(71, 24);
			this->button_sd2->TabIndex = 51;
			this->button_sd2->Text = L"Save Data";
			this->button_sd2->UseVisualStyleBackColor = true;
			this->button_sd2->Click += gcnew System::EventHandler(this, &MyForm::button_sd2_Click);
			// 
			// button_enable2
			// 
			this->button_enable2->Location = System::Drawing::Point(81, 239);
			this->button_enable2->Name = L"button_enable2";
			this->button_enable2->Size = System::Drawing::Size(65, 24);
			this->button_enable2->TabIndex = 46;
			this->button_enable2->Text = L"Enable";
			this->button_enable2->UseVisualStyleBackColor = true;
			this->button_enable2->Click += gcnew System::EventHandler(this, &MyForm::button_enable2_Click);
			// 
			// groupBox_ds2
			// 
			this->groupBox_ds2->Controls->Add(this->groupBox8);
			this->groupBox_ds2->Controls->Add(this->groupBox9);
			this->groupBox_ds2->Controls->Add(this->groupBox11);
			this->groupBox_ds2->Location = System::Drawing::Point(225, 9);
			this->groupBox_ds2->Name = L"groupBox_ds2";
			this->groupBox_ds2->Size = System::Drawing::Size(253, 224);
			this->groupBox_ds2->TabIndex = 47;
			this->groupBox_ds2->TabStop = false;
			this->groupBox_ds2->Text = L"Device Status";
			// 
			// groupBox8
			// 
			this->groupBox8->Controls->Add(this->label2);
			this->groupBox8->Controls->Add(this->textBox_beatpattern_ff);
			this->groupBox8->Location = System::Drawing::Point(8, 164);
			this->groupBox8->Name = L"groupBox8";
			this->groupBox8->Size = System::Drawing::Size(236, 54);
			this->groupBox8->TabIndex = 56;
			this->groupBox8->TabStop = false;
			this->groupBox8->Text = L"BEAT PATTERN";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(149, 26);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(28, 13);
			this->label2->TabIndex = 55;
			this->label2->Text = L"GHz";
			// 
			// textBox_beatpattern_ff
			// 
			this->textBox_beatpattern_ff->BackColor = System::Drawing::SystemColors::Control;
			this->textBox_beatpattern_ff->Location = System::Drawing::Point(50, 23);
			this->textBox_beatpattern_ff->Name = L"textBox_beatpattern_ff";
			this->textBox_beatpattern_ff->ReadOnly = true;
			this->textBox_beatpattern_ff->Size = System::Drawing::Size(66, 20);
			this->textBox_beatpattern_ff->TabIndex = 55;
			// 
			// groupBox9
			// 
			this->groupBox9->Controls->Add(this->label3);
			this->groupBox9->Controls->Add(this->textBox_cpw2_ff);
			this->groupBox9->Controls->Add(this->label4);
			this->groupBox9->Controls->Add(this->label5);
			this->groupBox9->Controls->Add(this->label6);
			this->groupBox9->Controls->Add(this->textBox_cf2_ff);
			this->groupBox9->Location = System::Drawing::Point(129, 21);
			this->groupBox9->Name = L"groupBox9";
			this->groupBox9->Size = System::Drawing::Size(115, 133);
			this->groupBox9->TabIndex = 55;
			this->groupBox9->TabStop = false;
			this->groupBox9->Text = L"LASER 2";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(28, 67);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(57, 13);
			this->label3->TabIndex = 1;
			this->label3->Text = L"Frequency";
			// 
			// textBox_cpw2_ff
			// 
			this->textBox_cpw2_ff->BackColor = System::Drawing::SystemColors::Control;
			this->textBox_cpw2_ff->Location = System::Drawing::Point(9, 38);
			this->textBox_cpw2_ff->Name = L"textBox_cpw2_ff";
			this->textBox_cpw2_ff->ReadOnly = true;
			this->textBox_cpw2_ff->Size = System::Drawing::Size(66, 20);
			this->textBox_cpw2_ff->TabIndex = 48;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(39, 19);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(37, 13);
			this->label4->TabIndex = 0;
			this->label4->Text = L"Power";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(81, 41);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(28, 13);
			this->label5->TabIndex = 53;
			this->label5->Text = L"dBm";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(81, 95);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(27, 13);
			this->label6->TabIndex = 54;
			this->label6->Text = L"THz";
			// 
			// textBox_cf2_ff
			// 
			this->textBox_cf2_ff->BackColor = System::Drawing::SystemColors::Control;
			this->textBox_cf2_ff->Location = System::Drawing::Point(9, 91);
			this->textBox_cf2_ff->Name = L"textBox_cf2_ff";
			this->textBox_cf2_ff->ReadOnly = true;
			this->textBox_cf2_ff->Size = System::Drawing::Size(66, 20);
			this->textBox_cf2_ff->TabIndex = 49;
			// 
			// groupBox11
			// 
			this->groupBox11->Controls->Add(this->label7);
			this->groupBox11->Controls->Add(this->textBox_cpw_ff);
			this->groupBox11->Controls->Add(this->label8);
			this->groupBox11->Controls->Add(this->label9);
			this->groupBox11->Controls->Add(this->label10);
			this->groupBox11->Controls->Add(this->textBox_cf_ff);
			this->groupBox11->Location = System::Drawing::Point(8, 21);
			this->groupBox11->Name = L"groupBox11";
			this->groupBox11->Size = System::Drawing::Size(115, 133);
			this->groupBox11->TabIndex = 46;
			this->groupBox11->TabStop = false;
			this->groupBox11->Text = L"LASER 1";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(28, 67);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(57, 13);
			this->label7->TabIndex = 1;
			this->label7->Text = L"Frequency";
			// 
			// textBox_cpw_ff
			// 
			this->textBox_cpw_ff->BackColor = System::Drawing::SystemColors::Control;
			this->textBox_cpw_ff->Location = System::Drawing::Point(9, 38);
			this->textBox_cpw_ff->Name = L"textBox_cpw_ff";
			this->textBox_cpw_ff->ReadOnly = true;
			this->textBox_cpw_ff->Size = System::Drawing::Size(66, 20);
			this->textBox_cpw_ff->TabIndex = 48;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(39, 19);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(37, 13);
			this->label8->TabIndex = 0;
			this->label8->Text = L"Power";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(81, 41);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(28, 13);
			this->label9->TabIndex = 53;
			this->label9->Text = L"dBm";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(81, 95);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(27, 13);
			this->label10->TabIndex = 54;
			this->label10->Text = L"THz";
			// 
			// textBox_cf_ff
			// 
			this->textBox_cf_ff->BackColor = System::Drawing::SystemColors::Control;
			this->textBox_cf_ff->Location = System::Drawing::Point(9, 91);
			this->textBox_cf_ff->Name = L"textBox_cf_ff";
			this->textBox_cf_ff->ReadOnly = true;
			this->textBox_cf_ff->Size = System::Drawing::Size(66, 20);
			this->textBox_cf_ff->TabIndex = 49;
			// 
			// groupBox_Wavelength2
			// 
			this->groupBox_Wavelength2->Controls->Add(this->textBox_set_beat);
			this->groupBox_Wavelength2->Controls->Add(this->button_Beat);
			this->groupBox_Wavelength2->Controls->Add(this->label11);
			this->groupBox_Wavelength2->Controls->Add(this->label12);
			this->groupBox_Wavelength2->Controls->Add(this->textBox_wave_ff);
			this->groupBox_Wavelength2->Controls->Add(this->button_Freq2);
			this->groupBox_Wavelength2->Controls->Add(this->label13);
			this->groupBox_Wavelength2->Controls->Add(this->label14);
			this->groupBox_Wavelength2->Location = System::Drawing::Point(12, 66);
			this->groupBox_Wavelength2->Name = L"groupBox_Wavelength2";
			this->groupBox_Wavelength2->Size = System::Drawing::Size(206, 167);
			this->groupBox_Wavelength2->TabIndex = 49;
			this->groupBox_Wavelength2->TabStop = false;
			this->groupBox_Wavelength2->Text = L"Wavelength";
			// 
			// textBox_set_beat
			// 
			this->textBox_set_beat->Location = System::Drawing::Point(15, 122);
			this->textBox_set_beat->Name = L"textBox_set_beat";
			this->textBox_set_beat->Size = System::Drawing::Size(77, 20);
			this->textBox_set_beat->TabIndex = 36;
			// 
			// button_Beat
			// 
			this->button_Beat->Location = System::Drawing::Point(142, 118);
			this->button_Beat->Name = L"button_Beat";
			this->button_Beat->Size = System::Drawing::Size(48, 24);
			this->button_Beat->TabIndex = 35;
			this->button_Beat->Text = L"Set";
			this->button_Beat->UseVisualStyleBackColor = true;
			this->button_Beat->Click += gcnew System::EventHandler(this, &MyForm::button_Beat_Click);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->Location = System::Drawing::Point(52, 92);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(101, 13);
			this->label11->TabIndex = 38;
			this->label11->Text = L"BEAT PATTERN";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->Location = System::Drawing::Point(105, 123);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(31, 15);
			this->label12->TabIndex = 37;
			this->label12->Text = L"GHz";
			// 
			// textBox_wave_ff
			// 
			this->textBox_wave_ff->Location = System::Drawing::Point(15, 51);
			this->textBox_wave_ff->Name = L"textBox_wave_ff";
			this->textBox_wave_ff->Size = System::Drawing::Size(77, 20);
			this->textBox_wave_ff->TabIndex = 21;
			// 
			// button_Freq2
			// 
			this->button_Freq2->Location = System::Drawing::Point(142, 47);
			this->button_Freq2->Name = L"button_Freq2";
			this->button_Freq2->Size = System::Drawing::Size(48, 24);
			this->button_Freq2->TabIndex = 20;
			this->button_Freq2->Text = L"Set";
			this->button_Freq2->UseVisualStyleBackColor = true;
			this->button_Freq2->Click += gcnew System::EventHandler(this, &MyForm::button_Freq2_Click);
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label13->Location = System::Drawing::Point(76, 25);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(58, 13);
			this->label13->TabIndex = 34;
			this->label13->Text = L"LASER 1";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label14->Location = System::Drawing::Point(105, 52);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(29, 15);
			this->label14->TabIndex = 26;
			this->label14->Text = L"THz";
			// 
			// groupBox_deviceInfo
			// 
			this->groupBox_deviceInfo->Controls->Add(this->groupBox10);
			this->groupBox_deviceInfo->Controls->Add(this->groupBox_ComPort);
			this->groupBox_deviceInfo->Location = System::Drawing::Point(16, 143);
			this->groupBox_deviceInfo->Name = L"groupBox_deviceInfo";
			this->groupBox_deviceInfo->Size = System::Drawing::Size(427, 298);
			this->groupBox_deviceInfo->TabIndex = 11;
			this->groupBox_deviceInfo->TabStop = false;
			this->groupBox_deviceInfo->Text = L"Device Information";
			// 
			// groupBox10
			// 
			this->groupBox10->Controls->Add(this->textBox_highft2);
			this->groupBox10->Controls->Add(this->button_CloseComport2);
			this->groupBox10->Controls->Add(this->label25);
			this->groupBox10->Controls->Add(this->comboBox_Comport2);
			this->groupBox10->Controls->Add(this->label27);
			this->groupBox10->Controls->Add(this->button_init_Comport2);
			this->groupBox10->Controls->Add(this->textBox_highf2);
			this->groupBox10->Controls->Add(this->label28);
			this->groupBox10->Controls->Add(this->label29);
			this->groupBox10->Controls->Add(this->textBox_lowp2);
			this->groupBox10->Controls->Add(this->label30);
			this->groupBox10->Controls->Add(this->label31);
			this->groupBox10->Controls->Add(this->label32);
			this->groupBox10->Controls->Add(this->textBox_lowft2);
			this->groupBox10->Controls->Add(this->label39);
			this->groupBox10->Controls->Add(this->label40);
			this->groupBox10->Controls->Add(this->textBox_lowf2);
			this->groupBox10->Controls->Add(this->textBox_highp2);
			this->groupBox10->Controls->Add(this->label41);
			this->groupBox10->Controls->Add(this->label45);
			this->groupBox10->Controls->Add(this->label46);
			this->groupBox10->Controls->Add(this->label76);
			this->groupBox10->Location = System::Drawing::Point(222, 22);
			this->groupBox10->Name = L"groupBox10";
			this->groupBox10->Size = System::Drawing::Size(199, 255);
			this->groupBox10->TabIndex = 44;
			this->groupBox10->TabStop = false;
			this->groupBox10->Text = L"LASER 2";
			// 
			// textBox_highft2
			// 
			this->textBox_highft2->BackColor = System::Drawing::SystemColors::Control;
			this->textBox_highft2->Location = System::Drawing::Point(111, 223);
			this->textBox_highft2->Name = L"textBox_highft2";
			this->textBox_highft2->ReadOnly = true;
			this->textBox_highft2->Size = System::Drawing::Size(48, 20);
			this->textBox_highft2->TabIndex = 43;
			// 
			// button_CloseComport2
			// 
			this->button_CloseComport2->Location = System::Drawing::Point(99, 54);
			this->button_CloseComport2->Name = L"button_CloseComport2";
			this->button_CloseComport2->Size = System::Drawing::Size(60, 25);
			this->button_CloseComport2->TabIndex = 17;
			this->button_CloseComport2->Text = L"Close";
			this->button_CloseComport2->UseVisualStyleBackColor = true;
			this->button_CloseComport2->Click += gcnew System::EventHandler(this, &MyForm::button_CloseComport2_Click);
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label25->Location = System::Drawing::Point(38, 153);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(107, 13);
			this->label25->TabIndex = 13;
			this->label25->Text = L"Frequency Range";
			// 
			// comboBox_Comport2
			// 
			this->comboBox_Comport2->FormattingEnabled = true;
			this->comboBox_Comport2->Location = System::Drawing::Point(99, 27);
			this->comboBox_Comport2->Name = L"comboBox_Comport2";
			this->comboBox_Comport2->Size = System::Drawing::Size(60, 21);
			this->comboBox_Comport2->TabIndex = 16;
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Location = System::Drawing::Point(165, 176);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(27, 13);
			this->label27->TabIndex = 31;
			this->label27->Text = L"THz";
			// 
			// button_init_Comport2
			// 
			this->button_init_Comport2->Location = System::Drawing::Point(33, 54);
			this->button_init_Comport2->Name = L"button_init_Comport2";
			this->button_init_Comport2->Size = System::Drawing::Size(60, 25);
			this->button_init_Comport2->TabIndex = 12;
			this->button_init_Comport2->Text = L"Connect";
			this->button_init_Comport2->UseVisualStyleBackColor = true;
			this->button_init_Comport2->Click += gcnew System::EventHandler(this, &MyForm::button_init_Comport2_Click);
			// 
			// textBox_highf2
			// 
			this->textBox_highf2->BackColor = System::Drawing::SystemColors::Control;
			this->textBox_highf2->Location = System::Drawing::Point(111, 173);
			this->textBox_highf2->Name = L"textBox_highf2";
			this->textBox_highf2->ReadOnly = true;
			this->textBox_highf2->Size = System::Drawing::Size(48, 20);
			this->textBox_highf2->TabIndex = 30;
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Location = System::Drawing::Point(40, 30);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(53, 13);
			this->label28->TabIndex = 11;
			this->label28->Text = L"COM Port";
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Location = System::Drawing::Point(166, 226);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(29, 13);
			this->label29->TabIndex = 42;
			this->label29->Text = L"MHz";
			// 
			// textBox_lowp2
			// 
			this->textBox_lowp2->BackColor = System::Drawing::SystemColors::Control;
			this->textBox_lowp2->Location = System::Drawing::Point(6, 119);
			this->textBox_lowp2->Name = L"textBox_lowp2";
			this->textBox_lowp2->ReadOnly = true;
			this->textBox_lowp2->Size = System::Drawing::Size(48, 20);
			this->textBox_lowp2->TabIndex = 22;
			// 
			// label30
			// 
			this->label30->AutoSize = true;
			this->label30->Location = System::Drawing::Point(91, 176);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(14, 13);
			this->label30->TabIndex = 29;
			this->label30->Text = L"~";
			// 
			// label31
			// 
			this->label31->AutoSize = true;
			this->label31->Location = System::Drawing::Point(91, 124);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(14, 13);
			this->label31->TabIndex = 24;
			this->label31->Text = L"~";
			// 
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->Location = System::Drawing::Point(61, 176);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(27, 13);
			this->label32->TabIndex = 28;
			this->label32->Text = L"THz";
			// 
			// textBox_lowft2
			// 
			this->textBox_lowft2->BackColor = System::Drawing::SystemColors::Control;
			this->textBox_lowft2->Location = System::Drawing::Point(6, 223);
			this->textBox_lowft2->Name = L"textBox_lowft2";
			this->textBox_lowft2->ReadOnly = true;
			this->textBox_lowft2->Size = System::Drawing::Size(48, 20);
			this->textBox_lowft2->TabIndex = 38;
			// 
			// label39
			// 
			this->label39->AutoSize = true;
			this->label39->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label39->Location = System::Drawing::Point(40, 100);
			this->label39->Name = L"label39";
			this->label39->Size = System::Drawing::Size(101, 13);
			this->label39->TabIndex = 12;
			this->label39->Text = L"Power Capability";
			// 
			// label40
			// 
			this->label40->AutoSize = true;
			this->label40->Location = System::Drawing::Point(61, 226);
			this->label40->Name = L"label40";
			this->label40->Size = System::Drawing::Size(29, 13);
			this->label40->TabIndex = 39;
			this->label40->Text = L"MHz";
			// 
			// textBox_lowf2
			// 
			this->textBox_lowf2->BackColor = System::Drawing::SystemColors::Control;
			this->textBox_lowf2->Location = System::Drawing::Point(6, 173);
			this->textBox_lowf2->Name = L"textBox_lowf2";
			this->textBox_lowf2->ReadOnly = true;
			this->textBox_lowf2->Size = System::Drawing::Size(48, 20);
			this->textBox_lowf2->TabIndex = 27;
			// 
			// textBox_highp2
			// 
			this->textBox_highp2->BackColor = System::Drawing::SystemColors::Control;
			this->textBox_highp2->Location = System::Drawing::Point(111, 119);
			this->textBox_highp2->Name = L"textBox_highp2";
			this->textBox_highp2->ReadOnly = true;
			this->textBox_highp2->Size = System::Drawing::Size(48, 20);
			this->textBox_highp2->TabIndex = 25;
			// 
			// label41
			// 
			this->label41->AutoSize = true;
			this->label41->Location = System::Drawing::Point(60, 122);
			this->label41->Name = L"label41";
			this->label41->Size = System::Drawing::Size(28, 13);
			this->label41->TabIndex = 23;
			this->label41->Text = L"dBm";
			// 
			// label45
			// 
			this->label45->AutoSize = true;
			this->label45->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label45->Location = System::Drawing::Point(36, 206);
			this->label45->Name = L"label45";
			this->label45->Size = System::Drawing::Size(105, 13);
			this->label45->TabIndex = 15;
			this->label45->Text = L"Fine Tune Range";
			// 
			// label46
			// 
			this->label46->AutoSize = true;
			this->label46->Location = System::Drawing::Point(165, 122);
			this->label46->Name = L"label46";
			this->label46->Size = System::Drawing::Size(28, 13);
			this->label46->TabIndex = 26;
			this->label46->Text = L"dBm";
			// 
			// label76
			// 
			this->label76->AutoSize = true;
			this->label76->Location = System::Drawing::Point(91, 230);
			this->label76->Name = L"label76";
			this->label76->Size = System::Drawing::Size(14, 13);
			this->label76->TabIndex = 40;
			this->label76->Text = L"~";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label16->Location = System::Drawing::Point(460, 120);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(42, 16);
			this->label16->TabIndex = 29;
			this->label16->Text = L"v1.0.0";
			// 
			// backgroundWorker2
			// 
			this->backgroundWorker2->WorkerReportsProgress = true;
			this->backgroundWorker2->WorkerSupportsCancellation = true;
			this->backgroundWorker2->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm::backgroundWorker2_DoWork);
			this->backgroundWorker2->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &MyForm::backgroundWorker2_ProgressChanged);
			this->backgroundWorker2->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &MyForm::backgroundWorker2_RunWorkerCompleted);
			// 
			// label67
			// 
			this->label67->AutoSize = true;
			this->label67->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 50.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label67->Location = System::Drawing::Point(376, 30);
			this->label67->Name = L"label67";
			this->label67->Size = System::Drawing::Size(86, 76);
			this->label67->TabIndex = 31;
			this->label67->Text = L"O";
			// 
			// label68
			// 
			this->label68->AutoSize = true;
			this->label68->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 50.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label68->Location = System::Drawing::Point(508, 30);
			this->label68->Name = L"label68";
			this->label68->Size = System::Drawing::Size(82, 76);
			this->label68->TabIndex = 32;
			this->label68->Text = L"H";
			// 
			// label70
			// 
			this->label70->AutoSize = true;
			this->label70->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 50.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label70->Location = System::Drawing::Point(746, 30);
			this->label70->Name = L"label70";
			this->label70->Size = System::Drawing::Size(79, 76);
			this->label70->TabIndex = 33;
			this->label70->Text = L"S";
			// 
			// label72
			// 
			this->label72->AutoSize = true;
			this->label72->BackColor = System::Drawing::Color::Transparent;
			this->label72->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label72->Location = System::Drawing::Point(442, 58);
			this->label72->Name = L"label72";
			this->label72->Size = System::Drawing::Size(78, 31);
			this->label72->TabIndex = 34;
			this->label72->Text = L"ptical";
			this->label72->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label73
			// 
			this->label73->AutoSize = true;
			this->label73->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label73->Location = System::Drawing::Point(571, 34);
			this->label73->Name = L"label73";
			this->label73->Size = System::Drawing::Size(179, 62);
			this->label73->TabIndex = 35;
			this->label73->Text = L"eterodyne \r\nMeasurement";
			this->label73->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label75
			// 
			this->label75->AutoSize = true;
			this->label75->BackColor = System::Drawing::Color::Transparent;
			this->label75->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label75->Location = System::Drawing::Point(803, 66);
			this->label75->Name = L"label75";
			this->label75->Size = System::Drawing::Size(87, 31);
			this->label75->TabIndex = 36;
			this->label75->Text = L"ystem";
			this->label75->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->fileToolStripMenuItem,
					this->helpToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(957, 24);
			this->menuStrip1->TabIndex = 37;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->exitToolStripMenuItem });
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(93, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::exitToolStripMenuItem_Click);
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->helpPageToolStripMenuItem });
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->helpToolStripMenuItem->Text = L"Help";
			// 
			// helpPageToolStripMenuItem
			// 
			this->helpPageToolStripMenuItem->Name = L"helpPageToolStripMenuItem";
			this->helpPageToolStripMenuItem->Size = System::Drawing::Size(129, 22);
			this->helpPageToolStripMenuItem->Text = L"Help Page";
			this->helpPageToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::helpPageToolStripMenuItem_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(957, 454);
			this->Controls->Add(this->groupBox_deviceInfo);
			this->Controls->Add(this->label75);
			this->Controls->Add(this->label73);
			this->Controls->Add(this->label72);
			this->Controls->Add(this->label70);
			this->Controls->Add(this->label68);
			this->Controls->Add(this->label67);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->textBox_Freq_user);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->menuStrip1);
			this->Cursor = System::Windows::Forms::Cursors::Default;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Optilab OHS GUI v1.0.0";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->groupBox_ComPort->ResumeLayout(false);
			this->groupBox_ComPort->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->groupBox_Wavelength1->ResumeLayout(false);
			this->groupBox_Wavelength1->PerformLayout();
			this->groupBox_Power1->ResumeLayout(false);
			this->groupBox_Power1->PerformLayout();
			this->textBox_Freq_user->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->groupBox_ds1->ResumeLayout(false);
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->groupBox_Power2->ResumeLayout(false);
			this->groupBox_Power2->PerformLayout();
			this->groupBox_ds2->ResumeLayout(false);
			this->groupBox8->ResumeLayout(false);
			this->groupBox8->PerformLayout();
			this->groupBox9->ResumeLayout(false);
			this->groupBox9->PerformLayout();
			this->groupBox11->ResumeLayout(false);
			this->groupBox11->PerformLayout();
			this->groupBox_Wavelength2->ResumeLayout(false);
			this->groupBox_Wavelength2->PerformLayout();
			this->groupBox_deviceInfo->ResumeLayout(false);
			this->groupBox10->ResumeLayout(false);
			this->groupBox10->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
			/// Form
			this->Width = 400;
			this->Height = 500;
			/// Comport
			//String^ str = "com";

			auto serialPorts = gcnew cli::array<String^>(50);
			// Get a list of serial port names.
			serialPorts = SerialPort::GetPortNames();

			for (int i = 0; i < serialPorts->Length; i++) {
				//comboBox_Comport->Items->Add(str + i);
				comboBox_Comport->Items->Add(serialPorts[i]);
				comboBox_Comport2->Items->Add(serialPorts[i]);
			}

			groupBox_Power1->Enabled = false;
			groupBox_Wavelength1->Enabled = false;
			groupBox_ds1->Enabled = false;
			groupBox_Power2->Enabled = false;
			groupBox_Wavelength2->Enabled = false;
			groupBox_ds2->Enabled = false;


		}
private: System::Void button_init_Comport_Click(System::Object^  sender, System::EventArgs^  e) {		 //Comport Connect
			int reg = 0, data = 0;
			int errorCode = 0;
			unsigned char* temp = NULL;
			string stdStr = "";
			std::string stdText = "";
			String^ SysTmp = comboBox_Comport->Text;
			//int comportNum = comboBox_Comport->SelectedIndex;
			char mode[] = { '8','N','1',0 };


	
			MarshalString(SysTmp, stdText);
			if (stdText.length() == 4) {
				comportNum = (stdText.at(3) - '0') - 1;
			}
			else if (stdText.length() > 4) {
				comportNum = (stdText.at(3) - '0') * 10 + (stdText.at(4) - '0') - 1;
			}
			errorCode = RS232_OpenComport(comportNum, 9600, mode);

			
			//temp = Rs232_read(comportNum);

			String^ SysTmp1 = "";																
			String^ SysTmp2 = "";
			String^ SysTmp3 = "";
			String^ SysTmp4 = "";
			String^ SysTmp5 = "";
			String^ SysTmp6 = "";
			String^ SysTmp7 = "";

			SysTmp1 = ITLAshow(0x50, 0, 0, comportNum);											//Lower power
			SysTmp2 = ITLAshow(0x51, 0, 0, comportNum);											//Upper power
			SysTmp3 = ITLAshow(0x52, 0, 0, comportNum);											//First Frequency THz
			SysTmp4 = ITLAshow(0x53, 0, 0, comportNum);											//First Frequency GHz
			SysTmp5 = ITLAshow(0x54, 0, 0, comportNum);											//Last Frequency THz
			SysTmp6 = ITLAshow(0x55, 0, 0, comportNum);											//Last Frequecy GHz
			SysTmp7 = ITLAshow(0x4F, 0, 0, comportNum);											//Fine tune range


			

			

			



			if (errorCode == 0) {																	//Port connect init start
				groupBox_Power1->Enabled = true;
				groupBox_Wavelength1->Enabled = true;
				groupBox_ds1->Enabled = true;
				groupBox_Power2->Enabled = true;
				groupBox_Wavelength2->Enabled = true;
				groupBox_ds2->Enabled = true;



				textBox_lowp->Text = "";
				textBox_highp->Text = "";
				textBox_lowf->Text = "";
				textBox_highf->Text = "";
				textBox_lowft->Text = "";
				textBox_highft->Text = "";


				textBox_lowp->AppendText((Convert::ToInt32(SysTmp1->Substring(4, 4), 16)*0.01).ToString());
				textBox_highp->AppendText((Convert::ToInt32(SysTmp2->Substring(4, 4), 16)*0.01).ToString());
				textBox_lowf->AppendText((Convert::ToInt32(SysTmp4->Substring(4, 4), 16)*0.0001 + Convert::ToInt32(SysTmp3->Substring(4, 4), 16)).ToString());
				textBox_highf->AppendText((Convert::ToInt32(SysTmp6->Substring(4, 4), 16)*0.0001 + Convert::ToInt32(SysTmp5->Substring(4, 4), 16)).ToString());
				textBox_lowft->AppendText("- " + (Convert::ToInt32(SysTmp7->Substring(4, 4), 16)).ToString());
				textBox_highft->AppendText((Convert::ToInt32(SysTmp7->Substring(4, 4), 16)).ToString());

			


			} else {
				MessageBox::Show("Failed to connect LASER 1", "Warning", MessageBoxButtons::OK);

			}
		}

private: System::Void button_init_Comport2_Click(System::Object^  sender, System::EventArgs^  e) {

			int reg = 0, data = 0;
			int errorCode = 0;
			unsigned char* temp = NULL;
			string stdStr = "";
			std::string stdText = "";
			String^ SysTmp8 = comboBox_Comport2->Text;
			//int comportNum = comboBox_Comport->SelectedIndex;
			char mode[] = { '8','N','1',0 };



			MarshalString(SysTmp8, stdText);
			if (stdText.length() == 4) {
				comportNum2 = (stdText.at(3) - '0') - 1;
			}
			else if (stdText.length() > 4) {
				comportNum2 = (stdText.at(3) - '0') * 10 + (stdText.at(4) - '0') - 1;
			}
			errorCode = RS232_OpenComport(comportNum2, 9600, mode);

			//temp = Rs232_read(comportNum);



			String^ SysTmp9 = "";
			String^ SysTmp10 = "";
			String^ SysTmp11 = "";
			String^ SysTmp12 = "";
			String^ SysTmp13 = "";
			String^ SysTmp14 = "";
			String^ SysTmp15 = "";

			SysTmp9 = ITLAshow(0x50, 0, 0, comportNum2);											//Lower power
			SysTmp10 = ITLAshow(0x51, 0, 0, comportNum2);											//Upper power
			SysTmp11 = ITLAshow(0x52, 0, 0, comportNum2);											//First Frequency THz
			SysTmp12 = ITLAshow(0x53, 0, 0, comportNum2);											//First Frequency GHz
			SysTmp13 = ITLAshow(0x54, 0, 0, comportNum2);											//Last Frequency THz
			SysTmp14 = ITLAshow(0x55, 0, 0, comportNum2);											//Last Frequecy GHz
			SysTmp15 = ITLAshow(0x4F, 0, 0, comportNum2);											//Fine tune range







			if (errorCode == 0) {																	//Port connect init start
				groupBox_Power1->Enabled = true;
				groupBox_Wavelength1->Enabled = true;
				groupBox_ds1->Enabled = true;
				groupBox_Power2->Enabled = true;
				groupBox_Wavelength2->Enabled = true;
				groupBox_ds2->Enabled = true;



				textBox_lowp2->Text = "";
				textBox_highp2->Text = "";
				textBox_lowf2->Text = "";
				textBox_highf2->Text = "";
				textBox_lowft2->Text = "";
				textBox_highft2->Text = "";



				textBox_lowp2->AppendText((Convert::ToInt32(SysTmp9->Substring(4, 4), 16)*0.01).ToString());
				textBox_highp2->AppendText((Convert::ToInt32(SysTmp10->Substring(4, 4), 16)*0.01).ToString());
				textBox_lowf2->AppendText((Convert::ToInt32(SysTmp12->Substring(4, 4), 16)*0.0001 + Convert::ToInt32(SysTmp11->Substring(4, 4), 16)).ToString());
				textBox_highf2->AppendText((Convert::ToInt32(SysTmp14->Substring(4, 4), 16)*0.0001 + Convert::ToInt32(SysTmp13->Substring(4, 4), 16)).ToString());
				textBox_lowft2->AppendText("- " + (Convert::ToInt32(SysTmp15->Substring(4, 4), 16)).ToString());
				textBox_highft2->AppendText((Convert::ToInt32(SysTmp15->Substring(4, 4), 16)).ToString());





			}
			else {
				MessageBox::Show("Failed to connect LASER 2", "Warning", MessageBoxButtons::OK);

			}



		}

private: System::Void button_CloseComport_Click(System::Object^  sender, System::EventArgs^  e) {

			RS232_CloseComport(comportNum);
			button_init_Comport->Enabled = true;
			groupBox_Power1->Enabled = false;
			groupBox_Wavelength1->Enabled = false;
			groupBox_ds1->Enabled = false;
			groupBox_Power2->Enabled = false;
			groupBox_Wavelength2->Enabled = false;
			groupBox_ds2->Enabled = false;
		}

private: System::Void button_CloseComport2_Click(System::Object^  sender, System::EventArgs^  e) {


			RS232_CloseComport(comportNum2);
			button_init_Comport2->Enabled = true;
			groupBox_Power1->Enabled = false;
			groupBox_Wavelength1->Enabled = false;
			groupBox_ds1->Enabled = false;
			groupBox_Power2->Enabled = false;
			groupBox_Wavelength2->Enabled = false;
			groupBox_ds2->Enabled = false;
		}

private: System::Void button_enable_Click(System::Object^  sender, System::EventArgs^  e) {  //Laser enable button
	int reg = 0, data = 0;
	unsigned char* temp = NULL;
	string stdStr = "";
	String^ SysTmp = "";

	laserStatus = !laserStatus;

	if (laserStatus) {
		data = 8;

		button_enable->Text = "Disable";
	}
	else {
		data = 0;

		button_enable->Text = "Enable";
	}

	//void ITLACommand(int reg, int data, int RW, int port)
	SysTmp = ITLAshow(50, data, 1, comportNum);
	SysTmp = ITLAshow(50, data, 1, comportNum2);

	SysTmp = gcnew String(stdStr.c_str());



}
		
private: System::Void button_enable2_Click(System::Object^  sender, System::EventArgs^  e) { //Laser Enable Fixed Frequency tab
	int reg = 0, data = 0;
	unsigned char* temp = NULL;
	string stdStr = "";
	String^ SysTmp = "";

	laserStatus = !laserStatus;

	if (laserStatus) {
		data = 8;

		button_enable->Text = "Disable";
	}
	else {
		data = 0;
		button_enable->Text = "Enable";
	}

	//void ITLACommand(int reg, int data, int RW, int port)
	SysTmp = ITLAshow(50, data, 1, comportNum);
	SysTmp = ITLAshow(50, data, 1, comportNum2);

	SysTmp = gcnew String(stdStr.c_str());
}

private: System::Void button_pw_set_Click(System::Object^  sender, System::EventArgs^  e) { //Power setting button
	int reg = 0;
	double data = 0;
	unsigned char* temp = NULL;
	string stdStr = "";
	String^ SysTmp = "";
	String^ SysTmp1 = "";
	String^ SysTmp2 = "";
	String^ SysTmp3 = "";
	String^ SysTmp4 = "";

	SysTmp1 = ITLAshow(0x50, 0, 0, comportNum);											//Lower power
	SysTmp2 = ITLAshow(0x51, 0, 0, comportNum);
	SysTmp3 = ITLAshow(0x50, 0, 0, comportNum2);											//Lower power
	SysTmp4 = ITLAshow(0x51, 0, 0, comportNum2);

	data = Convert::ToDouble(textBox_pw_level->Text) * 100;

	if (data <= Convert::ToInt32(SysTmp2->Substring(4, 4), 16) && data >= Convert::ToInt32(SysTmp1->Substring(4, 4), 16)) {
		if (data <= Convert::ToInt32(SysTmp2->Substring(4, 4), 16) && data >= Convert::ToInt32(SysTmp1->Substring(4, 4), 16)) {

			reg = 0x31;
			double realpower = Convert::ToDouble(textBox_pw_level->Text);

			//void ITLACommand(int reg, int data, int RW, int port)
			SysTmp = ITLAshow(reg, data, 1, comportNum);
			SysTmp = ITLAshow(reg, data, 1, comportNum2);

		}
		else
		{
			MessageBox::Show("Out of Power capability range!\nPlease check 'General' tab and enter valid power", "Warning", MessageBoxButtons::OK);
		}

	}
	else
	{
		MessageBox::Show("Out of Power capability range!\nPlease check 'General' tab and enter valid power", "Warning", MessageBoxButtons::OK);
	}


}
		

private: System::Void button_Power2_Click(System::Object^  sender, System::EventArgs^  e) { //Fixed Frequency page power setting
	int reg = 0;
	double data = 0;
	unsigned char* temp = NULL;
	string stdStr = "";
	String^ SysTmp = "";
	String^ SysTmp1 = "";
	String^ SysTmp2 = "";
	String^ SysTmp3 = "";
	String^ SysTmp4 = "";

	SysTmp1 = ITLAshow(0x50, 0, 0, comportNum);											//Lower power
	SysTmp2 = ITLAshow(0x51, 0, 0, comportNum);
	SysTmp3 = ITLAshow(0x50, 0, 0, comportNum2);											//Lower power
	SysTmp4 = ITLAshow(0x51, 0, 0, comportNum2);

	data = Convert::ToDouble(textBox_pw_level->Text) * 100;

	if (data <= Convert::ToInt32(SysTmp2->Substring(4, 4), 16) && data >= Convert::ToInt32(SysTmp1->Substring(4, 4), 16)) {
		if (data <= Convert::ToInt32(SysTmp2->Substring(4, 4), 16) && data >= Convert::ToInt32(SysTmp1->Substring(4, 4), 16)) {

			reg = 0x31;
			double realpower = Convert::ToDouble(textBox_pw_level->Text);

			//void ITLACommand(int reg, int data, int RW, int port)
			SysTmp = ITLAshow(reg, data, 1, comportNum);
			SysTmp = ITLAshow(reg, data, 1, comportNum2);

		}
		else
		{
			MessageBox::Show("Out of Power capability range!\nPlease check 'General' tab and enter valid power", "Warning", MessageBoxButtons::OK);
		}

	}
	else
	{
		MessageBox::Show("Out of Power capability range!\nPlease check 'General' tab and enter valid power", "Warning", MessageBoxButtons::OK);
	}
}
		


private: System::Void button_SetWave_Click(System::Object^  sender, System::EventArgs^  e) {  //Frequency setting THz
	int reg = 0, data_thz, data_ghz, data_mhz = 0;

	double m1, g1, g2 = 0;
	unsigned char* temp1 = NULL;
	unsigned char* temp = NULL;


	//double freq2 = Convert::ToDouble(textBox_wave_nm->Text);
	string stdStr = "";
	String^ SysTmp = "";
	String^ SysTmp1 = "";
	String^ SysTmp2 = "";
	String^ SysTmp3 = "";
	String^ SysTmp4 = "";
	String^ SysTmp5 = "";
	String^ SysTmp6 = "";



	SysTmp1 = ITLAshow(0x52, 0, 0, comportNum);					//THz first
	SysTmp2 = ITLAshow(0x53, 0, 0, comportNum);					//GHz first
	SysTmp3 = ITLAshow(0x54, 0, 0, comportNum);					//THz last
	SysTmp4 = ITLAshow(0x55, 0, 0, comportNum);					//GHz last
	SysTmp5 = ITLAshow(0x4F, 0, 0, comportNum);					//MHz first
	SysTmp6 = ITLAshow(0x32, 0, 0, comportNum);					//laser on/off




	double freq1 = Convert::ToDouble(textBox_wave->Text);
	data_thz = (int)freq1;
	g1 = (freq1 - data_thz) * 1000;						//GHz decimal conversion
	g2 = (int)g1;
	data_ghz = g2 * 10;
	m1 = g1 - g2;
	data_mhz = m1 * 1000;

	if (Convert::ToInt32(SysTmp6->Substring(4, 4), 16) == 8)
	{
		if ((freq1 <= Convert::ToInt32(SysTmp3->Substring(4, 4), 16) + Convert::ToInt32(SysTmp4->Substring(4, 4), 16)*0.0001) && (freq1 >= Convert::ToInt32(SysTmp2->Substring(4, 4), 16)*0.0001 + Convert::ToInt32(SysTmp1->Substring(4, 4), 16))) {

			SysTmp = ITLAshow(50, 0, 1, comportNum);
			SysTmp = ITLAshow(0x35, data_thz, 1, comportNum);  // THz register set first
			SysTmp = ITLAshow(0x36, data_ghz, 1, comportNum); // GHz decimal set
			SysTmp = ITLAshow(0x62, data_mhz, 1, comportNum); // MHz decimal set
			SysTmp = ITLAshow(50, 8, 1, comportNum);
			SysTmp = ITLAshow(0x30, 1, 1, comportNum);
			SysTmp = gcnew String(stdStr.c_str());

		}
		else
		{
			MessageBox::Show("Out of Frequency capability range!\nPlease check available frequency range and enter valid frequency", "Warning", MessageBoxButtons::OK);
		}
	}
	else
	{
		if ((freq1 <= Convert::ToInt32(SysTmp3->Substring(4, 4), 16) + Convert::ToInt32(SysTmp4->Substring(4, 4), 16)*0.0001) && (freq1 >= Convert::ToInt32(SysTmp2->Substring(4, 4), 16)*0.0001 + Convert::ToInt32(SysTmp1->Substring(4, 4), 16))) {


			SysTmp = ITLAshow(0x35, data_thz, 1, comportNum);  // THz register set first
			SysTmp = ITLAshow(0x36, data_ghz, 1, comportNum); // GHz decimal set
			SysTmp = ITLAshow(0x62, data_mhz, 1, comportNum); // MHz decimal set
			SysTmp = ITLAshow(0x30, 1, 1, comportNum);
			SysTmp = gcnew String(stdStr.c_str());



		}
		else
		{
			MessageBox::Show("Out of Frequency capability range!\nPlease check available frequency range and enter valid frequency", "Warning", MessageBoxButtons::OK);
		}
	}


}

private: System::Void button_Freq2_Click(System::Object^  sender, System::EventArgs^  e) { //Fixed Frequency tab Laser 1 freq setting 
	int reg = 0, data_thz, data_ghz, data_mhz = 0;

	double m1, g1, g2 = 0;



	//double freq2 = Convert::ToDouble(textBox_wave_nm->Text);
	string stdStr = "";
	String^ SysTmp = "";
	String^ SysTmp1 = "";
	String^ SysTmp2 = "";
	String^ SysTmp3 = "";
	String^ SysTmp4 = "";
	String^ SysTmp5 = "";
	String^ SysTmp6 = "";



	SysTmp1 = ITLAshow(0x52, 0, 0, comportNum);					//THz first
	SysTmp2 = ITLAshow(0x53, 0, 0, comportNum);					//GHz first
	SysTmp3 = ITLAshow(0x54, 0, 0, comportNum);					//THz last
	SysTmp4 = ITLAshow(0x55, 0, 0, comportNum);					//GHz last
	SysTmp5 = ITLAshow(0x4F, 0, 0, comportNum);					//MHz first
	SysTmp6 = ITLAshow(0x32, 0, 0, comportNum);					//laser on/off




	double freq1 = Convert::ToDouble(textBox_wave_ff->Text);
	data_thz = (int)freq1;
	g1 = (freq1 - data_thz) * 1000;						//GHz decimal conversion
	g2 = (int)g1;
	data_ghz = g2 * 10;
	m1 = g1 - g2;
	data_mhz = m1 * 1000;

	if (Convert::ToInt32(SysTmp6->Substring(4, 4), 16) == 8)
	{
		if ((freq1 <= Convert::ToInt32(SysTmp3->Substring(4, 4), 16) + Convert::ToInt32(SysTmp4->Substring(4, 4), 16)*0.0001) && (freq1 >= Convert::ToInt32(SysTmp2->Substring(4, 4), 16)*0.0001 + Convert::ToInt32(SysTmp1->Substring(4, 4), 16))) {

			SysTmp = ITLAshow(50, 0, 1, comportNum);
			SysTmp = ITLAshow(0x35, data_thz, 1, comportNum);  // THz register set first
			SysTmp = ITLAshow(0x36, data_ghz, 1, comportNum); // GHz decimal set
			SysTmp = ITLAshow(0x62, data_mhz, 1, comportNum); // MHz decimal set
			SysTmp = ITLAshow(50, 8, 1, comportNum);
			SysTmp = ITLAshow(0x30, 1, 1, comportNum);
			SysTmp = gcnew String(stdStr.c_str());

		}
		else
		{
			MessageBox::Show("Out of Frequency capability range!\nPlease check available frequency range and enter valid frequency", "Warning", MessageBoxButtons::OK);
		}
	}
	else
	{
		if ((freq1 <= Convert::ToInt32(SysTmp3->Substring(4, 4), 16) + Convert::ToInt32(SysTmp4->Substring(4, 4), 16)*0.0001) && (freq1 >= Convert::ToInt32(SysTmp2->Substring(4, 4), 16)*0.0001 + Convert::ToInt32(SysTmp1->Substring(4, 4), 16))) {


			SysTmp = ITLAshow(0x35, data_thz, 1, comportNum);  // THz register set first
			SysTmp = ITLAshow(0x36, data_ghz, 1, comportNum); // GHz decimal set
			SysTmp = ITLAshow(0x62, data_mhz, 1, comportNum); // MHz decimal set
			SysTmp = ITLAshow(0x30, 1, 1, comportNum);
			SysTmp = gcnew String(stdStr.c_str());



		}
		else
		{
			MessageBox::Show("Out of Frequency capability range!\nPlease check available frequency range and enter valid frequency", "Warning", MessageBoxButtons::OK);
		}
	}
}

private: System::Void button_Beat_Click(System::Object^  sender, System::EventArgs^  e) { //Beat Pattern setting
	int reg = 0, data_thz, data_ghz, data_mhz = 0;
	double m1, g1, g2 = 0;
	double LF1 = Convert::ToDouble(textBox_wave_ff->Text);
	double LF2 = (Convert::ToInt32(textBox_set_beat->Text) * 0.001) + LF1;

	string stdStr = "";
	String^ SysTmp = "";
	String^ SysTmp1 = "";
	String^ SysTmp2 = "";
	String^ SysTmp3 = "";
	String^ SysTmp4 = "";
	String^ SysTmp5 = "";
	String^ SysTmp6 = "";

	SysTmp1 = ITLAshow(0x52, 0, 0, comportNum2);					//THz first
	SysTmp2 = ITLAshow(0x53, 0, 0, comportNum2);					//GHz first
	SysTmp3 = ITLAshow(0x54, 0, 0, comportNum2);					//THz last
	SysTmp4 = ITLAshow(0x55, 0, 0, comportNum2);					//GHz last
	SysTmp5 = ITLAshow(0x4F, 0, 0, comportNum2);					//MHz first
	SysTmp6 = ITLAshow(0x32, 0, 0, comportNum2);					//laser on/off

	data_thz = (int)LF2;
	g1 = (LF2 - data_thz) * 1000;						//GHz decimal conversion
	g2 = (int)g1;
	data_ghz = g2 * 10;
	m1 = g1 - g2;
	data_mhz = m1 * 1000;

	if (Convert::ToInt32(SysTmp6->Substring(4, 4), 16) == 8)
	{
		if ((LF2 <= Convert::ToInt32(SysTmp3->Substring(4, 4), 16) + Convert::ToInt32(SysTmp4->Substring(4, 4), 16)*0.0001) && (LF2 >= Convert::ToInt32(SysTmp2->Substring(4, 4), 16)*0.0001 + Convert::ToInt32(SysTmp1->Substring(4, 4), 16))) {

			SysTmp = ITLAshow(50, 0, 1, comportNum2);
			SysTmp = ITLAshow(0x35, data_thz, 1, comportNum2);  // THz register set first
			SysTmp = ITLAshow(0x36, data_ghz, 1, comportNum2); // GHz decimal set
			SysTmp = ITLAshow(0x62, data_mhz, 1, comportNum2); // MHz decimal set
			SysTmp = ITLAshow(50, 8, 1, comportNum2);
			SysTmp = ITLAshow(0x30, 1, 1, comportNum2);
			SysTmp = gcnew String(stdStr.c_str());

		}
		else
		{
			MessageBox::Show("Out of Frequency capability range!\nPlease lower your 'Beat Pattern' or 'LASER 1 frequency'", "Warning", MessageBoxButtons::OK);
		}
	}
	else
	{
		if ((LF2 <= Convert::ToInt32(SysTmp3->Substring(4, 4), 16) + Convert::ToInt32(SysTmp4->Substring(4, 4), 16)*0.0001) && (LF2 >= Convert::ToInt32(SysTmp2->Substring(4, 4), 16)*0.0001 + Convert::ToInt32(SysTmp1->Substring(4, 4), 16))) {


			SysTmp = ITLAshow(0x35, data_thz, 1, comportNum2);  // THz register set first
			SysTmp = ITLAshow(0x36, data_ghz, 1, comportNum2); // GHz decimal set
			SysTmp = ITLAshow(0x62, data_mhz, 1, comportNum2); // MHz decimal set
			SysTmp = ITLAshow(0x30, 1, 1, comportNum2);
			SysTmp = gcnew String(stdStr.c_str());



		}
		else
		{
			MessageBox::Show("Out of Frequency capability range!\nPlease lower your 'Beat Pattern' or 'LASER 1 frequency'", "Warning", MessageBoxButtons::OK);
		}
	}

}

private: System::Void button_SetWave2_Click(System::Object^  sender, System::EventArgs^  e) {
	int reg = 0, data_thz, data_ghz, data_mhz = 0;

	double m1, g1, g2 = 0;
	unsigned char* temp1 = NULL;
	unsigned char* temp = NULL;


	//double freq2 = Convert::ToDouble(textBox_wave_nm->Text);
	string stdStr = "";
	String^ SysTmp = "";
	String^ SysTmp1 = "";
	String^ SysTmp2 = "";
	String^ SysTmp3 = "";
	String^ SysTmp4 = "";
	String^ SysTmp5 = "";
	String^ SysTmp6 = "";



	SysTmp1 = ITLAshow(0x52, 0, 0, comportNum2);					//THz first
	SysTmp2 = ITLAshow(0x53, 0, 0, comportNum2);					//GHz first
	SysTmp3 = ITLAshow(0x54, 0, 0, comportNum2);					//THz last
	SysTmp4 = ITLAshow(0x55, 0, 0, comportNum2);					//GHz last
	SysTmp5 = ITLAshow(0x4F, 0, 0, comportNum2);					//MHz first
	SysTmp6 = ITLAshow(0x32, 0, 0, comportNum2);					//laser on/off




	double freq1 = Convert::ToDouble(textBox_wave2->Text);
	data_thz = (int)freq1;
	g1 = (freq1 - data_thz) * 1000;						//GHz decimal conversion
	g2 = (int)g1;
	data_ghz = g2 * 10;
	m1 = g1 - g2;
	data_mhz = m1 * 1000;

	if (Convert::ToInt32(SysTmp6->Substring(4, 4), 16) == 8)
	{
		if ((freq1 <= Convert::ToInt32(SysTmp3->Substring(4, 4), 16) + Convert::ToInt32(SysTmp4->Substring(4, 4), 16)*0.0001) && (freq1 >= Convert::ToInt32(SysTmp2->Substring(4, 4), 16)*0.0001 + Convert::ToInt32(SysTmp1->Substring(4, 4), 16))) {

			SysTmp = ITLAshow(50, 0, 1, comportNum2);
			SysTmp = ITLAshow(0x35, data_thz, 1, comportNum2);  // THz register set first
			SysTmp = ITLAshow(0x36, data_ghz, 1, comportNum2); // GHz decimal set
			SysTmp = ITLAshow(0x62, data_mhz, 1, comportNum2); // MHz decimal set
			SysTmp = ITLAshow(50, 8, 1, comportNum2);
			SysTmp = ITLAshow(0x30, 1, 1, comportNum2);
			SysTmp = gcnew String(stdStr.c_str());

		}
		else
		{
			MessageBox::Show("Out of Frequency capability range!\nPlease check available frequency range and enter valid frequency", "Warning", MessageBoxButtons::OK);
		}
	}
	else
	{
		if ((freq1 <= Convert::ToInt32(SysTmp3->Substring(4, 4), 16) + Convert::ToInt32(SysTmp4->Substring(4, 4), 16)*0.0001) && (freq1 >= Convert::ToInt32(SysTmp2->Substring(4, 4), 16)*0.0001 + Convert::ToInt32(SysTmp1->Substring(4, 4), 16))) {


			SysTmp = ITLAshow(0x35, data_thz, 1, comportNum2);  // THz register set first
			SysTmp = ITLAshow(0x36, data_ghz, 1, comportNum2); // GHz decimal set
			SysTmp = ITLAshow(0x62, data_mhz, 1, comportNum2); // MHz decimal set
			SysTmp = ITLAshow(0x30, 1, 1, comportNum2);
			SysTmp = gcnew String(stdStr.c_str());



		}
		else
		{
			MessageBox::Show("Out of Frequency capability range!\nPlease check available frequency range and enter valid frequency", "Warning", MessageBoxButtons::OK);
		}
	}
}






private: System::Void button_su_Click(System::Object^  sender, System::EventArgs^  e) { //Status Update for CW setting tab

	double LF1, LF2 = 0.0;
	int beatpattern = 0;

	String^ SysTmp1 = "";
	String^ SysTmp2 = "";
	String^ SysTmp3 = "";
	String^ SysTmp4 = "";
	String^ SysTmp5 = "";
	String^ SysTmp6 = "";

	SysTmp1 = ITLAshow(0x42, 0, 0, comportNum);											//Current power
	SysTmp2 = ITLAshow(0x41, 0, 0, comportNum);
	SysTmp3 = ITLAshow(0x40, 0, 0, comportNum);
	SysTmp4 = ITLAshow(0x42, 0, 0, comportNum2);											//Current power
	SysTmp5 = ITLAshow(0x41, 0, 0, comportNum2);
	SysTmp6 = ITLAshow(0x40, 0, 0, comportNum2);

	LF1 = Convert::ToInt32(SysTmp2->Substring(4, 4), 16)*0.0001 + Convert::ToInt32(SysTmp3->Substring(4, 4), 16);
	LF2 = Convert::ToInt32(SysTmp5->Substring(4, 4), 16)*0.0001 + Convert::ToInt32(SysTmp6->Substring(4, 4), 16);

	textBox_cpw->Text = "";
	textBox_cf->Text = "";
	textBox_cpw2->Text = "";
	textBox_cf2->Text = "";
	textBox_beatpattern->Text = "";



	if (Convert::ToInt32(SysTmp1->Substring(4, 4), 16)*0.01 > 100)
	{
		textBox_cpw->AppendText("Laser Off");
	}
	else
	{
		textBox_cpw->AppendText((Convert::ToInt32(SysTmp1->Substring(4, 4), 16)*0.01).ToString());
	}

	if (Convert::ToInt32(SysTmp4->Substring(4, 4), 16)*0.01 > 100)
	{
		textBox_cpw2->AppendText("Laser Off");
	}
	else
	{
		textBox_cpw2->AppendText((Convert::ToInt32(SysTmp4->Substring(4, 4), 16)*0.01).ToString());
	}


	textBox_cf->AppendText((Convert::ToInt32(SysTmp2->Substring(4, 4), 16)*0.0001 + Convert::ToInt32(SysTmp3->Substring(4, 4), 16)).ToString());
	textBox_cf->AppendText((Convert::ToInt32(SysTmp5->Substring(4, 4), 16)*0.0001 + Convert::ToInt32(SysTmp6->Substring(4, 4), 16)).ToString());

	beatpattern = abs((LF1 - LF2) * 1000);
	textBox_beatpattern->AppendText(beatpattern.ToString());

}
		


private: System::Void button_su2_Click(System::Object^  sender, System::EventArgs^  e) { //Status Update for Fixed Frequency tab
	double LF1, LF2 = 0.0;
	int beatpattern = 0;

	String^ SysTmp1 = "";
	String^ SysTmp2 = "";
	String^ SysTmp3 = "";
	String^ SysTmp4 = "";
	String^ SysTmp5 = "";
	String^ SysTmp6 = "";

	SysTmp1 = ITLAshow(0x42, 0, 0, comportNum);											//Current power L1
	SysTmp2 = ITLAshow(0x41, 0, 0, comportNum);
	SysTmp3 = ITLAshow(0x40, 0, 0, comportNum);
	SysTmp4 = ITLAshow(0x42, 0, 0, comportNum2);											//Current power L2
	SysTmp5 = ITLAshow(0x41, 0, 0, comportNum2);
	SysTmp6 = ITLAshow(0x40, 0, 0, comportNum2);

	LF1 = Convert::ToInt32(SysTmp2->Substring(4, 4), 16)*0.0001 + Convert::ToInt32(SysTmp3->Substring(4, 4), 16);
	LF2 = Convert::ToInt32(SysTmp5->Substring(4, 4), 16)*0.0001 + Convert::ToInt32(SysTmp6->Substring(4, 4), 16);

	textBox_cpw_ff->Text = "";
	textBox_cf_ff->Text = "";
	textBox_cpw2_ff->Text = "";
	textBox_cf2_ff->Text = "";
	textBox_beatpattern_ff->Text = "";



	if (Convert::ToInt32(SysTmp1->Substring(4, 4), 16)*0.01 > 100)
	{
		textBox_cpw_ff->AppendText("Laser Off");
	}
	else
	{
		textBox_cpw_ff->AppendText((Convert::ToInt32(SysTmp1->Substring(4, 4), 16)*0.01).ToString());
	}

	if (Convert::ToInt32(SysTmp4->Substring(4, 4), 16)*0.01 > 100)
	{
		textBox_cpw2_ff->AppendText("Laser Off");
	}
	else
	{
		textBox_cpw2_ff->AppendText((Convert::ToInt32(SysTmp4->Substring(4, 4), 16)*0.01).ToString());
	}


	textBox_cf_ff->AppendText((Convert::ToInt32(SysTmp2->Substring(4, 4), 16)*0.0001 + Convert::ToInt32(SysTmp3->Substring(4, 4), 16)).ToString());
	textBox_cf_ff->AppendText((Convert::ToInt32(SysTmp5->Substring(4, 4), 16)*0.0001 + Convert::ToInt32(SysTmp6->Substring(4, 4), 16)).ToString());

	beatpattern = abs((LF1 - LF2) * 1000);
	textBox_beatpattern_ff->AppendText(beatpattern.ToString());

}





private: System::Void label10_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox_Power_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void comboBox_Comport_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void comboBox_Serial_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label15_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox_Command1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox_CMD_Pa1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}

private: System::Void label19_Click(System::Object^  sender, System::EventArgs^  e) {
}

private: System::Void textBox_pw_level_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox_wave_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	
}
private: System::Void groupBox_Command_Enter(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label17_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label21_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox_wave_nm_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}

private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	main();
}
private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
}

private: System::Void label22_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label22_Click_1(System::Object^  sender, System::EventArgs^  e) {
}

private: System::Void label_Comport_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label27_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label37_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label36_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label45_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void tabPage1_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
}

private: System::Void label63_Click(System::Object^  sender, System::EventArgs^  e) {
}

private: System::Void label65_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox1_TextChanged_2(System::Object^  sender, System::EventArgs^  e) {
}





private: System::Void button_sd_Click(System::Object^  sender, System::EventArgs^  e) {  //save current data log



	ofstream outData;

	

	double p = Convert::ToDouble(textBox_cpw->Text);
	double f = Convert::ToDouble(textBox_cf->Text);
	double p2 = Convert::ToDouble(textBox_cpw2->Text);
	double f2 = Convert::ToDouble(textBox_cf2->Text);
	int bp = Convert::ToDouble(textBox_beatpattern);

	char currDate[30];
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	sprintf(currDate, "%d-%d-%d %d:%d:%d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);




	
	outData.open("DataLog.csv", ios::app);
	outData << "----------------------------------------" << endl;
	outData << "LASER 1 Power : " << p << " dBm" << endl;
	outData << "LASER 1 Frequency : " << f << " THz" << endl;
	outData << "LASER 2 Power : " << p2 << " dBm" << endl;
	outData << "LASER 2 Frequency : " << f2 << " THz" << endl;
	outData << "Beat Pattern : " << bp << " GHz" << endl;
	outData << "Saved Time : " << currDate << endl;
	outData << "----------------------------------------" << endl;
	outData << " " << endl;

}

private: System::Void button_sd2_Click(System::Object^  sender, System::EventArgs^  e) {


	ofstream outData;



	double p = Convert::ToDouble(textBox_cpw_ff->Text);
	double f = Convert::ToDouble(textBox_cf_ff->Text);
	double p2 = Convert::ToDouble(textBox_cpw2_ff->Text);
	double f2 = Convert::ToDouble(textBox_cf2_ff->Text);
	int bp = Convert::ToDouble(textBox_beatpattern_ff->Text);

	char currDate[30];
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	sprintf(currDate, "%d-%d-%d %d:%d:%d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);





	outData.open("DataLog.csv", ios::app);
	outData << "----------------------------------------" << endl;
	outData << "LASER 1 Power : " << p << " dBm" << endl;
	outData << "LASER 1 Frequency : " << f << " THz" << endl;
	outData << "LASER 2 Power : " << p2 << " dBm" << endl;
	outData << "LASER 2 Frequency : " << f2 << " THz" << endl;
	outData << "Beat Pattern : " << bp << " GHz" << endl;
	outData << "Saved Time : " << currDate << endl;
	outData << "----------------------------------------" << endl;
	outData << " " << endl;

}




private: System::Void button_stop(System::Object^  sender, System::EventArgs^  e) {
	if (backgroundWorker1->IsBusy)
	{
		backgroundWorker1->CancelAsync();
	}
}




/*Thread for New Window*/
private: System::Void backgroundWorker2_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {

	MyForm1 ^obj1 = gcnew MyForm1();
	obj1->ShowDialog();
	if (backgroundWorker2->CancellationPending)
	{
		e->Cancel = true;

		return;
	}

}
private: System::Void backgroundWorker2_ProgressChanged(System::Object^  sender, System::ComponentModel::ProgressChangedEventArgs^  e) {
}
private: System::Void backgroundWorker2_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e) {

}










private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	ITLAshow(50, 0, 1, comportNum);
	ITLAshow(50, 0, 1, comportNum2);
	button_CloseComport->PerformClick();
	button_CloseComport2->PerformClick();
	Application::Exit();
}
private: System::Void helpPageToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	if (!backgroundWorker2->IsBusy)
	{
		backgroundWorker2->RunWorkerAsync();
	}
}
};
}



