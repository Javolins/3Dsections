/*****************************************************************//**
 * @file   MainFrame.cpp
 * @brief  Implementation of methods used in the class.
 * 
 * C++ constructor and destructor generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
 * http://www.wxformbuilder.org/
 * 
 * @author Michał Rutkowski @P4ndaM1x, Aleksander Bartoszek @AleksanderBartoszek, Mateusz Olejnik @MATT6007
 * @date   May 2022
 *********************************************************************/

#include "../include/MainFrame.h"


MainFrame::MainFrame(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxFrame(parent, id, title, pos, size, style) {
	this->SetSizeHints(wxSize(960, 640), wxDefaultSize);

	topMenuBar = new wxMenuBar(0);
	quitMenu = new wxMenu();
	topMenuBar->Append(quitMenu, wxT("&Quit"));
	quitMenu->Append(TOP_MENU_QUIT_WOUT_SAVE_ID, wxT("Quit"), wxEmptyString, wxITEM_NORMAL);

	helpMenu = new wxMenu();
	wxMenuItem* viewDocumentation;
	viewDocumentation = new wxMenuItem(helpMenu, VIEW_HELP_ID, wxString(wxT("View Documentation")), wxEmptyString, wxITEM_NORMAL);
	helpMenu->Append(viewDocumentation);

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

	controlSlider = new wxSlider(this, wxID_ANY, 100, 0, 200, wxDefaultPosition, wxSize(-1, 7), wxSL_LEFT|wxSL_RIGHT);
	mainFrameLeftSizer->Add(controlSlider, 0, wxEXPAND, 0);

	progressGauge = new wxGauge(this, PROGRESS_GAUGE_ID, 10000, wxDefaultPosition, wxSize(-1,10), wxGA_HORIZONTAL);
	progressGauge->SetValue(0);
	progressGauge->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
	progressGauge->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));

	//mainFrameLeftSizer->Add(progressGauge, 0, wxALL | wxEXPAND, 5);
	mainFrameLeftSizer->Add(progressGauge, 0, wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT, 5);

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

	mainFrameRightSizer->Add(0, 0, 1, wxEXPAND, 5);

	algorithmChoiceLabel = new wxStaticText(this, wxID_ANY, wxT("Algorithm choice:"), wxDefaultPosition, wxDefaultSize, 0);
	algorithmChoiceLabel->Wrap(-1);
	mainFrameRightSizer->Add(algorithmChoiceLabel, 0, wxALIGN_CENTER_HORIZONTAL|wxLEFT|wxRIGHT|wxTOP, 5);

	wxString algorithmChoiceChoices[] = { wxT("Quick"), wxT("RayCasting"), wxT("StatisticalRay"),wxT("Neighbors")};
	int algorithmChoiceNChoices = sizeof(algorithmChoiceChoices) / sizeof(wxString);
	algorithmChoice = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, algorithmChoiceNChoices, algorithmChoiceChoices, 0);
	algorithmChoice->SetSelection(0);
	mainFrameRightSizer->Add(algorithmChoice, 0, wxALL, 5);

	moreEdgesCheckBox = new wxCheckBox(this, wxID_ANY, wxT("More edges"), wxDefaultPosition, wxDefaultSize, 0);
	mainFrameRightSizer->Add(moreEdgesCheckBox, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5);

	mainFrameRightSizer->Add(0, 0, 1, wxEXPAND, 5);

	frameNumberSpinLabel = new wxStaticText(this, wxID_ANY, wxT("Frame number:"), wxDefaultPosition, wxDefaultSize, 0);
	frameNumberSpinLabel->Wrap(-1);
	mainFrameRightSizer->Add(frameNumberSpinLabel, 0, wxLEFT|wxRIGHT|wxTOP|wxALIGN_CENTER_HORIZONTAL, 5);

	frameNumberSpin = new wxSpinCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(75, -1), wxSP_ARROW_KEYS, 10, 999, 200);
	mainFrameRightSizer->Add(frameNumberSpin, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

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

	speedSlider = new wxSlider(this, SPEED_SLIDER_ID, 500, 1, 999, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL);
	speedSlider->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_APPWORKSPACE));

	mainFrameRightSizer->Add(speedSlider, 0, wxALIGN_CENTER_HORIZONTAL | wxBOTTOM | wxTOP, 5);

	mainFrameSizer->Add(mainFrameRightSizer, 0, wxALIGN_CENTER_VERTICAL | wxALL | wxEXPAND, 5);

	this->Bind(wxEVT_MENU, [&, this](wxCommandEvent&) { onExit(); }, TOP_MENU_QUIT_WOUT_SAVE_ID);
	this->SetSizer(mainFrameSizer);
	this->Layout();
	statusBar = this->CreateStatusBar(1, wxSTB_SIZEGRIP, STATUS_BAR_ID);
	statusBar->SetFieldsCount(3);

	this->Centre(wxBOTH);

	Bind(wxEVT_PAINT, &MainFrame::wxPanelRepaint, this);
	animationTimer = new wxTimer();

	// Connect Events
	helpMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrame::viewDocumentationOnMenuSelection), this, viewDocumentation->GetId());
	helpMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrame::sendFeedbackOnMenuSelection), this, sendFeedback->GetId());
	helpMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrame::about3DsectionsOnMenuSelection), this, about3Dsections->GetId());
	controlSlider->Connect(wxEVT_SCROLL_TOP, wxScrollEventHandler(MainFrame::controlSliderOnScroll), NULL, this);
	controlSlider->Connect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(MainFrame::controlSliderOnScroll), NULL, this);
	controlSlider->Connect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(MainFrame::controlSliderOnScroll), NULL, this);
	controlSlider->Connect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(MainFrame::controlSliderOnScroll), NULL, this);
	controlSlider->Connect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(MainFrame::controlSliderOnScroll), NULL, this);
	controlSlider->Connect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(MainFrame::controlSliderOnScroll), NULL, this);
	controlSlider->Connect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(MainFrame::controlSliderOnScroll), NULL, this);
	controlSlider->Connect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(MainFrame::controlSliderOnScroll), NULL, this);
	controlSlider->Connect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(MainFrame::controlSliderOnScroll), NULL, this);
	backwardButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::backwardButtonOnClick), NULL, this);
	prevFrameButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::prevFrameButtonOnClick), NULL, this);
	playToggle->Connect(wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler(MainFrame::playOnToggle), NULL, this);
	nextFrameButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::nextFrameButtonOnClick), NULL, this);
	forewardButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::forewardButtonOnClick), NULL, this);
	fileLoadButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::fileLoadButtonOnClick), NULL, this);
	saveAnimationButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::saveAnimationButtonOnClick), NULL, this);
	algorithmChoice->Connect(wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler(MainFrame::algorithmOnChoice), NULL, this);
	moreEdgesCheckBox->Connect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(MainFrame::moreEdgesCheckBoxOnCheck), NULL, this);
	frameNumberSpin->Connect(wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler(MainFrame::frameNumberOnSpin), NULL, this);
	planeChoice->Connect(wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler(MainFrame::planeOnChoice), NULL, this);
	speedSlider->Connect(wxEVT_SCROLL_TOP, wxScrollEventHandler(MainFrame::speedSliderOnScroll), NULL, this);
	speedSlider->Connect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(MainFrame::speedSliderOnScroll), NULL, this);
	speedSlider->Connect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(MainFrame::speedSliderOnScroll), NULL, this);
	speedSlider->Connect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(MainFrame::speedSliderOnScroll), NULL, this);
	speedSlider->Connect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(MainFrame::speedSliderOnScroll), NULL, this);
	speedSlider->Connect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(MainFrame::speedSliderOnScroll), NULL, this);
	speedSlider->Connect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(MainFrame::speedSliderOnScroll), NULL, this);
	speedSlider->Connect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(MainFrame::speedSliderOnScroll), NULL, this);
	speedSlider->Connect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(MainFrame::speedSliderOnScroll), NULL, this);
	statusBar->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MainFrame::statusBarUpdate), NULL, this);
	animationTimer->Connect(wxEVT_TIMER, wxTimerEventHandler(MainFrame::onTimerNotify), NULL, this);
}

