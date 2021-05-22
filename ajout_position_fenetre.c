#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define AJOUTER_POSITION 25

#include "variables.h"
#include "fonctions.h"
#include "ajout_position_nombre_fenetre.h"



HWND ajout_position; //child window
HWND hBoxAjoutPositionFenetre;
HWND hButtonAjoutPositionFenetre;
HWND hNumeroAPF,hNomAPF,hPrenomAPF,hDateAPF,hEmailAPF,hVilleAPF,hRueAPF,hCodeAPF;



LRESULT CALLBACK AjoutPositionFenetreProcedure (HWND hwnd, UINT msg, WPARAM wp , LPARAM lp){


    switch (msg){
    case WM_COMMAND:
        switch (wp){


        case AJOUTER_POSITION :
            {
                // variables


                char nom [35];
                char prenom [35];
                char numero [35];
                char date [30];
                char email[35];
                char rue [35];
                char ville[35];
                char code [30];

                // getting input field text

                GetWindowText(hNomAPF,nom,35);
                GetWindowText(hPrenomAPF,prenom,35);
                GetWindowText(hNumeroAPF,numero,20);
                GetWindowText(hDateAPF,date,35);
                GetWindowText(hEmailAPF,email,90);
                GetWindowText(hVilleAPF,ville,35);
                GetWindowText(hRueAPF,rue,35);
                GetWindowText(hCodeAPF,code,35);

                if (strcmp(nom,"") == 0 || strcmp(prenom,"") == 0 || strcmp(numero,"") == 0
                    || strcmp(email,"") == 0 || strcmp(date,"") == 0 || strcmp(ville,"") == 0
                    || strcmp(rue,"") == 0 || strcmp (code ,"") == 0){
                    MessageBoxW(hwnd,L" Tous les champs sont requis ",L" Attention !! ",MB_OK | MB_ICONERROR);
                }

                if (verifier_date(date) == -1){
                    MessageBoxW(hwnd,L" Date de Naissance Non Valide ",L" Attention !! ",MB_OK | MB_ICONERROR);
                    SetWindowText(hDateAPF,"");
                }

                if (verifier_numero(numero) == -1){
                    MessageBoxW(hwnd,L" Numero Non Valide ",L" Attention !! ",MB_OK | MB_ICONERROR);
                    SetWindowText(hNumero,"");
                }

                if (recherche_tel(nouveau_repertoire,numero) == -1){

                    MessageBoxW(hwnd,L" Numero deja Existant ",L" Attention !! ",MB_OK | MB_ICONEXCLAMATION);
                    SetWindowText(hNumero,"");
                }

                if (strcmp(nom,"") != 0 && strcmp(prenom,"") != 0 && strcmp(numero,"") != 0
                    && strcmp(email,"") != 0 && strcmp(date,"") != 0 && strcmp(ville,"") != 0
                    && strcmp(rue,"") != 0 && strcmp (code ,"") != 0 && verifier_date(date) == 1
                    && verifier_numero(numero) == 1 && recherche_tel(nouveau_repertoire,numero) == 1 ){

                    contact cont;
                    cont = saisie_contact(numero,nom,prenom,date,email,ville,rue,code);
                    insere_pos_tel(nouveau_repertoire,cont,position);
                    int valeur;
                    valeur = MessageBoxW(hwnd,L" Contact Ajoute Avec Succes ",L" Succes ",MB_OK | MB_ICONINFORMATION);
                    if (valeur == IDOK){
                        DestroyWindow(ajout_position);
                        DestroyWindow(ajout_position_nombre);
                    }

                    }

            }
        break;


        }
        break;

    case WM_CREATE:
        printf("%d\n",position);
        EnableWindow(ajout_position_nombre,FALSE);
        break;
    case WM_SIZE:
        {
        RECT MainRect;
        int MainWidth, MainHeight;
        GetWindowRect(ajout_position, &MainRect);
        MainWidth = MainRect.right - MainRect.left;
        MainHeight = MainRect.bottom - MainRect.top;
        SetWindowPos(hBoxAjoutPositionFenetre, hwnd, (MainWidth)/4,(MainHeight)/8, (MainWidth)/2, (MainHeight)-200, SWP_NOZORDER);
        SetWindowPos(hButton, hwnd,(MainWidth-100)/2,600,100,50, SWP_NOZORDER);
        }
        break;

    case WM_CLOSE:
        DestroyWindow(ajout_position);
        DestroyWindow(ajout_position_nombre);
        break;
    default:
        return DefWindowProcW(hwnd,msg,wp,lp);

    }


}


