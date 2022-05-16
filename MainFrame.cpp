///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "MainFrame.h"

///////////////////////////////////////////////////////////////////////////

MainFrame::MainFrame(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxFrame(parent, id, title, pos, size, style)
{
	this->SetSizeHints(wxSize(960, 640), wxDefaultSize);

	topMenuBar = new wxMenuBar(0);
	quitMenu = new wxMenu();
	topMenuBar->Append(quitMenu, wxT("&Quit"));

	helpMenu = new wxMenu();
	wxMenuItem* viewHelp;
	viewHelp = new wxMenuItem(helpMenu, VIEW_HELP_ID, wxString(wxT("View Help")), wxEmptyString, wxITEM_NORMAL);
	helpMenu->Append(viewHelp);

	wxMenuItem* sendFeedback;
	sendFeedback = new wxMenuItem(helpMenu, SEND_FEEDBACK_ID, wxString(wxT("Send Feedback")), wxEmptyString, wxITEM_NORMAL);
	helpMenu->Append(sendFeedback);

	helpMenu->AppendSeparator();

	wxMenuItem* about3Dsections;
	about3Dsections = new wxMenuItem(helpMenu, ABOUT_APP_ID, wxString(wxT("About 3Dsections")), wxEmptyString, wxITEM_NORMAL);
	helpMenu->Append(about3Dsections);

	topMenuBar->Append(helpMenu, wxT("&Help"));

	this->SetMenuBar(topMenuBar);

	wxBoxSizer* mainFrameSizer;
	mainFrameSizer = new wxBoxSizer(wxHORIZONTAL);

	wxBoxSizer* mainFrameLeftSizer;
	mainFrameLeftSizer = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* animationPanelsSizer;
	animationPanelsSizer = new wxBoxSizer(wxHORIZONTAL);

	leftPanel = new wxPanel(this, LEFT_PANEL_ID, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	leftPanel->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));

	animationPanelsSizer->Add(leftPanel, 1, wxEXPAND | wxALL, 5);

	rightPanel = new wxPanel(this, RIGHT_PANEL_ID, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	rightPanel->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));

	animationPanelsSizer->Add(rightPanel, 1, wxEXPAND | wxALL, 5);


	mainFrameLeftSizer->Add(animationPanelsSizer, 1, wxEXPAND | wxALIGN_CENTER_HORIZONTAL, 5);

	horizontalStaticLine = new wxStaticLine(this, HORIZONTAL_STATIC_LINE_ID, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
	mainFrameLeftSizer->Add(horizontalStaticLine, 0, wxBOTTOM | wxEXPAND, 5);

	progressGauge = new wxGauge(this, PROGRESS_GAUGE_ID, 1000, wxDefaultPosition, wxDefaultSize, wxGA_HORIZONTAL);
	progressGauge->SetValue(0);
	progressGauge->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
	progressGauge->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));

	mainFrameLeftSizer->Add(progressGauge, 0, wxALL | wxEXPAND, 5);

	wxBoxSizer* quickMenuSizer;
	quickMenuSizer = new wxBoxSizer(wxHORIZONTAL);


	quickMenuSizer->Add(0, 0, 6, wxEXPAND, 5);

	backwardButton = new wxButton(this, BACKWARD_BUTTON_ID, wxT("<< Backward  "), wxDefaultPosition, wxSize(140, -1), wxBU_LEFT | wxBU_RIGHT);
	backwardButton->SetMinSize(wxSize(140, -1));

	quickMenuSizer->Add(backwardButton, 0, wxALIGN_CENTER_HORIZONTAL | wxBOTTOM, 5);


	quickMenuSizer->Add(0, 0, 2, wxEXPAND, 5);

	prevFrameButton = new wxButton(this, PREV_FRAME_BUTTON_ID, wxT("<  "), wxDefaultPosition, wxSize(40, -1), wxBU_RIGHT);
	prevFrameButton->SetMinSize(wxSize(40, -1));

	quickMenuSizer->Add(prevFrameButton, 0, wxBOTTOM, 5);


	quickMenuSizer->Add(0, 0, 0, wxEXPAND, 5);

	playToggle = new wxToggleButton(this, PLAY_TOGGLE_ID, wxT("Play"), wxDefaultPosition, wxDefaultSize, 0);
	quickMenuSizer->Add(playToggle, 0, wxALIGN_CENTER_HORIZONTAL | wxBOTTOM, 5);


	quickMenuSizer->Add(0, 0, 0, wxEXPAND, 5);

	nextFrameButton = new wxButton(this, NEXT_FRAME_BUTTON_ID, wxT("  >"), wxDefaultPosition, wxSize(40, -1), wxBU_LEFT);
	nextFrameButton->SetFont(wxFont(wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString));
	nextFrameButton->SetMinSize(wxSize(40, -1));

	quickMenuSizer->Add(nextFrameButton, 0, wxBOTTOM, 5);


	quickMenuSizer->Add(0, 0, 2, wxEXPAND, 5);

	forewardButton = new wxButton(this, FOREWARD_BUTTON_ID, wxT("  Foreward >>"), wxDefaultPosition, wxSize(140, -1), wxBU_LEFT | wxBU_RIGHT);
	forewardButton->SetMinSize(wxSize(140, -1));

	quickMenuSizer->Add(forewardButton, 0, wxALIGN_CENTER_HORIZONTAL | wxBOTTOM, 5);


	quickMenuSizer->Add(0, 0, 6, wxEXPAND, 5);


	mainFrameLeftSizer->Add(quickMenuSizer, 0, wxALIGN_CENTER_HORIZONTAL | wxALL | wxTOP | wxEXPAND, 5);


	mainFrameSizer->Add(mainFrameLeftSizer, 1, wxALIGN_CENTER_VERTICAL | wxEXPAND, 5);

	verticalStaticLine = new wxStaticLine(this, VERTICAL_STATIC_LINE_ID, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL);
	mainFrameSizer->Add(verticalStaticLine, 0, wxEXPAND, 5);

	wxBoxSizer* mainFrameRightSizer;
	mainFrameRightSizer = new wxBoxSizer(wxVERTICAL);

	fileLoadLabel = new wxStaticText(this, FILE_LOAD_LABEL, wxT("File choice:"), wxDefaultPosition, wxDefaultSize, 0);
	fileLoadLabel->Wrap(-1);
	mainFrameRightSizer->Add(fileLoadLabel, 0, wxALIGN_CENTER_HORIZONTAL | wxLEFT | wxRIGHT | wxTOP, 5);

	fileLoadButton = new wxButton(this, FILE_LOAD_BUTTON, wxT("Load"), wxDefaultPosition, wxDefaultSize, 0);
	mainFrameRightSizer->Add(fileLoadButton, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 5);

	saveAnimationLabel = new wxStaticText(this, SAVE_ANIMATION_LABEL_ID, wxT("Save animation:"), wxDefaultPosition, wxDefaultSize, 0);
	saveAnimationLabel->Wrap(-1);
	mainFrameRightSizer->Add(saveAnimationLabel, 0, wxALIGN_CENTER_HORIZONTAL | wxLEFT | wxRIGHT | wxTOP, 5);

	saveAnimationButton = new wxButton(this, SAVE_ANIMATION_BUTTON_ID, wxT("Save"), wxDefaultPosition, wxDefaultSize, 0);
	mainFrameRightSizer->Add(saveAnimationButton, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);


	mainFrameRightSizer->Add(0, 0, 10, wxEXPAND, 5);

	planeChoiceLabel = new wxStaticText(this, PLANE_CHOICE_LABEL_ID, wxT("Plane choice:"), wxDefaultPosition, wxDefaultSize, 0);
	planeChoiceLabel->Wrap(-1);
	mainFrameRightSizer->Add(planeChoiceLabel, 0, wxALIGN_CENTER_HORIZONTAL | wxLEFT | wxRIGHT | wxTOP, 5);

	wxString planeChoiceChoices[] = { wxT(" xOy"), wxT(" xOz"), wxT(" yOz") };
	int planeChoiceNChoices = sizeof(planeChoiceChoices) / sizeof(wxString);
	planeChoice = new wxChoice(this, PLANE_CHOICE_ID, wxDefaultPosition, wxDefaultSize, planeChoiceNChoices, planeChoiceChoices, 0);
	planeChoice->SetSelection(0);
	mainFrameRightSizer->Add(planeChoice, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 5);

	speedChoiceLabel = new wxStaticText(this, SPEED_CHOICE_LABEL_ID, wxT("Speed choice:"), wxDefaultPosition, wxDefaultSize, 0);
	speedChoiceLabel->Wrap(-1);
	mainFrameRightSizer->Add(speedChoiceLabel, 0, wxALIGN_CENTER_HORIZONTAL | wxLEFT | wxRIGHT | wxTOP, 5);

	speedSlider = new wxSlider(this, SPEED_SLIDER_ID, 0, 0, 10, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL);
	speedSlider->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_APPWORKSPACE));

	mainFrameRightSizer->Add(speedSlider, 0, wxALIGN_CENTER_HORIZONTAL | wxBOTTOM | wxTOP, 5);


	mainFrameSizer->Add(mainFrameRightSizer, 0, wxALIGN_CENTER_VERTICAL | wxALL | wxEXPAND, 5);


	this->SetSizer(mainFrameSizer);
	this->Layout();
	statusBar = this->CreateStatusBar(1, wxSTB_SIZEGRIP, STATUS_BAR_ID);

	this->Centre(wxBOTH);

	// Connect Events
	backwardButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::backwardButtonOnButtonClick), NULL, this);
	prevFrameButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::prevFrameButtonOnButtonClick), NULL, this);
	playToggle->Connect(wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler(MainFrame::playToggleOnToggleButton), NULL, this);
	nextFrameButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::nextFrameButtonOnButtonClick), NULL, this);
	forewardButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::forewardButtonOnButtonClick), NULL, this);
	fileLoadButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::fileLoadButtonOnButtonClick), NULL, this);
	saveAnimationButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::saveAnimationButtonOnButtonClick), NULL, this);
	planeChoice->Connect(wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler(MainFrame::planeChoiceOnChoice), NULL, this);
	speedSlider->Connect(wxEVT_SCROLL_TOP, wxScrollEventHandler(MainFrame::speedSliderOnScroll), NULL, this);
	speedSlider->Connect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(MainFrame::speedSliderOnScroll), NULL, this);
	speedSlider->Connect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(MainFrame::speedSliderOnScroll), NULL, this);
	speedSlider->Connect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(MainFrame::speedSliderOnScroll), NULL, this);
	speedSlider->Connect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(MainFrame::speedSliderOnScroll), NULL, this);
	speedSlider->Connect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(MainFrame::speedSliderOnScroll), NULL, this);
	speedSlider->Connect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(MainFrame::speedSliderOnScroll), NULL, this);
	speedSlider->Connect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(MainFrame::speedSliderOnScroll), NULL, this);
	speedSlider->Connect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(MainFrame::speedSliderOnScroll), NULL, this);
}