MainFrame::~MainFrame() {
	// Disconnect Events
	controlSlider->Disconnect(wxEVT_SCROLL_TOP, wxScrollEventHandler(MainFrame::controlSliderOnScroll), NULL, this);
	controlSlider->Disconnect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(MainFrame::controlSliderOnScroll), NULL, this);
	controlSlider->Disconnect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(MainFrame::controlSliderOnScroll), NULL, this);
	controlSlider->Disconnect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(MainFrame::controlSliderOnScroll), NULL, this);
	controlSlider->Disconnect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(MainFrame::controlSliderOnScroll), NULL, this);
	controlSlider->Disconnect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(MainFrame::controlSliderOnScroll), NULL, this);
	controlSlider->Disconnect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(MainFrame::controlSliderOnScroll), NULL, this);
	controlSlider->Disconnect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(MainFrame::controlSliderOnScroll), NULL, this);
	controlSlider->Disconnect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(MainFrame::controlSliderOnScroll), NULL, this);
	backwardButton->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::backwardButtonOnClick), NULL, this);
	prevFrameButton->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::prevFrameButtonOnClick), NULL, this);
	playToggle->Disconnect(wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler(MainFrame::playOnToggle), NULL, this);
	nextFrameButton->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::nextFrameButtonOnClick), NULL, this);
	forewardButton->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::forewardButtonOnClick), NULL, this);
	fileLoadButton->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::fileLoadButtonOnClick), NULL, this);
	saveAnimationButton->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::saveAnimationButtonOnClick), NULL, this);
	algorithmChoice->Disconnect(wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler(MainFrame::algorithmOnChoice), NULL, this);
	moreEdgesCheckBox->Disconnect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(MainFrame::moreEdgesCheckBoxOnCheck), NULL, this);
	frameNumberSpin->Disconnect(wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler(MainFrame::frameNumberOnSpin), NULL, this);
	planeChoice->Disconnect(wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler(MainFrame::planeOnChoice), NULL, this);
	speedSlider->Disconnect(wxEVT_SCROLL_TOP, wxScrollEventHandler(MainFrame::speedSliderOnScroll), NULL, this);
	speedSlider->Disconnect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(MainFrame::speedSliderOnScroll), NULL, this);
	speedSlider->Disconnect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(MainFrame::speedSliderOnScroll), NULL, this);
	speedSlider->Disconnect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(MainFrame::speedSliderOnScroll), NULL, this);
	speedSlider->Disconnect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(MainFrame::speedSliderOnScroll), NULL, this);
	speedSlider->Disconnect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(MainFrame::speedSliderOnScroll), NULL, this);
	speedSlider->Disconnect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(MainFrame::speedSliderOnScroll), NULL, this);
	speedSlider->Disconnect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(MainFrame::speedSliderOnScroll), NULL, this);
	speedSlider->Disconnect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(MainFrame::speedSliderOnScroll), NULL, this);
	statusBar->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MainFrame::statusBarUpdate), NULL, this);
	animationTimer->Disconnect(wxEVT_TIMER, wxTimerEventHandler(MainFrame::onTimerNotify), NULL, this);
	delete animationTimer;
}

