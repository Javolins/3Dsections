/*****************************************************************//**
 * @file   MainFrame.h
 * @brief  Hedear file of the class representing main 3Dsections app window.
 * 
 * C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
 * http://www.wxformbuilder.org/
 * 
 * @author Michał Rutkowski @P4ndaM1x
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
#include <wx/timer.h>
#include <wx/wxprec.h>
#include <wx/colordlg.h>
#include <wx/spinctrl.h>

// All needed STL's modules.
#include <fstream>
#include <vector>
#include <map>
#include <limits>

// All of our headers used in the file. 
#include "../include/stout.h"
#include "../include/DataClasses.h"
#include "../include/OriginalEdge.h"
#include "../include/Vector4.h"
#include "../include/Matrix4.h"

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

		/**
		 * @brief Sets @ref currentPlane position.
		 * 
		 * @param event
		 */
		virtual void controlSliderOnScroll(wxScrollEvent& event){
			currentPlane.setD(-startingPosition - controlSlider->GetValue()* animationLength/frameNumberSpin->GetValue());
			repaintSec();
		}

		/**
		 * @brief After clicking @ref backwardButton, changes @ref currentPlane position 
		 * to the starting one and repaints the section.
		 * 
		 * @param event Connected event, in this case: wxEVT_COMMAND_BUTTON_CLICKED.
		 * @see backwardButton
		 */
		virtual void backwardButtonOnClick(wxCommandEvent& event);

		/**
		 * @brief After clicking @ref prevFrameButton, decreases the parameter of @ref currentPlane
		 * responsible for its position and repaints the section.
		 * 
		 * @param event Connected event, in this case: wxEVT_COMMAND_BUTTON_CLICKED.
		 * @see prevFrameButton
		 */
		virtual void prevFrameButtonOnClick(wxCommandEvent& event);

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
		 * @brief Draws points where edges are intersecting with a plane, on the @ref rightPanel.
		 * 
		 */
		virtual void repaintSec();

		/**
		 * @brief After clicking @ref nextFrameButton, increases the parameter of @ref currentPlane
		 * responsible for its position and repaints the section.
		 *
		 * @param event Connected event, in this case: wxEVT_COMMAND_BUTTON_CLICKED.
		 * @see nextFrameButton
		 */
		virtual void nextFrameButtonOnClick(wxCommandEvent& event);

		/**
		 * @brief After clicking @ref forewardButton, changes @ref currentPlane position
		 * to the ending one and repaints the section.
		 *
		 * @param event Connected event, in this case: wxEVT_COMMAND_BUTTON_CLICKED.
		 * @see forewardButton
		 */
		virtual void forewardButtonOnClick(wxCommandEvent& event);

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

		/**
		 * @brief After clicking @ref saveAnimationButton saves animation frames in .jpg format to the selected destination.
		 * 
		 * @param event Connected event, in this case: wxEVT_COMMAND_BUTTON_CLICKED.
		 * @see saveAnimationButton
		 */
		virtual void saveAnimationButtonOnClick(wxCommandEvent& event);

		/**
		 * @brief Manages animation frames number
		 * 
		 * @param event
		 */
		virtual void frameNumberSpinonSpin(wxSpinEvent& event){
			if( animationTimer->IsRunning() ){
				animationTimer->Start(1000000/speedSlider->GetValue()/frameNumberSpin->GetValue());
			}
			controlSlider->SetMax(frameNumberSpin->GetValue());
		}

		/**
		 * @brief Changes orientation of @ref currentPlane.
		 * 
		 * @param event Connected event, in this case: wxEVT_COMMAND_CHOICE_SELECTED.
		 * @see currentPlane
		 */
		virtual void planeChoiceOnChoice(wxCommandEvent& event);

		/**
		 * @brief Changes animation speed to be appropriate with the value of @ref speedSlider.
		 * 
		 * @param event Connected events regarding any change in @ref speedSlider state.
		 * @see speedSlider
		 */
		virtual void speedSliderOnScroll(wxScrollEvent& event);

		/**
		 * @brief Handler for class event
		 * 
		 * @param event Connected event, in this case: wxEVT_UPDATE_UI.
		 * @note Refresh wxPanel when updating UIEvent
		 */
		virtual void wxPanelRepaint(wxPaintEvent& event);

		/**
		 * @brief Displays info about @ref currentPlane position as well as
		 * @ref startingPosition and @ref endingPosition values.
		 * 
		 * @param event Connected event, in this case: wxEVT_UPDATE_UI.
		 * @see statusBar
		 */
		virtual void statusBarUpdate(wxUpdateUIEvent& event);
	
	private:

		/**
		 * @brief Calculates @ref animationLength, @ref startingPosition, @ref endingPosition.
		 * Also updates @ref currentPlane position and @ref progressGauge value.
		 * 
		 */
		void MainFrame::calculateAnimationlength();
		//! Stores distance between distance between the most distant points in @ref currentPlane normal vector direction.
		double animationLength = 0;
		//! Stores the starting position of cutting plane
		double startingPosition = 0;
		//! Stores the ending position of cutting plane
		double endingPosition = 0;

		/**
		 * @brief Periodically paints a next animation frame on @ref rightPlane, every time @ref animationTimer notifies.
		 * 
		 * @param event Connected event, in this case: wxEVT_TIMER.
		 */
		void onTimerNotify(wxTimerEvent& event);
		//! Counts down to the repaint of a next animation frame
		wxTimer* animationTimer;

		//! A bar on top of the window, contains: @ref quitMenu, @ref helpMenu.
		wxMenuBar* topMenuBar;
		wxMenu* quitMenu;
		//! Expands to the list of menu items: @ref viewDocumentation, @ref sendFeedback, @ref about3Dsections.
		wxMenu* helpMenu;
		//! Displays loaded solid
		wxPanel* leftPanel;
		//! Displays sections of the solid
		wxPanel* rightPanel;
		//! Optically separates right toolbar
		wxStaticLine* horizontalStaticLine;
		wxSlider* controlSlider;
		//! Indicates state of the played animation.
		wxGauge* progressGauge;
		//! Advances the animation to the start
		wxButton* backwardButton;
		//! Rewinds the animation by one frame
		wxButton* prevFrameButton;
		//! Controls if animation is being played.
		wxToggleButton* playToggle;
		//! Advances the animation by one frame
		wxButton* nextFrameButton;
		//! Advances the animation to the end
		wxButton* forewardButton;
		wxStaticLine* verticalStaticLine;
		wxStaticText* fileLoadLabel;
		//! Opens a file selection dialog.
		wxButton* fileLoadButton;
		wxStaticText* saveAnimationLabel;
		//! Opens a file save dialog.
		wxButton* saveAnimationButton;
		wxStaticText* frameNumberSpinLabel;
		wxSpinCtrl* frameNumberSpin;
		wxStaticText* planeChoiceLabel;
		//! Expands to the list of three planes: xOy, xOz, yOz
		wxChoice* planeChoice;
		wxStaticText* speedChoiceLabel;
		//! Controls animation speed
		wxSlider* speedSlider;
		//! Displays info about ref @currentPlane positioning
		wxStatusBar* statusBar;

		//! Stores edges of loaded solid
		std::vector<OriginalEdge> dataSegment;
		//! Stores a section points coordinates (co to, po co, na co?)
		std::vector<std::array<wxCoord, 4>> cordData;
		//! Stores the cutting plane
		Plane currentPlane{ 0,0,1,0 };
		//! Stores solid's center of mass
		Point geometricCenter;
		//! Stores extremes of the solid
		Point geoMin, geoMax, geoDimensions;
};

