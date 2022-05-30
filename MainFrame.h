/*****************************************************************//**
 * @file   MainFrame.h
 * @brief  Hedear file of the class representing main 3Dsections app window.
 * 
 * C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
 * http://www.wxformbuilder.org/
 * 
 * @author Micha³ Rutkowski @P4ndaM1x
 * @date   May 2022
 *********************************************************************/

#pragma once

// All needed wxWidgets' modules.
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
#include <wx/utils.h>
#include <wx/msgdlg.h>
#include <wx/filedlg.h>
#include <wx/msgdlg.h>
#include <wx/dcbuffer.h>

#include <fstream>
#include <vector>
#include <map>
#include <limits>

#include "stout.h"
#include "DataClasses.h"
#include "OriginalEdge.h"
#include "Vector4.h"
#include "Matrix4.h"

// Identifiers of all UI items.
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
#define TOP_MENU_QUIT_WOUT_SAVE_ID 1024

//! Represents the only app's window.
class MainFrame : public wxFrame {
	
	public:
		/**
		 * @brief Creates an instance of the class - main window.
		 *
		 * @param parent Pointer to the parent window.
		 * @param id Unique identifier of the window.
		 * @param title Text displayed on the top windows' bar.
		 * @param pos Positioning after the window show up.
		 * @param size Dimensions after the window show up.
		 * @param style Style properties of the window.
		 */
		MainFrame(wxWindow* parent = nullptr, wxWindowID id = MAIN_FRAME_ID, const wxString& title = wxT("3Dsections"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(960, 640), long style = wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL);

		/**
		 * @brief Disconnects all event handlers.
		 *
		 */
		~MainFrame();

	protected:

		/**
		 * @brief After clicking @ref viewDocumentation menu item, 
		 * launches default browser and opens code documentation site of the project.
		 * 
		 * If the browser wasn't successfully launched, a modal dialog with error message would be shown.
		 * 
		 * @param event Binded event, in this case: wxEVT_COMMAND_MENU_SELECTED.
		 * @see viewDocumentation
		 */
		virtual void viewDocumentationOnMenuSelection(wxCommandEvent& event);

		/**
		 * @brief After clicking @ref sendFeedback menu item, 
		 * launches default mail client with a new letter to the project authors.
		 * 
		 * If the client wasn't successfully launched, a modal dialog with error message would be shown.
		 * 
		 * @param event Binded event, in this case: wxEVT_COMMAND_MENU_SELECTED.
		 * @see sendFeedback
		 */
		virtual void sendFeedbackOnMenuSelection(wxCommandEvent& event);

		/**
		 * @brief After clicking @ref about3Dsections menu item, 
		 * launches default browser and opens a site with basic info about the project.
		 * 
		 * If the browser wasn't successfully launched, a modal dialog with error message would be shown.
		 * 
		 * @param event Binded event, in this case: wxEVT_COMMAND_MENU_SELECTED.
		 * @see about3Dsections
		 */
		virtual void about3DsectionsOnMenuSelection(wxCommandEvent& event);

		virtual void backwardButtonOnClick(wxCommandEvent& event) { event.Skip(); }
		virtual void prevFrameButtonOnClick(wxCommandEvent& event) { event.Skip(); }

		/**
		 * @brief Deals with all actions that should be managed after clicking @ref playToggle button.
		 *
		 * Actions include:
		 *	- changing @ref playToggle label,
		 *	- changing @ref progressGauge visibility.
		 *
		 * @param event Connected event, in this case: wxEVT_COMMAND_TOGGLEBUTTON_CLICKED.
		 * @see playToggle
		 * @note Function will execute every time button is clicked, no matter of button being a toggle type.
		 */
		virtual void playToggleOnToggle(wxCommandEvent& event);

		/**
		 * @brief Show a exit dialog window with a question whether user is sure to quit.
		 * 
		 * Actions include:
		 *	- accept exit, then main window and dialog window is closed
		 *	- cancel exit, then only dialog window is closed 
		 *
		 */
		virtual void onExit();

		/**
		 * @brief Draw a .geo file contents
		 * 
		 * @note Function display .geo file content on the left main window panel.
		 * It is executed every time .geo file to load is chosen, no matter of graphic is
		 * already loaded.
		 *
		 */
		virtual void repaintGeo();

		/**
		 * @brief Draws points where edges are intersecting with a plane, on the @ref rightPanel
		 * 
		 * @param foundPoints Edges which are causing the intersections and Points representing coordinates of those
		 */
		virtual void repaintSec(std::map<const Edge*, Point> foundPoints);

		virtual void nextFrameButtonOnClick(wxCommandEvent& event) { event.Skip(); }
		virtual void forewardButtonOnClick(wxCommandEvent& event) { event.Skip(); }

		/**
		 * @brief After clicking @ref fileLoadButton open a default folder browser dialog 
		 * to select .geo file which is expected to load.
		 * 
		 * @param event Connected event, in this case: wxEVT_COMMAND_BUTTON_CLICKED.
		 * @see fileLoadButton
		 * @note Function will execute every time button is clicked, no matter .geo file loaded before.
		 * .
		 */
		virtual void fileLoadButtonOnClick(wxCommandEvent& event);

		virtual void saveAnimationButtonOnClick(wxCommandEvent& event) { event.Skip(); }
		virtual void planeChoiceOnChoice(wxCommandEvent& event) { event.Skip(); }
		virtual void speedSliderOnScroll(wxScrollEvent& event) { event.Skip(); }


		/**
		 * @brief Handler for class event
		 * 
		 * @param event Connected event, in this case: wxEVT_UPDATE_UI.
		 * @note Refresh wxPanel when updating UIEvent
		 */
		virtual void wxPanelRepaint(wxPaintEvent& event);
	
	//private:
		//! A bar on top of the window, contains: @ref quitMenu, @ref helpMenu.
		wxMenuBar* topMenuBar;
		wxMenu* quitMenu;
		//! Expands to the list of menu items: @ref viewDocumentation, @ref sendFeedback, @ref about3Dsections.
		wxMenu* helpMenu;
		wxPanel* leftPanel;
		wxPanel* rightPanel;
		wxStaticLine* horizontalStaticLine;
		//! Indicates state of the played animation.
		wxGauge* progressGauge;
		wxButton* backwardButton;
		wxButton* prevFrameButton;
		//! Controls if animation is being played.
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

		//! Stores edges of loaded solid
		std::vector<OriginalEdge> dataSegment;
		//! 
		std::vector<std::array<wxCoord, 4>> cordData;

};