void MainFrame::viewDocumentationOnMenuSelection(wxCommandEvent& event){
	if( !wxLaunchDefaultBrowser("https://3dsections.p4m1.top/") ){
		wxMessageDialog* dialog = new wxMessageDialog(nullptr, "Przeglądarka nie mogła zostać otwarta.", "Błąd", wxICON_ERROR | wxSTAY_ON_TOP);
		dialog->ShowModal();
		delete dialog;
	}
}
void MainFrame::sendFeedbackOnMenuSelection(wxCommandEvent& event){
	if( !wxLaunchDefaultBrowser("mailto:3dsections@p4m1.top") ){
		wxMessageDialog* dialog = new wxMessageDialog(nullptr, "Klient pocztowy nie mógł zostać otwarty.", "Błąd", wxICON_ERROR | wxSTAY_ON_TOP);
		dialog->ShowModal();
		delete dialog;
	}
}
void MainFrame::about3DsectionsOnMenuSelection(wxCommandEvent& event){
	if( !wxLaunchDefaultBrowser("https://github.com/Javolins/3Dsections#readme") ){
		wxMessageDialog* dialog = new wxMessageDialog(nullptr, "Przeglądarka nie mogła zostać otwarta.", "Błąd", wxICON_ERROR | wxSTAY_ON_TOP);
		dialog->ShowModal();
		delete dialog;
	}
}

inline void MainFrame::controlSliderOnScroll(wxScrollEvent& event){
	currentPlane.setD(-startingPosition - controlSlider->GetValue()* animationDistance/frameNumberSpin->GetValue());
	repaintSec();
}

void MainFrame::backwardButtonOnClick(wxCommandEvent& event){

	currentPlane.setD(-startingPosition);
	repaintSec();
}
void MainFrame::prevFrameButtonOnClick(wxCommandEvent& event){

	currentPlane.setD(currentPlane.getD() + animationDistance/frameNumberSpin->GetValue());
	repaintSec();
}

void MainFrame::playOnToggle(wxCommandEvent& event) {
	if (playToggle->GetValue()) {

		playToggle->SetLabel("Stop");
		animationTimer->Start(1000000/speedSlider->GetValue()/frameNumberSpin->GetValue());
		progressGauge->Show();

		repaintSec(); 
	}
	else {

		playToggle->SetLabel("Play");
		if( animationTimer->IsRunning() )
			animationTimer->Stop();
	}
}

