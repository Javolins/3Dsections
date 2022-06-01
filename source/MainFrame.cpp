/*****************************************************************//**
 * @file   MainFrame.cpp
 * @brief  Implementation of methods used in the class
 * 
 * C++ constructor and destructor generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
 * http://www.wxformbuilder.org/
 * 
 * @author Michał Rutkowski @P4ndaM1x
 * @date   May 2022
 *********************************************************************/

#include "../include/MainFrame.h"


MainFrame::MainFrame(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxFrame(parent, id, title, pos, size, style) {
	this->SetSizeHints(wxSize(960, 640), wxDefaultSize);

	topMenuBar = new wxMenuBar(0);
	quitMenu = new wxMenu();
	topMenuBar->Append(quitMenu, wxT("&Quit"));
	quitMenu->Append(TOP_MENU_QUIT_WOUT_SAVE_ID, wxT("Quit Without Saving"), wxEmptyString, wxITEM_NORMAL);


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

	this->Bind(wxEVT_MENU, [&, this](wxCommandEvent&) { onExit(); }, TOP_MENU_QUIT_WOUT_SAVE_ID);
	this->SetSizer(mainFrameSizer);
	this->Layout();
	statusBar = this->CreateStatusBar(1, wxSTB_SIZEGRIP, STATUS_BAR_ID);

	this->Centre(wxBOTH);

	Bind(wxEVT_PAINT, &MainFrame::wxPanelRepaint, this);

	// Connect Events
	helpMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrame::viewDocumentationOnMenuSelection), this, viewDocumentation->GetId());
	helpMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrame::sendFeedbackOnMenuSelection), this, sendFeedback->GetId());
	helpMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrame::about3DsectionsOnMenuSelection), this, about3Dsections->GetId());
	backwardButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::backwardButtonOnClick), NULL, this);
	prevFrameButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::prevFrameButtonOnClick), NULL, this);
	playToggle->Connect(wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler(MainFrame::playToggleOnToggle), NULL, this);
	nextFrameButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::nextFrameButtonOnClick), NULL, this);
	forewardButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::forewardButtonOnClick), NULL, this);
	fileLoadButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::fileLoadButtonOnClick), NULL, this);
	saveAnimationButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::saveAnimationButtonOnClick), NULL, this);
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

MainFrame::~MainFrame() {
	// Disconnect Events
	backwardButton->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::backwardButtonOnClick), NULL, this);
	prevFrameButton->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::prevFrameButtonOnClick), NULL, this);
	playToggle->Disconnect(wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler(MainFrame::playToggleOnToggle), NULL, this);
	nextFrameButton->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::nextFrameButtonOnClick), NULL, this);
	forewardButton->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::forewardButtonOnClick), NULL, this);
	fileLoadButton->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::fileLoadButtonOnClick), NULL, this);
	saveAnimationButton->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::saveAnimationButtonOnClick), NULL, this);
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

void MainFrame::onExit(){
	if (wxMessageDialog(NULL, "Are you sure to quit?", "Question", wxOK | wxCANCEL).ShowModal() == wxID_OK) Destroy();
}

void MainFrame::viewDocumentationOnMenuSelection(wxCommandEvent& event) {
	if (!wxLaunchDefaultBrowser("https://3dsections.p4m1.top/")) {
		wxMessageDialog* dialog = new wxMessageDialog(nullptr, "Przeglądarka nie mogła zostać otwarta.", "Błąd", wxICON_ERROR | wxSTAY_ON_TOP);
		dialog->ShowModal();
		delete dialog;
	}
}
void MainFrame::sendFeedbackOnMenuSelection(wxCommandEvent& event) {
	if (!wxLaunchDefaultBrowser("mailto:3dsections@p4m1.top")) {
		wxMessageDialog* dialog = new wxMessageDialog(nullptr, "Klient pocztowy nie mógł zostać otwarty.", "Błąd", wxICON_ERROR | wxSTAY_ON_TOP);
		dialog->ShowModal();
		delete dialog;
	}
}
void MainFrame::about3DsectionsOnMenuSelection(wxCommandEvent& event) {
	if (!wxLaunchDefaultBrowser("https://github.com/Javolins/3Dsections#readme")) {
		wxMessageDialog* dialog = new wxMessageDialog(nullptr, "Przeglądarka nie mogła zostać otwarta.", "Błąd", wxICON_ERROR | wxSTAY_ON_TOP);
		dialog->ShowModal();
		delete dialog;
	}
}

void MainFrame::playToggleOnToggle(wxCommandEvent& event) {
	if (playToggle->GetValue()) {

		progressGauge->Show();
		playToggle->SetLabel("Stop");

		unsigned planeIndex = planeChoice->GetSelection();
		Plane plane;
		// plane: xOy
		if( planeIndex == 0 )
			plane.setC(1);
		// plane: xOz
		if( planeIndex == 1 )
			plane.setB(1);
		// plane: yOz
		if( planeIndex == 2 )
			plane.setA(1);

		repaintSec(intersectionPoints(dataSegment, plane));

		connectionPoints(secPoint);
		secPoint.clear();
	}
	else {
		progressGauge->Hide();
		playToggle->SetLabel("Play");

		wxClientDC dc(rightPanel);
		wxBufferedDC buffer(&dc);
		buffer.SetBackground(*wxWHITE_BRUSH);
		buffer.Clear();
	}
}

