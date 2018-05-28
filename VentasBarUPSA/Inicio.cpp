#include "Inicio.h"

using namespace System;
using namespace System::Windows::Forms;


[STAThread]
int Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	VentasBarUPSA::Inicio form;
	Application::Run(%form);
	return 0;
}
