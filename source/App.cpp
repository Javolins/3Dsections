/*****************************************************************//**
 * @file   App.cpp
 * @brief  Implementation of methods used in the App class.
 * 
 * @author Michał Rutkowski @P4ndaM1x, Aleksander Bartoszek @AleksanderBartoszek
 * @date   May 2022
 *********************************************************************/

#include "../include/App.h"
#include "../test/doctest.h"

bool App::OnInit() {

	initializeTests();

	MainFrame* mainFrame = new MainFrame();
	mainFrame->Show(true);
	return true;
}

void App::initializeTests() {
    AllocConsole();
    freopen("CONOUT$", "w", stdout);
    freopen("CONOUT$", "w", stderr);

    doctest::Context ctx;
    ctx.setOption("abort-after", 1);
    ctx.setOption("no-breaks", true);
    int res = ctx.run();
}