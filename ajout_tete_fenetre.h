#ifndef AJOUT_TETE_FENETRE_H_INCLUDED
#define AJOUT_TETE_FENETRE_H_INCLUDED

LRESULT CALLBACK DialogProcedure (HWND hwnd, UINT msg, WPARAM xp , LPARAM lp);
void registerDialogClass(HINSTANCE hInstance);
HWND displayDialog(HWND hwnd);


HWND child_window; //child window
HWND box;
HWND hButton;
HWND hNumero,hNom,hPrenom,hDate,hEmail,hVille,hRue,hCode;

#include "ajout_tete_fenetre.c"

#endif // AJOUT_TETE_FENETRE_H_INCLUDED
