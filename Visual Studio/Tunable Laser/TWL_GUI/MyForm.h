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
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
int comportNum = 0;
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

	private: System::Windows::Forms::GroupBox^  groupBox_ScanMode;



	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button_CMD_RD;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::TextBox^  textBox_CMD_Pa1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button_CMD_WR;
	private: System::Windows::Forms::TextBox^  textBox_Command1;
	private: System::Windows::Forms::Button^  button_Exit;
	private: System::Windows::Forms::ComboBox^  comboBox_Comport;
	private: System::Windows::Forms::Button^  button_Clear;

	private: System::Windows::Forms::TextBox^  textBox_Freq;
	private: System::Windows::Forms::Button^  button_Final;




	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  textBox_F0;

	private: System::Windows::Forms::Label^  label3;


	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::TextBox^  textBox_F3;

	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  textBox_E7;

	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  textBox_F2;

	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  textBox_F1;

	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::TextBox^  textBox_Power;
	private: System::Windows::Forms::Button^  button_Get;






	private: System::Windows::Forms::ComboBox^  comboBox_Serial;
	private: System::Windows::Forms::Button^  button_CloseComport;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::TextBox^  textBox_LFH;
	private: System::Windows::Forms::TextBox^  textBox_LFL;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::TextBox^  textBox_Range;

	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::CheckBox^  checkBox_Manual;



	private: System::Windows::Forms::Button^  button_enable;


	private: System::Windows::Forms::Button^  button_SetWave;
	private: System::Windows::Forms::TextBox^  textBox_wave;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::ImageList^  imageList1;
	private: System::Windows::Forms::PictureBox^  pictureBox1;



	private: System::Windows::Forms::TextBox^  textBox_pw_level;
	private: System::Windows::Forms::Button^  button_pw_set;

	private: System::Windows::Forms::GroupBox^  groupBox_Setting;


private: System::Windows::Forms::ColorDialog^  colorDialog1;
private: System::Windows::Forms::ColorDialog^  colorDialog2;
private: System::Windows::Forms::Label^  label21;
private: System::Windows::Forms::TextBox^  textBox_wave_nm;


private: System::Windows::Forms::Label^  label18;
private: System::Windows::Forms::Button^  button_SetWaveNm;

private: System::Windows::Forms::Label^  label22;
private: System::Windows::Forms::TabControl^  textBox_Freq_user;

private: System::Windows::Forms::TabPage^  tabPage1;
private: System::Windows::Forms::TabPage^  tabPage2;
private: System::Windows::Forms::TabPage^  tabPage3;
private: System::Windows::Forms::TabPage^  tabPage4;
private: System::Windows::Forms::GroupBox^  groupBox_deviceInfo;
private: System::Windows::Forms::Label^  label28;
private: System::Windows::Forms::Label^  label27;
private: System::Windows::Forms::Label^  label26;
private: System::Windows::Forms::Label^  label25;
private: System::Windows::Forms::Label^  label24;
private: System::Windows::Forms::Label^  label23;
private: System::Windows::Forms::Label^  label16;
private: System::Windows::Forms::Label^  label32;
private: System::Windows::Forms::Label^  label31;
private: System::Windows::Forms::Label^  label30;
private: System::Windows::Forms::Label^  label29;
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
private: System::Windows::Forms::Label^  label41;
private: System::Windows::Forms::TextBox^  textBox_highw;

private: System::Windows::Forms::Label^  label40;
private: System::Windows::Forms::Label^  label39;
private: System::Windows::Forms::TextBox^  textBox_loww;
private: System::Windows::Forms::TextBox^  textBox_baud;
private: System::Windows::Forms::TextBox^  textBox_highft;
private: System::Windows::Forms::Label^  label42;
private: System::Windows::Forms::Label^  label43;
private: System::Windows::Forms::Label^  label44;
private: System::Windows::Forms::TextBox^  textBox_lowft;
private: System::Windows::Forms::Label^  label45;
private: System::Windows::Forms::TextBox^  textBox_conn;

private: System::Windows::Forms::Label^  label46;
private: System::Windows::Forms::GroupBox^  groupBox2;
private: System::Windows::Forms::ComboBox^  comboBox_ch;

private: System::Windows::Forms::Label^  label50;
private: System::Windows::Forms::Label^  label49;
private: System::Windows::Forms::Label^  label48;
private: System::Windows::Forms::Label^  label47;
private: System::Windows::Forms::Label^  label19;
private: System::Windows::Forms::Label^  label17;
private: System::Windows::Forms::GroupBox^  groupBox1;
private: System::Windows::Forms::TextBox^  textBox_chvar;
private: System::Windows::Forms::Button^  button_setch;
private: System::Windows::Forms::GroupBox^  groupBox_option;

private: System::Windows::Forms::GroupBox^  groupBox_ds;

private: System::Windows::Forms::GroupBox^  groupBox5;
private: System::Windows::Forms::Label^  label20;
private: System::Windows::Forms::Label^  label63;
private: System::Windows::Forms::Label^  label60;
private: System::Windows::Forms::Label^  label61;
private: System::Windows::Forms::Label^  label62;

private: System::Windows::Forms::TextBox^  textBox_ct;
private: System::Windows::Forms::TextBox^  textBox_cw;
private: System::Windows::Forms::TextBox^  textBox_cf;
private: System::Windows::Forms::TextBox^  textBox_cpw;

private:


private: System::Windows::Forms::Label^  label58;
private: System::Windows::Forms::Label^  label57;
private: System::Windows::Forms::Label^  label56;
private: System::Windows::Forms::Label^  label55;

private: System::Windows::Forms::Label^  label53;
private: System::Windows::Forms::Label^  label52;
private: System::Windows::Forms::Label^  label51;
private: System::Windows::Forms::Button^  button_sd;
private: System::Windows::Forms::Button^  button_rt;
private: System::Windows::Forms::Button^  button_su;

private: System::Windows::Forms::Button^  button_savedef;
private: System::Windows::Forms::GroupBox^  groupBox4;
private: System::Windows::Forms::Label^  label65;
private: System::Windows::Forms::TextBox^  textBox_dither;

private: System::Windows::Forms::GroupBox^  groupBox3;
private: System::Windows::Forms::Button^  button_lnm;

private: System::Windows::Forms::Button^  button_ditherEn;
private: System::Windows::Forms::Button^  button_ditherSet;
private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;
private: System::Windows::Forms::GroupBox^  groupBox_Command;
public: System::Windows::Forms::Label^  label_status;
private:

private: System::Windows::Forms::Button^  button2;
private: System::ComponentModel::BackgroundWorker^  backgroundWorker2;
private: System::ComponentModel::BackgroundWorker^  backgroundWorker3;
private: System::Windows::Forms::Button^  scan0926;
private: System::Windows::Forms::Label^  label54;
private: System::ComponentModel::BackgroundWorker^  backgroundWorker4;
private: System::Windows::Forms::GroupBox^  groupBox_scan_user;

private: System::Windows::Forms::Label^  label9;
private: System::Windows::Forms::Button^  button_scan_user;


private: System::Windows::Forms::Button^  button_stop_user;
private: System::Windows::Forms::CheckBox^  checkBox_scan_user;
private: System::Windows::Forms::Label^  label59;
private: System::Windows::Forms::ComboBox^  comboBox_ScanSerial_user;



private: System::Windows::Forms::TextBox^  textBox_sweepRange_user;


private: System::Windows::Forms::Label^  label69;


private: System::Windows::Forms::Label^  label71;





private: System::Windows::Forms::Label^  label74;

private: System::Windows::Forms::TextBox^  textBox_LFH_user;

private: System::Windows::Forms::TextBox^  textBox_LFL_user;
private: System::Windows::Forms::GroupBox^  groupBox7;
private: System::Windows::Forms::Label^  label66;
private: System::Windows::Forms::GroupBox^  groupBox9;
private: System::Windows::Forms::ComboBox^  comboBox_power_user;

private: System::Windows::Forms::GroupBox^  groupBox8;
private: System::Windows::Forms::GroupBox^  groupBox_scan_status;

private: System::Windows::Forms::Button^  button1;
private: System::Windows::Forms::RichTextBox^  richTextBox2;
private: System::ComponentModel::BackgroundWorker^  backgroundWorker5;
private: System::Windows::Forms::GroupBox^  groupBox6;
private: System::Windows::Forms::TextBox^  textBox_fuser;


