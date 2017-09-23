#include <wx/wx.h>
#include "IMG.h"

Frame_IMG::Frame_IMG(): wxFrame(NULL, wxID_ANY, wxT("Calculateur d'IMG"), wxDefaultPosition, wxSize(800,500))
{
	wxPanel *fenetre = new wxPanel(this);

	/* 1 - Création des sizers */

	wxBoxSizer *conteneur_principal        = new wxBoxSizer(wxVERTICAL); // sizer contenant la fenêtre
	wxBoxSizer *conteneur_zone_input2      = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer *conteneur_zone_input_sexe  = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer *conteneur_zone_input_gouts = new wxBoxSizer(wxVERTICAL);

	wxStaticBoxSizer *conteneur_zone_input     = new wxStaticBoxSizer(wxVERTICAL, fenetre, "Veuillez entrer vos informations personnelles :");
	wxStaticBoxSizer *conteneur_zone_resultats = new wxStaticBoxSizer(wxVERTICAL, fenetre, "Resultats :");

	wxFlexGridSizer *conteneur_zone_input_droite  = new wxFlexGridSizer(2, 10, 10);
	wxFlexGridSizer *conteneur_zone_input_gauche  = new wxFlexGridSizer(2, 10, 10);
	wxFlexGridSizer *conteneur_souszone_resultats = new wxFlexGridSizer(2, 10, 10);

	/* 2 - Création des textes de description */

	wxStaticText *texte_explicatif_prenom = new wxStaticText(fenetre, wxID_ANY, wxT("Saisissez votre prénom :"));
	wxStaticText *texte_explicatif_age    = new wxStaticText(fenetre, wxID_ANY, wxT("Saisissez votre âge :"));
	wxStaticText *texte_explicatif_taille = new wxStaticText(fenetre, wxID_ANY, wxT("Saisissez votre taille (en m) :"));
	wxStaticText *texte_explicatif_poids  = new wxStaticText(fenetre, wxID_ANY, wxT("Saisissez votre poids (en kg) :"));
	wxStaticText *texte_explicatif_sexe   = new wxStaticText(fenetre, wxID_ANY, wxT("Vous êtes :"));
	wxStaticText *texte_explicatif_gouts  = new wxStaticText(fenetre, wxID_ANY, wxT("Vous mangez souvent :"));
	wxStaticText *texte_explicatif_IMG    = new wxStaticText(fenetre, wxID_ANY, wxT("Votre IMG :"));
	wxStaticText *texte_explicatif_sain   = new wxStaticText(fenetre, wxID_ANY, wxT("Alimentation :"));


	/* 2 bis - Création des zones de résultats */

	input_resultat_IMG = new wxTextCtrl(fenetre, wxID_ANY, wxT("0.00 %"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxTE_CENTRE); // input servant au résultat de l'IMG
	texte_resultat_sain = new wxStaticText(fenetre, wxID_ANY, wxT("Vous avez une alimentation saine pour la santé."));// Phrase

	/* 3 - Création des éléments de saisie */

	bouton_raz = new wxButton(fenetre, wxID_ANY, wxT("Remise à zéro")); // bouton remise à zéro


	wxString choices[117]; // Liste des années
	choices[0] = wxString(wxT("Année")); // Ajout du mot "année"
	for(int i=1; i<117; i++)
	{
		choices[i] = wxString::Format(wxT("%i"), 1900+i); // ajout des dates (1900, 1901, etc..) dans la liste
	}

	input_prenom = new wxTextCtrl(fenetre, wxID_ANY); // input du prénom
	input_poids  = new wxSpinCtrl(fenetre, wxID_ANY, wxT(""), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 1, 150, 50); // input du poid : peut aller de 1 à 150 kg
	input_taille = new wxSpinCtrlDouble(fenetre, wxID_ANY, wxT(""), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0.10, 2.50, 1.85, 0.01); // input de la taille : peut ale


	input_age = new wxChoice(fenetre, wxID_ANY, wxDefaultPosition, wxDefaultSize, 117, choices); // Création de la liste déroulante "Année" ( à partir de la variable choice remplie ci dessus)
	input_age->SetSelection(0); // Met la sélection de la liste sur le mot "Année"

	input_garcon = new wxRadioButton(fenetre, wxID_ANY, wxT("Un garçon"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP);
	input_fille  = new wxRadioButton(fenetre, wxID_ANY, wxT("Une fille")); // Création des 2 input pour le sexe

	input_frites  = new wxCheckBox(fenetre, wxID_ANY, wxT("Des frites")); // création des 3 checkbox
	input_fruits  = new wxCheckBox(fenetre, wxID_ANY, wxT("Des fruits")); // à propos des goûts de l'utilisateur
	input_legumes = new wxCheckBox(fenetre, wxID_ANY, wxT("Des légumes"));



	/* 4 - Ajout des éléments à leurs sizers */

	// Cas des "inputs groupés" (les checkbox et les radio). Les inputs sont ajoutés à leurs sizers respectifs
	conteneur_zone_input_sexe->Add(input_garcon); // zone d'input radio à propos du sexe
	conteneur_zone_input_sexe->Add(input_fille);

	conteneur_zone_input_gouts->Add(input_frites); // zone d'input radio à propos des gouts
	conteneur_zone_input_gouts->Add(input_fruits);
	conteneur_zone_input_gouts->Add(input_legumes);

	// Ajout des données (textes et inputs) aux 2 FlexGridSizer.
	conteneur_zone_input_gauche->Add(texte_explicatif_prenom); // votre Prénom ?
	conteneur_zone_input_gauche->Add(input_prenom);
	conteneur_zone_input_gauche->Add(texte_explicatif_poids); // votre Poids ?
	conteneur_zone_input_gauche->Add(input_poids);
	conteneur_zone_input_gauche->Add(texte_explicatif_gouts); // vous aimez ?
	conteneur_zone_input_gauche->Add(conteneur_zone_input_gouts);

	conteneur_zone_input_droite->Add(texte_explicatif_age); // votre âge?
	conteneur_zone_input_droite->Add(input_age);
	conteneur_zone_input_droite->Add(texte_explicatif_sexe); // votre sexe ?
	conteneur_zone_input_droite->Add(conteneur_zone_input_sexe);
	conteneur_zone_input_droite->Add(texte_explicatif_taille); // votre taille ?
	conteneur_zone_input_droite->Add(input_taille);


	// Fusion des 2 FlexGridSizer en une grande zone
	conteneur_zone_input2->Add(conteneur_zone_input_gauche, 1, wxLEFT|wxTOP, 10); // la premère des 2 zones de saisie à 10 px de marge a gauche et en haut
	conteneur_zone_input2->Add(conteneur_zone_input_droite, 1, wxTOP, 10); // la seconde ne possède que 10px en haut

	// Ajout de la grande zone et du bouton "RAZ" au StaticBoxSizer servant à la saisie
	conteneur_zone_input->Add(conteneur_zone_input2, 1, wxEXPAND); // La grande zone est la plus étendue possible
	conteneur_zone_input->Add(bouton_raz, 0, wxALIGN_CENTER_HORIZONTAL|wxBOTTOM, 10); // En revanche, le bouton est centré horizontalement et verouillé à 10 px du bord bas.



	// Zone de résultat : Ajout des éléments au FlezGridSizer de résultat
	conteneur_souszone_resultats->Add(texte_explicatif_IMG); // votre IMG est :
	conteneur_souszone_resultats->Add(input_resultat_IMG);
	conteneur_souszone_resultats->Add(texte_explicatif_sain); // Vous avez une alimentation saine
	conteneur_souszone_resultats->Add(texte_resultat_sain);

	// Ajout du FlexGridSizer à son StaticBoxSizer
	conteneur_zone_resultats->Add(conteneur_souszone_resultats, 1, wxALIGN_CENTER_HORIZONTAL|wxTOP, 15);// le FlexGridSizer est centré horizontalement et est à 15 px du bord haut.



	// Ajout des 2 StaticBoxSizer principaux (zone de saisie et de résultats) au conteneur principal
	conteneur_principal->Add(conteneur_zone_input, 2, wxEXPAND|wxALL, 20);
	conteneur_principal->Add(conteneur_zone_resultats, 1, wxEXPAND|wxALL, 20);

	fenetre->SetSizer(conteneur_principal);

	this->SetMinSize(wxSize(500, 220));

	input_prenom->SetFocus();


	input_prenom->Bind(wxEVT_TEXT,        &Frame_IMG::onCalculIMG, this);
	input_poids->Bind( wxEVT_TEXT,        &Frame_IMG::onCalculIMG, this);
	input_taille->Bind(wxEVT_TEXT,        &Frame_IMG::onCalculIMG, this);
	input_age->Bind(   wxEVT_CHOICE,      &Frame_IMG::onCalculIMG, this);
	input_garcon->Bind(wxEVT_RADIOBUTTON, &Frame_IMG::onCalculIMG, this);
	input_fille->Bind( wxEVT_RADIOBUTTON, &Frame_IMG::onCalculIMG, this);

	input_frites->Bind( wxEVT_CHECKBOX, &Frame_IMG::onCalculGouts, this);
	input_fruits->Bind( wxEVT_CHECKBOX, &Frame_IMG::onCalculGouts, this);
	input_legumes->Bind(wxEVT_CHECKBOX, &Frame_IMG::onCalculGouts, this);

	bouton_raz->Bind(wxEVT_BUTTON, &Frame_IMG::onRAZ, this);

	this->Bind(wxEVT_CLOSE_WINDOW, &Frame_IMG::onQuit, this);
}

Frame_IMG::~Frame_IMG()
{

}


void Frame_IMG::onCalculIMG(wxCommandEvent &evenement)
{
	double img = 0.0;
	wxDateTime now = wxDateTime::Today();


	if(input_poids->GetValue() > 0 // Poids : on vérfie si l'input n'est pas vide
	 &&
	(input_garcon->GetValue() || input_fille->GetValue()) // On vérifie que "Garcon" ou "Fille" a été séléctionné
	 &&
	input_age->GetSelection() != wxNOT_FOUND && input_age->GetSelection() != 0 // Age : on vérifie que la séléction n'est pas sur "Année"
	 &&
	input_taille->GetValue() > 0) // Taille : On vérifie si l'input n'est pas vide
	{
		double age = now.GetYear()-(1900+input_age->GetSelection());
		double taille = input_taille->GetValue();
		double poids = input_poids->GetValue();
		double sexe = 1.0;

		if (input_fille->GetValue()) sexe = 0.0; // Si c'est une fille : la variable sexe vaut 0.


		img = 1.2 * poids / (taille * taille)  + 0.23 * age - 10.8 * sexe - 5.4; // Calcul de l'IMG
	}

	input_resultat_IMG->SetValue(wxString::Format("%.2f",img)+" %");
}

void Frame_IMG::onCalculGouts(wxCommandEvent &evenement)
{
	if(input_frites->IsChecked() && !(input_legumes->IsChecked() || input_fruits->IsChecked()) )
	{
		texte_resultat_sain->SetLabel(wxT("Votre régime alimentaire est à risque.\nEssayez de manger 5 fruits et légumes par jour !"));
	}
	else
	{
		texte_resultat_sain->SetLabel(wxT("Vous avez une alimentation saine pour la santé."));
	}


}

void Frame_IMG::onRAZ(wxCommandEvent &evenement)
{
	input_poids->SetValue(50);
	input_taille->SetValue(1.85);
	input_age->SetSelection(0);
	input_garcon->SetValue(true);

	input_frites->SetValue(false);
	input_fruits->SetValue(false);
	input_legumes->SetValue(false);

	input_prenom->SetValue(wxT(""));
}

void Frame_IMG::onQuit(wxCloseEvent &evenement)
{
	if(evenement.CanVeto()) // Si on à le droit de véto
	{
		int quit = wxMessageBox(wxT("Voulez vous vraiment quitter ?"), wxT("Quitter..."), wxOK|wxCANCEL);

		if(quit == wxCANCEL)
		{
			evenement.Veto(); // Bloque la fermeture du programme
			return;
		}
	}
	this->Destroy(); // Lance le processus de destruction de la fenêtre
}