void registerAjoutPositionFenetre (HINSTANCE hInstance){

    WNDCLASSW ajoutPosFen = {0};
    ajoutPosFen.hbrBackground = (HBRUSH) COLOR_WINDOW;
    ajoutPosFen.hCursor = LoadCursor(NULL,IDC_ARROW);
    ajoutPosFen.hInstance = hInstance;
    ajoutPosFen.lpszClassName = L"AjouterPositionFenetre";
    ajoutPosFen.lpfnWndProc = AjoutPositionFenetreProcedure;

    RegisterClassW(&ajoutPosFen);

}

HWND displayAjoutPositionFenetre (HWND hwnd){

    ajout_position = CreateWindowW(L"AjouterPositionFenetre",L" Ajouter Nouveau Contact ", WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                  50,50,800,800,hwnd,NULL,NULL,NULL);

    RECT MainRect;
    int MainWidth, MainHeight;
    GetWindowRect(ajout_position, &MainRect);
    MainWidth = MainRect.right - MainRect.left;
    MainHeight = MainRect.bottom - MainRect.top;

    hBoxAjoutPositionFenetre = CreateWindowW(L"Button", L" Ajouter Nouveau Contact ",WS_CHILD | WS_VISIBLE | BS_GROUPBOX,(MainWidth)/4,(MainHeight)/8, (MainWidth)/2, (MainHeight)-200,ajout_position,NULL,NULL, NULL);


    CreateWindowW(L"Static",L" Numero :",WS_VISIBLE | WS_CHILD | SS_CENTER, 40,90,150,40,hBoxAjoutPositionFenetre,NULL,NULL,NULL);
    hNumeroAPF = CreateWindowW (L"Edit",L"",WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL,190,79,100,40,hBoxAjoutPositionFenetre,NULL,NULL,NULL);

    CreateWindowW(L"Static",L" Nom :",WS_VISIBLE | WS_CHILD | SS_CENTER, 40,140,150,40,hBoxAjoutPositionFenetre,NULL,NULL,NULL);
    hNomAPF = CreateWindowW (L"Edit",L"",WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL,190,129,100,40,hBoxAjoutPositionFenetre,NULL,NULL,NULL);

    CreateWindowW(L"Static",L" Prenom :",WS_VISIBLE | WS_CHILD | SS_CENTER, 40,190,150,40,hBoxAjoutPositionFenetre,NULL,NULL,NULL);
    hPrenomAPF = CreateWindowW (L"Edit",L"",WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL,190,179,100,40,hBoxAjoutPositionFenetre,NULL,NULL,NULL);

    CreateWindowW(L"Static",L" Date de Naissance :",WS_VISIBLE | WS_CHILD | SS_CENTER, 40,240,150,40,hBoxAjoutPositionFenetre,NULL,NULL,NULL);
    hDateAPF = CreateWindowW (L"Edit",L"",WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL,190,229,100,40,hBoxAjoutPositionFenetre,NULL,NULL,NULL);

    CreateWindowW(L"Static",L" Email :",WS_VISIBLE | WS_CHILD | SS_CENTER, 40,290,100,40,hBoxAjoutPositionFenetre,NULL,NULL,NULL);
    hEmailAPF = CreateWindowW (L"Edit",L"",WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL,190,279,100,40,hBoxAjoutPositionFenetre,NULL,NULL,NULL);

    CreateWindowW(L"Static",L" Ville :",WS_VISIBLE | WS_CHILD | SS_CENTER, 40,340,100,40,hBoxAjoutPositionFenetre,NULL,NULL,NULL);
    hVilleAPF = CreateWindowW (L"Edit",L"",WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL,190,329,100,40,hBoxAjoutPositionFenetre,NULL,NULL,NULL);

    CreateWindowW(L"Static",L" Rue :",WS_VISIBLE | WS_CHILD | SS_CENTER, 40,390,100,40,hBoxAjoutPositionFenetre,NULL,NULL,NULL);
    hRueAPF = CreateWindowW (L"Edit",L"",WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL,190,379,100,40,hBoxAjoutPositionFenetre,NULL,NULL,NULL);

    CreateWindowW(L"Static",L" Code :",WS_VISIBLE | WS_CHILD | SS_CENTER, 40,440,100,40,hBoxAjoutPositionFenetre,NULL,NULL,NULL);
    hCodeAPF = CreateWindowW (L"Edit",L"",WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL,190,429,100,40,hBoxAjoutPositionFenetre,NULL,NULL,NULL);

    hButtonAjoutPositionFenetre = CreateWindowW(L"Button",L"Ajouter",WS_VISIBLE|WS_CHILD,(MainWidth-100)/2,600,100,50,ajout_position,(HMENU)AJOUTER_POSITION,NULL,NULL);

    return ajout_position;


}