private: System::Windows::Forms::Label^  label64;
private: System::Windows::Forms::Label^  label_scanrange;











































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
			this->button_CloseComport = (gcnew System::Windows::Forms::Button());
			this->comboBox_Comport = (gcnew System::Windows::Forms::ComboBox());
			this->button_Exit = (gcnew System::Windows::Forms::Button());
			this->button_init_Comport = (gcnew System::Windows::Forms::Button());
			this->label_Comport = (gcnew System::Windows::Forms::Label());
			this->groupBox_ScanMode = (gcnew System::Windows::Forms::GroupBox());
			this->label54 = (gcnew System::Windows::Forms::Label());
			this->scan0926 = (gcnew System::Windows::Forms::Button());
			this->textBox_Freq = (gcnew System::Windows::Forms::TextBox());
			this->textBox_E7 = (gcnew System::Windows::Forms::TextBox());
			this->button_Final = (gcnew System::Windows::Forms::Button());
			this->checkBox_Manual = (gcnew System::Windows::Forms::CheckBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->comboBox_Serial = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox_Range = (gcnew System::Windows::Forms::TextBox());
			this->textBox_F2 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox_Power = (gcnew System::Windows::Forms::TextBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->textBox_F1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_F3 = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button_Get = (gcnew System::Windows::Forms::Button());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->textBox_F0 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_LFH = (gcnew System::Windows::Forms::TextBox());
			this->textBox_LFL = (gcnew System::Windows::Forms::TextBox());
			this->button_Clear = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button_CMD_RD = (gcnew System::Windows::Forms::Button());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->textBox_CMD_Pa1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button_CMD_WR = (gcnew System::Windows::Forms::Button());
			this->textBox_Command1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_wave = (gcnew System::Windows::Forms::TextBox());
			this->button_SetWave = (gcnew System::Windows::Forms::Button());
			this->button_enable = (gcnew System::Windows::Forms::Button());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->imageList1 = (gcnew System::Windows::Forms::ImageList(this->components));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->textBox_pw_level = (gcnew System::Windows::Forms::TextBox());
			this->button_pw_set = (gcnew System::Windows::Forms::Button());
			this->groupBox_Setting = (gcnew System::Windows::Forms::GroupBox());
			this->button_savedef = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->button_setch = (gcnew System::Windows::Forms::Button());
			this->textBox_chvar = (gcnew System::Windows::Forms::TextBox());
			this->comboBox_ch = (gcnew System::Windows::Forms::ComboBox());
			this->label50 = (gcnew System::Windows::Forms::Label());
			this->button_SetWaveNm = (gcnew System::Windows::Forms::Button());
			this->label49 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label48 = (gcnew System::Windows::Forms::Label());
			this->textBox_wave_nm = (gcnew System::Windows::Forms::TextBox());
			this->label47 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->colorDialog2 = (gcnew System::Windows::Forms::ColorDialog());
			this->textBox_Freq_user = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox_deviceInfo = (gcnew System::Windows::Forms::GroupBox());
			this->textBox_conn = (gcnew System::Windows::Forms::TextBox());
			this->label46 = (gcnew System::Windows::Forms::Label());
			this->label45 = (gcnew System::Windows::Forms::Label());
			this->textBox_highft = (gcnew System::Windows::Forms::TextBox());
			this->label42 = (gcnew System::Windows::Forms::Label());
			this->label43 = (gcnew System::Windows::Forms::Label());
			this->label44 = (gcnew System::Windows::Forms::Label());
			this->textBox_lowft = (gcnew System::Windows::Forms::TextBox());
			this->textBox_baud = (gcnew System::Windows::Forms::TextBox());
			this->label41 = (gcnew System::Windows::Forms::Label());
			this->textBox_highw = (gcnew System::Windows::Forms::TextBox());
			this->label40 = (gcnew System::Windows::Forms::Label());
			this->label39 = (gcnew System::Windows::Forms::Label());
			this->textBox_loww = (gcnew System::Windows::Forms::TextBox());
			this->label38 = (gcnew System::Windows::Forms::Label());
			this->textBox_highf = (gcnew System::Windows::Forms::TextBox());
			this->label36 = (gcnew System::Windows::Forms::Label());
			this->label37 = (gcnew System::Windows::Forms::Label());
			this->textBox_lowf = (gcnew System::Windows::Forms::TextBox());
			this->label35 = (gcnew System::Windows::Forms::Label());
			this->textBox_highp = (gcnew System::Windows::Forms::TextBox());
			this->label34 = (gcnew System::Windows::Forms::Label());
			this->label33 = (gcnew System::Windows::Forms::Label());
			this->textBox_lowp = (gcnew System::Windows::Forms::TextBox());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox_option = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->button_ditherSet = (gcnew System::Windows::Forms::Button());
			this->button_ditherEn = (gcnew System::Windows::Forms::Button());
			this->label65 = (gcnew System::Windows::Forms::Label());
			this->textBox_dither = (gcnew System::Windows::Forms::TextBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->button_lnm = (gcnew System::Windows::Forms::Button());
			this->groupBox_ds = (gcnew System::Windows::Forms::GroupBox());
			this->button_sd = (gcnew System::Windows::Forms::Button());
			this->button_rt = (gcnew System::Windows::Forms::Button());
			this->button_su = (gcnew System::Windows::Forms::Button());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->label_status = (gcnew System::Windows::Forms::Label());
			this->label63 = (gcnew System::Windows::Forms::Label());
			this->label60 = (gcnew System::Windows::Forms::Label());
			this->label61 = (gcnew System::Windows::Forms::Label());
			this->label62 = (gcnew System::Windows::Forms::Label());
			this->textBox_ct = (gcnew System::Windows::Forms::TextBox());
			this->textBox_cw = (gcnew System::Windows::Forms::TextBox());
			this->textBox_cf = (gcnew System::Windows::Forms::TextBox());
			this->textBox_cpw = (gcnew System::Windows::Forms::TextBox());
			this->label58 = (gcnew System::Windows::Forms::Label());
			this->label57 = (gcnew System::Windows::Forms::Label());
			this->label56 = (gcnew System::Windows::Forms::Label());
			this->label55 = (gcnew System::Windows::Forms::Label());
			this->label53 = (gcnew System::Windows::Forms::Label());
			this->label52 = (gcnew System::Windows::Forms::Label());
			this->label51 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox_scan_status = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox_fuser = (gcnew System::Windows::Forms::TextBox());
			this->label64 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->groupBox_scan_user = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox9 = (gcnew System::Windows::Forms::GroupBox());
			this->comboBox_power_user = (gcnew System::Windows::Forms::ComboBox());
			this->groupBox8 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox_sweepRange_user = (gcnew System::Windows::Forms::TextBox());
			this->label69 = (gcnew System::Windows::Forms::Label());
			this->groupBox7 = (gcnew System::Windows::Forms::GroupBox());
			this->label_scanrange = (gcnew System::Windows::Forms::Label());
			this->label66 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->checkBox_scan_user = (gcnew System::Windows::Forms::CheckBox());
			this->label74 = (gcnew System::Windows::Forms::Label());
			this->label71 = (gcnew System::Windows::Forms::Label());
			this->textBox_LFL_user = (gcnew System::Windows::Forms::TextBox());
			this->textBox_LFH_user = (gcnew System::Windows::Forms::TextBox());
			this->button_scan_user = (gcnew System::Windows::Forms::Button());
			this->button_stop_user = (gcnew System::Windows::Forms::Button());
			this->label59 = (gcnew System::Windows::Forms::Label());
			this->comboBox_ScanSerial_user = (gcnew System::Windows::Forms::ComboBox());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox_Command = (gcnew System::Windows::Forms::GroupBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->backgroundWorker2 = (gcnew System::ComponentModel::BackgroundWorker());
			this->backgroundWorker3 = (gcnew System::ComponentModel::BackgroundWorker());
			this->backgroundWorker4 = (gcnew System::ComponentModel::BackgroundWorker());
			this->backgroundWorker5 = (gcnew System::ComponentModel::BackgroundWorker());
			this->groupBox_ComPort->SuspendLayout();
			this->groupBox_ScanMode->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->groupBox_Setting->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->textBox_Freq_user->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->groupBox_deviceInfo->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->groupBox_option->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox_ds->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->tabPage3->SuspendLayout();
			this->groupBox_scan_status->SuspendLayout();
			this->groupBox6->SuspendLayout();
			this->groupBox_scan_user->SuspendLayout();
			this->groupBox9->SuspendLayout();
			this->groupBox8->SuspendLayout();
			this->groupBox7->SuspendLayout();
			this->tabPage4->SuspendLayout();
			this->groupBox_Command->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox_ComPort
			// 
			this->groupBox_ComPort->Controls->Add(this->button_CloseComport);
			this->groupBox_ComPort->Controls->Add(this->comboBox_Comport);
			this->groupBox_ComPort->Controls->Add(this->button_Exit);
			this->groupBox_ComPort->Controls->Add(this->button_init_Comport);
			this->groupBox_ComPort->Controls->Add(this->label_Comport);
			this->groupBox_ComPort->Location = System::Drawing::Point(78, 13);
			this->groupBox_ComPort->Name = L"groupBox_ComPort";
			this->groupBox_ComPort->Size = System::Drawing::Size(106, 243);
			this->groupBox_ComPort->TabIndex = 10;
			this->groupBox_ComPort->TabStop = false;
			this->groupBox_ComPort->Text = L"Connect";
			// 
			// button_CloseComport
			// 
			this->button_CloseComport->Location = System::Drawing::Point(20, 142);
			this->button_CloseComport->Name = L"button_CloseComport";
			this->button_CloseComport->Size = System::Drawing::Size(60, 25);
			this->button_CloseComport->TabIndex = 17;
			this->button_CloseComport->Text = L"Close";
			this->button_CloseComport->UseVisualStyleBackColor = true;
			this->button_CloseComport->Click += gcnew System::EventHandler(this, &MyForm::button_CloseComport_Click);
			// 
			// comboBox_Comport
			// 
			this->comboBox_Comport->FormattingEnabled = true;
			this->comboBox_Comport->Location = System::Drawing::Point(14, 60);
			this->comboBox_Comport->Name = L"comboBox_Comport";
			this->comboBox_Comport->Size = System::Drawing::Size(75, 21);
			this->comboBox_Comport->TabIndex = 16;
			this->comboBox_Comport->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox_Comport_SelectedIndexChanged);
			// 
			// button_Exit
			// 
			this->button_Exit->Location = System::Drawing::Point(20, 185);
			this->button_Exit->Name = L"button_Exit";
			this->button_Exit->Size = System::Drawing::Size(60, 25);
			this->button_Exit->TabIndex = 15;
			this->button_Exit->Text = L"Exit";
			this->button_Exit->UseVisualStyleBackColor = true;
			this->button_Exit->Click += gcnew System::EventHandler(this, &MyForm::button_Exit_Click);
			// 
			// button_init_Comport
			// 
			this->button_init_Comport->Location = System::Drawing::Point(20, 99);
			this->button_init_Comport->Name = L"button_init_Comport";
			this->button_init_Comport->Size = System::Drawing::Size(60, 25);
			this->button_init_Comport->TabIndex = 12;
			this->button_init_Comport->Text = L"Connect";
			this->button_init_Comport->UseVisualStyleBackColor = true;
			this->button_init_Comport->Click += gcnew System::EventHandler(this, &MyForm::button_init_Comport_Click);
			// 
			// label_Comport
			// 
			this->label_Comport->AutoSize = true;
			this->label_Comport->Location = System::Drawing::Point(25, 29);
			this->label_Comport->Name = L"label_Comport";
			this->label_Comport->Size = System::Drawing::Size(53, 13);
			this->label_Comport->TabIndex = 11;
			this->label_Comport->Text = L"COM Port";
			this->label_Comport->Click += gcnew System::EventHandler(this, &MyForm::label_Comport_Click);
			// 
			// groupBox_ScanMode
			// 
			this->groupBox_ScanMode->Controls->Add(this->label54);
			this->groupBox_ScanMode->Controls->Add(this->scan0926);
			this->groupBox_ScanMode->Controls->Add(this->textBox_Freq);
			this->groupBox_ScanMode->Controls->Add(this->textBox_E7);
			this->groupBox_ScanMode->Controls->Add(this->button_Final);
			this->groupBox_ScanMode->Controls->Add(this->checkBox_Manual);
			this->groupBox_ScanMode->Controls->Add(this->label12);
			this->groupBox_ScanMode->Controls->Add(this->comboBox_Serial);
			this->groupBox_ScanMode->Controls->Add(this->label3);
			this->groupBox_ScanMode->Controls->Add(this->label7);
			this->groupBox_ScanMode->Controls->Add(this->label6);
			this->groupBox_ScanMode->Controls->Add(this->textBox_Range);
			this->groupBox_ScanMode->Controls->Add(this->textBox_F2);
			this->groupBox_ScanMode->Controls->Add(this->label8);
			this->groupBox_ScanMode->Controls->Add(this->label14);
			this->groupBox_ScanMode->Controls->Add(this->label5);
			this->groupBox_ScanMode->Controls->Add(this->textBox_Power);
			this->groupBox_ScanMode->Controls->Add(this->label13);
			this->groupBox_ScanMode->Controls->Add(this->textBox_F1);
			this->groupBox_ScanMode->Controls->Add(this->textBox_F3);
			this->groupBox_ScanMode->Controls->Add(this->label10);
			this->groupBox_ScanMode->Controls->Add(this->label4);
			this->groupBox_ScanMode->Controls->Add(this->button_Get);
			this->groupBox_ScanMode->Controls->Add(this->label11);
			this->groupBox_ScanMode->Controls->Add(this->textBox_F0);
			this->groupBox_ScanMode->Controls->Add(this->textBox_LFH);
			this->groupBox_ScanMode->Controls->Add(this->textBox_LFL);
			this->groupBox_ScanMode->Location = System::Drawing::Point(411, 8);
			this->groupBox_ScanMode->Name = L"groupBox_ScanMode";
			this->groupBox_ScanMode->Size = System::Drawing::Size(437, 253);
			this->groupBox_ScanMode->TabIndex = 13;
			this->groupBox_ScanMode->TabStop = false;
			this->groupBox_ScanMode->Text = L"Scan Mode";
			// 
			// label54
			// 
			this->label54->AutoSize = true;
			this->label54->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label54->Location = System::Drawing::Point(9, 139);
			this->label54->Name = L"label54";
			this->label54->Size = System::Drawing::Size(77, 13);
			this->label54->TabIndex = 51;
			this->label54->Text = L"Scan Range";
			// 
			// scan0926
			// 
			this->scan0926->Location = System::Drawing::Point(16, 216);
			this->scan0926->Name = L"scan0926";
			this->scan0926->Size = System::Drawing::Size(70, 25);
			this->scan0926->TabIndex = 50;
			this->scan0926->Text = L"Scan";
			this->scan0926->UseVisualStyleBackColor = true;
			this->scan0926->Click += gcnew System::EventHandler(this, &MyForm::scan0926_Click);
			// 
			// textBox_Freq
			// 
			this->textBox_Freq->Location = System::Drawing::Point(119, 113);
			this->textBox_Freq->Name = L"textBox_Freq";
			this->textBox_Freq->Size = System::Drawing::Size(63, 20);
			this->textBox_Freq->TabIndex = 15;
			this->textBox_Freq->Text = L"191.65";
			// 
			// textBox_E7
			// 
			this->textBox_E7->Location = System::Drawing::Point(361, 101);
			this->textBox_E7->Name = L"textBox_E7";
			this->textBox_E7->ReadOnly = true;
			this->textBox_E7->Size = System::Drawing::Size(60, 20);
			this->textBox_E7->TabIndex = 25;
			// 
			// button_Final
			// 
			this->button_Final->Location = System::Drawing::Point(112, 216);
			this->button_Final->Name = L"button_Final";
			this->button_Final->Size = System::Drawing::Size(70, 25);
			this->button_Final->TabIndex = 17;
			this->button_Final->Text = L"Stop";
			this->button_Final->UseVisualStyleBackColor = true;
			this->button_Final->Click += gcnew System::EventHandler(this, &MyForm::button_Final_Click);
			// 
			// checkBox_Manual
			// 
			this->checkBox_Manual->AutoSize = true;
			this->checkBox_Manual->Location = System::Drawing::Point(119, 139);
			this->checkBox_Manual->Name = L"checkBox_Manual";
			this->checkBox_Manual->Size = System::Drawing::Size(61, 17);
			this->checkBox_Manual->TabIndex = 47;
			this->checkBox_Manual->Text = L"Manual";
			this->checkBox_Manual->UseVisualStyleBackColor = true;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(6, 30);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(73, 13);
			this->label12->TabIndex = 43;
			this->label12->Text = L"Serial Number";
			// 
			// comboBox_Serial
			// 
			this->comboBox_Serial->FormattingEnabled = true;
			this->comboBox_Serial->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"CRTNJ5W06P", L"CRTNJ5W06P" });
			this->comboBox_Serial->Location = System::Drawing::Point(119, 27);
			this->comboBox_Serial->Name = L"comboBox_Serial";
			this->comboBox_Serial->Size = System::Drawing::Size(103, 21);
			this->comboBox_Serial->TabIndex = 39;
			this->comboBox_Serial->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox_Serial_SelectedIndexChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(6, 115);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(91, 13);
			this->label3->TabIndex = 18;
			this->label3->Text = L"Target Frequency";
			this->label3->Click += gcnew System::EventHandler(this, &MyForm::label3_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(226, 104);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(136, 13);
			this->label7->TabIndex = 26;
			this->label7->Text = L"Current Adjust Value (0xE7)";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(226, 78);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(130, 13);
			this->label6->TabIndex = 24;
			this->label6->Text = L"Filter2 Temperature (0xF2)";
			// 
			// textBox_Range
			// 
			this->textBox_Range->Location = System::Drawing::Point(119, 57);
			this->textBox_Range->Name = L"textBox_Range";
			this->textBox_Range->Size = System::Drawing::Size(63, 20);
			this->textBox_Range->TabIndex = 46;
			this->textBox_Range->Text = L"100";
			// 
			// textBox_F2
			// 
			this->textBox_F2->Location = System::Drawing::Point(361, 75);
			this->textBox_F2->Name = L"textBox_F2";
			this->textBox_F2->ReadOnly = true;
			this->textBox_F2->Size = System::Drawing::Size(60, 20);
			this->textBox_F2->TabIndex = 23;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(226, 130);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(109, 13);
			this->label8->TabIndex = 28;
			this->label8->Text = L"Central Current (0xF3)";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(6, 60);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(105, 13);
			this->label14->TabIndex = 45;
			this->label14->Text = L"Sweep Range (GHz)";
			this->label14->Click += gcnew System::EventHandler(this, &MyForm::label14_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(226, 52);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(130, 13);
			this->label5->TabIndex = 22;
			this->label5->Text = L"Filter1 Temperature (0xF1)";
			// 
			// textBox_Power
			// 
			this->textBox_Power->Location = System::Drawing::Point(119, 85);
			this->textBox_Power->Name = L"textBox_Power";
			this->textBox_Power->Size = System::Drawing::Size(63, 20);
			this->textBox_Power->TabIndex = 31;
			this->textBox_Power->Text = L"10";
			this->textBox_Power->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox_Power_TextChanged);
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(6, 191);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(53, 13);
			this->label13->TabIndex = 44;
			this->label13->Text = L"Stop Freq";
			// 
			// textBox_F1
			// 
			this->textBox_F1->Location = System::Drawing::Point(361, 49);
			this->textBox_F1->Name = L"textBox_F1";
			this->textBox_F1->ReadOnly = true;
			this->textBox_F1->Size = System::Drawing::Size(60, 20);
			this->textBox_F1->TabIndex = 21;
			// 
			// textBox_F3
			// 
			this->textBox_F3->Location = System::Drawing::Point(361, 127);
			this->textBox_F3->Name = L"textBox_F3";
			this->textBox_F3->ReadOnly = true;
			this->textBox_F3->Size = System::Drawing::Size(60, 20);
			this->textBox_F3->TabIndex = 27;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(6, 88);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(71, 13);
			this->label10->TabIndex = 32;
			this->label10->Text = L"Target Power";
			this->label10->Click += gcnew System::EventHandler(this, &MyForm::label10_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(226, 26);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(123, 13);
			this->label4->TabIndex = 20;
			this->label4->Text = L"Sled Temperature (0xF0)";
			this->label4->Click += gcnew System::EventHandler(this, &MyForm::label4_Click);
			// 
			// button_Get
			// 
			this->button_Get->Location = System::Drawing::Point(361, 154);
			this->button_Get->Name = L"button_Get";
			this->button_Get->Size = System::Drawing::Size(60, 25);
			this->button_Get->TabIndex = 33;
			this->button_Get->Text = L"Get Regs";
			this->button_Get->UseVisualStyleBackColor = true;
			this->button_Get->Click += gcnew System::EventHandler(this, &MyForm::button_Get_Click);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(6, 165);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(53, 13);
			this->label11->TabIndex = 42;
			this->label11->Text = L"Start Freq";
			// 
			// textBox_F0
			// 
			this->textBox_F0->Location = System::Drawing::Point(361, 23);
			this->textBox_F0->Name = L"textBox_F0";
			this->textBox_F0->ReadOnly = true;
			this->textBox_F0->Size = System::Drawing::Size(60, 20);
			this->textBox_F0->TabIndex = 19;
			// 
			// textBox_LFH
			// 
			this->textBox_LFH->Location = System::Drawing::Point(119, 188);
			this->textBox_LFH->Name = L"textBox_LFH";
			this->textBox_LFH->Size = System::Drawing::Size(63, 20);
			this->textBox_LFH->TabIndex = 41;
			this->textBox_LFH->Text = L"0";
			// 
			// textBox_LFL
			// 
			this->textBox_LFL->Location = System::Drawing::Point(119, 162);
			this->textBox_LFL->Name = L"textBox_LFL";
			this->textBox_LFL->Size = System::Drawing::Size(63, 20);
			this->textBox_LFL->TabIndex = 40;
			this->textBox_LFL->Text = L"0";
			// 
			// button_Clear
			// 
			this->button_Clear->Location = System::Drawing::Point(299, 185);
			this->button_Clear->Name = L"button_Clear";
			this->button_Clear->Size = System::Drawing::Size(55, 24);
			this->button_Clear->TabIndex = 18;
			this->button_Clear->Text = L"Clear";
			this->button_Clear->UseVisualStyleBackColor = true;
			this->button_Clear->Click += gcnew System::EventHandler(this, &MyForm::button_Clear_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(288, 61);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(74, 13);
			this->label2->TabIndex = 17;
			this->label2->Text = L"PARAMETER";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// button_CMD_RD
			// 
			this->button_CMD_RD->Location = System::Drawing::Point(299, 143);
			this->button_CMD_RD->Name = L"button_CMD_RD";
			this->button_CMD_RD->Size = System::Drawing::Size(55, 25);
			this->button_CMD_RD->TabIndex = 16;
			this->button_CMD_RD->Text = L"Read";
			this->button_CMD_RD->UseVisualStyleBackColor = true;
			this->button_CMD_RD->Click += gcnew System::EventHandler(this, &MyForm::button_CMD_RD_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->BackColor = System::Drawing::SystemColors::Control;
			this->richTextBox1->Location = System::Drawing::Point(6, 19);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ReadOnly = true;
			this->richTextBox1->Size = System::Drawing::Size(270, 230);
			this->richTextBox1->TabIndex = 15;
			this->richTextBox1->Text = L"";
			this->richTextBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::richTextBox1_TextChanged);
			// 
			// textBox_CMD_Pa1
			// 
			this->textBox_CMD_Pa1->Location = System::Drawing::Point(282, 77);
			this->textBox_CMD_Pa1->Name = L"textBox_CMD_Pa1";
			this->textBox_CMD_Pa1->Size = System::Drawing::Size(87, 20);
			this->textBox_CMD_Pa1->TabIndex = 14;
			this->textBox_CMD_Pa1->Text = L"00";
			this->textBox_CMD_Pa1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox_CMD_Pa1_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(282, 19);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(91, 13);
			this->label1->TabIndex = 13;
			this->label1->Text = L"REGISTOR(HEX)";
			// 
			// button_CMD_WR
			// 
			this->button_CMD_WR->Location = System::Drawing::Point(299, 103);
			this->button_CMD_WR->Name = L"button_CMD_WR";
			this->button_CMD_WR->Size = System::Drawing::Size(55, 25);
			this->button_CMD_WR->TabIndex = 12;
			this->button_CMD_WR->Text = L"Write";
			this->button_CMD_WR->UseVisualStyleBackColor = true;
			this->button_CMD_WR->Click += gcnew System::EventHandler(this, &MyForm::button_CMD_WR_Click);
			// 
			// textBox_Command1
			// 
			this->textBox_Command1->Location = System::Drawing::Point(283, 35);
			this->textBox_Command1->Name = L"textBox_Command1";
			this->textBox_Command1->Size = System::Drawing::Size(87, 20);
			this->textBox_Command1->TabIndex = 11;
			this->textBox_Command1->Text = L"00";
			this->textBox_Command1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox_Command1_TextChanged);
			// 
			// textBox_wave
			// 
			this->textBox_wave->Location = System::Drawing::Point(87, 21);
			this->textBox_wave->Name = L"textBox_wave";
			this->textBox_wave->Size = System::Drawing::Size(77, 20);
			this->textBox_wave->TabIndex = 21;
			this->textBox_wave->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox_wave_TextChanged);
			// 
			// button_SetWave
			// 
			this->button_SetWave->Location = System::Drawing::Point(204, 18);
			this->button_SetWave->Name = L"button_SetWave";
			this->button_SetWave->Size = System::Drawing::Size(48, 24);
			this->button_SetWave->TabIndex = 20;
			this->button_SetWave->Text = L"Set";
			this->button_SetWave->UseVisualStyleBackColor = true;
			this->button_SetWave->Click += gcnew System::EventHandler(this, &MyForm::button_SetWave_Click);
			// 
			// button_enable
			// 
			this->button_enable->Location = System::Drawing::Point(15, 209);
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
			this->label15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 33.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label15->Location = System::Drawing::Point(304, 45);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(560, 52);
			this->label15->TabIndex = 20;
			this->label15->Text = L"Tunable Wavelength Laser";
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
			this->pictureBox1->Location = System::Drawing::Point(16, 23);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(282, 97);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 21;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MyForm::pictureBox1_Click);
			// 
			// textBox_pw_level
			// 
			this->textBox_pw_level->Location = System::Drawing::Point(56, 18);
			this->textBox_pw_level->Name = L"textBox_pw_level";
			this->textBox_pw_level->Size = System::Drawing::Size(52, 20);
			this->textBox_pw_level->TabIndex = 23;
			this->textBox_pw_level->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox_pw_level_TextChanged);
			// 
			// button_pw_set
			// 
			this->button_pw_set->Location = System::Drawing::Point(154, 15);
			this->button_pw_set->Name = L"button_pw_set";
			this->button_pw_set->Size = System::Drawing::Size(52, 23);
			this->button_pw_set->TabIndex = 24;
			this->button_pw_set->Text = L"Set";
			this->button_pw_set->UseVisualStyleBackColor = true;
			this->button_pw_set->Click += gcnew System::EventHandler(this, &MyForm::button_pw_set_Click);
			// 
			// groupBox_Setting
			// 
			this->groupBox_Setting->Controls->Add(this->button_savedef);
			this->groupBox_Setting->Controls->Add(this->groupBox2);
			this->groupBox_Setting->Controls->Add(this->button_enable);
			this->groupBox_Setting->Controls->Add(this->groupBox1);
			this->groupBox_Setting->Location = System::Drawing::Point(10, 9);
			this->groupBox_Setting->Name = L"groupBox_Setting";
			this->groupBox_Setting->Size = System::Drawing::Size(296, 250);
			this->groupBox_Setting->TabIndex = 26;
			this->groupBox_Setting->TabStop = false;
			this->groupBox_Setting->Text = L"Setting";
			// 
			// button_savedef
			// 
			this->button_savedef->Location = System::Drawing::Point(181, 209);
			this->button_savedef->Name = L"button_savedef";
			this->button_savedef->Size = System::Drawing::Size(96, 24);
			this->button_savedef->TabIndex = 34;
			this->button_savedef->Text = L"Save as Default";
			this->button_savedef->UseVisualStyleBackColor = true;
			this->button_savedef->Click += gcnew System::EventHandler(this, &MyForm::button_savedef_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->button_setch);
			this->groupBox2->Controls->Add(this->textBox_chvar);
			this->groupBox2->Controls->Add(this->comboBox_ch);
			this->groupBox2->Controls->Add(this->label50);
			this->groupBox2->Controls->Add(this->button_SetWaveNm);
			this->groupBox2->Controls->Add(this->label49);
			this->groupBox2->Controls->Add(this->label21);
			this->groupBox2->Controls->Add(this->label48);
			this->groupBox2->Controls->Add(this->textBox_wave_nm);
			this->groupBox2->Controls->Add(this->textBox_wave);
			this->groupBox2->Controls->Add(this->button_SetWave);
			this->groupBox2->Controls->Add(this->label47);
			this->groupBox2->Controls->Add(this->label19);
			this->groupBox2->Controls->Add(this->label17);
			this->groupBox2->Controls->Add(this->label18);
			this->groupBox2->Location = System::Drawing::Point(15, 74);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(262, 118);
			this->groupBox2->TabIndex = 33;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Wavelength";
			// 
			// button_setch
			// 
			this->button_setch->Location = System::Drawing::Point(204, 88);
			this->button_setch->Name = L"button_setch";
			this->button_setch->Size = System::Drawing::Size(48, 24);
			this->button_setch->TabIndex = 42;
			this->button_setch->Text = L"Set";
			this->button_setch->UseVisualStyleBackColor = true;
			this->button_setch->Click += gcnew System::EventHandler(this, &MyForm::button_setch_Click);
			// 
			// textBox_chvar
			// 
			this->textBox_chvar->Location = System::Drawing::Point(154, 90);
			this->textBox_chvar->Name = L"textBox_chvar";
			this->textBox_chvar->Size = System::Drawing::Size(41, 20);
			this->textBox_chvar->TabIndex = 41;
			this->textBox_chvar->Text = L"0";
			// 
			// comboBox_ch
			// 
			this->comboBox_ch->FormattingEnabled = true;
			this->comboBox_ch->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"50G", L"100G" });
			this->comboBox_ch->Location = System::Drawing::Point(87, 90);
			this->comboBox_ch->Name = L"comboBox_ch";
			this->comboBox_ch->Size = System::Drawing::Size(58, 21);
			this->comboBox_ch->TabIndex = 40;
			this->comboBox_ch->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedIndexChanged);
			// 
			// label50
			// 
			this->label50->AutoSize = true;
			this->label50->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label50->Location = System::Drawing::Point(70, 93);
			this->label50->Name = L"label50";
			this->label50->Size = System::Drawing::Size(11, 13);
			this->label50->TabIndex = 39;
			this->label50->Text = L":";
			// 
			// button_SetWaveNm
			// 
			this->button_SetWaveNm->Location = System::Drawing::Point(204, 55);
			this->button_SetWaveNm->Name = L"button_SetWaveNm";
			this->button_SetWaveNm->Size = System::Drawing::Size(48, 24);
			this->button_SetWaveNm->TabIndex = 30;
			this->button_SetWaveNm->Text = L"Set";
			this->button_SetWaveNm->UseVisualStyleBackColor = true;
			this->button_SetWaveNm->Click += gcnew System::EventHandler(this, &MyForm::button_SetWaveNm_Click);
			// 
			// label49
			// 
			this->label49->AutoSize = true;
			this->label49->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label49->Location = System::Drawing::Point(70, 61);
			this->label49->Name = L"label49";
			this->label49->Size = System::Drawing::Size(11, 13);
			this->label49->TabIndex = 38;
			this->label49->Text = L":";
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label21->Location = System::Drawing::Point(174, 59);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(25, 15);
			this->label21->TabIndex = 29;
			this->label21->Text = L"nm";
			this->label21->Click += gcnew System::EventHandler(this, &MyForm::label21_Click);
			// 
			// label48
			// 
			this->label48->AutoSize = true;
			this->label48->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label48->Location = System::Drawing::Point(70, 24);
			this->label48->Name = L"label48";
			this->label48->Size = System::Drawing::Size(11, 13);
			this->label48->TabIndex = 37;
			this->label48->Text = L":";
			// 
			// textBox_wave_nm
			// 
			this->textBox_wave_nm->Location = System::Drawing::Point(87, 58);
			this->textBox_wave_nm->Name = L"textBox_wave_nm";
			this->textBox_wave_nm->Size = System::Drawing::Size(77, 20);
			this->textBox_wave_nm->TabIndex = 28;
			this->textBox_wave_nm->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox_wave_nm_TextChanged);
			// 
			// label47
			// 
			this->label47->AutoSize = true;
			this->label47->Location = System::Drawing::Point(6, 93);
			this->label47->Name = L"label47";
			this->label47->Size = System::Drawing::Size(46, 13);
			this->label47->TabIndex = 36;
			this->label47->Text = L"Channel";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(6, 61);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(65, 13);
			this->label19->TabIndex = 35;
			this->label19->Text = L"Wavelength";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(6, 24);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(57, 13);
			this->label17->TabIndex = 34;
			this->label17->Text = L"Frequency";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label18->Location = System::Drawing::Point(169, 24);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(29, 15);
			this->label18->TabIndex = 26;
			this->label18->Text = L"THz";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->textBox_pw_level);
			this->groupBox1->Controls->Add(this->label22);
			this->groupBox1->Controls->Add(this->button_pw_set);
			this->groupBox1->Location = System::Drawing::Point(15, 17);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(262, 49);
			this->groupBox1->TabIndex = 32;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Power";
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(117, 21);
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
			this->textBox_Freq_user->Controls->Add(this->tabPage3);
			this->textBox_Freq_user->Controls->Add(this->tabPage4);
			this->textBox_Freq_user->Location = System::Drawing::Point(12, 143);
			this->textBox_Freq_user->Name = L"textBox_Freq_user";
			this->textBox_Freq_user->SelectedIndex = 0;
			this->textBox_Freq_user->Size = System::Drawing::Size(870, 298);
			this->textBox_Freq_user->TabIndex = 28;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->groupBox_deviceInfo);
			this->tabPage1->Controls->Add(this->groupBox_ComPort);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(862, 272);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"General";
			this->tabPage1->UseVisualStyleBackColor = true;
			this->tabPage1->Click += gcnew System::EventHandler(this, &MyForm::tabPage1_Click);
			// 
			// groupBox_deviceInfo
			// 
			this->groupBox_deviceInfo->Controls->Add(this->textBox_conn);
			this->groupBox_deviceInfo->Controls->Add(this->label46);
			this->groupBox_deviceInfo->Controls->Add(this->label45);
			this->groupBox_deviceInfo->Controls->Add(this->textBox_highft);
			this->groupBox_deviceInfo->Controls->Add(this->label42);
			this->groupBox_deviceInfo->Controls->Add(this->label43);
			this->groupBox_deviceInfo->Controls->Add(this->label44);
			this->groupBox_deviceInfo->Controls->Add(this->textBox_lowft);
			this->groupBox_deviceInfo->Controls->Add(this->textBox_baud);
			this->groupBox_deviceInfo->Controls->Add(this->label41);
			this->groupBox_deviceInfo->Controls->Add(this->textBox_highw);
			this->groupBox_deviceInfo->Controls->Add(this->label40);
			this->groupBox_deviceInfo->Controls->Add(this->label39);
			this->groupBox_deviceInfo->Controls->Add(this->textBox_loww);
			this->groupBox_deviceInfo->Controls->Add(this->label38);
			this->groupBox_deviceInfo->Controls->Add(this->textBox_highf);
			this->groupBox_deviceInfo->Controls->Add(this->label36);
			this->groupBox_deviceInfo->Controls->Add(this->label37);
			this->groupBox_deviceInfo->Controls->Add(this->textBox_lowf);
			this->groupBox_deviceInfo->Controls->Add(this->label35);
			this->groupBox_deviceInfo->Controls->Add(this->textBox_highp);
			this->groupBox_deviceInfo->Controls->Add(this->label34);
			this->groupBox_deviceInfo->Controls->Add(this->label33);
			this->groupBox_deviceInfo->Controls->Add(this->textBox_lowp);
			this->groupBox_deviceInfo->Controls->Add(this->label32);
			this->groupBox_deviceInfo->Controls->Add(this->label31);
			this->groupBox_deviceInfo->Controls->Add(this->label30);
			this->groupBox_deviceInfo->Controls->Add(this->label29);
			this->groupBox_deviceInfo->Controls->Add(this->label28);
			this->groupBox_deviceInfo->Controls->Add(this->label27);
			this->groupBox_deviceInfo->Controls->Add(this->label26);
			this->groupBox_deviceInfo->Controls->Add(this->label25);
			this->groupBox_deviceInfo->Controls->Add(this->label24);
			this->groupBox_deviceInfo->Controls->Add(this->label23);
			this->groupBox_deviceInfo->Location = System::Drawing::Point(243, 13);
			this->groupBox_deviceInfo->Name = L"groupBox_deviceInfo";
			this->groupBox_deviceInfo->Size = System::Drawing::Size(544, 243);
			this->groupBox_deviceInfo->TabIndex = 11;
			this->groupBox_deviceInfo->TabStop = false;
			this->groupBox_deviceInfo->Text = L"Device Information";
			// 
			// textBox_conn
			// 
			this->textBox_conn->BackColor = System::Drawing::SystemColors::Control;
			this->textBox_conn->Location = System::Drawing::Point(253, 24);
			this->textBox_conn->Name = L"textBox_conn";
			this->textBox_conn->ReadOnly = true;
			this->textBox_conn->Size = System::Drawing::Size(273, 20);
			this->textBox_conn->TabIndex = 46;
			// 
			// label46
			// 
			this->label46->AutoSize = true;
			this->label46->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label46->Location = System::Drawing::Point(225, 25);
			this->label46->Name = L"label46";
			this->label46->Size = System::Drawing::Size(12, 16);
			this->label46->TabIndex = 45;
			this->label46->Text = L":";
			// 
			// label45
			// 
			this->label45->AutoSize = true;
			this->label45->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label45->Location = System::Drawing::Point(37, 25);
			this->label45->Name = L"label45";
			this->label45->Size = System::Drawing::Size(113, 16);
			this->label45->TabIndex = 44;
			this->label45->Text = L"Serial Connection";
			this->label45->Click += gcnew System::EventHandler(this, &MyForm::label45_Click);
			// 
			// textBox_highft
			// 
			this->textBox_highft->BackColor = System::Drawing::SystemColors::Control;
			this->textBox_highft->Location = System::Drawing::Point(382, 166);
			this->textBox_highft->Name = L"textBox_highft";
			this->textBox_highft->ReadOnly = true;
			this->textBox_highft->Size = System::Drawing::Size(57, 20);
			this->textBox_highft->TabIndex = 43;
			// 
			// label42
			// 
			this->label42->AutoSize = true;
			this->label42->Location = System::Drawing::Point(445, 169);
			this->label42->Name = L"label42";
			this->label42->Size = System::Drawing::Size(29, 13);
			this->label42->TabIndex = 42;
			this->label42->Text = L"MHz";
			// 
			// label43
			// 
			this->label43->AutoSize = true;
			this->label43->Location = System::Drawing::Point(350, 169);
			this->label43->Name = L"label43";
			this->label43->Size = System::Drawing::Size(14, 13);
			this->label43->TabIndex = 40;
			this->label43->Text = L"~";
			// 
			// label44
			// 
			this->label44->AutoSize = true;
			this->label44->Location = System::Drawing::Point(316, 167);
			this->label44->Name = L"label44";
			this->label44->Size = System::Drawing::Size(29, 13);
			this->label44->TabIndex = 39;
			this->label44->Text = L"MHz";
			// 
			// textBox_lowft
			// 
			this->textBox_lowft->BackColor = System::Drawing::SystemColors::Control;
			this->textBox_lowft->Location = System::Drawing::Point(253, 164);
			this->textBox_lowft->Name = L"textBox_lowft";
			this->textBox_lowft->ReadOnly = true;
			this->textBox_lowft->Size = System::Drawing::Size(57, 20);
			this->textBox_lowft->TabIndex = 38;
			// 
			// textBox_baud
			// 
			this->textBox_baud->BackColor = System::Drawing::SystemColors::Control;
			this->textBox_baud->Location = System::Drawing::Point(253, 202);
			this->textBox_baud->Name = L"textBox_baud";
			this->textBox_baud->ReadOnly = true;
			this->textBox_baud->Size = System::Drawing::Size(57, 20);
			this->textBox_baud->TabIndex = 37;
			// 
			// label41
			// 
			this->label41->AutoSize = true;
			this->label41->Location = System::Drawing::Point(445, 133);
			this->label41->Name = L"label41";
			this->label41->Size = System::Drawing::Size(21, 13);
			this->label41->TabIndex = 36;
			this->label41->Text = L"nm";
			// 
			// textBox_highw
			// 
			this->textBox_highw->BackColor = System::Drawing::SystemColors::Control;
			this->textBox_highw->Location = System::Drawing::Point(382, 130);
			this->textBox_highw->Name = L"textBox_highw";
			this->textBox_highw->ReadOnly = true;
			this->textBox_highw->Size = System::Drawing::Size(57, 20);
			this->textBox_highw->TabIndex = 35;
			// 
			// label40
			// 
			this->label40->AutoSize = true;
			this->label40->Location = System::Drawing::Point(345, 135);
			this->label40->Name = L"label40";
			this->label40->Size = System::Drawing::Size(14, 13);
			this->label40->TabIndex = 34;
			this->label40->Text = L"~";
			// 
			// label39
			// 
			this->label39->AutoSize = true;
			this->label39->Location = System::Drawing::Point(316, 133);
			this->label39->Name = L"label39";
			this->label39->Size = System::Drawing::Size(21, 13);
			this->label39->TabIndex = 33;
			this->label39->Text = L"nm";
			// 
			// textBox_loww
			// 
			this->textBox_loww->BackColor = System::Drawing::SystemColors::Control;
			this->textBox_loww->Location = System::Drawing::Point(253, 130);
			this->textBox_loww->Name = L"textBox_loww";
			this->textBox_loww->ReadOnly = true;
			this->textBox_loww->Size = System::Drawing::Size(57, 20);
			this->textBox_loww->TabIndex = 32;
			// 
			// label38
			// 
			this->label38->AutoSize = true;
			this->label38->Location = System::Drawing::Point(445, 99);
			this->label38->Name = L"label38";
			this->label38->Size = System::Drawing::Size(27, 13);
			this->label38->TabIndex = 31;
			this->label38->Text = L"THz";
			// 
			// textBox_highf
			// 
			this->textBox_highf->BackColor = System::Drawing::SystemColors::Control;
			this->textBox_highf->Location = System::Drawing::Point(382, 96);
			this->textBox_highf->Name = L"textBox_highf";
			this->textBox_highf->ReadOnly = true;
			this->textBox_highf->Size = System::Drawing::Size(57, 20);
			this->textBox_highf->TabIndex = 30;
			// 
			// label36
			// 
			this->label36->AutoSize = true;
			this->label36->Location = System::Drawing::Point(350, 99);
			this->label36->Name = L"label36";
			this->label36->Size = System::Drawing::Size(14, 13);
			this->label36->TabIndex = 29;
			this->label36->Text = L"~";
			this->label36->Click += gcnew System::EventHandler(this, &MyForm::label36_Click);
			// 
			// label37
			// 
			this->label37->AutoSize = true;
			this->label37->Location = System::Drawing::Point(316, 97);
			this->label37->Name = L"label37";
			this->label37->Size = System::Drawing::Size(27, 13);
			this->label37->TabIndex = 28;
			this->label37->Text = L"THz";
			this->label37->Click += gcnew System::EventHandler(this, &MyForm::label37_Click);
			// 
			// textBox_lowf
			// 
			this->textBox_lowf->BackColor = System::Drawing::SystemColors::Control;
			this->textBox_lowf->Location = System::Drawing::Point(253, 94);
			this->textBox_lowf->Name = L"textBox_lowf";
			this->textBox_lowf->ReadOnly = true;
			this->textBox_lowf->Size = System::Drawing::Size(57, 20);
			this->textBox_lowf->TabIndex = 27;
			this->textBox_lowf->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// label35
			// 
			this->label35->AutoSize = true;
			this->label35->Location = System::Drawing::Point(445, 61);
			this->label35->Name = L"label35";
			this->label35->Size = System::Drawing::Size(28, 13);
			this->label35->TabIndex = 26;
			this->label35->Text = L"dBm";
			// 
			// textBox_highp
			// 
			this->textBox_highp->BackColor = System::Drawing::SystemColors::Control;
			this->textBox_highp->Location = System::Drawing::Point(382, 58);
			this->textBox_highp->Name = L"textBox_highp";
			this->textBox_highp->ReadOnly = true;
			this->textBox_highp->Size = System::Drawing::Size(57, 20);
			this->textBox_highp->TabIndex = 25;
			// 
			// label34
			// 
			this->label34->AutoSize = true;
			this->label34->Location = System::Drawing::Point(350, 63);
			this->label34->Name = L"label34";
			this->label34->Size = System::Drawing::Size(14, 13);
			this->label34->TabIndex = 24;
			this->label34->Text = L"~";
			// 
			// label33
			// 
			this->label33->AutoSize = true;
			this->label33->Location = System::Drawing::Point(316, 61);
			this->label33->Name = L"label33";
			this->label33->Size = System::Drawing::Size(28, 13);
			this->label33->TabIndex = 23;
			this->label33->Text = L"dBm";
			// 
			// textBox_lowp
			// 
			this->textBox_lowp->BackColor = System::Drawing::SystemColors::Control;
			this->textBox_lowp->Location = System::Drawing::Point(253, 58);
			this->textBox_lowp->Name = L"textBox_lowp";
			this->textBox_lowp->ReadOnly = true;
			this->textBox_lowp->Size = System::Drawing::Size(57, 20);
			this->textBox_lowp->TabIndex = 22;
			// 
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label32->Location = System::Drawing::Point(225, 202);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(12, 16);
			this->label32->TabIndex = 21;
			this->label32->Text = L":";
			// 
			// label31
			// 
			this->label31->AutoSize = true;
			this->label31->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label31->Location = System::Drawing::Point(225, 166);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(12, 16);
			this->label31->TabIndex = 20;
			this->label31->Text = L":";
			// 
			// label30
			// 
			this->label30->AutoSize = true;
			this->label30->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label30->Location = System::Drawing::Point(225, 130);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(12, 16);
			this->label30->TabIndex = 19;
			this->label30->Text = L":";
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label29->Location = System::Drawing::Point(225, 94);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(12, 16);
			this->label29->TabIndex = 18;
			this->label29->Text = L":";
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label28->Location = System::Drawing::Point(225, 58);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(12, 16);
			this->label28->TabIndex = 17;
			this->label28->Text = L":";
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label27->Location = System::Drawing::Point(37, 202);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(135, 16);
			this->label27->TabIndex = 16;
			this->label27->Text = L"Maximum Buad Rate ";
			this->label27->Click += gcnew System::EventHandler(this, &MyForm::label27_Click);
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label26->Location = System::Drawing::Point(37, 166);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(179, 16);
			this->label26->TabIndex = 15;
			this->label26->Text = L"Fine Tune Frequency Range";
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label25->Location = System::Drawing::Point(37, 130);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(124, 16);
			this->label25->TabIndex = 14;
			this->label25->Text = L"Wavelength Range";
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label24->Location = System::Drawing::Point(37, 94);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(116, 16);
			this->label24->TabIndex = 13;
			this->label24->Text = L"Frequency Range";
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label23->Location = System::Drawing::Point(37, 58);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(109, 16);
			this->label23->TabIndex = 12;
			this->label23->Text = L"Power Capability";
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->groupBox_option);
			this->tabPage2->Controls->Add(this->groupBox_ds);
			this->tabPage2->Controls->Add(this->groupBox_Setting);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(862, 272);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Laser Setting";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// groupBox_option
			// 
			this->groupBox_option->Controls->Add(this->groupBox4);
			this->groupBox_option->Controls->Add(this->groupBox3);
			this->groupBox_option->Location = System::Drawing::Point(662, 9);
			this->groupBox_option->Name = L"groupBox_option";
			this->groupBox_option->Size = System::Drawing::Size(189, 250);
			this->groupBox_option->TabIndex = 0;
			this->groupBox_option->TabStop = false;
			this->groupBox_option->Text = L"Option";
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->button_ditherSet);
			this->groupBox4->Controls->Add(this->button_ditherEn);
			this->groupBox4->Controls->Add(this->label65);
			this->groupBox4->Controls->Add(this->textBox_dither);
			this->groupBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox4->Location = System::Drawing::Point(6, 137);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(177, 100);
			this->groupBox4->TabIndex = 1;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Dither";
			// 
			// button_ditherSet
			// 
			this->button_ditherSet->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button_ditherSet->Location = System::Drawing::Point(109, 29);
			this->button_ditherSet->Name = L"button_ditherSet";
			this->button_ditherSet->Size = System::Drawing::Size(52, 23);
			this->button_ditherSet->TabIndex = 34;
			this->button_ditherSet->Text = L"Set";
			this->button_ditherSet->UseVisualStyleBackColor = true;
			this->button_ditherSet->Click += gcnew System::EventHandler(this, &MyForm::button_ditherSet_Click);
			// 
			// button_ditherEn
			// 
			this->button_ditherEn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_ditherEn->Location = System::Drawing::Point(44, 58);
			this->button_ditherEn->Name = L"button_ditherEn";
			this->button_ditherEn->Size = System::Drawing::Size(89, 23);
			this->button_ditherEn->TabIndex = 33;
			this->button_ditherEn->Text = L"ON";
			this->button_ditherEn->UseVisualStyleBackColor = true;
			this->button_ditherEn->Click += gcnew System::EventHandler(this, &MyForm::button_ditherEn_Click);
			// 
			// label65
			// 
			this->label65->AutoSize = true;
			this->label65->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label65->Location = System::Drawing::Point(75, 33);
			this->label65->Name = L"label65";
			this->label65->Size = System::Drawing::Size(31, 15);
			this->label65->TabIndex = 27;
			this->label65->Text = L"GHz";
			this->label65->Click += gcnew System::EventHandler(this, &MyForm::label65_Click);
			// 
			// textBox_dither
			// 
			this->textBox_dither->Location = System::Drawing::Point(17, 30);
			this->textBox_dither->Name = L"textBox_dither";
			this->textBox_dither->Size = System::Drawing::Size(52, 22);
			this->textBox_dither->TabIndex = 24;
			this->textBox_dither->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged_2);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->button_lnm);
			this->groupBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox3->Location = System::Drawing::Point(6, 22);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(177, 100);
			this->groupBox3->TabIndex = 0;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Low Noise Mode";
			// 
			// button_lnm
			// 
			this->button_lnm->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_lnm->Location = System::Drawing::Point(64, 39);
			this->button_lnm->Name = L"button_lnm";
			this->button_lnm->Size = System::Drawing::Size(52, 23);
			this->button_lnm->TabIndex = 32;
			this->button_lnm->Text = L"ON";
			this->button_lnm->UseVisualStyleBackColor = true;
			this->button_lnm->Click += gcnew System::EventHandler(this, &MyForm::button2_Click_1);
			// 
			// groupBox_ds
			// 
			this->groupBox_ds->Controls->Add(this->button_sd);
			this->groupBox_ds->Controls->Add(this->button_rt);
			this->groupBox_ds->Controls->Add(this->button_su);
			this->groupBox_ds->Controls->Add(this->groupBox5);
			this->groupBox_ds->Location = System::Drawing::Point(317, 9);
			this->groupBox_ds->Name = L"groupBox_ds";
			this->groupBox_ds->Size = System::Drawing::Size(334, 250);
			this->groupBox_ds->TabIndex = 27;
			this->groupBox_ds->TabStop = false;
			this->groupBox_ds->Text = L"Device Status";
			// 
			// button_sd
			// 
			this->button_sd->Location = System::Drawing::Point(243, 213);
			this->button_sd->Name = L"button_sd";
			this->button_sd->Size = System::Drawing::Size(71, 24);
			this->button_sd->TabIndex = 45;
			this->button_sd->Text = L"Save Data";
			this->button_sd->UseVisualStyleBackColor = true;
			this->button_sd->Click += gcnew System::EventHandler(this, &MyForm::button_sd_Click);
			// 
			// button_rt
			// 
			this->button_rt->Location = System::Drawing::Point(116, 213);
			this->button_rt->Name = L"button_rt";
			this->button_rt->Size = System::Drawing::Size(64, 24);
			this->button_rt->TabIndex = 44;
			this->button_rt->Text = L"Real Time";
			this->button_rt->UseVisualStyleBackColor = true;
			this->button_rt->Click += gcnew System::EventHandler(this, &MyForm::button_rt_Click);
			// 
			// button_su
			// 
			this->button_su->Location = System::Drawing::Point(18, 213);
			this->button_su->Name = L"button_su";
			this->button_su->Size = System::Drawing::Size(92, 24);
			this->button_su->TabIndex = 43;
			this->button_su->Text = L"Status Update";
			this->button_su->UseMnemonic = false;
			this->button_su->UseVisualStyleBackColor = true;
			this->button_su->Click += gcnew System::EventHandler(this, &MyForm::button_su_Click);
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->label_status);
			this->groupBox5->Controls->Add(this->label63);
			this->groupBox5->Controls->Add(this->label60);
			this->groupBox5->Controls->Add(this->label61);
			this->groupBox5->Controls->Add(this->label62);
			this->groupBox5->Controls->Add(this->textBox_ct);
			this->groupBox5->Controls->Add(this->textBox_cw);
			this->groupBox5->Controls->Add(this->textBox_cf);
			this->groupBox5->Controls->Add(this->textBox_cpw);
			this->groupBox5->Controls->Add(this->label58);
			this->groupBox5->Controls->Add(this->label57);
			this->groupBox5->Controls->Add(this->label56);
			this->groupBox5->Controls->Add(this->label55);
			this->groupBox5->Controls->Add(this->label53);
			this->groupBox5->Controls->Add(this->label52);
			this->groupBox5->Controls->Add(this->label51);
			this->groupBox5->Controls->Add(this->label20);
			this->groupBox5->Location = System::Drawing::Point(18, 19);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(296, 188);
			this->groupBox5->TabIndex = 30;
			this->groupBox5->TabStop = false;
			// 
			// label_status
			// 
			this->label_status->AutoSize = true;
			this->label_status->Location = System::Drawing::Point(46, 160);
			this->label_status->Name = L"label_status";
			this->label_status->Size = System::Drawing::Size(0, 13);
			this->label_status->TabIndex = 58;
			// 
			// label63
			// 
			this->label63->AutoSize = true;
			this->label63->Location = System::Drawing::Point(237, 116);
			this->label63->Name = L"label63";
			this->label63->Size = System::Drawing::Size(18, 13);
			this->label63->TabIndex = 56;
			this->label63->Text = L"°C";
			this->label63->Click += gcnew System::EventHandler(this, &MyForm::label63_Click);
			// 
			// label60
			// 
			this->label60->AutoSize = true;
			this->label60->Location = System::Drawing::Point(237, 89);
			this->label60->Name = L"label60";
			this->label60->Size = System::Drawing::Size(21, 13);
			this->label60->TabIndex = 55;
			this->label60->Text = L"nm";
			// 
			// label61
			// 
			this->label61->AutoSize = true;
			this->label61->Location = System::Drawing::Point(237, 61);
			this->label61->Name = L"label61";
			this->label61->Size = System::Drawing::Size(27, 13);
			this->label61->TabIndex = 54;
			this->label61->Text = L"THz";
			// 
			// label62
			// 
			this->label62->AutoSize = true;
			this->label62->Location = System::Drawing::Point(237, 31);
			this->label62->Name = L"label62";
			this->label62->Size = System::Drawing::Size(28, 13);
			this->label62->TabIndex = 53;
			this->label62->Text = L"dBm";
			// 
			// textBox_ct
			// 
			this->textBox_ct->BackColor = System::Drawing::SystemColors::Control;
			this->textBox_ct->Location = System::Drawing::Point(158, 113);
			this->textBox_ct->Name = L"textBox_ct";
			this->textBox_ct->ReadOnly = true;
			this->textBox_ct->Size = System::Drawing::Size(73, 20);
			this->textBox_ct->TabIndex = 51;
			this->textBox_ct->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox_ct_TextChanged);
			// 
			// textBox_cw
			// 
			this->textBox_cw->BackColor = System::Drawing::SystemColors::Control;
			this->textBox_cw->Location = System::Drawing::Point(158, 86);
			this->textBox_cw->Name = L"textBox_cw";
			this->textBox_cw->ReadOnly = true;
			this->textBox_cw->Size = System::Drawing::Size(73, 20);
			this->textBox_cw->TabIndex = 50;
			// 
			// textBox_cf
			// 
			this->textBox_cf->BackColor = System::Drawing::SystemColors::Control;
			this->textBox_cf->Location = System::Drawing::Point(158, 59);
			this->textBox_cf->Name = L"textBox_cf";
			this->textBox_cf->ReadOnly = true;
			this->textBox_cf->Size = System::Drawing::Size(73, 20);
			this->textBox_cf->TabIndex = 49;
			// 
			// textBox_cpw
			// 
			this->textBox_cpw->BackColor = System::Drawing::SystemColors::Control;
			this->textBox_cpw->Location = System::Drawing::Point(158, 30);
			this->textBox_cpw->Name = L"textBox_cpw";
			this->textBox_cpw->ReadOnly = true;
			this->textBox_cpw->Size = System::Drawing::Size(73, 20);
			this->textBox_cpw->TabIndex = 48;
			// 
			// label58
			// 
			this->label58->AutoSize = true;
			this->label58->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label58->Location = System::Drawing::Point(123, 116);
			this->label58->Name = L"label58";
			this->label58->Size = System::Drawing::Size(11, 13);
			this->label58->TabIndex = 46;
			this->label58->Text = L":";
			// 
			// label57
			// 
			this->label57->AutoSize = true;
			this->label57->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label57->Location = System::Drawing::Point(123, 89);
			this->label57->Name = L"label57";
			this->label57->Size = System::Drawing::Size(11, 13);
			this->label57->TabIndex = 45;
			this->label57->Text = L":";
			// 
			// label56
			// 
			this->label56->AutoSize = true;
			this->label56->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label56->Location = System::Drawing::Point(123, 62);
			this->label56->Name = L"label56";
			this->label56->Size = System::Drawing::Size(11, 13);
			this->label56->TabIndex = 44;
			this->label56->Text = L":";
			// 
			// label55
			// 
			this->label55->AutoSize = true;
			this->label55->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label55->Location = System::Drawing::Point(123, 33);
			this->label55->Name = L"label55";
			this->label55->Size = System::Drawing::Size(11, 13);
			this->label55->TabIndex = 43;
			this->label55->Text = L":";
			// 
			// label53
			// 
			this->label53->AutoSize = true;
			this->label53->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label53->Location = System::Drawing::Point(35, 114);
			this->label53->Name = L"label53";
			this->label53->Size = System::Drawing::Size(86, 16);
			this->label53->TabIndex = 3;
			this->label53->Text = L"Temperature";
			// 
			// label52
			// 
			this->label52->AutoSize = true;
			this->label52->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label52->Location = System::Drawing::Point(35, 87);
			this->label52->Name = L"label52";
			this->label52->Size = System::Drawing::Size(80, 16);
			this->label52->TabIndex = 2;
			this->label52->Text = L"Wavelength";
			// 
			// label51
			// 
			this->label51->AutoSize = true;
			this->label51->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label51->Location = System::Drawing::Point(35, 59);
			this->label51->Name = L"label51";
			this->label51->Size = System::Drawing::Size(72, 16);
			this->label51->TabIndex = 1;
			this->label51->Text = L"Frequency";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label20->Location = System::Drawing::Point(35, 31);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(46, 16);
			this->label20->TabIndex = 0;
			this->label20->Text = L"Power";
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->groupBox_scan_status);
			this->tabPage3->Controls->Add(this->groupBox_scan_user);
			this->tabPage3->Location = System::Drawing::Point(4, 22);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(862, 272);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Scan Mode";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// groupBox_scan_status
			// 
			this->groupBox_scan_status->Controls->Add(this->groupBox6);
			this->groupBox_scan_status->Controls->Add(this->button1);
			this->groupBox_scan_status->Controls->Add(this->richTextBox2);
			this->groupBox_scan_status->Location = System::Drawing::Point(585, 6);
			this->groupBox_scan_status->Name = L"groupBox_scan_status";
			this->groupBox_scan_status->Size = System::Drawing::Size(271, 253);
			this->groupBox_scan_status->TabIndex = 15;
			this->groupBox_scan_status->TabStop = false;
			this->groupBox_scan_status->Text = L"Status Display";
			// 
			// groupBox6
			// 
			this->groupBox6->Controls->Add(this->textBox_fuser);
			this->groupBox6->Controls->Add(this->label64);
			this->groupBox6->Location = System::Drawing::Point(6, 17);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Size = System::Drawing::Size(257, 47);
			this->groupBox6->TabIndex = 31;
			this->groupBox6->TabStop = false;
			// 
			// textBox_fuser
			// 
			this->textBox_fuser->Location = System::Drawing::Point(172, 17);
			this->textBox_fuser->Name = L"textBox_fuser";
			this->textBox_fuser->ReadOnly = true;
			this->textBox_fuser->Size = System::Drawing::Size(72, 20);
			this->textBox_fuser->TabIndex = 1;
			// 
			// label64
			// 
			this->label64->AutoSize = true;
			this->label64->Location = System::Drawing::Point(7, 20);
			this->label64->Name = L"label64";
			this->label64->Size = System::Drawing::Size(157, 13);
			this->label64->TabIndex = 0;
			this->label64->Text = L"Current Center Frequency (THz)";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(193, 218);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(70, 25);
			this->button1->TabIndex = 55;
			this->button1->Text = L"Clear";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click_1);
			// 
			// richTextBox2
			// 
			this->richTextBox2->BackColor = System::Drawing::SystemColors::Control;
			this->richTextBox2->Location = System::Drawing::Point(6, 75);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->ReadOnly = true;
			this->richTextBox2->Size = System::Drawing::Size(257, 137);
			this->richTextBox2->TabIndex = 0;
			this->richTextBox2->Text = L"";
			this->richTextBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::richTextBox2_TextChanged);
			// 
			// groupBox_scan_user
			// 
			this->groupBox_scan_user->Controls->Add(this->groupBox9);
			this->groupBox_scan_user->Controls->Add(this->groupBox8);
			this->groupBox_scan_user->Controls->Add(this->groupBox7);
			this->groupBox_scan_user->Controls->Add(this->button_scan_user);
			this->groupBox_scan_user->Controls->Add(this->button_stop_user);
			this->groupBox_scan_user->Controls->Add(this->label59);
			this->groupBox_scan_user->Controls->Add(this->comboBox_ScanSerial_user);
			this->groupBox_scan_user->Location = System::Drawing::Point(6, 6);
			this->groupBox_scan_user->Name = L"groupBox_scan_user";
			this->groupBox_scan_user->Size = System::Drawing::Size(573, 253);
			this->groupBox_scan_user->TabIndex = 14;
			this->groupBox_scan_user->TabStop = false;
			this->groupBox_scan_user->Text = L"Scan Setting";
			// 
			// groupBox9
			// 
			this->groupBox9->Controls->Add(this->comboBox_power_user);
			this->groupBox9->Location = System::Drawing::Point(293, 165);
			this->groupBox9->Name = L"groupBox9";
			this->groupBox9->Size = System::Drawing::Size(166, 74);
			this->groupBox9->TabIndex = 54;
			this->groupBox9->TabStop = false;
			this->groupBox9->Text = L"Target Power (dBm)";
			// 
			// comboBox_power_user
			// 
			this->comboBox_power_user->FormattingEnabled = true;
			this->comboBox_power_user->Items->AddRange(gcnew cli::array< System::Object^  >(1) { L"10" });
			this->comboBox_power_user->Location = System::Drawing::Point(49, 26);
			this->comboBox_power_user->Name = L"comboBox_power_user";
			this->comboBox_power_user->Size = System::Drawing::Size(70, 21);
			this->comboBox_power_user->TabIndex = 55;
			this->comboBox_power_user->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedIndexChanged_1);
			// 
			// groupBox8
			// 
			this->groupBox8->Controls->Add(this->textBox_sweepRange_user);
			this->groupBox8->Controls->Add(this->label69);
			this->groupBox8->Location = System::Drawing::Point(293, 51);
			this->groupBox8->Name = L"groupBox8";
			this->groupBox8->Size = System::Drawing::Size(166, 108);
			this->groupBox8->TabIndex = 53;
			this->groupBox8->TabStop = false;
			this->groupBox8->Text = L"Sweep Range (GHz)";
			// 
			// textBox_sweepRange_user
			// 
			this->textBox_sweepRange_user->Location = System::Drawing::Point(49, 67);
			this->textBox_sweepRange_user->Name = L"textBox_sweepRange_user";
			this->textBox_sweepRange_user->Size = System::Drawing::Size(70, 20);
			this->textBox_sweepRange_user->TabIndex = 46;
			this->textBox_sweepRange_user->Text = L"100";
			// 
			// label69
			// 
			this->label69->AutoSize = true;
			this->label69->Location = System::Drawing::Point(10, 24);
			this->label69->Name = L"label69";
			this->label69->Size = System::Drawing::Size(135, 26);
			this->label69->TabIndex = 45;
			this->label69->Text = L"  Range (GHz) : 50 ~ 250\r\n(100 GHz is recommended)";
			// 
			// groupBox7
			// 
			this->groupBox7->Controls->Add(this->label_scanrange);
			this->groupBox7->Controls->Add(this->label66);
			this->groupBox7->Controls->Add(this->label9);
			this->groupBox7->Controls->Add(this->checkBox_scan_user);
			this->groupBox7->Controls->Add(this->label74);
			this->groupBox7->Controls->Add(this->label71);
			this->groupBox7->Controls->Add(this->textBox_LFL_user);
			this->groupBox7->Controls->Add(this->textBox_LFH_user);
			this->groupBox7->Location = System::Drawing::Point(19, 51);
			this->groupBox7->Name = L"groupBox7";
			this->groupBox7->Size = System::Drawing::Size(249, 188);
			this->groupBox7->TabIndex = 52;
			this->groupBox7->TabStop = false;
			this->groupBox7->Text = L"Scan Range";
			// 
			// label_scanrange
			// 
			this->label_scanrange->AutoSize = true;
			this->label_scanrange->Location = System::Drawing::Point(103, 85);
			this->label_scanrange->Name = L"label_scanrange";
			this->label_scanrange->Size = System::Drawing::Size(0, 13);
			this->label_scanrange->TabIndex = 52;
			// 
			// label66
			// 
			this->label66->AutoSize = true;
			this->label66->Location = System::Drawing::Point(2, 54);
			this->label66->Name = L"label66";
			this->label66->Size = System::Drawing::Size(245, 13);
			this->label66->TabIndex = 48;
			this->label66->Text = L"------------------------------------ OR ------------------------------------";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(16, 84);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(89, 13);
			this->label9->TabIndex = 51;
			this->label9->Text = L"Scan Range : ";
			// 
			// checkBox_scan_user
			// 
			this->checkBox_scan_user->AutoSize = true;
			this->checkBox_scan_user->Location = System::Drawing::Point(44, 29);
			this->checkBox_scan_user->Name = L"checkBox_scan_user";
			this->checkBox_scan_user->Size = System::Drawing::Size(161, 17);
			this->checkBox_scan_user->TabIndex = 47;
			this->checkBox_scan_user->Text = L"               Entire Range Scan";
			this->checkBox_scan_user->UseVisualStyleBackColor = true;
			// 
			// label74
			// 
			this->label74->AutoSize = true;
			this->label74->Location = System::Drawing::Point(16, 126);
			this->label74->Name = L"label74";
			this->label74->Size = System::Drawing::Size(111, 13);
			this->label74->TabIndex = 42;
			this->label74->Text = L"Start Frequency (THz)";
			// 
			// label71
			// 
			this->label71->AutoSize = true;
			this->label71->Location = System::Drawing::Point(16, 152);
			this->label71->Name = L"label71";
			this->label71->Size = System::Drawing::Size(108, 13);
			this->label71->TabIndex = 44;
			this->label71->Text = L"Stop Frequency(THz)";
			// 
			// textBox_LFL_user
			// 
			this->textBox_LFL_user->Location = System::Drawing::Point(142, 123);
			this->textBox_LFL_user->Name = L"textBox_LFL_user";
			this->textBox_LFL_user->Size = System::Drawing::Size(70, 20);
			this->textBox_LFL_user->TabIndex = 40;
			this->textBox_LFL_user->Text = L"0";
			// 
			// textBox_LFH_user
			// 
			this->textBox_LFH_user->Location = System::Drawing::Point(142, 149);
			this->textBox_LFH_user->Name = L"textBox_LFH_user";
			this->textBox_LFH_user->Size = System::Drawing::Size(70, 20);
			this->textBox_LFH_user->TabIndex = 41;
			this->textBox_LFH_user->Text = L"0";
			// 
			// button_scan_user
			// 
			this->button_scan_user->Location = System::Drawing::Point(487, 93);
			this->button_scan_user->Name = L"button_scan_user";
			this->button_scan_user->Size = System::Drawing::Size(70, 25);
			this->button_scan_user->TabIndex = 50;
			this->button_scan_user->Text = L"Scan";
			this->button_scan_user->UseVisualStyleBackColor = true;
			this->button_scan_user->Click += gcnew System::EventHandler(this, &MyForm::button_scan_user_Click);
			// 
			// button_stop_user
			// 
			this->button_stop_user->Location = System::Drawing::Point(487, 188);
			this->button_stop_user->Name = L"button_stop_user";
			this->button_stop_user->Size = System::Drawing::Size(70, 25);
			this->button_stop_user->TabIndex = 17;
			this->button_stop_user->Text = L"Stop";
			this->button_stop_user->UseVisualStyleBackColor = true;
			this->button_stop_user->Click += gcnew System::EventHandler(this, &MyForm::button_stop_user_Click);
			// 
			// label59
			// 
			this->label59->AutoSize = true;
			this->label59->Location = System::Drawing::Point(183, 22);
			this->label59->Name = L"label59";
			this->label59->Size = System::Drawing::Size(73, 13);
			this->label59->TabIndex = 43;
			this->label59->Text = L"Serial Number";
			// 
			// comboBox_ScanSerial_user
			// 
			this->comboBox_ScanSerial_user->FormattingEnabled = true;
			this->comboBox_ScanSerial_user->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"C-Band", L"L-Band" });
			this->comboBox_ScanSerial_user->Location = System::Drawing::Point(267, 19);
			this->comboBox_ScanSerial_user->Name = L"comboBox_ScanSerial_user";
			this->comboBox_ScanSerial_user->Size = System::Drawing::Size(157, 21);
			this->comboBox_ScanSerial_user->TabIndex = 39;
			// 
			// tabPage4
			// 
			this->tabPage4->Controls->Add(this->groupBox_ScanMode);
			this->tabPage4->Controls->Add(this->groupBox_Command);
			this->tabPage4->Location = System::Drawing::Point(4, 22);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Padding = System::Windows::Forms::Padding(3);
			this->tabPage4->Size = System::Drawing::Size(862, 272);
			this->tabPage4->TabIndex = 3;
			this->tabPage4->Text = L"Developer Mode";
			this->tabPage4->UseVisualStyleBackColor = true;
			// 
			// groupBox_Command
			// 
			this->groupBox_Command->Controls->Add(this->richTextBox1);
			this->groupBox_Command->Controls->Add(this->button_CMD_WR);
			this->groupBox_Command->Controls->Add(this->button_Clear);
			this->groupBox_Command->Controls->Add(this->label2);
			this->groupBox_Command->Controls->Add(this->label1);
			this->groupBox_Command->Controls->Add(this->textBox_Command1);
			this->groupBox_Command->Controls->Add(this->textBox_CMD_Pa1);
			this->groupBox_Command->Controls->Add(this->button_CMD_RD);
			this->groupBox_Command->Location = System::Drawing::Point(9, 6);
			this->groupBox_Command->Name = L"groupBox_Command";
			this->groupBox_Command->Size = System::Drawing::Size(377, 255);
			this->groupBox_Command->TabIndex = 14;
			this->groupBox_Command->TabStop = false;
			this->groupBox_Command->Text = L"Register";
			this->groupBox_Command->Enter += gcnew System::EventHandler(this, &MyForm::groupBox_Command_Enter);
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label16->Location = System::Drawing::Point(310, 97);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(32, 16);
			this->label16->TabIndex = 29;
			this->label16->Text = L"v1.0";
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->WorkerReportsProgress = true;
			this->backgroundWorker1->WorkerSupportsCancellation = true;
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm::backgroundWorker1_DoWork);
			this->backgroundWorker1->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &MyForm::backgroundWorker1_ProgressChanged);
			this->backgroundWorker1->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &MyForm::backgroundWorker1_RunWorkerCompleted);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(803, 114);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 30;
			this->button2->Text = L"Help";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click_2);
			// 
			// backgroundWorker2
			// 
			this->backgroundWorker2->WorkerReportsProgress = true;
			this->backgroundWorker2->WorkerSupportsCancellation = true;
			this->backgroundWorker2->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm::backgroundWorker2_DoWork);
			this->backgroundWorker2->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &MyForm::backgroundWorker2_ProgressChanged);
			this->backgroundWorker2->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &MyForm::backgroundWorker2_RunWorkerCompleted);
			// 
			// backgroundWorker3
			// 
			this->backgroundWorker3->WorkerReportsProgress = true;
			this->backgroundWorker3->WorkerSupportsCancellation = true;
			this->backgroundWorker3->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm::backgroundWorker3_DoWork);
			this->backgroundWorker3->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &MyForm::backgroundWorker3_ProgressChanged);
			this->backgroundWorker3->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &MyForm::backgroundWorker3_RunWorkerCompleted);
			// 
			// backgroundWorker4
			// 
			this->backgroundWorker4->WorkerReportsProgress = true;
			this->backgroundWorker4->WorkerSupportsCancellation = true;
			this->backgroundWorker4->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm::backgroundWorker4_DoWork);
			this->backgroundWorker4->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &MyForm::backgroundWorker4_ProgressChanged);
			this->backgroundWorker4->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &MyForm::backgroundWorker4_RunWorkerCompleted);
			// 
			// backgroundWorker5
			// 
			this->backgroundWorker5->WorkerReportsProgress = true;
			this->backgroundWorker5->WorkerSupportsCancellation = true;
			this->backgroundWorker5->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm::backgroundWorker5_DoWork);
			this->backgroundWorker5->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &MyForm::backgroundWorker5_ProgressChanged);
			this->backgroundWorker5->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &MyForm::backgroundWorker5_RunWorkerCompleted);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(894, 453);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->textBox_Freq_user);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label15);
			this->Cursor = System::Windows::Forms::Cursors::Default;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Optilab TWL GUI v1.0";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->groupBox_ComPort->ResumeLayout(false);
			this->groupBox_ComPort->PerformLayout();
			this->groupBox_ScanMode->ResumeLayout(false);
			this->groupBox_ScanMode->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->groupBox_Setting->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->textBox_Freq_user->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->groupBox_deviceInfo->ResumeLayout(false);
			this->groupBox_deviceInfo->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->groupBox_option->ResumeLayout(false);
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox_ds->ResumeLayout(false);
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			this->tabPage3->ResumeLayout(false);
			this->groupBox_scan_status->ResumeLayout(false);
			this->groupBox6->ResumeLayout(false);
			this->groupBox6->PerformLayout();
			this->groupBox_scan_user->ResumeLayout(false);
			this->groupBox_scan_user->PerformLayout();
			this->groupBox9->ResumeLayout(false);
			this->groupBox8->ResumeLayout(false);
			this->groupBox8->PerformLayout();
			this->groupBox7->ResumeLayout(false);
			this->groupBox7->PerformLayout();
			this->tabPage4->ResumeLayout(false);
			this->groupBox_Command->ResumeLayout(false);
			this->groupBox_Command->PerformLayout();
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
			}
			//comboBox_Comport->SelectedIndex = 0;
			//comboBox_Comport->SelectedIndex = 11;
			
			//comboBox_Serial->Items->Add("9270029");
			//comboBox_Serial->Items->Add("9270030");
			comboBox_Serial->SelectedIndex = 0;

			groupBox_Setting->Enabled = false;
			groupBox_option->Enabled = false;
			groupBox_deviceInfo->Enabled = false;
			groupBox_ds->Enabled = false;
			groupBox_Command->Enabled = false;
			groupBox_ScanMode->Enabled = false;
			groupBox_scan_user->Enabled = false;
			groupBox_scan_status->Enabled = false;
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
			String^ SysTmp8 = "";
			SysTmp1 = ITLAshow(0x50, 0, 0, comportNum);											//Lower power
			SysTmp2 = ITLAshow(0x51, 0, 0, comportNum);											//Upper power
			SysTmp3 = ITLAshow(0x52, 0, 0, comportNum);											//First Frequency THz
			SysTmp4 = ITLAshow(0x53, 0, 0, comportNum);											//First Frequency GHz
			SysTmp5 = ITLAshow(0x54, 0, 0, comportNum);											//Last Frequency THz
			SysTmp6 = ITLAshow(0x55, 0, 0, comportNum);											//Last Frequecy GHz
			SysTmp7 = ITLAshow(0x4F, 0, 0, comportNum);											//Fine tune range
			SysTmp8 = ITLAshow(0x0D, 0, 0, comportNum);											//Baudrate
			
			AEA(comportNum, 0x04);
			AEA(comportNum, 0x03);

			



			if (errorCode == 0) {																	//Port connect init start
				groupBox_Command->Enabled = true;
				groupBox_ScanMode->Enabled = true;
				groupBox_Setting->Enabled = true;
				groupBox_option->Enabled = true;
				groupBox_deviceInfo->Enabled = true;
				groupBox_ds->Enabled = true;
				groupBox_scan_user->Enabled = true;
				groupBox_scan_status->Enabled = true;
				richTextBox1->Text = gcnew System::String("");
				button_init_Comport->Enabled = false;

				
				
				textBox_conn->Text = "";
				textBox_lowp->Text = "";
				textBox_highp->Text = "";
				textBox_lowf->Text = "";
				textBox_highf->Text = "";
				textBox_loww->Text = "";
				textBox_highw->Text = "";
				textBox_lowft->Text = "";
				textBox_highft->Text = "";
				textBox_baud->Text = "";





				textBox_conn->AppendText(gcnew System::String("Successfully initialized!"));
				textBox_lowp->AppendText((Convert::ToInt32(SysTmp1->Substring(4, 4), 16)*0.01).ToString());
				textBox_highp->AppendText((Convert::ToInt32(SysTmp2->Substring(4, 4), 16)*0.01).ToString());
				textBox_lowf->AppendText((Convert::ToInt32(SysTmp4->Substring(4, 4), 16)*0.0001 + Convert::ToInt32(SysTmp3->Substring(4, 4), 16)).ToString());
				textBox_highf->AppendText((Convert::ToInt32(SysTmp6->Substring(4, 4), 16)*0.0001 + Convert::ToInt32(SysTmp5->Substring(4, 4), 16)).ToString());
				textBox_loww->AppendText(Round_off(ThzToNm((Convert::ToInt32(SysTmp6->Substring(4, 4), 16)*0.0001) + Convert::ToInt32(SysTmp5->Substring(4, 4), 16)),8).ToString());
				textBox_highw->AppendText(Round_off(ThzToNm((Convert::ToInt32(SysTmp4->Substring(4, 4), 16)*0.0001) + Convert::ToInt32(SysTmp3->Substring(4, 4), 16)),8).ToString());
				textBox_lowft->AppendText("- " + (Convert::ToInt32(SysTmp7->Substring(4, 4), 16)).ToString());
				textBox_highft->AppendText((Convert::ToInt32(SysTmp7->Substring(4, 4), 16)).ToString());

				label_scanrange->Text = "";
				label_scanrange->Text = (Convert::ToInt32(SysTmp4->Substring(4, 4), 16)*0.0001 + Convert::ToInt32(SysTmp3->Substring(4, 4), 16)).ToString() + " THz ~ " +
					(Convert::ToInt32(SysTmp6->Substring(4, 4), 16)*0.0001 + Convert::ToInt32(SysTmp5->Substring(4, 4), 16)).ToString() + " THz";
				label_scanrange->Update();

				switch (Convert::ToInt32(SysTmp8->Substring(4, 4), 16))
				{
				case 1: textBox_baud->AppendText("1200");
					break;
				case 2: textBox_baud->AppendText("2400");
					break;
				case 3: textBox_baud->AppendText("4800");
					break;
				case 4: textBox_baud->AppendText("9600");
					break;
				case 5: textBox_baud->AppendText("14400");
					break;
				case 6: textBox_baud->AppendText("19200");
					break;
				case 7: textBox_baud->AppendText("28800");
					break;
				case 8: textBox_baud->AppendText("38400");
					break;
				case 9: textBox_baud->AppendText("57600");
					break;
				case 10: textBox_baud->AppendText("115200");
					break;
				default: textBox_baud->AppendText("Error");
					break;
				}

				



	

			} else {
				textBox_conn->AppendText(gcnew System::String("Failed to initialize! Please choose another port and try"));

			}
		}
		private: System::Void button_CloseComport_Click(System::Object^  sender, System::EventArgs^  e) {
			/*std::string stdText = "";
			String^ SysTmp = comboBox_Comport->Text;
			int comportNum = comboBox_Comport->SelectedIndex;

			MarshalString(SysTmp, stdText);
			if (stdText.length() == 4) {
				comportNum = (stdText.at(3) - '0') - 1;
			}
			else if (stdText.length() > 4) {
				comportNum = (stdText.at(3) - '0') * 10 + (stdText.at(4) - '0') - 1;
			}*/

			RS232_CloseComport(comportNum);
			button_init_Comport->Enabled = true;
			groupBox_Command->Enabled = false;
			groupBox_ScanMode->Enabled = false;
		}
		private: System::Void button_enable_Click(System::Object^  sender, System::EventArgs^  e) {  //Laser enable button
			int reg = 0, data = 0;
			unsigned char* temp = NULL;
			string stdStr = "";
			String^ SysTmp = "";

			laserStatus = !laserStatus;
			
			if (laserStatus) {
				data = 8;
				label_status->Text = "Laser Enabled";
				button_enable->Text = "Disable";
			}
			else {
				data = 0;
				label_status->Text = "Laser Disabled";
				button_enable->Text = "Enable";
			}
			
			//void ITLACommand(int reg, int data, int RW, int port)
			SysTmp = ITLAshow(50, data, 1, comportNum);

			SysTmp = gcnew String(stdStr.c_str());
			richTextBox1->AppendText(SysTmp);
			richTextBox1->ScrollToCaret();
			richTextBox1->AppendText("\n\n");

		
		}


		private: System::Void button_pw_set_Click(System::Object^  sender, System::EventArgs^  e) { //Power setting button
			int reg = 0;
			double data = 0;
			unsigned char* temp = NULL;
			string stdStr = "";
			String^ SysTmp = "";
			String^ SysTmp1 = "";
			String^ SysTmp2 = "";

			SysTmp1 = ITLAshow(0x50, 0, 0, comportNum);											//Lower power
			SysTmp2 = ITLAshow(0x51, 0, 0, comportNum);

			data = Convert::ToDouble(textBox_pw_level->Text) * 100;
			
			if (data <= Convert::ToInt32(SysTmp2->Substring(4, 4), 16) && data >= Convert::ToInt32(SysTmp1->Substring(4, 4), 16)) {

				reg = 0x31;
				double realpower = Convert::ToDouble(textBox_pw_level->Text);

				//void ITLACommand(int reg, int data, int RW, int port)
				SysTmp = ITLAshow(reg, data, 1, comportNum);
				//SysTmp = gcnew String(stdStr.c_str());

				label_status->Text = "Power set to " + realpower + " dBm";

				//richTextBox1->AppendText(SysTmp);

				//richTextBox1->ScrollToCaret();
				//richTextBox1->AppendText("\n");
				//richTextBox1->AppendText("Power set to " + realpower + " dBm\n");


			}
			else
			{
				MessageBox::Show("Out of Power capability range!\nPlease check 'General' tab and enter valid power", "Warning", MessageBoxButtons::OK);
			}

			
		}
		
		private: System::Void textBox1_TextChanged_1(System::Object^  sender, System::EventArgs^  e) {


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
			data_ghz = g2*10;
			m1 = g1- g2;
			data_mhz = m1*1000;

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
					// //Convert THz to GHz
					//temp1 = ITLACommand(0x36, data_thz, 1, comportNum); //GHz register
					//richTextBox1->AppendText(SysTmp);
					//richTextBox1->ScrollToCaret();
					//richTextBox1->AppendText("\n");
					//richTextBox1->AppendText(data_nm_thz.ToString);
					label_status->Text = "Frequency set to " + freq1 + " THz";
					//richTextBox1->AppendText("Wavelength set to " + freq1 + " THz\n");
				}
				else
				{
					MessageBox::Show("Out of Frequency capability range!\nPlease check 'General' tab and enter valid frequency", "Warning", MessageBoxButtons::OK);
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

					label_status->Text = "Frequency set to " + freq1 + " THz";

				}
				else
				{
					MessageBox::Show("Out of Frequency capability range!\nPlease check 'General' tab and enter valid frequency", "Warning", MessageBoxButtons::OK);
				}
			}

			
		}


		private: System::Void button_SetWaveNm_Click(System::Object^  sender, System::EventArgs^  e) { //Wavelength setting nm

			int reg = 0, data_thz, data_ghz, data_mhz = 0;
			double m1 = 0;

			unsigned char* temp = NULL;
			unsigned char* temp1 = NULL;
			
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
			SysTmp5 = ITLAshow(0x4F, 0, 0, comportNum);					//MHz 
			SysTmp6 = ITLAshow(0x32, 0, 0, comportNum);					//laser on/off

			double freq2 = Convert::ToDouble(textBox_wave_nm->Text);	
			data_thz = (int)NmtoThz(freq2);								
			data_ghz = (NmtoThz(freq2) - data_thz) * 10000;
			m1 = (NmtoThz(freq2) - data_thz) * 10000 - (int)((NmtoThz(freq2) - data_thz) * 10000);
			data_mhz = m1 * 100;

			if (Convert::ToInt32(SysTmp6->Substring(4, 4), 16) == 8)
			{
				if ((freq2 <= ThzToNm(Convert::ToInt32(SysTmp5->Substring(4, 4), 16)*0.000001 + (Convert::ToInt32(SysTmp2->Substring(4, 4), 16)*0.0001) + Convert::ToInt32(SysTmp1->Substring(4, 4), 16)) && freq2 >= ThzToNm(Convert::ToInt32(SysTmp5->Substring(4, 4), 16)*(-0.000001) + (Convert::ToInt32(SysTmp4->Substring(4, 4), 16)*0.0001) + Convert::ToInt32(SysTmp3->Substring(4, 4), 16)))) {

					//void ITLACommand(int reg, int data, int RW, int port)
					SysTmp = ITLAshow(50, 0, 1, comportNum);
					SysTmp = ITLAshow(0x35, data_thz, 1, comportNum);  // THz register set first
					SysTmp = ITLAshow(0x36, data_ghz, 1, comportNum); // GHz decimal set
					SysTmp = ITLAshow(0x62, data_mhz, 1, comportNum); // MHz decimal set
					SysTmp = ITLAshow(50, 8, 1, comportNum);
					SysTmp = ITLAshow(0x30, 1, 1, comportNum);
					//richTextBox1->AppendText(SysTmp);
					//richTextBox1->ScrollToCaret();
					//richTextBox1->AppendText("\n");
					label_status->Text = "Wavelength set to " + freq2 + " nm";
					//richTextBox1->AppendText("Wavelength set to " + freq2 + " nm\n");
				}
				else
				{
					MessageBox::Show("Out of Wavelength capability range!\nPlease check 'General' tab and enter valid wavelength", "Warning", MessageBoxButtons::OK);
				}
			}
			else
			{
				if ((freq2 <= ThzToNm(Convert::ToInt32(SysTmp5->Substring(4, 4), 16)*0.000001 + (Convert::ToInt32(SysTmp2->Substring(4, 4), 16)*0.0001) + Convert::ToInt32(SysTmp1->Substring(4, 4), 16)) && freq2 >= ThzToNm(Convert::ToInt32(SysTmp5->Substring(4, 4), 16)*(-0.000001) + (Convert::ToInt32(SysTmp4->Substring(4, 4), 16)*0.0001) + Convert::ToInt32(SysTmp3->Substring(4, 4), 16)))) {

					SysTmp = ITLAshow(0x35, data_thz, 1, comportNum);  // THz register set first
					SysTmp = ITLAshow(0x36, data_ghz, 1, comportNum); // GHz decimal set
					SysTmp = ITLAshow(0x62, data_mhz, 1, comportNum); // MHz decimal set
					SysTmp = ITLAshow(0x30, 1, 1, comportNum);

					label_status->Text = "Wavelength set to " + freq2 + " nm";
				}
				else
				{
					MessageBox::Show("Out of Wavelength capability range!\nPlease check 'General' tab and enter valid wavelength", "Warning", MessageBoxButtons::OK);
				}
			}

			

		}

		private: System::Void button_setch_Click(System::Object^  sender, System::EventArgs^  e) { //Channel setting
			int reg, data_thz, data_ghz, ch;
			double ff, lf = 0;
			int x = Convert::ToInt32(textBox_chvar->Text);

			double f100 = 190 + 0.1*x;
			double f50 = 190 + 0.1*x + 0.05;

			unsigned char* temp1 = NULL;
			unsigned char* temp2 = NULL;

			String^ SysTmp = "";
			String^ SysTmp1 = "";
			String^ SysTmp2 = "";
			String^ SysTmp3 = "";
			String^ SysTmp4 = "";
			String^ SysTmp5 = "";
			SysTmp1 = ITLAshow(0x52, 0, 0, comportNum);					//THz first
			SysTmp2 = ITLAshow(0x53, 0, 0, comportNum);					//GHz first
			SysTmp3 = ITLAshow(0x54, 0, 0, comportNum);					//THz last
			SysTmp4 = ITLAshow(0x55, 0, 0, comportNum);					//GHz last
			SysTmp5 = ITLAshow(0x32, 0, 0, comportNum);					//laser on/off

			ff = Convert::ToInt32(SysTmp1->Substring(4, 4), 16) + Convert::ToInt32(SysTmp2->Substring(4, 4), 16)*0.0001;			//First Freq
			lf = Convert::ToInt32(SysTmp3->Substring(4, 4), 16) + Convert::ToInt32(SysTmp4->Substring(4, 4), 16)*0.0001;			//Last Freq

			if (Convert::ToInt32(SysTmp5->Substring(4, 4), 16) == 8)
			{
				if (comboBox_ch->Text == "50G")													//50G spacing
				{
					if (((f50 - ff) >= 0) && (f50 <= lf))
					{
						data_thz = (int)f50;
						data_ghz = (f50 - data_thz) * 10000;
						SysTmp = ITLAshow(50, 0, 1, comportNum);
						SysTmp = ITLAshow(0x35, data_thz, 1, comportNum);
						SysTmp = ITLAshow(0x36, data_ghz, 1, comportNum);
						SysTmp = ITLAshow(50, 8, 1, comportNum);
						ch = (f50 - ff) / 50 + 1;
						SysTmp = ITLAshow(0x30, ch, 1, comportNum);
						label_status->Text = "Channel set to H" + x + " (ITU-Grid)";
					}
					else
					{
						MessageBox::Show("Out of Frequency capability range!\nPlease check 'General' tab and enter valid channel frequency", "Warning", MessageBoxButtons::OK);
					}
				}
				else if (comboBox_ch->Text == "100G")											//100G spacing
				{
					if (((f100 - ff) >= 0) && (f100 <= lf))
					{
						data_thz = (int)f100;
						data_ghz = (f100 - data_thz) * 10000;
						SysTmp = ITLAshow(50, 0, 1, comportNum);
						SysTmp = ITLAshow(0x35, data_thz, 1, comportNum);
						SysTmp = ITLAshow(0x36, data_ghz, 1, comportNum);
						SysTmp = ITLAshow(50, 8, 1, comportNum);
						ch = (f100 - ff) / 100 + 1;
						SysTmp = ITLAshow(0x30, ch, 1, comportNum);
						label_status->Text = "Channel set to C" + x + " (ITU-Grid)";
					}
					else
					{
						MessageBox::Show("Out of Frequency capability range!\nPlease check 'General' tab and enter valid channel frequency", "Warning", MessageBoxButtons::OK);
					}
				}
				else
				{
					MessageBox::Show("Please one of select grid spacing", "Warning", MessageBoxButtons::OK);
				}
			}
			else
			{
				if (comboBox_ch->Text == "50G")													//50G spacing
				{
					if ((f50 - ff) >= 0 && (f50 <= lf))
					{
						data_thz = (int)f50;
						data_ghz = (f50 - data_thz) * 10000;	
						SysTmp = ITLAshow(0x35, data_thz, 1, comportNum);
						SysTmp = ITLAshow(0x36, data_ghz, 1, comportNum);
						ch = (f50 - ff) / 50 + 1;
						SysTmp = ITLAshow(0x30, ch, 1, comportNum);
						label_status->Text = "Channel set to H" + x + " (ITU-Grid)";
					}
					else
					{
						MessageBox::Show("Out of Frequency capability range!\nPlease check 'General' tab and enter valid channel frequency", "Warning", MessageBoxButtons::OK);
					}
				}
				else if (comboBox_ch->Text == "100G")											//100G spacing
				{
					if ((f100 - ff) >= 0 && (f100 <= lf))
					{
						data_thz = (int)f100;
						data_ghz = (f100 - data_thz) * 10000;
						SysTmp = ITLAshow(0x35, data_thz, 1, comportNum);
						SysTmp = ITLAshow(0x36, data_ghz, 1, comportNum);
						ch = (f100 - ff) / 100 + 1;
						SysTmp = ITLAshow(0x30, ch, 1, comportNum);
						label_status->Text = "Channel set to C" + x + " (ITU-Grid)";
					}
					else
					{
						MessageBox::Show("Out of Frequency capability range!\nPlease check 'General' tab and enter valid channel frequency", "Warning", MessageBoxButtons::OK);
					}
				}
				else
				{
					MessageBox::Show("Please one of select grid spacing", "Warning", MessageBoxButtons::OK);
				}
			}


			

		}

		private: System::Void button_CMD_WR_Click(System::Object^  sender, System::EventArgs^  e) { //buttoon Write
			int reg = 0, data = 0;
			unsigned char* temp = NULL;
			string stdStr = "";
			String^ SysTmp = "";

			reg = Convert::ToInt32(textBox_Command1->Text, 16);
			data = Convert::ToInt32(textBox_CMD_Pa1->Text);
			richTextBox1->AppendText(gcnew System::String("Read from register " + reg.ToString("X2") + "\n"));

			//void ITLACommand(int reg, int data, int RW, int port)
			SysTmp = ITLAshow(reg, data, 1, comportNum);
			//sprintf(const_cast<char*>(stdStr.c_str()), "%2.2x%2.2x%2.2x%2.2x", temp[0], temp[1], temp[2], temp[3]);
			//SysTmp = gcnew String(stdStr.c_str());
			richTextBox1->AppendText(SysTmp);
			richTextBox1->ScrollToCaret();
			richTextBox1->AppendText("\n\n");
			
		}
		private: System::Void button_CMD_RD_Click(System::Object^  sender, System::EventArgs^  e) { //button Read
			int reg = 0;
			unsigned char* temp = NULL;
			string stdStr = "";
			String^ SysTmp = "";
			String^ SysTmp2 = "";


			reg = Convert::ToInt32(textBox_Command1->Text, 16);
			richTextBox1->AppendText(gcnew System::String("Read from register " + reg.ToString("X2") + "\n"));

			SysTmp2 = ITLAshow(reg, 0, 0, comportNum);


			// ITLACommand(int reg, int data, int RW, int port)
			//temp = ITLACommand2(reg, 0, 0, comportNum);
			//sprintf(const_cast<char*>(stdStr.c_str()), "%2.2x%2.2x%2.2x%2.2x", temp[0], temp[1], temp[2], temp[3]);
			//SysTmp = gcnew String(stdStr.c_str());
			//richTextBox1->AppendText(SysTmp);
			richTextBox1->ScrollToCaret();			
			richTextBox1->AppendText(Convert::ToInt32(SysTmp2->Substring(4, 4), 16).ToString());
			richTextBox1->AppendText("\n\n");
		}


		

		
		private: System::Void button_Final_Click(System::Object^  sender, System::EventArgs^  e) { //stop button

			if (backgroundWorker4->IsBusy)
			{
				backgroundWorker4->CancelAsync();
				

			}
			else
			{
				richTextBox1->AppendText("No operation in progress to cancel");
			}


			

		}

		
		
		private: System::Void button_Exit_Click(System::Object^  sender, System::EventArgs^  e) {
			ITLAshow(50, 0, 1, comportNum);
			button_CloseComport->PerformClick();
			Application::Exit();
		}
		private: System::Void button_Clear_Click(System::Object^  sender, System::EventArgs^  e) {
			richTextBox1->Text = "";
		}
		private: System::Void button_Get_Click(System::Object^  sender, System::EventArgs^  e) {
			// Read data from current2 and map files to array
			int serialNum = 0;
			char filename[100] = "";
			FILE *fp;
			int size = 0, sizeMap = 0;	// store the number of lines for each file
			int i = 0, j = 0;			// loop counter
			int power[REGSIZE], cs[REGSIZE];
			double freq[REGSIZE], lcc[REGSIZE], hcc[REGSIZE], lccTmp = 0.0, hccTmp = 0.0;
			int regF0 = 0, regF1 = 0, regF2 = 0, regF3 = 0, regE7 = 0;
			double targetFreq = Convert::ToDouble(textBox_Freq->Text);
			int targetPower = Convert::ToDouble(textBox_Power->Text) * 100;
			double fractional = 0.0, integer = 0.0;
			// variables for Map file
			int powerMap[REGSIZE], current = 0, ambient = 0;
			double freqMap[REGSIZE], sled[REGSIZE], f1[REGSIZE], f2[REGSIZE];
			double f1p = 0.0, f2p = 0.0, f1High = 0.0, f2High = 0.0, f1Low = 0.0, f2Low = 0.0, f1Tmp = 0.0, f2Tmp = 0.0, sledTmp = 0.0;
			int indexHigh = 0, indexLow = 0;

			String^ SysTmp1 = "";
			SysTmp1 = ITLAshow(0xE8, 0, 0, comportNum);
			int sledSlopeRead = Convert::ToInt32(SysTmp1->Substring(4, 4), 16);
			double sledSlope = -1 * (sledSlopeRead / 10000);
			//double sledSlope = -0.245;		// read from 0xE8/10,000
			int F1_Index = 0, F2_Index = 0;
			int SLED_Index_Low = 0, SLED_Index_High = 0;

			fractional = modf(targetFreq, &integer);
			//printf("%d %d\n", (int)integer, (int)round((fractional * 1000.00)));


			//ifstream file_("input2/CRTNJ5W06P.current2");

			serialNum = comboBox_Serial->SelectedIndex;
			switch (serialNum) {
			case 0:
				strncpy(filename, "input2/CRTNJ5W06P.current2", 100);
				break;
			case 1:
				strncpy(filename, "input2/CRTNCAJ02E.current2", 100);
				break;
			}

			size = countlines(filename) + 1;
			fp = fopen(filename, "r");
			
			while (!feof(fp)) {
				fscanf(fp, "%lf %d %lf %lf %d", &freq[i], &power[i], &lcc[i], &hcc[i], &cs[i]);
				printf("%lf %d %lf %lf %d\n", freq[i], power[i], lcc[i], hcc[i], cs[i]);
				i++;
			}




			fclose(fp);
			// look for target frequency and power for scanning
			for (i = 0; i < countlines(filename) + 1; i++) {
				if (power[i] == 1000) {
					// Target frequency is in the current2 file
					if (freq[i] == targetFreq * 100 / 100) {
						//printf("freq: %f powerMap: %d \n", freq[i], power[i]);
						//targetIndex = i;
						regE7 = (int)floor(100.00*hcc[i]) * 256 + (int)floor(100.00*lcc[i]);
						regF3 = cs[i];
					}
					// Interpolation
					else if (freq[i] < targetFreq * 100 / 100 && freq[i + 1] > targetFreq * 100 / 100) {
						//printf("freq[i]: %f, targetFreq: %f, freq[i+1]: %f \n", freq[i], targetFreq, freq[i + 1]);
						// Calculate target Setpoint using interpolation
						regF3 = round((cs[i + 1] - cs[i]) / (freq[i + 1] - freq[i])*(targetFreq - freq[i]) + cs[i]);
						// Calculate Higher Current Correction and Lower Current Correction using interpolation.
						hccTmp = (hcc[i + 1] - hcc[i]) / (freq[i + 1] - freq[i])*(targetFreq - freq[i]) + hcc[i];
						lccTmp = (lcc[i + 1] - lcc[i]) / (freq[i + 1] - freq[i])*(targetFreq - freq[i]) + lcc[i];
						regE7 = (int)floor(100.00*hccTmp) * 256 + (int)floor(100.00*lccTmp);
					}
				}
			}
			// 186.35 31.03 55.394 64.546 17.0 27.07 1110 1000
			switch (serialNum) {
			case 0:
				strncpy(filename, "input2/CRTNJ5W06P_1000.map", 100);
				break;
			case 1:
				strncpy(filename, "input2/CRTNCAJ02E_1000.map", 100);
				break;
			}
			sizeMap = countlines(filename) + 1;
			fp = fopen(filename, "r");
			i = 0;



			while (!feof(fp)) {
				if (serialNum == 0) {
					fscanf(fp, "%lf %lf %lf %lf %lf %lf %d %d %d", &freqMap[i], &sled[i], &f1[i], &f2[i], &f1p, &f2p, &current, &powerMap[i], &ambient);
					printf("%lf %lf %lf %lf %lf %lf %d %d %d\n", freqMap[i], sled[i], f1[i], f2[i], f1p, f2p, current, powerMap[i], ambient);
				} else {
					fscanf(fp, "%lf %lf %lf %lf %lf %lf %d %d %d", &freqMap[i], &sled[i], &f1[i], &f2[i], &f1p, &f2p, &current, &powerMap[i], &ambient);
					printf("%lf %lf %lf %lf %lf %lf %d %d %d\n", freqMap[i], sled[i], f1[i], f2[i], f1p, f2p, current, powerMap[i], ambient);
				}
				i++;
			}
			fclose(fp);
			// look for target frequency and power for scanning
			for (i = 0; i < sizeMap; i++) {
				// Target frequency is in the map file
				if (freqMap[i] == targetFreq * 100 / 100) {
					//printf("freqMap: %f powerMap: %d \n", freqMap[i], powerMap[i]);
					regF0 = sled[i] * 1000;
					regF1 = (int)floorf((f1[i] - 50.00)*1000.00);
					regF2 = (int)floorf((f2[i] - 50.00)*1000.00);
				}
				// Interpolation or extrapolation
				else if (freqMap[i] < targetFreq * 100 / 100 && freqMap[i + 1] > targetFreq * 100 / 100) {
					//printf("freq[i]: %f, targetFreq: %f, freq[i+1]: %f \n", freqMap[i], targetFreq, freqMap[i + 1]);
					indexLow = i;
					indexHigh = i + 1;
					// Interpolation
					if ((f1[indexHigh] < f1[indexLow] && f2[indexHigh] < f2[indexLow])) {
						f1Tmp = (f1[indexHigh] - f1[indexLow]) / (freqMap[indexHigh] - freqMap[indexLow])*(targetFreq - freqMap[indexLow]) + f1[indexLow];
						f2Tmp = (f2[indexHigh] - f2[indexLow]) / (freqMap[indexHigh] - freqMap[indexLow])*(targetFreq - freqMap[indexLow]) + f2[indexLow];
						regF1 = (int)floorf((f1Tmp - 50.00)*1000.00);
						regF2 = (int)floorf((f2Tmp - 50.00)*1000.00);
						F1_Index = indexHigh; //For sled calculation
						F2_Index = indexLow;
					}
					else {
						// Calculate high extrapolation of F1 and F2
						j = 1;
						while (f1[indexHigh + j] > f1[indexHigh + j - 1] || f2[indexHigh + j] > f2[indexHigh + j - 1]) {
							j++;
						}
						f1High = (f1[indexHigh + j] - f1[indexHigh + j - 1]) / (freqMap[indexHigh + j] - freqMap[indexHigh + j - 1])*(targetFreq - freqMap[indexHigh]) + f1[indexHigh];
						f2High = (f2[indexHigh + j] - f2[indexHigh + j - 1]) / (freqMap[indexHigh + j] - freqMap[indexHigh + j - 1])*(targetFreq - freqMap[indexHigh]) + f2[indexHigh];
						SLED_Index_High = indexHigh + j - 1;

						// Calculate low extrapolation of F1 and F2
						j = 1;
						while (f1[indexLow - j + 1] > f1[indexLow - j] || f2[indexLow - j + 1] > f2[indexLow - j]) {
							j++;
						}
						f1Low = (f1[j + 1] - f1[j]) / (freqMap[j + 1] - freqMap[j])*(targetFreq - freqMap[j]) + f1[j];
						f1Low = ((f1[indexLow - j + 1] - f1[indexLow - j]) / (freq[indexLow - j + 1] - freq[indexLow - j]))*(targetFreq - freq[indexLow]) + f1[indexLow];
						f2Low = ((f2[indexLow - j + 1] - f2[indexLow - j]) / (freq[indexLow - j + 1] - freq[indexLow - j]))*(targetFreq - freq[indexLow]) + f2[indexLow];
						SLED_Index_Low = indexLow - j + 1;						

						// Use the value of F1 closest to 69
						if (abs(f1High - 69) < abs(f1Low - 69)) {
							regF1 = (int)floorf((f1High - 50.00)*1000.00);
							F1_Index = SLED_Index_High;
						}
						else {
							regF1 = (int)floorf((f1Low - 50.00)*1000.00);
							F1_Index = SLED_Index_Low;
						}

						//Use the value of F2 closest to 69
						if (abs(f2High - 69) < abs(f2Low - 69)) {
							regF2 = (int)floorf((f2High - 50.00)*1000.00);
							F2_Index = SLED_Index_High;
						}
						else if (abs(f2High - 69) > abs(f2Low - 69)) {
							regF2 = (int)floorf((f2Low - 50.00)*1000.00);
							F2_Index = SLED_Index_Low;
						}
					}

					// Calculate SLED. Extrapolate using the closest setpoint used to calculate F1 & F2
					if (abs(freqMap[F1_Index] - targetFreq) < abs(freqMap[F2_Index] - targetFreq)) {     //Use closer point if different
						sledTmp = (sledSlope * (targetFreq - freqMap[F1_Index])) + sled[F1_Index];
						//sledTmp = sledSlope * 1000*(targetFreq - freqMap[F1_Index]) + sled[F1_Index];
					}
					else {
						sledTmp = (sledSlope * (targetFreq - freqMap[F2_Index])) + sled[F2_Index];
						//sledTmp = sledSlope * 1000*(targetFreq - freqMap[F2_Index]) + sled[F2_Index];
					}
					regF0 = sledTmp * 1000;
				}
			}
			//printf("F0: %d F1: %d F2: %d E7: %d F3: %d\n", regF0, regF1, regF2, regE7, regF3);
			textBox_F0->Text = regF0.ToString();
			textBox_F0->Update();
			textBox_F1->Text = regF1.ToString();
			textBox_F1->Update();
			textBox_F2->Text = regF2.ToString();
			textBox_F2->Update();
			textBox_E7->Text = regE7.ToString();
			textBox_E7->Update();
			textBox_F3->Text = regF3.ToString();
			textBox_F3->Update();
		}

		private: System::Void button_su_Click(System::Object^  sender, System::EventArgs^  e) {

			String^ SysTmp1 = "";
			String^ SysTmp2 = "";
			String^ SysTmp3 = "";
			String^ SysTmp4 = "";
			String^ SysTmp5 = "";
			String^ SysTmp6 = "";

			SysTmp1 = ITLAshow(0x42, 0, 0, comportNum);											//Current power
			SysTmp2 = ITLAshow(0x41, 0, 0, comportNum);
			SysTmp3 = ITLAshow(0x40, 0, 0, comportNum);
			SysTmp4 = ITLAshow(0x43, 0, 0, comportNum);											//Current Temp
			SysTmp5 = ITLAshow(0x57, 0, 0, comportNum);
			SysTmp6 = ITLAshow(0x62, 0, 0, comportNum);											//MHz
		


			textBox_cpw->Text = "";
			textBox_cf->Text = "";
			textBox_cw->Text = "";
			textBox_ct->Text = "";


			
			if (Convert::ToInt32(SysTmp1->Substring(4, 4), 16)*0.01 > 100)
			{
				textBox_cpw->AppendText("Laser Off");
			}
			else
			{
				textBox_cpw->AppendText((Convert::ToInt32(SysTmp1->Substring(4, 4), 16)*0.01).ToString());
			}

			


			textBox_cf->AppendText(((Convert::ToInt32(SysTmp2->Substring(4, 4), 16)*0.0001) + Convert::ToInt32(SysTmp3->Substring(4, 4), 16)).ToString());
			textBox_cw->AppendText(Round_off(ThzToNm(((Convert::ToInt32(SysTmp2->Substring(4, 4), 16)*0.0001) + Convert::ToInt32(SysTmp3->Substring(4, 4), 16))),8).ToString());
			textBox_ct->AppendText((Convert::ToInt32(SysTmp4->Substring(4, 4), 16)*0.01).ToString());
			

			DateTime datetime = DateTime::Now;
			this->label_status->Text = "Last Updated : " + datetime.ToString();


		}


		/*Thread for realtime status reading*/
		private: System::Void backgroundWorker1_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
			
			
			string stdStr = "";
			String^ SysTmp = "";
			String^ SysTmp1 = "";
			String^ SysTmp2 = "";
			String^ SysTmp3 = "";
			String^ SysTmp4 = "";
			String^ SysTmp5 = "";
			int i = 0;

			

			for (i = 0; e->Cancel == false ; i++)
			{

				CheckForIllegalCrossThreadCalls = false;
				label_status->Text = "Real time reading processing.....";
				
				SysTmp1 = ITLAshow(0x42, 0, 0, comportNum);											//Current power
				SysTmp2 = ITLAshow(0x41, 0, 0, comportNum);
				SysTmp3 = ITLAshow(0x40, 0, 0, comportNum);
				SysTmp4 = ITLAshow(0x43, 0, 0, comportNum);											//Current Temp
				SysTmp5 = ITLAshow(0x57, 0, 0, comportNum);



				textBox_cpw->Text = "";
				textBox_cf->Text = "";

				textBox_cw->Text = "";
				textBox_ct->Text = "";



				if (Convert::ToInt32(SysTmp1->Substring(4, 4), 16)*0.01 > 100)
				{
					textBox_cpw->AppendText("Laser Off");
				}
				else
				{
					textBox_cpw->AppendText((Convert::ToInt32(SysTmp1->Substring(4, 4), 16)*0.01).ToString());
				}
				textBox_cf->AppendText(((Convert::ToInt32(SysTmp2->Substring(4, 4), 16)*0.0001) + Convert::ToInt32(SysTmp3->Substring(4, 4), 16)).ToString());
				textBox_cw->AppendText(Round_off(ThzToNm(((Convert::ToInt32(SysTmp2->Substring(4, 4), 16)*0.0001) + Convert::ToInt32(SysTmp3->Substring(4, 4), 16))), 8).ToString());
				textBox_ct->AppendText((Convert::ToInt32(SysTmp4->Substring(4, 4), 16)*0.01).ToString());


				Delay_ms(1000);

				if (backgroundWorker1->CancellationPending)
				{
					e->Cancel = true;

					return;
				}
			}

			

			//e.Result

		}
		private: System::Void backgroundWorker1_ProgressChanged(System::Object^  sender, System::ComponentModel::ProgressChangedEventArgs^  e) {
		}
		private: System::Void backgroundWorker1_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e) {

			string stdStr = "";
			String^ SysTmp = "";
			String^ SysTmp1 = "";
			String^ SysTmp2 = "";
			String^ SysTmp3 = "";
			String^ SysTmp4 = "";
			String^ SysTmp5 = "";

			if (e->Cancelled)
			{
				SysTmp1 = ITLAshow(0x42, 0, 0, comportNum);											//Current power
				SysTmp2 = ITLAshow(0x41, 0, 0, comportNum);
				SysTmp3 = ITLAshow(0x40, 0, 0, comportNum);
				SysTmp4 = ITLAshow(0x43, 0, 0, comportNum);											//Current Temp
				SysTmp5 = ITLAshow(0x57, 0, 0, comportNum);



				textBox_cpw->Text = "";
				textBox_cf->Text = "";

				textBox_cw->Text = "";
				textBox_ct->Text = "";



				if (Convert::ToInt32(SysTmp1->Substring(4, 4), 16)*0.01 > 100)
				{
					textBox_cpw->AppendText("Laser Off");
				}
				else
				{
					textBox_cpw->AppendText((Convert::ToInt32(SysTmp1->Substring(4, 4), 16)*0.01).ToString());
				}
				textBox_cf->AppendText(((Convert::ToInt32(SysTmp2->Substring(4, 4), 16)*0.0001) + Convert::ToInt32(SysTmp3->Substring(4, 4), 16)).ToString());
				textBox_cw->AppendText(Round_off(ThzToNm(((Convert::ToInt32(SysTmp2->Substring(4, 4), 16)*0.0001) + Convert::ToInt32(SysTmp3->Substring(4, 4), 16))), 8).ToString());
				textBox_ct->AppendText((Convert::ToInt32(SysTmp4->Substring(4, 4), 16)*0.01).ToString());


				label_status->Text = "Real time reading cancelled!";
			}
			else
			{
				int i = 0;
				for (i = 0; ; i++)
				{

					CheckForIllegalCrossThreadCalls = false;

					SysTmp1 = ITLAshow(0x42, 0, 0, comportNum);											//Current power
					SysTmp2 = ITLAshow(0x41, 0, 0, comportNum);
					SysTmp3 = ITLAshow(0x40, 0, 0, comportNum);
					SysTmp4 = ITLAshow(0x43, 0, 0, comportNum);											//Current Temp
					SysTmp5 = ITLAshow(0x57, 0, 0, comportNum);



					textBox_cpw->Text = "";
					textBox_cf->Text = "";

					textBox_cw->Text = "";
					textBox_ct->Text = "";



					if (Convert::ToInt32(SysTmp1->Substring(4, 4), 16)*0.01 > 100)
					{
						textBox_cpw->AppendText("Laser Off");
					}
					else
					{
						textBox_cpw->AppendText((Convert::ToInt32(SysTmp1->Substring(4, 4), 16)*0.01).ToString());
					}
					textBox_cf->AppendText(((Convert::ToInt32(SysTmp2->Substring(4, 4), 16)*0.0001) + Convert::ToInt32(SysTmp3->Substring(4, 4), 16)).ToString());
					textBox_cw->AppendText(Round_off(ThzToNm(((Convert::ToInt32(SysTmp2->Substring(4, 4), 16)*0.0001) + Convert::ToInt32(SysTmp3->Substring(4, 4), 16))), 8).ToString());
					textBox_ct->AppendText((Convert::ToInt32(SysTmp4->Substring(4, 4), 16)*0.01).ToString());


					Delay_ms(1000);
					//backgroundWorker1->ReportProgress(i);
				}
			}
			


		}

		private: System::Void button_rt_Click(System::Object^  sender, System::EventArgs^  e) { //Real time function

			realTime = !realTime;

			if (realTime) {
				if (!backgroundWorker1->IsBusy)
				{
					backgroundWorker1->RunWorkerAsync();
					
				}
				button_rt->Text = "Stop";	
				
			}
			else {

				if (backgroundWorker1->IsBusy)
				{
					backgroundWorker1->CancelAsync();
					
				}
				button_rt->Text = "Real Time";
				
			}
			
						
		}

		private: System::Void button2_Click_1(System::Object^  sender, System::EventArgs^  e) {
			String^ SysTmp = "";
			unsigned char* temp = NULL;
			int data = 0;

			LowNoise = !LowNoise;

			if (LowNoise) {
				data = 2;
				button_lnm->Text = "OFF";
			}
			else {
				data = 0;
				button_lnm->Text = "ON";
			}

			SysTmp = ITLAshow(0x90, data, 1, comportNum);

			

		}

		private: System::Void button_ditherEn_Click(System::Object^  sender, System::EventArgs^  e) {
			String^ SysTmp = "";
			int data = 0;
			unsigned char* temp = NULL;

			dither = !dither;

			if (dither) {
				data = 2;
				button_ditherEn->Text = "OFF";
			}
			else {
				data = 0;
				button_ditherEn->Text = "ON";
			}

			
			SysTmp = ITLAshow(0x59, data, 1, comportNum);

		}

		private: System::Void button_ditherSet_Click(System::Object^  sender, System::EventArgs^  e) {
			String^ SysTmp = "";
			unsigned char* temp = NULL;

			double data = Convert::ToDouble(textBox_dither->Text);
			
			SysTmp = ITLAshow(0x5B, data, 1, comportNum);
			

		}