void MainFrame::onExit(){
	if( wxMessageDialog(NULL, "Are you really want to quit?\nDo not give up on me :(", "Question", wxOK | wxCANCEL).ShowModal() == wxID_OK ) Destroy();
}

void MainFrame::repaintGeo(){
	Matrix4 scaleMatrix;
	Matrix4 rotationX, rotationY, rotationZ;
	Matrix4 translationMatrix, perspectiveMatrix, transformationMatrix;
	double angle = 0;

	scaleMatrix.setElement(0, 0, 1);
	scaleMatrix.setElement(1, 1, 1);
	scaleMatrix.setElement(2, 2, 1);

	angle = 180 * M_PI / 180.0;
	rotationX.setElement(0, 0, 1);
	rotationX.setElement(1, 1, cos(angle));
	rotationX.setElement(1, 2, -sin(angle));
	rotationX.setElement(2, 1, sin(angle));
	rotationX.setElement(2, 2, cos(angle));
	rotationX.setElement(3, 3, 1);

	angle = 180 * M_PI / 180.0;
	rotationY.setElement(0, 0, cos(angle));
	rotationY.setElement(0, 2, sin(angle));
	rotationY.setElement(1, 1, 1);
	rotationY.setElement(2, 0, -sin(angle));
	rotationY.setElement(2, 2, cos(angle));
	rotationY.setElement(3, 3, 1);

	angle = 180 * M_PI / 180.0;
	rotationZ.setElement(0, 0, cos(angle));
	rotationZ.setElement(0, 1, -sin(angle));
	rotationZ.setElement(1, 0, sin(angle));
	rotationZ.setElement(1, 1, cos(angle));
	rotationZ.setElement(2, 2, 1);
	rotationZ.setElement(3, 3, 1);

	translationMatrix.setElement(0, 0, 1);
	translationMatrix.setElement(1, 1, 1);
	translationMatrix.setElement(2, 2, 1);
	translationMatrix.setElement(3, 3, 1);

	// X, Y, Z
	translationMatrix.setElement(0, 3, -geometricCenter.getX());
	translationMatrix.setElement(1, 3, -geometricCenter.getY());
	translationMatrix.setElement(2, 3, 1+0.22*geoDimensions.getZ()); //geometricCenter.getZ()*0.6

	transformationMatrix = translationMatrix * rotationZ * rotationY * rotationX * scaleMatrix;

	double scalar = std::min(leftPanel->GetSize().GetWidth(), leftPanel->GetSize().GetHeight());

	perspectiveMatrix.setElement(0, 0, (0.5 * scalar));
	perspectiveMatrix.setElement(0, 2, (0.5 * scalar));
	perspectiveMatrix.setElement(0, 3, (0.5 * scalar));
	perspectiveMatrix.setElement(1, 1, (-0.5 * scalar));
	perspectiveMatrix.setElement(1, 2, (0.5 * scalar));
	perspectiveMatrix.setElement(1, 3, (0.5 * scalar));
	perspectiveMatrix.setElement(3, 2, 1);
	perspectiveMatrix.setElement(3, 3, 1);

	wxClientDC  dc(leftPanel);
	wxBufferedDC buffer(&dc);
	buffer.SetBackground(*wxWHITE_BRUSH);
	buffer.Clear();

	std::vector<Triangle> in;
	std::vector<Edge> polyLine;
	if( geo ){
		if( moreEdgesCheckBox->IsChecked() ){
			in = stout::triangulateEdges(dataSegment);
			for( auto& e: in ){
				polyLine.push_back(e.getEdgeA());
				polyLine.push_back(e.getEdgeB());
				polyLine.push_back(e.getEdgeC());
			}
		} else
			polyLine = dataSegment;
	} else{
		in = dataTriangle;
		for( auto& e: in ){
			polyLine.push_back(e.getEdgeA());
			polyLine.push_back(e.getEdgeB());
			polyLine.push_back(e.getEdgeC());
		}
	}

	for( auto& segment : polyLine ){
		buffer.SetPen(wxPen(wxColour(segment.getRgb().getR(), segment.getRgb().getG(), segment.getRgb().getB())));

		Vector4 beginVec, endVec;
		beginVec.set(segment.getStart().getX(), segment.getStart().getY(), segment.getStart().getZ());
		endVec.set(segment.getEnd().getX(), segment.getEnd().getY(), segment.getEnd().getZ());

		beginVec = transformationMatrix * beginVec;
		endVec = transformationMatrix * endVec;
		beginVec = perspectiveMatrix * beginVec;
		endVec = perspectiveMatrix * endVec;

		if( beginVec.getElement(3) >= 0 ){
			beginVec.setElement(0, beginVec.getElement(0) / beginVec.getElement(3));
			beginVec.setElement(1, beginVec.getElement(1) / beginVec.getElement(3));
		} else{
			beginVec.setElement(0, beginVec.getElement(0) / -beginVec.getElement(3));
			beginVec.setElement(1, beginVec.getElement(1) / -beginVec.getElement(3));
		}

		if( endVec.getElement(3) >= 0 ){
			endVec.setElement(0, endVec.getElement(0) / endVec.getElement(3));
			endVec.setElement(1, endVec.getElement(1) / endVec.getElement(3));
		} else{
			endVec.setElement(0, endVec.getElement(0) / -endVec.getElement(3));
			endVec.setElement(1, endVec.getElement(1) / -endVec.getElement(3));
		}

		std::array<wxCoord, 4> cordArr{ beginVec.getX(), beginVec.getY(), endVec.getX(), endVec.getY() };
		buffer.DrawLine(beginVec.getX(), beginVec.getY(), endVec.getX(), endVec.getY());
	}
}

