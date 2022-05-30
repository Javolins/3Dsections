/*****************************************************************//**
 * @file   App.h
 * @brief  Hedear file of the class representing 3Dsections app
 * 
 * @author Micha³ Rutkowski @P4ndaM1x
 * @date   May 2022
 *********************************************************************/

#pragma once
#include <wx/wxprec.h>
#include "../include/MainFrame.h"

/**
 * Simple class with actions that are happening right after opening an app.
 */
class App : public wxApp {
	public:
		virtual bool OnInit();
		void initializeTests();
};