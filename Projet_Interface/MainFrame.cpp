#include "MainFrame.hpp"

void MainFrame::OnButtonQuitterClicked(wxCommandEvent &event)
{ //Quitter
    Close();
}


MainFrame::MainFrame(const wxString title) : wxFrame(NULL,wxID_ANY,title){
	wxBoxSizer *sizer_intermed, *sizer_boutons;
	wxStaticBoxSizer *cadre;
	wxFlexGridSizer *grille;
	wxButton *btnQuitter;


	panel = new wxPanel(this); // Création du panel d'affichage
	sizer_intermed = new wxBoxSizer(wxVERTICAL); // Création du wxBoxSizer intermédiaire

	cadre = new wxStaticBoxSizer(wxVERTICAL, panel, _T("")); // wxStaticBoxSizer dans cadre    
	grille = new wxFlexGridSizer(5, 5, 5, 5); // Création du wxFlexGridSizer

	//////L I G N E    1////////
	txtValeur = new wxTextCtrl(panel, ID_TXT_VALEUR, _T("0")); // wxTextCtrl pour la valeur
	grille->Add(txtValeur, 0, wxEXPAND); //Ajout txtValeur à la grille
	////////////////////////////

	//////L I G N E    2////////

	sizer_boutons = new wxBoxSizer(wxHORIZONTAL); // Création du wxBoxSizer pour les boutons

	btnVide = new wxButton(panel, ID_BTN_TAUX, _T(" "), wxPoint(10,60), wxSize(50,30)); // Création du bouton "Pourcent"
	btnVide2 = new wxButton(panel, ID_BTN_VALIDER, _T(" "), wxPoint(65,60), wxSize(50,30)); // Création du bouton "CE"
	btnSin1 = new wxButton(panel, ID_BTN_QUITTER, _T("Sin-1"), wxPoint(120,60), wxSize(50,30)); // Création du bouton "C"
	btnCos1 = new wxButton(panel, ID_BTN_QUITTER, _T("Cos-1"), wxPoint(175,60), wxSize(50,30)); // Création du bouton "Delete"
	btnTan1 = new wxButton(panel, ID_BTN_QUITTER, _T("Tan-1"), wxPoint(230,60), wxSize(50,30)); // Création du bouton "Diviser"

	sizer_boutons->Add(btnVide, 0); //Ajoute boutton Pourcent
	sizer_boutons->AddSpacer(5); // Ajout d'un espace entre les deux boutons
	sizer_boutons->Add(btnVide2, 0); //Ajoute boutton CE
	sizer_boutons->AddSpacer(5); // Ajout d'un espace entre les deux boutons
	sizer_boutons->Add(btnSin1, 0); //Ajoute boutton C
	sizer_boutons->AddSpacer(5); // Ajout d'un espace entre les deux boutons
	sizer_boutons->Add(btnCos1, 0); //Ajoute boutton Delete
	sizer_boutons->AddSpacer(5); // Ajout d'un espace entre les deux boutons
	sizer_boutons->Add(btnTan1, 0); //Ajoute boutton Diviser

	btnVide->wxControl::SetBackgroundColour(wxColour(148, 148, 148));
	btnVide2->wxControl::SetBackgroundColour(wxColour(148, 148, 148));
	btnSin1->wxControl::SetBackgroundColour(wxColour(148, 148, 148));
	btnCos1->wxControl::SetBackgroundColour(wxColour(148, 148, 148));
	btnTan1->wxControl::SetBackgroundColour(wxColour(148, 148, 148));

	//////L I G N E    3////////

	btnLn = new wxButton(panel, ID_BTN_TAUX, _T("Ln"), wxPoint(10,90), wxSize(50,30)); // Création du bouton "Pourcent"
	btnExp = new wxButton(panel, ID_BTN_VALIDER, _T("Exp"), wxPoint(65,90), wxSize(50,30)); // Création du bouton "CE"
	btnSin = new wxButton(panel, ID_BTN_QUITTER, _T("Sin"), wxPoint(120,90), wxSize(50,30)); // Création du bouton "C"
	btnCos = new wxButton(panel, ID_BTN_QUITTER, _T("Cos"), wxPoint(175,90), wxSize(50,30)); // Création du bouton "Delete"
	btnTan = new wxButton(panel, ID_BTN_QUITTER, _T("Tan"), wxPoint(230,90), wxSize(50,30)); // Création du bouton "Diviser"

	sizer_boutons->Add(btnLn, 0); //Ajoute boutton Pourcent
	sizer_boutons->AddSpacer(5); // Ajout d'un espace entre les deux boutons
	sizer_boutons->Add(btnExp, 0); //Ajoute boutton CE
	sizer_boutons->AddSpacer(5); // Ajout d'un espace entre les deux boutons
	sizer_boutons->Add(btnSin, 0); //Ajoute boutton C
	sizer_boutons->AddSpacer(5); // Ajout d'un espace entre les deux boutons
	sizer_boutons->Add(btnCos, 0); //Ajoute boutton Delete
	sizer_boutons->AddSpacer(5); // Ajout d'un espace entre les deux boutons
	sizer_boutons->Add(btnTan, 0); //Ajoute boutton Diviser

	btnLn->wxControl::SetBackgroundColour(wxColour(148, 148, 148));
	btnExp->wxControl::SetBackgroundColour(wxColour(148, 148, 148));
	btnSin->wxControl::SetBackgroundColour(wxColour(148, 148, 148));
	btnCos->wxControl::SetBackgroundColour(wxColour(148, 148, 148));
	btnTan->wxControl::SetBackgroundColour(wxColour(148, 148, 148));

	///////////////////////////

	//////L I G N E    4////////

	btnLog = new wxButton(panel, ID_BTN_TAUX, _T("Log"), wxPoint(10,120), wxSize(50,30)); // Création du bouton "Pourcent"
	btnPuiss = new wxButton(panel, ID_BTN_VALIDER, _T("Puiss"), wxPoint(65,120), wxSize(50,30)); // Création du bouton "CE"
	btnFact = new wxButton(panel, ID_BTN_QUITTER, _T("!"), wxPoint(120,120), wxSize(50,30)); // Création du bouton "C"
	btnRacine = new wxButton(panel, ID_BTN_QUITTER, _T("Racine"), wxPoint(175,120), wxSize(50,30)); // Création du bouton "Delete"
	btnPi = new wxButton(panel, ID_BTN_QUITTER, _T("Pi"), wxPoint(230,120), wxSize(50,30)); // Création du bouton "Diviser"

	sizer_boutons->Add(btnLog, 0); //Ajoute boutton Pourcent
	sizer_boutons->AddSpacer(5); // Ajout d'un espace entre les deux boutons
	sizer_boutons->Add(btnPuiss, 0); //Ajoute boutton CE
	sizer_boutons->AddSpacer(5); // Ajout d'un espace entre les deux boutons
	sizer_boutons->Add(btnFact, 0); //Ajoute boutton C
	sizer_boutons->AddSpacer(5); // Ajout d'un espace entre les deux boutons
	sizer_boutons->Add(btnRacine, 0); //Ajoute boutton Delete
	sizer_boutons->AddSpacer(5); // Ajout d'un espace entre les deux boutons
	sizer_boutons->Add(btnPi, 0); //Ajoute boutton Diviser

	btnLog->wxControl::SetBackgroundColour(wxColour(148, 148, 148));
	btnPuiss->wxControl::SetBackgroundColour(wxColour(148, 148, 148));
	btnFact->wxControl::SetBackgroundColour(wxColour(148, 148, 148));
	btnRacine->wxControl::SetBackgroundColour(wxColour(148, 148, 148));
	btnPi->wxControl::SetBackgroundColour(wxColour(148, 148, 148));	

	///////////////////////////	

	//////L I G N E    5////////

	btn7 = new wxButton(panel, ID_BTN_TAUX, _T("7"), wxPoint(10,150), wxSize(50,30)); // Création du bouton "Pourcent"
	btn8 = new wxButton(panel, ID_BTN_VALIDER, _T("8"), wxPoint(65,150), wxSize(50,30)); // Création du bouton "CE"
	btn9 = new wxButton(panel, ID_BTN_QUITTER, _T("9"), wxPoint(120,150), wxSize(50,30)); // Création du bouton "C"
	btnDel = new wxButton(panel, ID_BTN_QUITTER, _T("DEL"), wxPoint(175,150), wxSize(50,30)); // Création du bouton "Delete"
	btnAc = new wxButton(panel, ID_BTN_QUITTER, _T("AC"), wxPoint(230,150), wxSize(50,30)); // Création du bouton "Diviser"

	sizer_boutons->Add(btn7, 0); //Ajoute boutton Pourcent
	sizer_boutons->AddSpacer(5); // Ajout d'un espace entre les deux boutons
	sizer_boutons->Add(btn8, 0); //Ajoute boutton CE
	sizer_boutons->AddSpacer(5); // Ajout d'un espace entre les deux boutons
	sizer_boutons->Add(btn9, 0); //Ajoute boutton C
	sizer_boutons->AddSpacer(5); // Ajout d'un espace entre les deux boutons
	sizer_boutons->Add(btnDel, 0); //Ajoute boutton Delete
	sizer_boutons->AddSpacer(5); // Ajout d'un espace entre les deux boutons
	sizer_boutons->Add(btnAc, 0); //Ajoute boutton Diviser

	btnDel->wxControl::SetBackgroundColour(wxColour(99, 172, 238));	
	btnAc->wxControl::SetBackgroundColour(wxColour(99, 172, 238));	

	///////////////////////////

	//////L I G N E    5////////

	btn4 = new wxButton(panel, ID_BTN_TAUX, _T("4"), wxPoint(10,180), wxSize(50,30)); // Création du bouton "Pourcent"
	btn5 = new wxButton(panel, ID_BTN_VALIDER, _T("5"), wxPoint(65,180), wxSize(50,30)); // Création du bouton "CE"
	btn6 = new wxButton(panel, ID_BTN_QUITTER, _T("6"), wxPoint(120,180), wxSize(50,30)); // Création du bouton "C"
	btnX = new wxButton(panel, ID_BTN_QUITTER, _T("X"), wxPoint(175,180), wxSize(50,30)); // Création du bouton "Delete"
	btnDiv = new wxButton(panel, ID_BTN_QUITTER, _T("/"), wxPoint(230,180), wxSize(50,30)); // Création du bouton "Diviser"

	sizer_boutons->Add(btn4, 0); //Ajoute boutton Pourcent
	sizer_boutons->AddSpacer(5); // Ajout d'un espace entre les deux boutons
	sizer_boutons->Add(btn5, 0); //Ajoute boutton CE
	sizer_boutons->AddSpacer(5); // Ajout d'un espace entre les deux boutons
	sizer_boutons->Add(btn6, 0); //Ajoute boutton C
	sizer_boutons->AddSpacer(5); // Ajout d'un espace entre les deux boutons
	sizer_boutons->Add(btnX, 0); //Ajoute boutton Delete
	sizer_boutons->AddSpacer(5); // Ajout d'un espace entre les deux boutons
	sizer_boutons->Add(btnDiv, 0); //Ajoute boutton Diviser

	btnX->wxControl::SetBackgroundColour(wxColour(99, 172, 238));	
	btnDiv->wxControl::SetBackgroundColour(wxColour(99, 172, 238));	

	///////////////////////////		

		//////L I G N E    6////////

	btn1 = new wxButton(panel, ID_BTN_TAUX, _T("1"), wxPoint(10,210), wxSize(50,30)); // Création du bouton "Pourcent"
	btn2 = new wxButton(panel, ID_BTN_VALIDER, _T("2"), wxPoint(65,210), wxSize(50,30)); // Création du bouton "CE"
	btn3 = new wxButton(panel, ID_BTN_QUITTER, _T("3"), wxPoint(120,210), wxSize(50,30)); // Création du bouton "C"
	btnPlus = new wxButton(panel, ID_BTN_QUITTER, _T("+"), wxPoint(175,210), wxSize(50,30)); // Création du bouton "Delete"
	btnMoins = new wxButton(panel, ID_BTN_QUITTER, _T("-"), wxPoint(230,210), wxSize(50,30)); // Création du bouton "Diviser"

	sizer_boutons->Add(btn1, 0); //Ajoute boutton Pourcent
	sizer_boutons->AddSpacer(5); // Ajout d'un espace entre les deux boutons
	sizer_boutons->Add(btn2, 0); //Ajoute boutton CE
	sizer_boutons->AddSpacer(5); // Ajout d'un espace entre les deux boutons
	sizer_boutons->Add(btn3, 0); //Ajoute boutton C
	sizer_boutons->AddSpacer(5); // Ajout d'un espace entre les deux boutons
	sizer_boutons->Add(btnPlus, 0); //Ajoute boutton Delete
	sizer_boutons->AddSpacer(5); // Ajout d'un espace entre les deux boutons
	sizer_boutons->Add(btnMoins, 0); //Ajoute boutton Diviser

	btnPlus->wxControl::SetBackgroundColour(wxColour(99, 172, 238));	
	btnMoins->wxControl::SetBackgroundColour(wxColour(99, 172, 238));	

	///////////////////////////	

		//////L I G N E    7////////

	btn0 = new wxButton(panel, ID_BTN_TAUX, _T("0"), wxPoint(10,240), wxSize(50,30)); // Création du bouton "Pourcent"
	btnPoint = new wxButton(panel, ID_BTN_VALIDER, _T("."), wxPoint(65,240), wxSize(50,30)); // Création du bouton "CE"
	btnTiret = new wxButton(panel, ID_BTN_QUITTER, _T("( - )"), wxPoint(120,240), wxSize(50,30)); // Création du bouton "C"
	btnVide4 = new wxButton(panel, ID_BTN_QUITTER, _T(" "), wxPoint(175,240), wxSize(50,30)); // Création du bouton "Delete"
	btnEgal = new wxButton(panel, ID_BTN_QUITTER, _T("="), wxPoint(230,240), wxSize(50,30)); // Création du bouton "Diviser"

	sizer_boutons->Add(btn0, 0); //Ajoute boutton Pourcent
	sizer_boutons->AddSpacer(5); // Ajout d'un espace entre les deux boutons
	sizer_boutons->Add(btnPoint, 0); //Ajoute boutton CE
	sizer_boutons->AddSpacer(5); // Ajout d'un espace entre les deux boutons
	sizer_boutons->Add(btnTiret, 0); //Ajoute boutton C
	sizer_boutons->AddSpacer(5); // Ajout d'un espace entre les deux boutons
	sizer_boutons->Add(btnVide4, 0); //Ajoute boutton Delete
	sizer_boutons->AddSpacer(5); // Ajout d'un espace entre les deux boutons
	sizer_boutons->Add(btnEgal, 0); //Ajoute boutton Diviser

	btnVide4->wxControl::SetBackgroundColour(wxColour(99, 172, 238));	
	btnEgal->wxControl::SetBackgroundColour(wxColour(99, 172, 238));	

	///////////////////////////

	cadre->Add(grille, 1, wxALL | wxEXPAND, 5); // Ajout de la grille au wxStaticBoxSizer
	grille->AddGrowableCol(0); // La Première colonne est extensible
	sizer_intermed->Add(cadre, 1, wxALL | wxEXPAND, 5);

	///// A F F I C H A G E 	B O U T T O N S /////////////////
	sizer_boutons = new wxBoxSizer(wxHORIZONTAL); // Création du wxBoxSizer pour les boutons
	btnQuitter = new wxButton(panel, ID_BTN_QUITTER, _T("Quitter")); // Création du bouton "Quitter"
	sizer_boutons->Add(btnQuitter, 0); //Ajoute boutton Quitter
	////////////////////////////////////////////////////////////

	
	sizer_intermed->Add(sizer_boutons, 0, wxALIGN_RIGHT | wxALL, 5); // Ajout du sizer des boutons au sizer intermédiaire

	
	panel->SetSizer(sizer_intermed); // Affectation du sizer intermédiaire au wxPanel

}


BEGIN_EVENT_TABLE(MainFrame,wxFrame)
	EVT_BUTTON(ID_BTN_QUITTER,MainFrame::OnButtonQuitterClicked)
END_EVENT_TABLE()

MainFrame::~MainFrame(){}