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

	progressGauge = new wxGauge(this, PROGRESS_GAUGE_ID, 10000, wxDefaultPosition, wxDefaultSize, wxGA_HORIZONTAL);
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

	speedSlider = new wxSlider(this, SPEED_SLIDER_ID, 5, 1, 9, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL);
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
	statusBar->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MainFrame::statusBarUpdate), NULL, this);
	animationTimer->Connect(wxEVT_TIMER, wxTimerEventHandler(MainFrame::onTimerNotify), NULL, this);
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
	statusBar->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MainFrame::statusBarUpdate), NULL, this);
	animationTimer->Disconnect(wxEVT_TIMER, wxTimerEventHandler(MainFrame::onTimerNotify), NULL, this);
	delete animationTimer;
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

		playToggle->SetLabel("Stop");
		animationTimer->Start(100/speedSlider->GetValue());
		progressGauge->Show();

		repaintSec(); 
	}
	else {
		playToggle->SetLabel("Play");
		if( animationTimer->IsRunning() )
			animationTimer->Stop();
		//progressGauge->Hide();
	}
}

void MainFrame::fileLoadButtonOnClick(wxCommandEvent& event) {
	wxFileDialog WxOpenFileDialog(this, wxT("Choose a file"), wxT(""), wxT(""), wxT("Geometry file (*.geo)|*.geo"), wxFD_OPEN | wxFD_FILE_MUST_EXIST);
	if (WxOpenFileDialog.ShowModal() == wxID_OK) {
		double xStartPoint, yStartPoint, zStartPoint, xEndPoint, yEndPoint, zEndPoint;
		int r, g, b;

		std::ifstream in(WxOpenFileDialog.GetPath().ToStdString());
		if (in.is_open()) {

			geometricCenter.set(0, 0, 0);
			geoMin.set(std::numeric_limits<float>::max(), std::numeric_limits<float>::max(), std::numeric_limits<float>::max());
			geoMax.set(std::numeric_limits<float>::min(), std::numeric_limits<float>::min(), std::numeric_limits<float>::min());

			dataSegment.clear();
			while (!in.eof()) {
				in >> xStartPoint >> yStartPoint >> zStartPoint >> xEndPoint >> yEndPoint >> zEndPoint >> r >> g >> b;
				dataSegment.push_back(OriginalEdge(Point(xStartPoint, yStartPoint, zStartPoint), Point(xEndPoint, yEndPoint, zEndPoint), Color(r, g, b)));
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

	calculateAnimationlength();
	repaintGeo();
	repaintSec();
}

void MainFrame::wxPanelRepaint(wxPaintEvent& event) {
	repaintGeo();
	repaintSec();
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

	/**/
	std::vector<Triangle> in = edgesToTriangles(dataSegment);
	std::vector<Edge> polyLine;
	for( auto& e: in ){
		polyLine.push_back(e.getEdgeA());
		polyLine.push_back(e.getEdgeB());
		polyLine.push_back(e.getEdgeC());
	}

	for (auto& segment : /*dataSegment*/polyLine ){
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

void MainFrame::repaintSec(){
	
	std::vector<std::pair<const Edge*, Point>> foundPoints = intersectionPoints(dataSegment, currentPlane);
	//std::vector<Edge> lines = polygonalChain(foundPoints, dataSegment).getEdges();
	//**std::vector<Edge> lines = removeTriangles(connectedIntersectionPoints(foundPoints), meshTriangles(dataSegment)).getEdges();
	//std::vector<Edge> lines = connectedIntersectionPoints(foundPoints);
	//std::vector<Edge> lines = stupidFunction(meshTriangles(dataSegment), currentPlane).getEdges();
	std::vector<Edge> lines = godFunction(edgesToTriangles(dataSegment), currentPlane).getEdges();

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

	progressGauge->SetValue( 10000 * (-currentPlane.getD()-startingPosition) / animationLength );
}

void MainFrame::planeChoiceOnChoice(wxCommandEvent& event){
	
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

void MainFrame::backwardButtonOnClick(wxCommandEvent& event){

	currentPlane.setD(-startingPosition);
	repaintSec();
}

void MainFrame::prevFrameButtonOnClick(wxCommandEvent& event){

	currentPlane.setD(currentPlane.getD() + animationLength/200);
	repaintSec();
}

void MainFrame::nextFrameButtonOnClick(wxCommandEvent& event){
	
	currentPlane.setD(currentPlane.getD() - animationLength/200);
	repaintSec();
}

void MainFrame::forewardButtonOnClick(wxCommandEvent& event){
	
	currentPlane.setD(-endingPosition);
	repaintSec();
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

	animationLength = abs(max - min);
	startingPosition = min;
	endingPosition = max;

	currentPlane.setD(-startingPosition);
	progressGauge->SetValue(10000 * (-currentPlane.getD()-startingPosition) / animationLength);
}

void MainFrame::statusBarUpdate(wxUpdateUIEvent& event){

	double currentPosition = -currentPlane.getD();
	if( currentPlane.getD() == 0 ) currentPosition = 0;
	statusBar->SetStatusText("startingPosition = " + std::to_string(startingPosition), 0);
	statusBar->SetStatusText("currenPosition = " +  std::to_string(currentPosition), 1);
	statusBar->SetStatusText("endingPosition = " + std::to_string(endingPosition), 2);
}

void MainFrame::onTimerNotify(wxTimerEvent& event){
	if( -currentPlane.getD() < endingPosition ){
		currentPlane.setD(currentPlane.getD() - animationLength/200);
		repaintSec();
	}
}

void MainFrame::speedSliderOnScroll(wxScrollEvent& event){

	if( animationTimer->IsRunning() ){
		animationTimer->Start(100/speedSlider->GetValue());
	}
	else{
		animationTimer->Start(100/speedSlider->GetValue());
		animationTimer->Stop();
	}
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
		currentPlane.setD(currentPlane.getD() - animationLength/200);
	}
}