void MainFrame::repaintSec(){

	std::vector<std::pair<const Edge*, Point>> foundPoints = intersections::edgesWithPlane(dataSegment, currentPlane);
	std::vector<Edge> lines;

	if( geo ){
		if( algorithmChoice->GetSelection() == 3 )
			lines = stout::connectNeighboursSection(foundPoints, dataSegment).getEdges();
		if( algorithmChoice->GetSelection() == 2 )
			lines = stout::rayTrianglesSection(stout::triangulateIntersectionPoints(foundPoints), stout::triangulateEdges(dataSegment), true).getEdges();
		if( algorithmChoice->GetSelection() == 1 )
			lines = stout::rayTrianglesSection(stout::triangulateIntersectionPoints(foundPoints), stout::triangulateEdges(dataSegment), false).getEdges();
		if( algorithmChoice->GetSelection() == 0 )
			lines = stout::quickSection(stout::triangulateEdges(dataSegment), currentPlane).getEdges();
	} else{
		if( algorithmChoice->GetSelection() == 3 )
			lines = stout::connectNeighboursSection(foundPoints, dataSegment).getEdges();
		if( algorithmChoice->GetSelection() == 2 )
			lines = stout::rayTrianglesSection(stout::triangulateIntersectionPoints(foundPoints), dataTriangle, true).getEdges();
		if( algorithmChoice->GetSelection() == 1 )
			lines = stout::rayTrianglesSection(stout::triangulateIntersectionPoints(foundPoints), dataTriangle, false).getEdges();
		if( algorithmChoice->GetSelection() == 0 )
			lines = stout::quickSection(dataTriangle, currentPlane).getEdges();
	}

	wxClientDC dc(rightPanel);
	wxBufferedDC buffer(&dc);
	buffer.SetBackground(*wxWHITE_BRUSH);
	buffer.SetPen(*wxBLACK_PEN);
	buffer.Clear();

	double min_x = std::numeric_limits<double>::max(), min_y = std::numeric_limits<double>::max(),
		max_x = std::numeric_limits<double>::min(), max_y = std::numeric_limits<double>::min();

	unsigned planeIndex = planeChoice->GetSelection();
	// plane: xOy
	float (Point::* get_x)() const = &Point::getX;
	float (Point::* get_y)() const = &Point::getY;
	// plane: xOz
	if( planeIndex == 1 ){
		get_y = &Point::getZ;
	}
	// plane: yOz
	if( planeIndex == 2 ){
		get_x = &Point::getY;
		get_y = &Point::getZ;
	}

	for( const auto& element : foundPoints ){

		if( (element.second.*get_x)() > max_x )
			max_x = (element.second.*get_x)();
		if( (element.second.*get_y)() > max_y )
			max_y = (element.second.*get_y)();
		if( (element.second.*get_x)() < min_x )
			min_x = (element.second.*get_x)();
		if( (element.second.*get_y)() < min_y )
			min_y = (element.second.*get_y)();
	}

	float reduction = 1.1;
	double w = abs(max_x - min_x);
	double h = abs(max_y - min_y);
	double scale = std::min(rightPanel->GetSize().GetWidth(), rightPanel->GetSize().GetHeight())
		/ std::max(w, h) / reduction;
	float margin_x = (rightPanel->GetSize().GetWidth()-w*scale)/2.0;
	float margin_y = (rightPanel->GetSize().GetHeight()-h*scale)/2.0;

	double x0 = 0;
	double y0 = 0;
	bool first = true;

	// draw circles
	for( const auto& element : foundPoints ){

		double x = (element.second.*get_x)() - min_x;
		double y = (element.second.*get_y)() - min_y;

		buffer.DrawCircle(
			abs(x)*scale + margin_x,
			abs(y)*scale + margin_y,
			2
		);
	}

	// draw lines
	for( const auto& element : lines ){

		double x_start = (element.getStart().*get_x)() - min_x;
		double y_start = (element.getStart().*get_y)() - min_y;
		double x_end = (element.getEnd().*get_x)() - min_x;
		double y_end = (element.getEnd().*get_y)() - min_y;

		buffer.DrawLine(
			wxPoint{
				static_cast<int>(abs(x_start)*scale + margin_x),
				static_cast<int>(abs(y_start)*scale + margin_y)
			},
			wxPoint{
				static_cast<int>(abs(x_end)*scale + margin_x),
				static_cast<int>(abs(y_end)*scale + margin_y)
			}
		);
	}

	progressGauge->SetValue(10000 * (-currentPlane.getD()-startingPosition) / animationDistance);
	controlSlider->SetValue(frameNumberSpin->GetValue() * (-currentPlane.getD()-startingPosition) / animationDistance);
}

