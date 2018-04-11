#ifndef MAINFRAME_H
#define MAINFRAME_H

enum{
	ID_BTN_VALIDER = wxID_HIGHEST + 1,
	ID_BTN_QUITTER,
	ID_BTN_TAUX,
	ID_TXT_VALEUR,
	ID_CHOICE_CURRENCY,
	ID_TXT_RES,
};

class MainFrame : public wxFrame{ //dérivée de wxFrame
	public:
		MainFrame(const wxString title); //Constructeur
		virtual ~MainFrame(); //Destructeur

	protected:
		wxPanel *panel;
		wxTextCtrl *txtValeur ,*labelVal;
		wxChoice *wxChDevise;
		wxButton *btnVide,*btnVide2,*btnSin1,*btnCos1,*btnTan1,*btnLn,*btnExp,*btnSin,*btnCos,*btnTan;
		wxButton *btnLog,*btnPuiss,*btnFact,*btnRacine,*btnPi,*btn7,*btn8,*btn9,*btnDel,*btnAc;
		wxButton *btn4,*btn5,*btn6,*btnX,*btnDiv,*btn1,*btn2,*btn3,*btnPlus,*btnMoins;
		wxButton *btn0,*btnPoint,*btnVide3,*btnVide4,*btnEgal;

		
		void OnButtonValiderClicked(wxCommandEvent &event);
		void OnButtonQuitterClicked(wxCommandEvent &event);
		void OnButtonTauxClicked(wxCommandEvent &event);


		DECLARE_EVENT_TABLE()

};




#endif //MAINFRAME_H