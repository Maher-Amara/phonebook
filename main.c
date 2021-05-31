#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "variables.h"
#include "fonctions.h"
#include "enreg&recup.h"
#include "menus.h"


#include "ajout_tete_fenetre.h"
#include "ajout_queue_fenetre.h"
#include "ajout_position_fenetre.h"
#include "affichage.h"
#include "ajout_position_nombre_fenetre.h"
#include "suppression_position_nombre_fenetre.h"



HWND main_window; //handler for main window
int repertoire_chargement = 0;
int repertoire_creation = 0;
LRESULT CALLBACK WindowProcedure (HWND,UINT,WPARAM,LPARAM);



int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR args, int ncmdShow){

    WNDCLASS wc = {0};
    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.hCursor = LoadCursor(NULL,IDC_ARROW);
    wc.hInstance = hInstance;
    wc.lpszClassName = L"mainWindow";
    wc.lpfnWndProc = WindowProcedure;

    if (!RegisterClassW(&wc))
        return -1;

    /** REGISTER CHILD WINDOWS HERE **/

    registerDialogClass(hInstance);
    registerAffichageClass(hInstance);
    registerAjoutQueueClass(hInstance);
    registerAjoutPositionNombreFenetre(hInstance);
    registerAjoutPositionFenetre(hInstance);
    registerSuppressionPositionNombreFenetre (hInstance);



    /** CREATING MAIN WINDOW **/

    main_window = CreateWindowW(L"mainWindow",L"Repertoire telephonique",WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                                100,100,800,800,NULL,NULL,NULL,NULL);
    MSG msg = {0};
    while(GetMessage(&msg,NULL,NULL,NULL)){
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}



/** PROCEDURE FOR MAIN WINDOW **/
LRESULT CALLBACK WindowProcedure (HWND hwnd,UINT msg,WPARAM wp,LPARAM lp){

    switch(msg){

    case WM_CREATE:
        addMenus(hwnd);
        break;

    case WM_COMMAND:
        switch (wp){

        case QUITTER:
            {
                int valeur;
                valeur = MessageBoxW(hwnd,L" Voulez-Vous Vraiment Quitter ? ",L" Attendez  ",MB_YESNO | MB_ICONASTERISK);
                if (valeur == IDYES)
                {
                    DestroyWindow(hwnd);
                }

            }
            break;
        case AJOUT_TETE:
            {
                if (repertoire_creation == 1){
                    child_window =  displayDialog(hwnd);
                }
                else{
                    MessageBoxW(hwnd,L" Veuillez creer Le Repertoire D'abord !  ",L" Attention !! ",MB_OK | MB_ICONERROR);
                }



            }
            break;

        case AJOUT_QUEUE:
            {
                if (repertoire_creation == 1){
                    ajout_queue_fenetre = displayAjoutQueueFenetre(hwnd);
                }
                else{
                    MessageBoxW(hwnd,L" Veuillez creer Le Repertoire D'abord !  ",L" Attention !! ",MB_OK | MB_ICONERROR);
                }

            }
            break;

        case AJOUT_POSITION:
            {

                if (repertoire_creation == 1){
                    ajout_position_nombre = displayAjoutPositionNombreFenetre(hwnd);
                }
                else{
                    MessageBoxW(hwnd,L" Veuillez creer Le Repertoire D'abord !  ",L" Attention !! ",MB_OK | MB_ICONERROR);
                }

            }
            break;
        case SUPPRESSION_TETE:
            {
                if (repertoire_creation == 1){
                    if (nouveau_repertoire != NULL){
                        int valeur;
                        valeur = MessageBoxW(hwnd,L" Vous allez Supprimer le premier element De votre Repertoire. Continuez ? !  ",L" Attendez !! ",MB_YESNO | MB_ICONINFORMATION);
                        if (valeur == IDYES){
                            nouveau_repertoire = supprimer_tete_tel(nouveau_repertoire);
                            HWND affichage_window = displayAffichage(hwnd);
                            afficher(nouveau_repertoire);
                        }
                    }
                    else{
                        MessageBoxW(hwnd,L" Repertoire Vide !  ",L" Attention !! ",MB_OK | MB_ICONEXCLAMATION);
                    }
                }
                else{
                    MessageBoxW(hwnd,L" Veuillez creer Le Repertoire D'abord !  ",L" Attention !! ",MB_OK | MB_ICONERROR);
                }
            }
            break;
        case SUPPRESSION_QUEUE:
            {
                if (repertoire_creation == 1){
                    if (nouveau_repertoire != NULL){
                            int valeur = MessageBoxW(hwnd,L" Vous allez Supprimer le dernier element De votre Repertoire. Continuez ? !  ",L" Attendez !! ",MB_YESNO | MB_ICONINFORMATION);
                            if (valeur == IDYES){
                                nouveau_repertoire = supprimer_queue_tel(nouveau_repertoire);
                                HWND affichage_window = displayAffichage(hwnd);
                            }

                    }
                    else{
                        MessageBoxW(hwnd,L" Repertoire Vide !  ",L" Attention !! ",MB_OK | MB_ICONEXCLAMATION);
                    }
                }
                else{
                    MessageBoxW(hwnd,L" Veuillez creer Le Repertoire D'abord !  ",L" Attention !! ",MB_OK | MB_ICONERROR);
                }
            }
            break;
        case SUPPRESSION_POSITION:
            {
                if (repertoire_creation == 1){
                    suppression_position_nombre = displaySuppressionPositionNombreFenetre(hwnd);

                }
                else{
                    MessageBoxW(hwnd,L" Veuillez creer Le Repertoire D'abord !  ",L" Attention !! ",MB_OK | MB_ICONERROR);
                }

            }
            break;

        case CONTENU_LISTE:
            {
                if (repertoire_creation == 1){
                    HWND affichage_window = displayAffichage(hwnd);
                }
                else{
                    MessageBoxW(hwnd,L" Veuillez creer Le Repertoire D'abord !  ",L" Attention !! ",MB_OK | MB_ICONERROR);
                }

            }
            break;

        case ENREGISTREMENT_LISTE:
            {
                if (nouveau_repertoire != NULL){
                    enregistrer(nouveau_repertoire,"repertoire.txt");
                    MessageBoxW(hwnd,L" Repertoire enregistre avec Succes ",L" Succes ",MB_OK | MB_ICONINFORMATION);
                }
                else{
                    int valeur;
                    valeur = MessageBoxW(hwnd,L" Votre repertoire est vide , Voulez vous l'enregistrer quand meme ? ",L" Attention !! ",MB_YESNO | MB_ICONEXCLAMATION);
                    if (valeur == IDYES){
                        enregistrer(nouveau_repertoire,"repertoire.txt");
                        MessageBoxW(hwnd,L" Repertoire enregistre avec Succes ",L" Succes ",MB_OK | MB_ICONINFORMATION);
                    }
                }

            }
            break;

        case CHARGEMENT_LISTE:
            {
                if (repertoire_chargement == 0){
                    nouveau_repertoire = recuperation(nouveau_repertoire,"repertoire.txt");
                    MessageBoxW(hwnd,L" Repertoire recupere avec Succes ",L" Succes ",MB_OK | MB_ICONINFORMATION);
                    repertoire_chargement = 1;
                }
                else{
                    MessageBoxW(hwnd,L" Repertoire deja charge ",L" Attention !! ",MB_OK | MB_ICONINFORMATION);
                }

            }
            break;

        case CREATION:
            {
                if (repertoire_chargement == 0){
                    MessageBoxW(hwnd,L" Veuillez charger Le Repertoire D'abord !  ",L" Attention !! ",MB_OK | MB_ICONERROR);
                }
                else{
                        if (repertoire_creation == 0){
                            MessageBoxW(hwnd,L" Repertoire cree avec Succes ",L" Succes ",MB_OK | MB_ICONINFORMATION);
                            repertoire_creation = 1;
                        }
                        else{
                            MessageBoxW(hwnd,L" Repertoire deja Cree ",L" Succes ",MB_OK | MB_ICONINFORMATION);
                        }


                }

            }
            break;
        }
        break;
    case WM_DESTROY :
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProcW(hwnd,msg,wp,lp);
        break;

    }

}

