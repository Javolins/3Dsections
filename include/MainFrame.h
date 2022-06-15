/*****************************************************************//**
 * @file   MainFrame.h
 * @brief  Hedear file of the class representing main 3Dsections app window.
 * 
 * C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
 * http://www.wxformbuilder.org/
 * 
 * @author Michał Rutkowski @P4ndaM1x, Aleksander Bartoszek @AleksanderBartoszek
 * @date   May 2022
 *********************************************************************/

#pragma once

// All required wxWidgets' modules.
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

// All required STL's modules.
#include <fstream>
#include <vector>
#include <limits>

// All required headers. 
#include "../include/stout.h"
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
		 * @brief Disconnects all event handlers and deletes @ref animationTimer.
		 *
		 */
		~MainFrame();

	protected:

		/**
		 * @brief After clicking @ref viewDocumentation menu item, 
		 * launches default browser and opens code documentation site of the project.
		 * 
		 * @param event Binded event, in this case: wxEVT_COMMAND_MENU_SELECTED.
		 * @see viewDocumentation
		 * @note If the browser wasn't successfully launched, a modal dialog with an error message would be shown.
		 */
		virtual void viewDocumentationOnMenuSelection(wxCommandEvent& event);

		/**
		 * @brief After clicking @ref sendFeedback menu item, 
		 * launches default mail client with a new letter to the project authors.
		 * 
		 * @param event Binded event, in this case: wxEVT_COMMAND_MENU_SELECTED.
		 * @see sendFeedback
		 * @note If the client wasn't successfully launched, a modal dialog with error message would be shown.
		 */
		virtual void sendFeedbackOnMenuSelection(wxCommandEvent& event);

		/**
		 * @brief After clicking @ref about3Dsections menu item, 
		 * launches default browser and opens a site with basic info about the project.
		 * 
		 * @param event Binded event, in this case: wxEVT_COMMAND_MENU_SELECTED.
		 * @see about3Dsections
		 * @note If the browser wasn't successfully launched, a modal dialog with error message would be shown.
		 */
		virtual void about3DsectionsOnMenuSelection(wxCommandEvent& event);

		/**
		 * @brief Sets @ref currentPlane position and repaints the section.
		 * 
		 * @param event Binded events, in this case: wxEVT_SCROLL_TOP, wxEVT_SCROLL_BOTTOM, wxEVT_SCROLL_LINEUP, 
		 * wxEVT_SCROLL_LINEDOWN, wxEVT_SCROLL_PAGEUP, wxEVT_SCROLL_PAGEDOWN, wxEVT_SCROLL_THUMBTRACK,
		 * wxEVT_SCROLL_THUMBRELEASE, wxEVT_SCROLL_CHANGED.
		 */
		virtual void controlSliderOnScroll(wxScrollEvent& event);

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
		 *  - changing @ref animationTimer state and interval,
		 *  - repaints the section.
		 *
		 * @param event Connected event, in this case: wxEVT_COMMAND_TOGGLEBUTTON_CLICKED.
		 * @see playToggle
		 * @note Function will execute every time button is clicked, no matter of button being a toggle type.
		 */
		virtual void playOnToggle(wxCommandEvent& event);

		/**
		 * @brief After clicking @ref quitMenu shows an exit dialog window to confirm.
		 * 
		 * Actions include:
		 *	- accept exit, then main window and dialog window is closed
		 *	- cancel exit, then only dialog window is closed 
		 *
		 */
		virtual void onExit();

		/**
		 * @brief Draws a .geo or .trg file representing solid on the @ref leftPanel.
		 * 
		 * @see leftPanel
		 *
		 */
		virtual void repaintGeo();

		/**
		 * @brief Draws points and polyline where edges are intersecting with a plane, on the @ref rightPanel.
		 * 
		 * @see rightPanel
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
		 * @brief After clicking @ref fileLoadButton opens a default folder browser dialog 
		 * to select .geo or .trg file which is to load.
		 * 
		 * @param event Connected event, in this case: wxEVT_COMMAND_BUTTON_CLICKED.
		 * @see fileLoadButton
		 */
		virtual void fileLoadButtonOnClick(wxCommandEvent& event);

		/**
		 * @brief After clicking @ref saveAnimationButton saves animation frames as .jpg images to the selected destination.
		 * 
		 * @param event Connected event, in this case: wxEVT_COMMAND_BUTTON_CLICKED.
		 * @see saveAnimationButton
		 */
		virtual void saveAnimationButtonOnClick(wxCommandEvent& event);

		/**
		 * @brief Changes current working algorithm and repaints the section on the @ref rightPanel.
		 * 
		 * @param event Connected event, in this case: wxEVT_COMMAND_CHOICE_SELECTED.
		 * @see rightPanel
		 * @see algorithmChoice
		 */
		virtual void algorithmOnChoice(wxCommandEvent& event);
		
		/**
		 * @brief After checking @ref moreEdgesCheckBox repaints the @ref leftPanel with additional edges provided .geo file is loaded.
		 * 
		 * Additional edges are calculated with @ref triangulateEdges.
		 * 
		 * @param event Connected event, in this case: wxEVT_COMMAND_CHECKBOX_CLICKED.
		 * @see moreEdgesCheckBox
		 */
		virtual void moreEdgesCheckBoxOnCheck(wxCommandEvent& event);

		/**
		 * @brief Sets interval of @ref animationTimer and ensures correct behaviour of @ref controlSlider.
		 * 
		 * @param event Connected event, in this case: wxEVT_COMMAND_SPINCTRL_UPDATED.
		 * @see animationTimer
		 * @see controlSlider
		 */
		virtual void frameNumberOnSpin(wxSpinEvent& event);

		/**
		 * @brief Changes orientation of @ref currentPlane and calculates @ref animationDistance.
		 * 
		 * @param event Connected event, in this case: wxEVT_COMMAND_CHOICE_SELECTED.
		 * @see currentPlane
		 * @see animationDistance
		 */
		virtual void planeOnChoice(wxCommandEvent& event);

		/**
		 * @brief Changes animation speed to be appropriate with the value of @ref speedSlider.
		 * 
		 * @param event Connected events regarding any change in @ref speedSlider state.
		 * @see speedSlider
		 */
		virtual void speedSliderOnScroll(wxScrollEvent& event);

		/**
		 * @brief Repaints both @ref leftPanel and @ref rightPanel.
		 * 
		 * @param event Connected event, in this case: wxEVT_UPDATE_UI.
		 */
		virtual void wxPanelRepaint(wxPaintEvent& event);

		/**
		 * @brief Displays informations about @ref currentPlane position as well as
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
		//! Stores distance between the most distant points in @ref currentPlane normal vector direction.
		double animationDistance = 0;
		//! Stores the starting position of cutting plane.
		double startingPosition = 0;
		//! Stores the ending position of cutting plane.
		double endingPosition = 0;

		/**
		 * @brief Periodically paints a next animation frame on @ref rightPlane, every time @ref animationTimer notifies.
		 * 
		 * @param event Connected event, in this case: wxEVT_TIMER.
		 * @see rightPlane
		 * @see animationTimer
		 */
		void onTimerNotify(wxTimerEvent& event);
		//! Counts down to the repaint of a next animation frame.
		wxTimer* animationTimer;

		//! A bar on top of the window, contains: @ref quitMenu, @ref helpMenu.
		wxMenuBar* topMenuBar;
		//! Expands to numerous possibilities of quitting. One to be exact.
		wxMenu* quitMenu;
		//! Expands to the list of menu items: @ref viewDocumentation, @ref sendFeedback, @ref about3Dsections.
		wxMenu* helpMenu;
		//! Displays loaded solid.
		wxPanel* leftPanel;
		//! Displays sections of the solid.
		wxPanel* rightPanel;
		//! Optically separates right toolbar.
		wxStaticLine* horizontalStaticLine;
		//! Dragging it sets @ref currentPlane position.
		wxSlider* controlSlider;
		//! Indicates state of the played animation.
		wxGauge* progressGauge;
		//! Rewinds the animation to the start.
		wxButton* backwardButton;
		//! Rewinds the animation by one frame.
		wxButton* prevFrameButton;
		//! Controls if animation is being played.
		wxToggleButton* playToggle;
		//! Advances the animation by one frame.
		wxButton* nextFrameButton;
		//! Advances the animation to the end.
		wxButton* forewardButton;
		//! Optically separates @ref leftPlane and @ref rightPlane from bottom toolbar.
		wxStaticLine* verticalStaticLine;
		//! Label of @ref fileLoadButton.
		wxStaticText* fileLoadLabel;
		//! Opens a file selection dialog.
		wxButton* fileLoadButton;
		//! Label of @ref saveAnimationButton.
		wxStaticText* saveAnimationLabel;
		//! Opens a file save dialog.
		wxButton* saveAnimationButton;
		//! Label of @ref algorithmChoice.
		wxStaticText* algorithmChoiceLabel;
		//! Expands to the list of possible algorithms to calculate the section.
		wxChoice* algorithmChoice;
		//! Enables additional edges on the solid representation on the @ref leftPanel.
		wxCheckBox* moreEdgesCheckBox;
		//! Label of @ref frameNumberSpin.
		wxStaticText* frameNumberSpinLabel;
		//! Indicates the number of animation frames.
		wxSpinCtrl* frameNumberSpin;
		//! Label of @ref planeChoice.
		wxStaticText* planeChoiceLabel;
		//! Expands to the list of three cutting planes: xOy, xOz, yOz.
		wxChoice* planeChoice;
		//! Label of @ref speedSlider.
		wxStaticText* speedChoiceLabel;
		//! Controls animation speed.
		wxSlider* speedSlider;
		//! Displays info about ref @currentPlane positioning.
		wxStatusBar* statusBar;

		//! Stores edges of loaded solid.
		std::vector<Edge> dataSegment;
		//! Stores triangles of loaded solid.
		std::vector<Triangle> dataTriangle;
		//! Indicates a type of file loaded, true if .geo file was loaded.
		bool geo;
		//! Stores the cutting plane.
		Plane currentPlane{ 0,0,1,0 };
		//! Stores solid's center of mass.
		Point geometricCenter;
		//! Stores extremes of the solid.
		Point geoMin, geoMax, geoDimensions;
};

