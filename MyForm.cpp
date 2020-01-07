#include "MyForm.h"

using namespace BotOfExile;

[STAThreadAttribute]
int Main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	// Create the main window and run it

	Application::Run(gcnew MyForm());
	return 0;
}