private: System::Void button_ok_Click(System::Object^  sender, System::EventArgs^  e) { //Status update



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
private: System::Void richTextBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	if (richTextBox1->Visible)
	{
		richTextBox1->SelectionStart = richTextBox1->TextLength;
		richTextBox1->ScrollToCaret();
	}
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
	double w = Convert::ToDouble(textBox_cw->Text);	

	double o = Convert::ToDouble(textBox_ct->Text);
	char currDate[30];
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	sprintf(currDate, "%d-%d-%d %d:%d:%d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);




	
	outData.open("DataLog.csv", ios::app);
	outData << "----------------------------------------" << endl;
	outData << "Power : " << p << " dBm" << endl;
	outData << "Frequency : " << f << " THz" << endl;
	outData << "Wavelength : " << w << " nm" << endl;
	outData << "Temperature : " << o << " C" << endl;
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
private: System::Void button_savedef_Click(System::Object^  sender, System::EventArgs^  e) {

	if (!backgroundWorker3->IsBusy)
	{
		backgroundWorker3->RunWorkerAsync();
	}
	else
	{
		MessageBox::Show("Processing, Please wait..", "Warning", MessageBoxButtons::OK);
	}


}
private: System::Void button2_Click_2(System::Object^  sender, System::EventArgs^  e) {						//Open up new window
	if (!backgroundWorker2->IsBusy)
	{
		backgroundWorker2->RunWorkerAsync();
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

/*Thread for Save default setting button*/
private: System::Void backgroundWorker3_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {

	String^ SysTmp = "";
		
	SysTmp = ITLAshow(50, 0, 1, comportNum);
	Delay_ms(3000);
	SysTmp = ITLAshow(0x08, 1, 1, comportNum);
	Delay_ms(3000);
	SysTmp = ITLAshow(50, 8, 1, comportNum);
}
private: System::Void backgroundWorker3_ProgressChanged(System::Object^  sender, System::ComponentModel::ProgressChangedEventArgs^  e) {
}
private: System::Void backgroundWorker3_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e) {
}
private: System::Void textBox_ct_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}

private: System::Void scan0926_Click(System::Object^  sender, System::EventArgs^  e) {
	richTextBox1->AppendText(gcnew System::String("Starting Scan Mode... \n"));
	if (!backgroundWorker4->IsBusy)
	{
		backgroundWorker4->RunWorkerAsync();
	}
	else
	{
		richTextBox1->AppendText("Scanning is already processing");
	}
	
}
private: System::Void label4_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label3_Click(System::Object^  sender, System::EventArgs^  e) {
}

/*Thread for Clean Scan (Developer Mode)*/
private: System::Void backgroundWorker4_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
	unsigned char* temp = NULL;
	string stdStr = "";
	String^ SysTmp = "";
	double data_thz, data_ghz, startFreq = 0.0, stopFreq = 0.0, targetFreq = 0.0;
	//double overlapFreq = Convert::ToInt32(textBox_Range->Text) / 10000.0;

	int scanRange = Convert::ToInt32(textBox_Range->Text);
	int counter = 0, i = 0, g1 = 0;
	double LFL = 0.0, LFH = 0.0, ff = 0.0, lf = 0.0;

	CheckForIllegalCrossThreadCalls = false;

	String^ SysTmp1 = "";
	String^ SysTmp2 = "";
	String^ SysTmp3 = "";
	String^ SysTmp4 = "";
	String^ SysTmp5 = "";

	SysTmp1 = ITLAshow(0x52, 0, 0, comportNum);					//THz first
	SysTmp2 = ITLAshow(0x53, 0, 0, comportNum);					//GHz first
	SysTmp3 = ITLAshow(0x54, 0, 0, comportNum);					//THz last
	SysTmp4 = ITLAshow(0x55, 0, 0, comportNum);					//GHz last

	ff = Convert::ToInt32(SysTmp1->Substring(4, 4), 16) + (Convert::ToInt32(SysTmp2->Substring(4, 4), 16)*0.0001);			//First Freq
	lf = Convert::ToInt32(SysTmp3->Substring(4, 4), 16) + (Convert::ToInt32(SysTmp4->Substring(4, 4), 16)*0.0001);			//Last Freq

	if (checkBox_Manual->Checked == true) {
		LFL = Convert::ToDouble(textBox_LFL->Text);
		LFH = Convert::ToDouble(textBox_LFH->Text);

		if (LFL >= ff && LFL <= lf) {											//Range Condition Check
			if (LFH >= ff && LFH <= lf) {
				goto ScanStart;												//If meets, start scan
			}
			else
			{
				MessageBox::Show("Following value is out of Frequency range!\n[Stop Frequency]\nPlease check 'General' tab and enter valid power", "Warning", MessageBoxButtons::OK);
			}

		}
		else
		{
			MessageBox::Show("Following value is out of Frequency range!\n[Start Frequency]\nPlease check 'General' tab and enter valid power", "Warning", MessageBoxButtons::OK);
		}

	}
	else {
		textBox_LFL->Text = ff.ToString();
		textBox_LFL->Update();
		LFL = Convert::ToDouble(textBox_LFL->Text);			// Convert to double

		textBox_LFH->Text = lf.ToString();
		textBox_LFH->Update();
		LFH = Convert::ToDouble(textBox_LFH->Text);			// Convert to double

	}

ScanStart:
	
	startFreq = LFL + scanRange / 2000.0;	// Get the start center frequncy from LFL, LFL + ScanRagne(GHz)/2
	textBox_Freq->Update();
	textBox_Freq->Text = startFreq.ToString();
	textBox_Freq->Update();
	targetFreq = Convert::ToDouble(textBox_Freq->Text);
	stopFreq = LFH;



	int a = 0;



		double freq1 = targetFreq;
		data_thz = (int)freq1;
		g1 = (freq1 - data_thz) * 10000;						//GHz decimal conversion
		data_ghz = (int)g1;

		button_Get->PerformClick();

		ITLAshow(0xF0, Convert::ToInt32(textBox_F0->Text) + 2000, 1, comportNum);			//Set sled base temperature : 2 degree above the target temp

		ITLAshow(0xE5, 1, 1, comportNum);													//Change sled base temp

		ITLAshow(0xE7, Convert::ToInt32(textBox_E7->Text), 1, comportNum);					//Set current adjust value for 1st point

		ITLAshow(0x35, data_thz, 1, comportNum);												//THz register

		ITLAshow(0x36, data_ghz, 1, comportNum);												//GHz register

		ITLAshow(0xE4, scanRange, 1, comportNum);											//Set scan range

		ITLAshow(0x31, 1000, 1, comportNum);													//Set power level : 10dBm fixed for now

		ITLAshow(0x30, 1, 1, comportNum);													//Set ch to 1



		ITLAshow(0x32, 8, 1, comportNum);													//Turn on laser

		SysTmp = ITLAshow(0x00, 0, 0, comportNum);		// Read from NOP
		sprintf(const_cast<char*>(stdStr.c_str()), "%2.2x%2.2x%2.2x%2.2x", SysTmp[0], SysTmp[1], SysTmp[2], SysTmp[3]);
		SysTmp = gcnew String(stdStr.c_str());

		while (SysTmp->CompareTo("10000010") != 0) {	// while the value read back from 0x00 is not 10000010, continue reading
			SysTmp = ITLAshow(0x00, 0, 0, comportNum);		// Read from NOP
			sprintf(const_cast<char*>(stdStr.c_str()), "%2.2x%2.2x%2.2x%2.2x", SysTmp[0], SysTmp[1], SysTmp[2], SysTmp[3]);
			//sprintf(const_cast<char*>(stdStr.c_str()), "%02x", temp[3]);
			SysTmp = gcnew String(stdStr.c_str());
			counter++;
			if (counter > 200) break;
		}

		ITLAshow(0x90, 1, 1, comportNum);													//Low noise mode on

		Delay_ms(500);																			// Delay 500ms

		SysTmp = ITLAshow(0xE5, 1, 1, comportNum);													//Turn on the Clean Scan
		if (backgroundWorker4->CancellationPending)
		{
			e->Cancel = true;
			richTextBox1->AppendText(gcnew System::String("Starting scan process finalization... \n"));
			ITLAshow(0xE5, 0, 1, comportNum);		// Stop Clean Scan
			ITLAshow(0x90, 0, 1, comportNum);		// Exit Low-noise mode
			ITLAshow(0x32, 0, 1, comportNum);		// Disable laser
			richTextBox1->AppendText(gcnew System::String("Scan process finalization finished... \n\n"));
			return;
		}

		

			while ((targetFreq < stopFreq)) {
				textBox_Freq->Text = targetFreq.ToString();
				textBox_Freq->Update();
				printf("S: %f E: %f %f %d\n", startFreq, stopFreq, targetFreq, counter);
				button_Get->PerformClick();
				//button_writeReg->PerformClick();
				//MessageBox::Show("Button_Get was clicked!!");
				Delay_ms(1000);

				if (targetFreq != startFreq) {
					// Check the value of 0xE5
					// Check if Clean Scan state & 0x0001 == 0; no : read from E5 and check again
					SysTmp5 = ITLAshow(0xE5, 0, 0, comportNum);						// Read from 0xE5, Clean Scan
																					//temp = ITLACommand(0xE5, 0, 0, comportNum);		
																					//sprintf(const_cast<char*>(stdStr.c_str()), "%02x", temp[3]);	// Take the last byte only
																					//SysTmp = gcnew String(stdStr.c_str());


																					// 
					while (Convert::ToInt32(SysTmp5->Substring(4, 4), 16) != 10) {												// while the last byte of read back value is not equal to 0A, it means that the ITLA is scanning and we need to continue reading
						SysTmp5 = ITLAshow(0xE5, 0, 0, comportNum);		// Read from 0xE5
						Delay_ms(500);

					}
					goto RegistWrite;																							//Send to next register value
				}
			RegistWrite:
				ITLAshow(0xF0, Convert::ToInt32(textBox_F0->Text), 1, comportNum);					//Set next sled Temp
				ITLAshow(0xF1, Convert::ToInt32(textBox_F1->Text), 1, comportNum);					//Set next f1 temp
				ITLAshow(0xF2, Convert::ToInt32(textBox_F2->Text), 1, comportNum);					//Set next f2 temp
				ITLAshow(0xE7, Convert::ToInt32(textBox_E7->Text), 1, comportNum);					//Set current adjust value
				ITLAshow(0xF3, Convert::ToInt32(textBox_F3->Text), 1, comportNum);					//Set central current

				targetFreq = targetFreq + scanRange / 1000.00;		// Increase targetFreq by scan range

				if (backgroundWorker4->CancellationPending)
				{
					e->Cancel = true;
					richTextBox1->AppendText(gcnew System::String("Starting scan process finalization... \n"));
					ITLAshow(0xE5, 0, 1, comportNum);		// Stop Clean Scan
					ITLAshow(0x90, 0, 1, comportNum);		// Exit Low-noise mode
					ITLAshow(0x32, 0, 1, comportNum);		// Disable laser
					richTextBox1->AppendText(gcnew System::String("Scan process finalization finished... \n\n"));
					return;
				}


			}
			if (backgroundWorker4->CancellationPending)
			{
				e->Cancel = true;
				richTextBox1->AppendText(gcnew System::String("Starting scan process finalization... \n"));
				ITLAshow(0xE5, 0, 1, comportNum);		// Stop Clean Scan
				ITLAshow(0x90, 0, 1, comportNum);		// Exit Low-noise mode
				ITLAshow(0x32, 0, 1, comportNum);		// Disable laser
				richTextBox1->AppendText(gcnew System::String("Scan process finalization finished... \n\n"));
				return;
			}

			richTextBox1->AppendText(gcnew System::String("Stopping Scan Mode... \n"));
			// Delay .5 seconds after the target frequency is greater than stop frequency, start finalizing process
			if (targetFreq > stopFreq) {
				Delay_ms(500);
				richTextBox1->AppendText(gcnew System::String("Scanning Last Frequency \n"));
				ITLAshow(0xE5, 0, 1, comportNum);		// Stop Clean Scan
				ITLAshow(0x90, 0, 1, comportNum);		// Exit Low-noise mode
				ITLAshow(0x32, 0, 1, comportNum);		// Disable laser
				richTextBox1->AppendText(gcnew System::String("Scan process completed \n\n"));
			}
		
		
		
}
private: System::Void backgroundWorker4_ProgressChanged(System::Object^  sender, System::ComponentModel::ProgressChangedEventArgs^  e) {
}
private: System::Void backgroundWorker4_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e) {
	if (e->Cancelled)
	{
		button_Final->PerformClick();
	}
}
private: System::Void label14_Click(System::Object^  sender, System::EventArgs^  e) {
}

