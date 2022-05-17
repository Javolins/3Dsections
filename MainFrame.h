///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/menu.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/statline.h>
#include <wx/gauge.h>
#include <wx/button.h>
#include <wx/tglbtn.h>
#include <wx/stattext.h>
#include <wx/choice.h>
#include <wx/slider.h>
#include <wx/statusbr.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////

#define MAIN_FRAME_ID 1000
#define TOP_MENU_BAR_ID 1001
#define VIEW_HELP_ID 1002
#define SEND_FEEDBACK_ID 1003
#define ABOUT_APP_ID 1004
#define LEFT_PANEL_ID 1005
#define RIGHT_PANEL_ID 1006
#define HORIZONTAL_STATIC_LINE_ID 1007
#define PROGRESS_GAUGE_ID 1008
#define BACKWARD_BUTTON_ID 1009
#define PREV_FRAME_BUTTON_ID 1010
#define PLAY_TOGGLE_ID 1011
#define NEXT_FRAME_BUTTON_ID 1012
#define FOREWARD_BUTTON_ID 1013
#define VERTICAL_STATIC_LINE_ID 1014
#define FILE_LOAD_LABEL 1015
#define FILE_LOAD_BUTTON 1016
#define SAVE_ANIMATION_LABEL_ID 1017
#define SAVE_ANIMATION_BUTTON_ID 1018
#define PLANE_CHOICE_LABEL_ID 1019
#define PLANE_CHOICE_ID 1020
#define SPEED_CHOICE_LABEL_ID 1021
#define SPEED_SLIDER_ID 1022
#define STATUS_BAR_ID 1023

///////////////////////////////////////////////////////////////////////////////
/// Class MainFrame
///////////////////////////////////////////////////////////////////////////////
class MainFrame : public wxFrame
{
private:

protected:
	wxMenuBar* topMenuBar;
	wxMenu* quitMenu;
	wxMenu* helpMenu;
	wxPanel* leftPanel;
	wxPanel* rightPanel;
	wxStaticLine* horizontalStaticLine;
	wxGauge* progressGauge;
	wxButton* backwardButton;
	wxButton* prevFrameButton;
	wxToggleButton* playToggle;
	wxButton* nextFrameButton;
	wxButton* forewardButton;
	wxStaticLine* verticalStaticLine;
	wxStaticText* fileLoadLabel;
	wxButton* fileLoadButton;
	wxStaticText* saveAnimationLabel;
	wxButton* saveAnimationButton;
	wxStaticText* planeChoiceLabel;
	wxChoice* planeChoice;
	wxStaticText* speedChoiceLabel;
	wxSlider* speedSlider;
	wxStatusBar* statusBar;

	// Virtual event handlers, override them in your derived class
	virtual void backwardButtonOnButtonClick(wxCommandEvent& event) { event.Skip(); }
	virtual void prevFrameButtonOnButtonClick(wxCommandEvent& event) { event.Skip(); }
	virtual void playToggleOnToggleButton(wxCommandEvent& event) { event.Skip(); }
	virtual void nextFrameButtonOnButtonClick(wxCommandEvent& event) { event.Skip(); }
	virtual void forewardButtonOnButtonClick(wxCommandEvent& event) { event.Skip(); }
	virtual void fileLoadButtonOnButtonClick(wxCommandEvent& event) { event.Skip(); }
	virtual void saveAnimationButtonOnButtonClick(wxCommandEvent& event) { event.Skip(); }
	virtual void planeChoiceOnChoice(wxCommandEvent& event) { event.Skip(); }
	virtual void speedSliderOnScroll(wxScrollEvent& event) { event.Skip(); }


public:

	MainFrame(wxWindow* parent, wxWindowID id = MAIN_FRAME_ID, const wxString& title = wxT("3Dsections"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(960, 640), long style = wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL);

	~MainFrame();

};

