#include <wx/wx.h>
#include <wx/spinctrl.h>
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

	wxTextCtrl *input_resultat_IMG = new wxTextCtrl(fenetre, wxID_ANY, wxT("0.00 %"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxTE_CENTRE); // input servant au résultat de l'IMG
	wxStaticText *texte_resultat_sain = new wxStaticText(fenetre, wxID_ANY, wxT("Vous avez une alimentation saine pour la santé."));// Phrase

	/* 3 - Création des éléments de saisie */

	wxButton *bouton_raz = new wxButton(fenetre, wxID_ANY, wxT("Remise à zéro")); // bouton remise à zéro


	wxString choices[117]; // Liste des années
	choices[0] = wxString(wxT("Année")); // Ajout du mot "année"
	for(int i=1; i<117; i++)
	{
		choices[i] = wxString::Format(wxT("%i"), 1900+i); // ajout des dates (1900, 1901, etc..) dans la liste
	}

	wxTextCtrl *input_prenom = new wxTextCtrl(fenetre, wxID_ANY); // input du prénom
	wxSpinCtrl *input_poids  = new wxSpinCtrl(fenetre, wxID_ANY, wxT(""), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 1, 150, 50); // input du poid : peut aller de 1 à 150 kg
	wxSpinCtrlDouble *input_taille = new wxSpinCtrlDouble(fenetre, wxID_ANY, wxT(""), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0.10, 2.50, 1.85, 0.01); // input de la taille : peut ale


	wxChoice *input_age = new wxChoice(fenetre, wxID_ANY, wxDefaultPosition, wxDefaultSize, 117, choices); // Création de la liste déroulante "Année" ( à partir de la variable choice remplie ci dessus)
	input_age->SetSelection(0); // Met la sélection de la liste sur le mot "Année"

	wxRadioButton *input_garcon = new wxRadioButton(fenetre, wxID_ANY, wxT("Un garçon"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP);
	wxRadioButton *input_fille  = new wxRadioButton(fenetre, wxID_ANY, wxT("Une fille")); // Création des 2 input pour le sexe

	wxCheckBox *input_frites  = new wxCheckBox(fenetre, wxID_ANY, wxT("Des frites")); // création des 3 checkbox
	wxCheckBox *input_fruits  = new wxCheckBox(fenetre, wxID_ANY, wxT("Des fruits")); // à propos des goûts de l'utilisateur
	wxCheckBox *input_legumes = new wxCheckBox(fenetre, wxID_ANY, wxT("Des légumes"));



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
}

Frame_IMG::~Frame_IMG()
{

}
