/*****************************************************************//**
 * @file   App.h
 * @brief  Class representing 3Dsections app
 * 
 * @author Micha³ Rutkowski @P4ndaM1x
 * @date   May 2022
 *********************************************************************/

#pragma once
#include <wx/wxprec.h>

#include "MainFrame.h"

class App : public wxApp {
	public:
		virtual bool OnInit();
		void initializeTests();
};