private: System::Void comboBox1_SelectedIndexChanged_1(System::Object^  sender, System::EventArgs^  e) {
}




		 /*Thread for Clean Scan (User Mode)*/
private: System::Void backgroundWorker5_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {

	CheckForIllegalCrossThreadCalls = false;
	
	
	unsigned char* temp = NULL;
	char filename[100] = "";
	string stdStr = "";
	String^ SysTmp = "";
	double data_thz, data_ghz, startFreq = 0.0, stopFreq = 0.0, targetFreq = 0.0;
	//double overlapFreq = Convert::ToInt32(textBox_sweepRange_user->Text) / 10000.0;
	FILE *fp;
	int scanRange = Convert::ToInt32(textBox_sweepRange_user->Text);
	int size, sizeMap, counter = 0, i = 0, g1 = 0;
	int serialNum = 0;
	double LFL = 0.0, LFH = 0.0, ff = 0.0, lf = 0.0;
	int power[REGSIZE], cs[REGSIZE];
	int targetPower = Convert::ToInt32(comboBox_power_user->Text)*100;
	double freq[REGSIZE], lcc[REGSIZE], hcc[REGSIZE], lccTmp = 0.0, hccTmp = 0.0;
	int regF0 = 0, regF1 = 0, regF2 = 0, regF3 = 0, regE7 = 0;
	int powerMap[REGSIZE], current = 0, ambient = 0;
	double freqMap[REGSIZE], sled[REGSIZE], f1[REGSIZE], f2[REGSIZE];
	double f1p = 0.0, f2p = 0.0, f1High = 0.0, f2High = 0.0, f1Low = 0.0, f2Low = 0.0, f1Tmp = 0.0, f2Tmp = 0.0, sledTmp = 0.0;
	int indexHigh = 0, indexLow = 0;
	String^ SysTmp7 = "";
	SysTmp7 = ITLAshow(0xE8, 0, 0, comportNum);
	int sledSlopeRead = Convert::ToInt32(SysTmp7->Substring(4, 4), 16);
	double sledSlope = -1 * (sledSlopeRead / 10000);
	//double sledSlope = -0.245;		// read from 0xE8/10,000
	int F1_Index = 0, F2_Index = 0;
	int SLED_Index_Low = 0, SLED_Index_High = 0;



	

	String^ SysTmp1 = "";
	String^ SysTmp2 = "";
	String^ SysTmp3 = "";
	String^ SysTmp4 = "";
	String^ SysTmp5 = "";

	SysTmp1 = ITLAshow(0x52, 0, 0, comportNum);					//THz first
	SysTmp2 = ITLAshow(0x53, 0, 0, comportNum);					//GHz first
	SysTmp3 = ITLAshow(0x54, 0, 0, comportNum);					//THz last
	SysTmp4 = ITLAshow(0x55, 0, 0, comportNum);					//GHz last

	ff = Convert::ToInt32(SysTmp1->Substring(4, 4), 16) + (Convert::ToInt32(SysTmp2->Substring(4, 4), 16)*0.0001);			//First Freq
	lf = Convert::ToInt32(SysTmp3->Substring(4, 4), 16) + (Convert::ToInt32(SysTmp4->Substring(4, 4), 16)*0.0001);			//Last Freq

	if (checkBox_scan_user->Checked == true) {

		textBox_LFL_user->Text = ff.ToString();
		textBox_LFL_user->Update();
		LFL = Convert::ToDouble(textBox_LFL_user->Text);			// Convert to double

		textBox_LFH_user->Text = lf.ToString();
		textBox_LFH_user->Update();
		LFH = Convert::ToDouble(textBox_LFH_user->Text);			// Convert to double

	}
	else {
		LFL = Convert::ToDouble(textBox_LFL_user->Text);
		LFH = Convert::ToDouble(textBox_LFH_user->Text);

		if (LFL >= ff && LFL <= lf) {											//Range Condition Check
			if (LFH >= ff && LFH <= lf) {
				goto ScanStart_user;												//If meets, start scan
			}
			else
			{
				MessageBox::Show("Following value is out of Frequency range!\n[Stop Frequency]\nPlease check 'General' tab and enter valid power", "Warning", MessageBoxButtons::OK);
				richTextBox2->AppendText("Scan Mode Stopped");
				return;
			}

		}
		else
		{
			MessageBox::Show("Following value is out of Frequency range!\n[Start Frequency]\nPlease check 'General' tab and enter valid power", "Warning", MessageBoxButtons::OK);
			richTextBox2->AppendText("Scan Mode Stopped");
			return;
		}
	}

ScanStart_user:

	startFreq = LFL + scanRange / 2000.0;	// Get the start center frequncy from LFL, LFL + ScanRagne(GHz)/2
	textBox_fuser->Update();
	textBox_fuser->Text = startFreq.ToString();
	textBox_fuser->Update();
	targetFreq = Convert::ToDouble(textBox_fuser->Text);
	stopFreq = LFH;



	int a = 0;

	
		double freq1 = targetFreq;
		data_thz = (int)freq1;
		g1 = (freq1 - data_thz) * 10000;						//GHz decimal conversion
		data_ghz = (int)g1;









		/*---------------------------------------------------Registration Value calculation-----------------------------------------------------------*/
		serialNum = comboBox_ScanSerial_user->SelectedIndex;
		switch (serialNum) {
		case 0:
			strncpy(filename, "input2/CRTNJ5W06P.current2", 100);
			break;
		case 1:
			strncpy(filename, "input2/CRTNCAJ02E.current2", 100);
			break;
		}

		size = countlines(filename) + 1;
		fp = fopen(filename, "r");

		while (!feof(fp)) {
			fscanf(fp, "%lf %d %lf %lf %d", &freq[i], &power[i], &lcc[i], &hcc[i], &cs[i]);
			printf("%lf %d %lf %lf %d\n", freq[i], power[i], lcc[i], hcc[i], cs[i]);
			i++;
		}



		/*while (file_ >> freq[i] >> power[i] >> lcc[i] >> hcc[i] >> cs[i]) {
		//fscanf(fp, "%lf %d %lf %lf %d", &freq[i], &power[i], &lcc[i], &hcc[i], &cs[i]);
		printf("%lf %d %lf %lf %d\n", freq[i], power[i], lcc[i], hcc[i], cs[i]);
		i++;
		}*/

		fclose(fp);
		// look for target frequency and power for scanning
		for (i = 0; i < countlines(filename) + 1; i++) {
			if (power[i] == targetPower) {
				// Target frequency is in the current2 file
				if (freq[i] == targetFreq * 100 / 100) {
					//printf("freq: %f powerMap: %d \n", freq[i], power[i]);
					//targetIndex = i;
					regE7 = (int)floor(100.00*hcc[i]) * 256 + (int)floor(100.00*lcc[i]);
					regF3 = cs[i];
				}
				// Interpolation
				else if (freq[i] < targetFreq * 100 / 100 && freq[i + 1] > targetFreq * 100 / 100) {
					//printf("freq[i]: %f, targetFreq: %f, freq[i+1]: %f \n", freq[i], targetFreq, freq[i + 1]);
					// Calculate target Setpoint using interpolation
					regF3 = round((cs[i + 1] - cs[i]) / (freq[i + 1] - freq[i])*(targetFreq - freq[i]) + cs[i]);
					// Calculate Higher Current Correction and Lower Current Correction using interpolation.
					hccTmp = (hcc[i + 1] - hcc[i]) / (freq[i + 1] - freq[i])*(targetFreq - freq[i]) + hcc[i];
					lccTmp = (lcc[i + 1] - lcc[i]) / (freq[i + 1] - freq[i])*(targetFreq - freq[i]) + lcc[i];
					regE7 = (int)floor(100.00*hccTmp) * 256 + (int)floor(100.00*lccTmp);
				}
			}
		}
		// 186.35 31.03 55.394 64.546 17.0 27.07 1110 1000
		switch (serialNum) {
		case 0:
			strncpy(filename, "input2/CRTNJ5W06P_1000.map", 100);
			break;
		case 1:
			strncpy(filename, "input2/CRTNCAJ02E_1000.map", 100);
			break;
		}
		sizeMap = countlines(filename) + 1;
		fp = fopen(filename, "r");
		i = 0;

		/*ifstream file_1("input2/CRTNJ5W06P_1000.txt");

		while (file_1 >> freqMap[i] >> sled[i] >> f1[i] >> f2[i] >> f1p >> f2p >> current >> powerMap[i] >> ambient) {
		//fscanf(fp, "%lf %d %lf %lf %d", &freq[i], &power[i], &lcc[i], &hcc[i], &cs[i]);
		printf("%lf %lf %lf %lf %lf %lf %d %d %d\n", freqMap[i], sled[i], f1[i], f2[i], f1p, f2p, current, powerMap[i], ambient);
		i++;
		}*/

		while (!feof(fp)) {
			if (serialNum == 0) {
				fscanf(fp, "%lf %lf %lf %lf %lf %lf %d %d %d", &freqMap[i], &sled[i], &f1[i], &f2[i], &f1p, &f2p, &current, &powerMap[i], &ambient);
				printf("%lf %lf %lf %lf %lf %lf %d %d %d\n", freqMap[i], sled[i], f1[i], f2[i], f1p, f2p, current, powerMap[i], ambient);
			}
			else {
				fscanf(fp, "%lf %lf %lf %lf %lf %lf %d %d %d", &freqMap[i], &sled[i], &f1[i], &f2[i], &f1p, &f2p, &current, &powerMap[i], &ambient);
				printf("%lf %lf %lf %lf %lf %lf %d %d %d\n", freqMap[i], sled[i], f1[i], f2[i], f1p, f2p, current, powerMap[i], ambient);
			}
			i++;
		}
		fclose(fp);
		// look for target frequency and power for scanning
		for (i = 0; i < sizeMap; i++) {
			// Target frequency is in the map file
			if (freqMap[i] == targetFreq * 100 / 100) {
				//printf("freqMap: %f powerMap: %d \n", freqMap[i], powerMap[i]);
				regF0 = sled[i] * 1000;
				regF1 = (int)floorf((f1[i] - 50.00)*1000.00);
				regF2 = (int)floorf((f2[i] - 50.00)*1000.00);
			}
			// Interpolation or extrapolation
			else if (freqMap[i] < targetFreq * 100 / 100 && freqMap[i + 1] > targetFreq * 100 / 100) {
				//printf("freq[i]: %f, targetFreq: %f, freq[i+1]: %f \n", freqMap[i], targetFreq, freqMap[i + 1]);
				indexLow = i;
				indexHigh = i + 1;
				// Interpolation
				if ((f1[indexHigh] < f1[indexLow] && f2[indexHigh] < f2[indexLow])) {
					f1Tmp = (f1[indexHigh] - f1[indexLow]) / (freqMap[indexHigh] - freqMap[indexLow])*(targetFreq - freqMap[indexLow]) + f1[indexLow];
					f2Tmp = (f2[indexHigh] - f2[indexLow]) / (freqMap[indexHigh] - freqMap[indexLow])*(targetFreq - freqMap[indexLow]) + f2[indexLow];
					regF1 = (int)floorf((f1Tmp - 50.00)*1000.00);
					regF2 = (int)floorf((f2Tmp - 50.00)*1000.00);
					F1_Index = indexHigh; //For sled calculation
					F2_Index = indexLow;
				}
				else {
					// Calculate high extrapolation of F1 and F2
					int j = 1;
					while (f1[indexHigh + j] > f1[indexHigh + j - 1] || f2[indexHigh + j] > f2[indexHigh + j - 1]) {
						j++;
					}
					f1High = (f1[indexHigh + j] - f1[indexHigh + j - 1]) / (freqMap[indexHigh + j] - freqMap[indexHigh + j - 1])*(targetFreq - freqMap[indexHigh]) + f1[indexHigh];
					f2High = (f2[indexHigh + j] - f2[indexHigh + j - 1]) / (freqMap[indexHigh + j] - freqMap[indexHigh + j - 1])*(targetFreq - freqMap[indexHigh]) + f2[indexHigh];
					SLED_Index_High = indexHigh + j - 1;

					// Calculate low extrapolation of F1 and F2
					j = 1;
					while (f1[indexLow - j + 1] > f1[indexLow - j] || f2[indexLow - j + 1] > f2[indexLow - j]) {
						j++;
					}
					f1Low = (f1[j + 1] - f1[j]) / (freqMap[j + 1] - freqMap[j])*(targetFreq - freqMap[j]) + f1[j];
					f1Low = ((f1[indexLow - j + 1] - f1[indexLow - j]) / (freq[indexLow - j + 1] - freq[indexLow - j]))*(targetFreq - freq[indexLow]) + f1[indexLow];
					f2Low = ((f2[indexLow - j + 1] - f2[indexLow - j]) / (freq[indexLow - j + 1] - freq[indexLow - j]))*(targetFreq - freq[indexLow]) + f2[indexLow];
					SLED_Index_Low = indexLow - j + 1;

					// Use the value of F1 closest to 69
					if (abs(f1High - 69) < abs(f1Low - 69)) {
						regF1 = (int)floorf((f1High - 50.00)*1000.00);
						F1_Index = SLED_Index_High;
					}
					else {
						regF1 = (int)floorf((f1Low - 50.00)*1000.00);
						F1_Index = SLED_Index_Low;
					}

					//Use the value of F2 closest to 69
					if (abs(f2High - 69) < abs(f2Low - 69)) {
						regF2 = (int)floorf((f2High - 50.00)*1000.00);
						F2_Index = SLED_Index_High;
					}
					else if (abs(f2High - 69) > abs(f2Low - 69)) {
						regF2 = (int)floorf((f2Low - 50.00)*1000.00);
						F2_Index = SLED_Index_Low;
					}
				}

				// Calculate SLED. Extrapolate using the closest setpoint used to calculate F1 & F2
				if (abs(freqMap[F1_Index] - targetFreq) < abs(freqMap[F2_Index] - targetFreq)) {     //Use closer point if different
					sledTmp = (sledSlope * (targetFreq - freqMap[F1_Index])) + sled[F1_Index];
					//sledTmp = sledSlope * 1000*(targetFreq - freqMap[F1_Index]) + sled[F1_Index];
				}
				else {
					sledTmp = (sledSlope * (targetFreq - freqMap[F2_Index])) + sled[F2_Index];
					//sledTmp = sledSlope * 1000*(targetFreq - freqMap[F2_Index]) + sled[F2_Index];
				}
				regF0 = sledTmp * 1000;
			}
		}


		/*--------------------------------------------------------------------------------------------------------------------------------------------------*/







		ITLAshow(0xF0, regF0 + 2000, 1, comportNum);			//Set sled base temperature : 2 degree above the target temp

		ITLAshow(0xE5, 1, 1, comportNum);													//Change sled base temp

		ITLAshow(0xE7, regE7, 1, comportNum);					//Set current adjust value for 1st point

		ITLAshow(0x35, data_thz, 1, comportNum);												//THz register

		ITLAshow(0x36, data_ghz, 1, comportNum);												//GHz register

		ITLAshow(0xE4, scanRange, 1, comportNum);											//Set scan range

		ITLAshow(0x31, targetPower, 1, comportNum);													//Set power level : 10dBm fixed for now

		ITLAshow(0x30, 1, 1, comportNum);													//Set ch to 1



		ITLAshow(0x32, 8, 1, comportNum);													//Turn on laser

		SysTmp = ITLAshow(0x00, 0, 0, comportNum);		// Read from NOP
		sprintf(const_cast<char*>(stdStr.c_str()), "%2.2x%2.2x%2.2x%2.2x", SysTmp[0], SysTmp[1], SysTmp[2], SysTmp[3]);
		SysTmp = gcnew String(stdStr.c_str());

		while (SysTmp->CompareTo("10000010") != 0) {	// while the value read back from 0x00 is not 10000010, continue reading
			SysTmp = ITLAshow(0x00, 0, 0, comportNum);		// Read from NOP
			sprintf(const_cast<char*>(stdStr.c_str()), "%2.2x%2.2x%2.2x%2.2x", SysTmp[0], SysTmp[1], SysTmp[2], SysTmp[3]);
			//sprintf(const_cast<char*>(stdStr.c_str()), "%02x", temp[3]);
			SysTmp = gcnew String(stdStr.c_str());
			counter++;
			if (counter > 200) break;
		}

		ITLAshow(0x90, 1, 1, comportNum);													//Low noise mode on

		Delay_ms(500);																			// Delay 500ms

		SysTmp = ITLAshow(0xE5, 1, 1, comportNum);													//Turn on the Clean Scan

		/*----------------------------------------------------------Cancel pending before go into loop-------------------------------------------------------------*/
		if (backgroundWorker5->CancellationPending)
		{
			e->Cancel = true;
			richTextBox2->AppendText(gcnew System::String("Canceling Scan process..."));
			ITLAshow(0xE5, 0, 1, comportNum);		// Stop Clean Scan
			ITLAshow(0x90, 0, 1, comportNum);		// Exit Low-noise mode
			ITLAshow(0x32, 0, 1, comportNum);		// Disable laser
			richTextBox2->AppendText(gcnew System::String("Scanning Process Cancelled \n\n"));
			return;
		}
		/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/


		while ((targetFreq < stopFreq)) {
			textBox_fuser->Text = targetFreq.ToString();
			textBox_fuser->Update();
			printf("S: %f E: %f %f %d\n", startFreq, stopFreq, targetFreq, counter);





			
			/*---------------------------------------------------Registration Value calculation-----------------------------------------------------------*/
			switch (serialNum) {
			case 0:
				strncpy(filename, "input2/CRTNJ5W06P.current2", 100);
				break;
			case 1:
				strncpy(filename, "input2/CRTNCAJ02E.current2", 100);
				break;
			}
			int c = 0;
			size = countlines(filename) + 1;
			fp = fopen(filename, "r");

			while (!feof(fp)) {
				fscanf(fp, "%lf %d %lf %lf %d", &freq[c], &power[c], &lcc[c], &hcc[c], &cs[c]);
				printf("%lf %d %lf %lf %d\n", freq[c], power[c], lcc[c], hcc[c], cs[c]);
				c++;
			}




			fclose(fp);
			
			// look for target frequency and power for scanning
			for (c = 0; c < countlines(filename) + 1; c++) {
				if (power[c] == targetPower) {
					// Target frequency is in the current2 file
					if (freq[c] == targetFreq * 100 / 100) {
						//printf("freq: %f powerMap: %d \n", freq[i], power[i]);
						//targetIndex = i;
						regE7 = (int)floor(100.00*hcc[c]) * 256 + (int)floor(100.00*lcc[c]);
						regF3 = cs[c];
					}
					// Interpolation
					else if (freq[c] < targetFreq * 100 / 100 && freq[c + 1] > targetFreq * 100 / 100) {
						//printf("freq[i]: %f, targetFreq: %f, freq[i+1]: %f \n", freq[i], targetFreq, freq[i + 1]);
						// Calculate target Setpoint using interpolation
						regF3 = round((cs[c + 1] - cs[c]) / (freq[c + 1] - freq[c])*(targetFreq - freq[c]) + cs[c]);
						// Calculate Higher Current Correction and Lower Current Correction using interpolation.
						hccTmp = (hcc[c + 1] - hcc[c]) / (freq[c + 1] - freq[c])*(targetFreq - freq[c]) + hcc[c];
						lccTmp = (lcc[c + 1] - lcc[c]) / (freq[c + 1] - freq[c])*(targetFreq - freq[c]) + lcc[c];
						regE7 = (int)floor(100.00*hccTmp) * 256 + (int)floor(100.00*lccTmp);
					}
				}
			}
			// 186.35 31.03 55.394 64.546 17.0 27.07 1110 1000
			switch (serialNum) {
			case 0:
				strncpy(filename, "input2/CRTNJ5W06P_1000.map", 100);
				break;
			case 1:
				strncpy(filename, "input2/CRTNCAJ02E_1000.map", 100);
				break;
			}
			sizeMap = countlines(filename) + 1;
			fp = fopen(filename, "r");
			c = 0;





			while (!feof(fp)) {
				if (serialNum == 0) {
					fscanf(fp, "%lf %lf %lf %lf %lf %lf %d %d %d", &freqMap[c], &sled[c], &f1[c], &f2[c], &f1p, &f2p, &current, &powerMap[c], &ambient);
					printf("%lf %lf %lf %lf %lf %lf %d %d %d\n", freqMap[c], sled[c], f1[c], f2[c], f1p, f2p, current, powerMap[c], ambient);
				}
				else {
					fscanf(fp, "%lf %lf %lf %lf %lf %lf %d %d %d", &freqMap[c], &sled[c], &f1[c], &f2[c], &f1p, &f2p, &current, &powerMap[c], &ambient);
					printf("%lf %lf %lf %lf %lf %lf %d %d %d\n", freqMap[c], sled[c], f1[c], f2[c], f1p, f2p, current, powerMap[c], ambient);
				}
				c++;
			}
			fclose(fp);
			// look for target frequency and power for scanning
			for (c = 0; c < sizeMap; c++) {
				// Target frequency is in the map file
				if (freqMap[c] == targetFreq * 100 / 100) {
					//printf("freqMap: %f powerMap: %d \n", freqMap[i], powerMap[i]);
					regF0 = sled[c] * 1000;
					regF1 = (int)floorf((f1[c] - 50.00)*1000.00);
					regF2 = (int)floorf((f2[c] - 50.00)*1000.00);
				}
				// Interpolation or extrapolation
				else if (freqMap[c] < targetFreq * 100 / 100 && freqMap[c + 1] > targetFreq * 100 / 100) {
					//printf("freq[i]: %f, targetFreq: %f, freq[i+1]: %f \n", freqMap[i], targetFreq, freqMap[i + 1]);
					indexLow = c;
					indexHigh = c + 1;
					// Interpolation
					if ((f1[indexHigh] < f1[indexLow] && f2[indexHigh] < f2[indexLow])) {
						f1Tmp = (f1[indexHigh] - f1[indexLow]) / (freqMap[indexHigh] - freqMap[indexLow])*(targetFreq - freqMap[indexLow]) + f1[indexLow];
						f2Tmp = (f2[indexHigh] - f2[indexLow]) / (freqMap[indexHigh] - freqMap[indexLow])*(targetFreq - freqMap[indexLow]) + f2[indexLow];
						regF1 = (int)floorf((f1Tmp - 50.00)*1000.00);
						regF2 = (int)floorf((f2Tmp - 50.00)*1000.00);
						F1_Index = indexHigh; //For sled calculation
						F2_Index = indexLow;
					}
					else {
						// Calculate high extrapolation of F1 and F2
						int d = 1;
						while (f1[indexHigh + d] > f1[indexHigh + d - 1] || f2[indexHigh + d] > f2[indexHigh + d - 1]) {
							d++;
						}
						f1High = (f1[indexHigh + d] - f1[indexHigh + d - 1]) / (freqMap[indexHigh + d] - freqMap[indexHigh + d - 1])*(targetFreq - freqMap[indexHigh]) + f1[indexHigh];
						f2High = (f2[indexHigh + d] - f2[indexHigh + d - 1]) / (freqMap[indexHigh + d] - freqMap[indexHigh + d - 1])*(targetFreq - freqMap[indexHigh]) + f2[indexHigh];
						SLED_Index_High = indexHigh + d - 1;

						// Calculate low extrapolation of F1 and F2
						d = 1;
						while (f1[indexLow - d + 1] > f1[indexLow - d] || f2[indexLow - d + 1] > f2[indexLow - d]) {
							d++;
						}
						f1Low = (f1[d + 1] - f1[d]) / (freqMap[d + 1] - freqMap[d])*(targetFreq - freqMap[d]) + f1[d];
						f1Low = ((f1[indexLow - d + 1] - f1[indexLow - d]) / (freq[indexLow - d + 1] - freq[indexLow - d]))*(targetFreq - freq[indexLow]) + f1[indexLow];
						f2Low = ((f2[indexLow - d + 1] - f2[indexLow - d]) / (freq[indexLow - d + 1] - freq[indexLow - d]))*(targetFreq - freq[indexLow]) + f2[indexLow];
						SLED_Index_Low = indexLow - d + 1;

						// Use the value of F1 closest to 69
						if (abs(f1High - 69) < abs(f1Low - 69)) {
							regF1 = (int)floorf((f1High - 50.00)*1000.00);
							F1_Index = SLED_Index_High;
						}
						else {
							regF1 = (int)floorf((f1Low - 50.00)*1000.00);
							F1_Index = SLED_Index_Low;
						}

						//Use the value of F2 closest to 69
						if (abs(f2High - 69) < abs(f2Low - 69)) {
							regF2 = (int)floorf((f2High - 50.00)*1000.00);
							F2_Index = SLED_Index_High;
						}
						else if (abs(f2High - 69) > abs(f2Low - 69)) {
							regF2 = (int)floorf((f2Low - 50.00)*1000.00);
							F2_Index = SLED_Index_Low;
						}
					}

					// Calculate SLED. Extrapolate using the closest setpoint used to calculate F1 & F2
					if (abs(freqMap[F1_Index] - targetFreq) < abs(freqMap[F2_Index] - targetFreq)) {     //Use closer point if different
						sledTmp = (sledSlope * (targetFreq - freqMap[F1_Index])) + sled[F1_Index];
						//sledTmp = sledSlope * 1000*(targetFreq - freqMap[F1_Index]) + sled[F1_Index];
					}
					else {
						sledTmp = (sledSlope * (targetFreq - freqMap[F2_Index])) + sled[F2_Index];
						//sledTmp = sledSlope * 1000*(targetFreq - freqMap[F2_Index]) + sled[F2_Index];
					}
					regF0 = sledTmp * 1000;
				}
			}
			/*--------------------------------------------------------------------------------------------------------------------------------------------------*/




			Delay_ms(1000);

			if (targetFreq != startFreq) {
				// Check the value of 0xE5
				// Check if Clean Scan state & 0x0001 == 0; no : read from E5 and check again
				SysTmp5 = ITLAshow(0xE5, 0, 0, comportNum);						// Read from 0xE5, Clean Scan
																				//temp = ITLACommand(0xE5, 0, 0, comportNum);		
																				//sprintf(const_cast<char*>(stdStr.c_str()), "%02x", temp[3]);	// Take the last byte only
																				//SysTmp = gcnew String(stdStr.c_str());


																				// 
				while (Convert::ToInt32(SysTmp5->Substring(4, 4), 16) != 10) {												// while the last byte of read back value is not equal to 0A, it means that the ITLA is scanning and we need to continue reading
					SysTmp5 = ITLAshow(0xE5, 0, 0, comportNum);		// Read from 0xE5
					Delay_ms(500);

				}
				goto RegistWrite;																							//Send to next register value
			}
		RegistWrite:
			ITLAshow(0xF0, regF0, 1, comportNum);					//Set next sled Temp
			ITLAshow(0xF1, regF1, 1, comportNum);					//Set next f1 temp
			ITLAshow(0xF2, regF2, 1, comportNum);					//Set next f2 temp
			ITLAshow(0xE7, regE7, 1, comportNum);					//Set current adjust value
			ITLAshow(0xF3, regF3, 1, comportNum);					//Set central current

			targetFreq = targetFreq + scanRange / 1000.00;		// Increase targetFreq by scan range


			/*Cancel pending inside loop*/
			if (backgroundWorker5->CancellationPending)
			{
				e->Cancel = true;
				richTextBox2->AppendText(gcnew System::String("Canceling Scan process..."));
				ITLAshow(0xE5, 0, 1, comportNum);		// Stop Clean Scan
				ITLAshow(0x90, 0, 1, comportNum);		// Exit Low-noise mode
				ITLAshow(0x32, 0, 1, comportNum);		// Disable laser
				richTextBox2->AppendText(gcnew System::String("Scanning Process Cancelled \n\n"));
				return;
			}


		}


		/*Cancel pending after loop*/
		if (backgroundWorker5->CancellationPending)
		{
			e->Cancel = true;
			richTextBox2->AppendText(gcnew System::String("Canceling Scan process..."));
			ITLAshow(0xE5, 0, 1, comportNum);		// Stop Clean Scan
			ITLAshow(0x90, 0, 1, comportNum);		// Exit Low-noise mode
			ITLAshow(0x32, 0, 1, comportNum);		// Disable laser
			richTextBox2->AppendText(gcnew System::String("Scanning Process Cancelled \n\n"));
			return;
		}

		
		// Delay .5 seconds after the target frequency is greater than stop frequency, start finalizing process
		if (targetFreq > stopFreq) {
			Delay_ms(500);
			richTextBox2->AppendText(gcnew System::String("Scanning Last Frequency \n"));
			ITLAshow(0xE5, 0, 1, comportNum);		// Stop Clean Scan
			ITLAshow(0x90, 0, 1, comportNum);		// Exit Low-noise mode
			ITLAshow(0x32, 0, 1, comportNum);		// Disable laser
			richTextBox2->AppendText(gcnew System::String("Scan process completed \n\n"));
		}
	
}
private: System::Void backgroundWorker5_ProgressChanged(System::Object^  sender, System::ComponentModel::ProgressChangedEventArgs^  e) {
}
private: System::Void backgroundWorker5_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e) {
}
private: System::Void button_scan_user_Click(System::Object^  sender, System::EventArgs^  e) {

	if (comboBox_ScanSerial_user->Text == "")
	{
		MessageBox::Show("Please select serial number", "Warning", MessageBoxButtons::OK);
	}
	else
	{
		if (comboBox_power_user->Text == "")
		{
			MessageBox::Show("Please pick power level", "Warning", MessageBoxButtons::OK);
		}
		else
		{

			richTextBox2->AppendText(gcnew System::String("Starting Scan Mode \n"));
			if (!backgroundWorker5->IsBusy)
			{
				backgroundWorker5->RunWorkerAsync();
			}
			else
			{
				richTextBox2->AppendText("Scanning is already processing");
			}
		}
	}

}
private: System::Void button_stop_user_Click(System::Object^  sender, System::EventArgs^  e) {
	if (backgroundWorker5->IsBusy)
	{
		backgroundWorker5->CancelAsync();


	}
	else
	{
		richTextBox2->AppendText("No operation in progress to cancel");
	}
}
private: System::Void richTextBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	if (richTextBox2->Visible)
	{
		richTextBox2->SelectionStart = richTextBox2->TextLength;
		richTextBox2->ScrollToCaret();
	}
}
private: System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e) {
	richTextBox2->Text = "";
}
};
}



