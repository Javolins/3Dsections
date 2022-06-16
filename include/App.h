/*****************************************************************//**
 * @file   App.h
 * @brief  Header file of the class representing 3Dsections app
 * 
 * @author Michał Rutkowski @P4ndaM1x, Aleksander Bartoszek @AleksanderBartoszek
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
		/**
		 * @brief Defines behavior of the app, right after launching
		 *
		 * @return Always returns true
		 */
		virtual bool OnInit();
		/**
		 * @brief Opens console for logging and runs all tests
		 *
		 */
		void initializeTests();
};