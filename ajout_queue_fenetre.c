#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define AJOUTER_BOUTTON_QUEUE 23

#include "variables.h"
#include "fonctions.h"



HWND ajout_queue_fenetre; //child window
HWND box;
HWND hButton;
HWND hNumero,hNom,hPrenom,hDate,hEmail,hVille,hRue,hCode;



LRESULT CALLBACK AjoutQueueFenetre (HWND hwnd, UINT msg, WPARAM wp , LPARAM lp){


    switch (msg){
    case WM_COMMAND:
        switch (wp){


        case AJOUTER_BOUTTON_QUEUE :
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

                GetWindowText(hNom,nom,35);
                GetWindowText(hPrenom,prenom,35);
                GetWindowText(hNumero,numero,20);
                GetWindowText(hDate,date,35);
                GetWindowText(hEmail,email,90);
                GetWindowText(hVille,ville,35);
                GetWindowText(hRue,rue,35);
                GetWindowText(hCode,code,35);

                if (strcmp(nom,"") == 0 || strcmp(prenom,"") == 0 || strcmp(numero,"") == 0
                    || strcmp(email,"") == 0 || strcmp(date,"") == 0 || strcmp(ville,"") == 0
                    || strcmp(rue,"") == 0 || strcmp (code ,"") == 0){
                    MessageBoxW(hwnd,L" Tous les champs sont requis ",L" Attention !! ",MB_OK | MB_ICONERROR);
                }

                if (verifier_date(date) == -1){
                    MessageBoxW(hwnd,L" Date de Naissance Non Valide ",L" Attention !! ",MB_OK | MB_ICONERROR);
                    SetWindowText(hDate,"");
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
                    && verifier_numero(numero) == 1 && recherche_tel(nouveau_repertoire,numero) == 1){

                    contact cont;
                    cont = saisie_contact(numero,nom,prenom,date,email,ville,rue,code);
                    nouveau_repertoire = insere_queue_tel(nouveau_repertoire,cont);
                    int valeur;
                    valeur = MessageBoxW(hwnd,L" Contact Ajoute Avec Succes ",L" Succes ",MB_OK | MB_ICONINFORMATION);
                    if (valeur == IDOK){
                        SetWindowText(hNumero,"");
                        SetWindowText(hNom,"");
                        SetWindowText(hPrenom,"");
                        SetWindowText(hDate,"");
                        SetWindowText(hEmail,"");
                        SetWindowText(hVille,"");
                        SetWindowText(hRue,"");
                        SetWindowText(hCode,"");
                    }

                    }

            }
        break;


        }
        break;

    case WM_CREATE:
        break;
    case WM_SIZE:
        {
        RECT MainRect;
        int MainWidth, MainHeight;
        GetWindowRect(ajout_queue_fenetre, &MainRect);
        MainWidth = MainRect.right - MainRect.left;
        MainHeight = MainRect.bottom - MainRect.top;
        SetWindowPos(box, hwnd, (MainWidth)/4,(MainHeight)/8, (MainWidth)/2, (MainHeight)-200, SWP_NOZORDER);
        SetWindowPos(hButton, hwnd,(MainWidth-100)/2,600,100,50, SWP_NOZORDER);
        }
        break;

    case WM_CLOSE:
        DestroyWindow(ajout_queue_fenetre);
        break;
    default:
        return DefWindowProcW(hwnd,msg,wp,lp);

    }


}


void registerAjoutQueueClass (HINSTANCE hInstance){

    WNDCLASSW queueFenetre = {0};
    queueFenetre.hbrBackground = (HBRUSH) COLOR_WINDOW;
    queueFenetre.hCursor = LoadCursor(NULL,IDC_ARROW);
    queueFenetre.hInstance = hInstance;
    queueFenetre.lpszClassName = L"AjoutQueueTelephone";
    queueFenetre.lpfnWndProc = AjoutQueueFenetre;

    RegisterClassW(&queueFenetre);

}

HWND displayAjoutQueueFenetre (HWND hwnd){

    ajout_queue_fenetre = CreateWindowW(L"AjoutQueueTelephone",L" Ajouter Nouveau Contact ", WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                  50,50,800,800,hwnd,NULL,NULL,NULL);

    RECT MainRect;
    int MainWidth, MainHeight;
    GetWindowRect(ajout_queue_fenetre, &MainRect);
    MainWidth = MainRect.right - MainRect.left;
    MainHeight = MainRect.bottom - MainRect.top;

    box = CreateWindowW(L"Button", L" Ajouter Nouveau Contact ",WS_CHILD | WS_VISIBLE | BS_GROUPBOX,(MainWidth)/4,(MainHeight)/8, (MainWidth)/2, (MainHeight)-200,ajout_queue_fenetre,NULL,NULL, NULL);


    CreateWindowW(L"Static",L" Numero :",WS_VISIBLE | WS_CHILD | SS_CENTER, 40,90,150,40,box,NULL,NULL,NULL);
    hNumero = CreateWindowW (L"Edit",L"",WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL,190,79,100,40,box,NULL,NULL,NULL);

    CreateWindowW(L"Static",L" Nom :",WS_VISIBLE | WS_CHILD | SS_CENTER, 40,140,150,40,box,NULL,NULL,NULL);
    hNom = CreateWindowW (L"Edit",L"",WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL,190,129,100,40,box,NULL,NULL,NULL);

    CreateWindowW(L"Static",L" Prenom :",WS_VISIBLE | WS_CHILD | SS_CENTER, 40,190,150,40,box,NULL,NULL,NULL);
    hPrenom = CreateWindowW (L"Edit",L"",WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL,190,179,100,40,box,NULL,NULL,NULL);

    CreateWindowW(L"Static",L" Date de Naissance :",WS_VISIBLE | WS_CHILD | SS_CENTER, 40,240,150,40,box,NULL,NULL,NULL);
    hDate = CreateWindowW (L"Edit",L"",WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL,190,229,100,40,box,NULL,NULL,NULL);

    CreateWindowW(L"Static",L" Email :",WS_VISIBLE | WS_CHILD | SS_CENTER, 40,290,100,40,box,NULL,NULL,NULL);
    hEmail = CreateWindowW (L"Edit",L"",WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL,190,279,100,40,box,NULL,NULL,NULL);

    CreateWindowW(L"Static",L" Ville :",WS_VISIBLE | WS_CHILD | SS_CENTER, 40,340,100,40,box,NULL,NULL,NULL);
    hVille = CreateWindowW (L"Edit",L"",WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL,190,329,100,40,box,NULL,NULL,NULL);

    CreateWindowW(L"Static",L" Rue :",WS_VISIBLE | WS_CHILD | SS_CENTER, 40,390,100,40,box,NULL,NULL,NULL);
    hRue = CreateWindowW (L"Edit",L"",WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL,190,379,100,40,box,NULL,NULL,NULL);

    CreateWindowW(L"Static",L" Code :",WS_VISIBLE | WS_CHILD | SS_CENTER, 40,440,100,40,box,NULL,NULL,NULL);
    hCode = CreateWindowW (L"Edit",L"",WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL,190,429,100,40,box,NULL,NULL,NULL);

    hButton = CreateWindowW(L"Button",L"Ajouter",WS_VISIBLE|WS_CHILD,(MainWidth-100)/2,600,100,50,ajout_queue_fenetre,(HMENU)AJOUTER_BOUTTON_QUEUE,NULL,NULL);

    return ajout_queue_fenetre;


}
