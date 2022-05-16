#include "App.h"

bool App::OnInit()
{
	MainFrame* mainFrame = new MainFrame(nullptr);
	mainFrame->Show(true);
	return true;
}