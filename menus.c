#include <windows.h>
#include "variables.h"

HMENU hMenu; //handler for our menu


void addMenus (HWND hwnd){

    /** Mother Menu **/

    hMenu = CreateMenu();

    /** Les Menus Principales **/

    //HMENU hCreation = CreateMenu();
    HMENU hMiseAjour = CreateMenu();
    HMENU hRechAffTri = CreateMenu();
    HMENU hEnregCharg = CreateMenu();
    HMENU quitter = CreateMenu ();

    /** Les subMenus **/

    // Menu mise à Jour

    HMENU hAjout = CreateMenu ();
    HMENU hSupprimer = CreateMenu();
    HMENU hModifier = CreateMenu();

    // Ajout des subMenus du menu mise à jour

    AppendMenu(hMiseAjour,MF_POPUP,(UINT_PTR) hAjout,"Ajouter un nouvel téléphone");
    AppendMenu(hMiseAjour,MF_SEPARATOR,NULL,NULL);
    AppendMenu(hMiseAjour,MF_POPUP,(UINT_PTR) hSupprimer,"Supprimer un téléphone");
    AppendMenu(hMiseAjour,MF_SEPARATOR,NULL,NULL);
    AppendMenu(hMiseAjour,MF_POPUP,(UINT_PTR) hModifier,"Modifier les données d'un téléphone");

    // Les subMenus des subMenus du menu mise à jour

    AppendMenu(hAjout,MF_STRING,AJOUT_TETE,"Ajouter un numero");
    AppendMenu(hAjout,MF_SEPARATOR,NULL,NULL);
    AppendMenu(hSupprimer,MF_STRING,SUPPRESSION,"Supprimer un numero");
    AppendMenu(hSupprimer,MF_SEPARATOR,NULL,NULL);
    AppendMenu(hSupprimer,MF_STRING,SUPPRESSION_TELEPHONE,"Suppression d'un téléphone donné");
    AppendMenu(hSupprimer,MF_SEPARATOR,NULL,NULL);
    AppendMenu(hSupprimer,MF_STRING,SUPPRESSION_VILLE,"Suppression des téléphones d'une ville donnée");
    AppendMenu(hSupprimer,MF_SEPARATOR,NULL,NULL);
    AppendMenu(hSupprimer,MF_STRING,SUPPRESSION_INDICATIF,"Suppression des téléphones d'un indicatif donné");


    AppendMenu(hModifier,MF_STRING,MODIFIER_ADRESSE,"Adresse");
    AppendMenu(hModifier,MF_SEPARATOR,NULL,NULL);
    AppendMenu(hModifier,MF_STRING,MODIFIER_TELEPHONE,"Téléphone");


    // Menu Recherche & Affichage

    AppendMenu(hRechAffTri,MF_STRING,CONTENU_LISTE,"Contenu de la liste des téléphones");
    AppendMenu(hRechAffTri,MF_SEPARATOR,NULL,NULL);
    AppendMenu(hRechAffTri,MF_STRING,RECHERCHE_NUMERO,"Recherche par numéro téléphone");
    AppendMenu(hRechAffTri,MF_SEPARATOR,NULL,NULL);
    AppendMenu(hRechAffTri,MF_STRING,RECHERCHE_NOM,"Recherche par nom");
    AppendMenu(hRechAffTri,MF_SEPARATOR,NULL,NULL);
    AppendMenu(hRechAffTri,MF_STRING,RECHERCHE_INDICATIF,"Recherche par indicatif téléphone");
    AppendMenu(hRechAffTri,MF_SEPARATOR,NULL,NULL);
    AppendMenu(hRechAffTri,MF_STRING,RECHERCHE_VILLE,"Recherche par ville");
    AppendMenu(hRechAffTri,MF_SEPARATOR,NULL,NULL);
    AppendMenu(hRechAffTri,MF_STRING,TRI_LISTE,"Tri 1");


    // Menu Enregistrement & chargement

    AppendMenu(hEnregCharg,MF_STRING,ENREGISTREMENT_LISTE,"Enregistrement");
    AppendMenu(hEnregCharg,MF_SEPARATOR,NULL,NULL);
    AppendMenu(hEnregCharg,MF_STRING,CHARGEMENT_LISTE,"Chargement");



    /** Ajout Des Menus Générales **/

    AppendMenu(hMenu,MF_STRING,CREATION, "Création");
    AppendMenu(hMenu,MF_SEPARATOR,NULL,NULL);
    AppendMenu(hMenu,MF_POPUP,(UINT_PTR) hMiseAjour, "Mise à Jour");
    AppendMenu(hMenu,MF_SEPARATOR,NULL,NULL);
    AppendMenu(hMenu,MF_POPUP,(UINT_PTR) hRechAffTri, "Recherche, Affichage & Tri");
    AppendMenu(hMenu,MF_SEPARATOR,NULL,NULL);
    AppendMenu(hMenu,MF_POPUP,(UINT_PTR) hEnregCharg, "Enregistrement & Chargement");
    AppendMenu(hMenu,MF_SEPARATOR,NULL,NULL);
    AppendMenu(hMenu,MF_STRING,QUITTER, "Quitter");
    SetMenu(hwnd,hMenu);



}
