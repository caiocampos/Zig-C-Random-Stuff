#include "JanelaPrincipal.h"

using namespace System;
using namespace System::Windows::Forms;

void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	RP1::JanelaPrincipal janelaP;
	Application::Run(%janelaP);
}