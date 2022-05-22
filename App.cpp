/*****************************************************************//**
 * @file   App.cpp
 * @brief  Implementation of methods used in the class
 * 
 * @author Micha³ Rutkowski @P4ndaM1x, Aleksander Bartoszek @AleksanderBartoszek
 * @date   May 2022
 *********************************************************************/

#include "App.h"
#include "doctest.h"

/**
 * @brief Defines behavior of the app, right after launching
 * 
 * @return Always returns true
 */
bool App::OnInit() {

	initializeTests();

	MainFrame* mainFrame = new MainFrame();
	mainFrame->Show(true);
	return true;
}

/**
 * @brief Opens console for logging and runs all tests
 * 
 */
void App::initializeTests() {
    AllocConsole();
    freopen("CONOUT$", "w", stdout);
    freopen("CONOUT$", "w", stderr);

    doctest::Context ctx;
    ctx.setOption("abort-after", 1);  // default - stop after 1 failed asserts
    ctx.setOption("no-breaks", true); // override - don't break in the debugger
    int res = ctx.run();              // run test cases unless with --no-run
}
