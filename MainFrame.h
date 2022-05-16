///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/panel.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/sizer.h>
#include <wx/statline.h>
#include <wx/gauge.h>
#include <wx/tglbtn.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/stattext.h>
#include <wx/button.h>
#include <wx/choice.h>
#include <wx/slider.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////

#define MAIN_FRAME_ID 1000
#define LEFT_PANEL_ID 1001
#define RIGHT_PANEL_ID 1002
#define HORIZONTAL_STATIC_LINE_ID 1003
#define PROGRESS_GAUGE_ID 1004
#define PLAY_TOGGLE_ID 1005
#define VERTICAL_STATIC_LINE_ID 1006
#define FILE_LOAD_LABEL 1007
#define FILE_LOAD_BUTTON 1008
#define PLANE_CHOICE_LABEL_ID 1009
#define PLANE_CHOICE_ID 1010
#define SPEED_CHOICE_LABEL_ID 1011
#define SPEED_SLIDER_ID 1012

///////////////////////////////////////////////////////////////////////////////
/// Class MainFrame
///////////////////////////////////////////////////////////////////////////////
class MainFrame : public wxFrame
{
private:

protected:
	wxPanel* leftPanel;
	wxPanel* rightPanel;
	wxStaticLine* horizontalStaticLine;
	wxGauge* progressGauge;
	wxToggleButton* playToggle;
	wxStaticLine* verticalStaticLine;
	wxStaticText* fileLoadLabel;
	wxButton* fileLoadButton;
	wxStaticText* planeChoiceLabel;
	wxChoice* planeChoice;
	wxStaticText* speedChoiceLabel;
	wxSlider* speedSlider;

public:

	MainFrame(wxWindow* parent, wxWindowID id = MAIN_FRAME_ID, const wxString& title = wxT("3Dsections"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(960, 720), long style = wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL);

	~MainFrame();

};