void MainFrame::nextFrameButtonOnClick(wxCommandEvent& event){

	currentPlane.setD(currentPlane.getD() - animationDistance/frameNumberSpin->GetValue());
	repaintSec();
}
void MainFrame::forewardButtonOnClick(wxCommandEvent& event){

	currentPlane.setD(-endingPosition);
	repaintSec();
}

void MainFrame::fileLoadButtonOnClick(wxCommandEvent& event) {
	
	wxFileDialog WxOpenFileDialog(this, wxT("Choose a file"), wxT(""), wxT(""), wxT("Geometry file (*.geo, *.trg)|*.geo; *.trg"), wxFD_OPEN | wxFD_FILE_MUST_EXIST);
	dataSegment.clear();
	dataTriangle.clear();
	geometricCenter.set(0, 0, 0);
	geoMin.set(std::numeric_limits<float>::max(), std::numeric_limits<float>::max(), std::numeric_limits<float>::max());
	geoMax.set(std::numeric_limits<float>::min(), std::numeric_limits<float>::min(), std::numeric_limits<float>::min());
	
	if (WxOpenFileDialog.ShowModal() == wxID_OK && WxOpenFileDialog.GetPath()[WxOpenFileDialog.GetPath().size()-3] == 'g' ){
		double xStartPoint, yStartPoint, zStartPoint, xEndPoint, yEndPoint, zEndPoint;
		int r, g, b;
		geo = true;
		std::ifstream in(WxOpenFileDialog.GetPath().ToStdString());
		if (in.is_open()) {
			while (!in.eof()) {
				in >> xStartPoint >> yStartPoint >> zStartPoint >> xEndPoint >> yEndPoint >> zEndPoint >> r >> g >> b;
				dataSegment.push_back(Edge(Point(xStartPoint, yStartPoint, zStartPoint), Point(xEndPoint, yEndPoint, zEndPoint), Color(r, g, b)));
				geometricCenter.set(geometricCenter.getX()+xStartPoint+xEndPoint, geometricCenter.getY()+yStartPoint+yEndPoint, geometricCenter.getZ()+zStartPoint+zEndPoint);
				if( xStartPoint > geoMax.getX() ) geoMax.setX(xStartPoint);
				if( xStartPoint < geoMin.getX() ) geoMin.setX(xStartPoint);
				if( yStartPoint > geoMax.getY() ) geoMax.setY(yStartPoint);
				if( yStartPoint < geoMin.getY() ) geoMin.setY(yStartPoint);
				if( zStartPoint > geoMax.getZ() ) geoMax.setZ(zStartPoint);
				if( zStartPoint < geoMin.getZ() ) geoMin.setZ(zStartPoint);
				if( xEndPoint > geoMax.getX() ) geoMax.setX(xEndPoint);
				if( xEndPoint < geoMin.getX() ) geoMin.setX(xEndPoint);
				if( yEndPoint > geoMax.getY() ) geoMax.setY(yEndPoint);
				if( yEndPoint < geoMin.getY() ) geoMin.setY(yEndPoint);
				if( zEndPoint > geoMax.getZ() ) geoMax.setZ(zEndPoint);
				if( zEndPoint < geoMin.getZ() ) geoMin.setZ(zEndPoint);
			}
			in.close();
			
			geometricCenter.set(0.5*geometricCenter.getX()/dataSegment.size(), 0.5*geometricCenter.getY()/dataSegment.size(), 0.5*geometricCenter.getZ()/dataSegment.size());
			geoDimensions.set(abs(geoMax.getX()-geoMin.getX()), abs(geoMax.getY()-geoMin.getY()), abs(geoMax.getZ()-geoMin.getZ()) );
		}
		event.Skip();
	}
	else if(WxOpenFileDialog.GetPath()[WxOpenFileDialog.GetPath().size()-3] == 't' ){
		double x1, y1, z1;
		double x2, y2, z2;
		double x3, y3, z3;
		int r, g, b;
		geo = false;
		std::ifstream in(WxOpenFileDialog.GetPath().ToStdString());
		if( in.is_open() ){
			while( !in.eof() ){
				in >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 >> x3 >> y3 >> z3 >> r >> g >> b;
				Edge A{ Point(x1,y1,z1), Point(x2,y2,z2), Color(r,g,b) };
				Edge B{ Point(x2,y2,z2), Point(x3,y3,z3), Color(r,g,b) };
				Edge C{ Point(x3,y3,z3), Point(x1,y1,z1), Color(r,g,b) };
				dataSegment.push_back(A);
				dataSegment.push_back(B);
				dataSegment.push_back(C);
				dataTriangle.push_back(Triangle(A, B, C));
				geometricCenter.set(geometricCenter.getX()+x1+x2+x3, geometricCenter.getY()+y1+y2+y3, geometricCenter.getZ()+z1+z2+z3);
				if( x1 > geoMax.getX() ) geoMax.setX(x1);
				if( x1 < geoMin.getX() ) geoMin.setX(x1);
				if( y1 > geoMax.getY() ) geoMax.setY(y1);
				if( y1 < geoMin.getY() ) geoMin.setY(y1);
				if( z1 > geoMax.getZ() ) geoMax.setZ(z1);
				if( z1 < geoMin.getZ() ) geoMin.setZ(z1);
				if( x2 > geoMax.getX() ) geoMax.setX(x2);
				if( x2 < geoMin.getX() ) geoMin.setX(x2);
				if( y2 > geoMax.getY() ) geoMax.setY(y2);
				if( y2 < geoMin.getY() ) geoMin.setY(y2);
				if( z2 > geoMax.getZ() ) geoMax.setZ(z2);
				if( z2 < geoMin.getZ() ) geoMin.setZ(z2);
				if( x3 > geoMax.getX() ) geoMax.setX(x3);
				if( x3 < geoMin.getX() ) geoMin.setX(x3);
				if( y3 > geoMax.getY() ) geoMax.setY(y3);
				if( y3 < geoMin.getY() ) geoMin.setY(y3);
				if( z3 > geoMax.getZ() ) geoMax.setZ(z3);
				if( z3 < geoMin.getZ() ) geoMin.setZ(z3);
			}
			in.close();

			geometricCenter.set(0.5*geometricCenter.getX()/dataSegment.size(), 0.5*geometricCenter.getY()/dataSegment.size(), 0.5*geometricCenter.getZ()/dataSegment.size());
			geoDimensions.set(abs(geoMax.getX()-geoMin.getX()), abs(geoMax.getY()-geoMin.getY()), abs(geoMax.getZ()-geoMin.getZ()));
		}
		event.Skip();
	}
	calculateAnimationlength();
	repaintGeo();
	repaintSec();
}

