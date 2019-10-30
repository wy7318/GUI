#include "MyForm.h"
//#include "RS232.h"
#include "rs232_linux.h"
#include "ITLA.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
//int Main(array<String^>^ args)
int Main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	
	TWL_GUI::MyForm form;
	Application::Run(%form);
	return 0;
}