void MainFrame::fileLoadButtonOnClick(wxCommandEvent& event) {
	wxFileDialog WxOpenFileDialog(this, wxT("Choose a file"), wxT(""), wxT(""), wxT("Geometry file (*.geo)|*.geo"), wxFD_OPEN | wxFD_FILE_MUST_EXIST);
	if (WxOpenFileDialog.ShowModal() == wxID_OK) {
		double xStartPoint, yStartPoint, zStartPoint, xEndPoint, yEndPoint, zEndPoint;
		int r, g, b;

		std::ifstream in(WxOpenFileDialog.GetPath().ToStdString());
		if (in.is_open()) {
			dataSegment.clear();
			while (!in.eof()) {
				in >> xStartPoint >> yStartPoint >> zStartPoint >> xEndPoint >> yEndPoint >> zEndPoint >> r >> g >> b;
				dataSegment.push_back(OriginalEdge(Point(xStartPoint, yStartPoint, zStartPoint), Point(xEndPoint, yEndPoint, zEndPoint), Color(r, g, b)));
			}
			in.close();
		}

		event.Skip();
	}

	repaintGeo();
}


void MainFrame::wxPanelRepaint(wxPaintEvent& event) {
	repaintGeo();
}

void MainFrame::repaintGeo() {
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
	translationMatrix.setElement(0, 3, 0.10);
	translationMatrix.setElement(1, 1, 1);
	translationMatrix.setElement(1, 3, 0.10);
	translationMatrix.setElement(2, 2, 1);
	translationMatrix.setElement(2, 3, 0.25);
	translationMatrix.setElement(3, 3, 1);

	transformationMatrix = translationMatrix * rotationZ * rotationY * rotationX * scaleMatrix;

	perspectiveMatrix.setElement(0, 0, (0.5 * leftPanel->GetSize().GetWidth()));
	perspectiveMatrix.setElement(0, 2, (0.5 * leftPanel->GetSize().GetWidth()));
	perspectiveMatrix.setElement(0, 3, (0.5 * leftPanel->GetSize().GetWidth()));
	perspectiveMatrix.setElement(1, 1, (-0.5 * leftPanel->GetSize().GetHeight()));
	perspectiveMatrix.setElement(1, 2, (0.5 * leftPanel->GetSize().GetHeight()));
	perspectiveMatrix.setElement(1, 3, (0.5 * leftPanel->GetSize().GetHeight()));
	perspectiveMatrix.setElement(3, 2, 1);
	perspectiveMatrix.setElement(3, 3, 1);

	wxClientDC  dc(leftPanel);
	wxBufferedDC buffer(&dc);
	buffer.SetBackground(*wxWHITE_BRUSH);
	buffer.Clear();

	for (auto& segment : dataSegment) {
		buffer.SetPen(wxPen(wxColour(segment.getRgb().getR(), segment.getRgb().getG(), segment.getRgb().getB())));

		Vector4 beginVec, endVec;
		beginVec.set(segment.getStart().getX(), segment.getStart().getY(), segment.getStart().getZ());
		endVec.set(segment.getEnd().getX(), segment.getEnd().getY(), segment.getEnd().getZ());

		beginVec = transformationMatrix * beginVec;
		endVec = transformationMatrix * endVec;
		
		beginVec = perspectiveMatrix * beginVec;
		endVec = perspectiveMatrix * endVec;

		if (beginVec.getElement(3) >= 0) {
			beginVec.setElement(0, beginVec.getElement(0) / beginVec.getElement(3));
			beginVec.setElement(1, beginVec.getElement(1) / beginVec.getElement(3));
		}
		else {
			beginVec.setElement(0, beginVec.getElement(0) / -beginVec.getElement(3));
			beginVec.setElement(1, beginVec.getElement(1) / -beginVec.getElement(3));
		}

		if (endVec.getElement(3) >= 0) {
			endVec.setElement(0, endVec.getElement(0) / endVec.getElement(3));
			endVec.setElement(1, endVec.getElement(1) / endVec.getElement(3));
		}
		else {
			endVec.setElement(0, endVec.getElement(0) / -endVec.getElement(3));
			endVec.setElement(1, endVec.getElement(1) / -endVec.getElement(3));
		}

		std::array<wxCoord, 4> cordArr{ beginVec.getX(), beginVec.getY(), endVec.getX(), endVec.getY() } ;
		cordData.push_back(cordArr);
		buffer.DrawLine(beginVec.getX(), beginVec.getY(), endVec.getX(), endVec.getY());
	}
}

void MainFrame::repaintSec(std::map<const Edge*, Point> foundPoints){

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

	for( const auto& element : foundPoints ) {
		
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

	for( const auto& element : foundPoints ){

		double x = (element.second.*get_x)() - min_x;
		double y = (element.second.*get_y)() - min_y;
		buffer.DrawCircle(abs(x)*scale + margin_x, abs(y)*scale + margin_y, 2);
		buffer.DrawCircle(abs(x)*scale + margin_x, abs(y)*scale + margin_y, 2);

		//gathered point cordinates to container
		if(first){ x0 = x; y0 = y; first = false;}
		std::array<double, 4> arr{ abs(x) * scale + margin_x, abs(y) * scale + margin_y, abs(x0) * scale + margin_x, abs(y0) * scale + margin_y };
		secPoint.push_back(arr);
		x0 = x;
		y0 = y;
	}
}



void MainFrame::connectionPoints(std::vector<std::array<double, 4>> secPoint){

	wxClientDC dc(rightPanel);
	wxBufferedDC buffer(&dc);
	buffer.SetBackground(*wxWHITE_BRUSH);
	buffer.SetPen(*wxBLACK_PEN);
	buffer.Clear();

	for( const auto& element : secPoint ){
		buffer.DrawLine(element[0], element[1], element[2], element[3]);
	}

}