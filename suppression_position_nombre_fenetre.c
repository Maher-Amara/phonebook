#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "variables.h"
#include "fonctions.h"
#include "ajout_position_fenetre.h"
#include "affichage.h"

#define SUPPRESSION_POSITION_NOMBRE 26

HWND suppression_position_nombre;
HWND box;
HWND hButton;
HWND hPosition;
int position_suppression;

LRESULT CALLBACK SuppressionPositionNombreFenetreProcedure (HWND hwnd, UINT msg, WPARAM wp , LPARAM lp){


    switch (msg){
    case WM_COMMAND:
        switch (wp){


        case SUPPRESSION_POSITION_NOMBRE :
            {
                // variables

                char pos [35];



                // getting input field text

                GetWindowText(hPosition,pos,35);
                //printf("%s\n",pos);
                position_suppression = atoi(pos);
                //printf("%d\n",position);
                int taille = taille_liste_rep(nouveau_repertoire);
                printf("%d\n",taille);
                if(position_suppression< 1 || position_suppression > taille){
                    MessageBoxW(hwnd,L" Position Erronee (sup a la taille du repertoire ou inferieure a 0) ",L" Erreur ",MB_OK | MB_ICONERROR);
                    SetWindowText(hPosition,"");
                }
                if (position_suppression == 1 || position_suppression == taille){
                    MessageBoxW(hwnd,L" Position egale a la tete ou a la queue du repertoire. Utilisez supprimer tete ou supprimer queue ",L" Attention ",MB_OK | MB_ICONEXCLAMATION);
                    SetWindowText(hPosition,"");
                }
                if (position_suppression> 1 && position_suppression < taille){

                    int valeur = MessageBoxW(hwnd,L" Vous voulez supprimer ce contact ? ",L" Attention ",MB_YESNO| MB_ICONEXCLAMATION);
                    EnableWindow(suppression_position_nombre,FALSE);
                    if (valeur == IDYES){
                        supprimer_pos_tel(nouveau_repertoire,position_suppression);
                        HWND affichage_window = displayAffichage(hwnd);
                        MessageBoxW(hwnd,L" Contact Supprime Avec succes ",L" Succes ",MB_OK| MB_ICONINFORMATION);
                        EnableWindow(suppression_position_nombre,TRUE);
                    }
                    else{
                        EnableWindow(suppression_position_nombre,TRUE);
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
        GetWindowRect(suppression_position_nombre, &MainRect);
        MainWidth = MainRect.right - MainRect.left;
        MainHeight = MainRect.bottom - MainRect.top;
        SetWindowPos(box, hwnd, (MainWidth)/4,(MainHeight)/8, (MainWidth)/2, (MainHeight)-200, SWP_NOZORDER);
        SetWindowPos(hButton, hwnd,(MainWidth-100)/2,MainHeight-140,100,50, SWP_NOZORDER);
        }
        break;

    case WM_CLOSE:
        DestroyWindow(suppression_position_nombre);
        break;
    default:
        return DefWindowProcW(hwnd,msg,wp,lp);

    }


}


void registerSuppressionPositionNombreFenetre (HINSTANCE hInstance){

    WNDCLASSW suppPosNom = {0};
    suppPosNom.hbrBackground = (HBRUSH) COLOR_WINDOW;
    suppPosNom.hCursor = LoadCursor(NULL,IDC_ARROW);
    suppPosNom.hInstance = hInstance;
    suppPosNom.lpszClassName = L"SuppressionPositionNombreFenetre";
    suppPosNom.lpfnWndProc = SuppressionPositionNombreFenetreProcedure;

    RegisterClassW(&suppPosNom);

}


HWND displaySuppressionPositionNombreFenetre (HWND hwnd){

    suppression_position_nombre = CreateWindowW(L"SuppressionPositionNombreFenetre",L" Entrez une Position ", WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                  50,50,400,400,hwnd,NULL,NULL,NULL);

    RECT MainRect;
    int MainWidth, MainHeight;
    GetWindowRect(suppression_position_nombre, &MainRect);
    MainWidth = MainRect.right - MainRect.left;
    MainHeight = MainRect.bottom - MainRect.top;

    box = CreateWindowW(L"Button", L" Position ",WS_CHILD | WS_VISIBLE | BS_GROUPBOX,(MainWidth)/4,(MainHeight)/8, (MainWidth)/2, (MainHeight)-200,suppression_position_nombre,NULL,NULL, NULL);


    CreateWindowW(L"Static",L" Position :",WS_VISIBLE | WS_CHILD | SS_CENTER, 10,80,120,40,box,NULL,NULL,NULL);
    hPosition = CreateWindowW (L"Edit",L"",WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL,110,70,50,40,box,NULL,NULL,NULL);
    hButton = CreateWindowW(L"Button",L"Choisir",WS_VISIBLE|WS_CHILD,(MainWidth-100)/2,MainHeight-140,100,50,suppression_position_nombre,(HMENU)SUPPRESSION_POSITION_NOMBRE,NULL,NULL);

    return suppression_position_nombre;


}
