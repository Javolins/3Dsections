/*****************************************************************//**
 * @file   App.cpp
 * @brief  Implementation of methods used in the class
 * 
 * @author Micha³ Rutkowski @P4ndaM1x
 * @date   May 2022
 *********************************************************************/

#include "App.h"

/**
 * @brief Defines behavior of the app, right after launching
 * 
 * @return Always returns true
 */
bool App::OnInit()
{
	MainFrame* mainFrame = new MainFrame(nullptr);
	mainFrame->Show(true);
	return true;
}