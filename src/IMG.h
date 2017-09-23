#include <wx/spinctrl.h>

#ifndef HEADERS_INCLUS_IMG
	#define HEADERS_INCLUS_IMG

	class Frame_IMG : public wxFrame
	{
		private:
			wxTextCtrl *input_resultat_IMG, *input_prenom;
			wxStaticText *texte_resultat_sain;
			wxButton *bouton_raz;
			wxSpinCtrl *input_poids;
			wxSpinCtrlDouble *input_taille;
			wxChoice *input_age;
			wxRadioButton *input_garcon, *input_fille;
			wxCheckBox *input_frites, *input_fruits, *input_legumes;

		public:
			Frame_IMG();
			~Frame_IMG();
			void onCalculIMG(wxCommandEvent &evenement);
			void onCalculGouts(wxCommandEvent &evenement);
			void onRAZ(wxCommandEvent &evenement);
			void onQuit(wxCloseEvent &evenement);
	};

#endif