MainFrame::~MainFrame()
{
	// Disconnect Events
	backwardButton->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::backwardButtonOnButtonClick), NULL, this);
	prevFrameButton->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::prevFrameButtonOnButtonClick), NULL, this);
	playToggle->Disconnect(wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler(MainFrame::playToggleOnToggleButton), NULL, this);
	nextFrameButton->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::nextFrameButtonOnButtonClick), NULL, this);
	forewardButton->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::forewardButtonOnButtonClick), NULL, this);
	fileLoadButton->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::fileLoadButtonOnButtonClick), NULL, this);
	saveAnimationButton->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::saveAnimationButtonOnButtonClick), NULL, this);
	planeChoice->Disconnect(wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler(MainFrame::planeChoiceOnChoice), NULL, this);
	speedSlider->Disconnect(wxEVT_SCROLL_TOP, wxScrollEventHandler(MainFrame::speedSliderOnScroll), NULL, this);
	speedSlider->Disconnect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(MainFrame::speedSliderOnScroll), NULL, this);
	speedSlider->Disconnect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(MainFrame::speedSliderOnScroll), NULL, this);
	speedSlider->Disconnect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(MainFrame::speedSliderOnScroll), NULL, this);
	speedSlider->Disconnect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(MainFrame::speedSliderOnScroll), NULL, this);
	speedSlider->Disconnect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(MainFrame::speedSliderOnScroll), NULL, this);
	speedSlider->Disconnect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(MainFrame::speedSliderOnScroll), NULL, this);
	speedSlider->Disconnect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(MainFrame::speedSliderOnScroll), NULL, this);
	speedSlider->Disconnect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(MainFrame::speedSliderOnScroll), NULL, this);

}
