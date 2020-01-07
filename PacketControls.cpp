#include "PacketControls.h"

using namespace BotOfExile;



[STAThreadAttribute]
int SubwindowMain()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	// Create the main window and run it

	Application::Run(gcnew PacketControls());
	return 0;
}