void MainFrame::saveAnimationButtonOnClick(wxCommandEvent& event){

	wxFileDialog saveToFileDialog(this, _("Choose file:"), _(""), _(""), _("JPG files (*.jpg)|*.jpg"), wxFD_SAVE);
	if( saveToFileDialog.ShowModal() == wxID_CANCEL )
		return;
	Refresh();
	wxString filePath = saveToFileDialog.GetPath();
	wxString fileName = saveToFileDialog.GetFilename();

	int i = 0;
	currentPlane.setD(-startingPosition);
	while( -currentPlane.getD() < endingPosition ){
		repaintSec();
		Refresh();
		wxClientDC dcClient{ rightPanel };
		wxBufferedDC dcBuffer{ &dcClient };
		PrepareDC(dcBuffer);
		wxInitAllImageHandlers();

		wxSize panelSize = rightPanel->GetVirtualSize();
		wxBitmap bitMapToSave{ panelSize };

		wxMemoryDC memory;
		memory.SelectObject(bitMapToSave);
		memory.Blit(0, 0, panelSize.GetX(), panelSize.GetY(), &dcBuffer, 0, 0, wxCOPY, true);

		wxString newFileName = saveToFileDialog.GetFilename();
		newFileName.insert(newFileName.size()-4, "-" + std::to_string(++i));
		wxString newFilePath = saveToFileDialog.GetPath();
		newFilePath.Replace(fileName, newFileName);

		bitMapToSave.ConvertToImage().SaveFile(newFilePath, wxBITMAP_TYPE_JPEG);
		currentPlane.setD(currentPlane.getD() - animationDistance/frameNumberSpin->GetValue());
	}
}

