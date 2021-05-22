#ifndef VARIABLES_H_INCLUDED
#define VARIABLES_H_INCLUDED


/** ====== LES VARIABLES ===== **/
typedef struct adresse{
        char rue [35];
        char ville[35];
        char code [10];


} adresse;



typedef struct contact{
        char numero [20];
        char nom[35];
        char prenom [35];
        adresse adr;
        char date_naissance [18];
        char email [100];


}contact;

typedef struct cellule {
        contact cont;
        struct cellule *suiv;

}cellule;

typedef struct cellule* repertoire;

/** ====== LES VARIABLES ===== **/



repertoire nouveau_repertoire = NULL;

#define AJOUT_TETE 1
#define SUPPRESSION 2
#define SUPPRESSION_TELEPHONE 3
#define SUPPRESSION_VILLE 4
#define SUPPRESSION_INDICATIF 5
#define MODIFIER_ADRESSE 6
#define MODIFIER_TELEPHONE 7
#define CONTENU_LISTE 8
#define RECHERCHE_NUMERO 9
#define RECHERCHE_NOM 10
#define RECHERCHE_INDICATIF 11
#define RECHERCHE_VILLE 12
#define TRI_LISTE 13
#define QUITTER 14
#define ENREGISTREMENT_LISTE 15
#define CHARGEMENT_LISTE 16
#define CREATION 17


#define AJOUTER_BOUTTON_TETE 40
#define AJOUTER_BOUTTON_QUEUE 23
#define AHOUTER_BOUTON_POSITION 24


#define SUPPRESSION_VILLE_BOUTTON 28
#define AJOUTER_POSITION_NOMBRE 24
#define RECHERCHE_NUMERO_BOUTTON 30
#define SUPPRESSION_NUMERO 27
#define SUPPRESSION_INDICATIF_BOUTTON 29

#define AJOUT_QUEUE 41
#define AJOUT_POSITION 42
#define SUPPRESSION_POSITION 44
#define SUPPRESSION_QUEUE 43
#define SUPPRESSION_TETE 45
#endif // VARIABLES_H_INCLUDED
