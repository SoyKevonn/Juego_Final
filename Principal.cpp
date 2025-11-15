#include "FrmMundo11.h"
using namespace System;
using namespace System::Windows::Forms; [STAThread]

void main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew Mundo1Kevin::FrmMundo11());
}