inline void MainFrame::algorithmOnChoice(wxCommandEvent& event){
	repaintSec();
}
inline void MainFrame::moreEdgesCheckBoxOnCheck(wxCommandEvent& event){
	repaintGeo();
}

void MainFrame::frameNumberOnSpin(wxSpinEvent& event){
	if( animationTimer->IsRunning() )
		animationTimer->Start(1000000/speedSlider->GetValue()/frameNumberSpin->GetValue());
	controlSlider->SetMax(frameNumberSpin->GetValue());
}

void MainFrame::planeOnChoice(wxCommandEvent& event){

	unsigned planeIndex = planeChoice->GetSelection();
	// plane: xOy
	if( planeIndex == 0 )
		currentPlane.set(0, 0, 1, 0);
	// plane: xOz
	if( planeIndex == 1 )
		currentPlane.set(0, 1, 0, 0);
	// plane: yOz
	if( planeIndex == 2 )
		currentPlane.set(1, 0, 0, 0);

	calculateAnimationlength();
	repaintSec();
}

void MainFrame::speedSliderOnScroll(wxScrollEvent& event){

	if( animationTimer->IsRunning() ){
		animationTimer->Start(1000000/speedSlider->GetValue()/frameNumberSpin->GetValue());
	} else{
		animationTimer->Start(1000000/speedSlider->GetValue()/frameNumberSpin->GetValue());
		animationTimer->Stop();
	}
}

void MainFrame::wxPanelRepaint(wxPaintEvent& event) {
	repaintGeo();
	repaintSec();
}

void MainFrame::statusBarUpdate(wxUpdateUIEvent& event){

	double currentPosition = -currentPlane.getD();
	if( currentPlane.getD() == 0 ) currentPosition = 0;

	wxString direction;
	unsigned planeIndex = planeChoice->GetSelection();
	// plane: xOy
	if( planeIndex == 0 )
		direction = "z";
	// plane: xOz
	if( planeIndex == 1 )
		direction = "y";
	// plane: yOz
	if( planeIndex == 2 )
		direction = "x";

	statusBar->SetStatusText(direction + "Start = " + std::to_string(startingPosition), 0);
	statusBar->SetStatusText(direction + "Current = " +  std::to_string(currentPosition), 1);
	statusBar->SetStatusText(direction + "End = " + std::to_string(endingPosition), 2);
}

void MainFrame::calculateAnimationlength(){

	double min = std::numeric_limits<double>::max();
	double max = std::numeric_limits<double>::min();

	// plane: xOy
	float (Point::* get_z)() const = &Point::getZ;
	// plane: xOz
	if( planeChoice->GetSelection() == 1 )
		get_z = &Point::getY;
	// plane: yOz
	if( planeChoice->GetSelection() == 2 )
		get_z = &Point::getX;

	for( auto& edge : dataSegment ){
		if( (edge.getStart().*get_z)() > max )
			max = (edge.getStart().*get_z)();
		if( (edge.getEnd().*get_z)() > max )
			max = (edge.getEnd().*get_z)();
		if( (edge.getStart().*get_z)() < min )
			min = (edge.getStart().*get_z)();
		if( (edge.getEnd().*get_z)() < min )
			min = (edge.getEnd().*get_z)();
	}

	animationDistance = abs(max - min);
	startingPosition = min;
	endingPosition = max;

	currentPlane.setD(-startingPosition);
	progressGauge->SetValue(10000 * (-currentPlane.getD()-startingPosition) / animationDistance);
}

void MainFrame::onTimerNotify(wxTimerEvent& event){
	if( -currentPlane.getD() < endingPosition ){
		currentPlane.setD(currentPlane.getD() - animationDistance/frameNumberSpin->GetValue());
		repaintSec();
	}
}