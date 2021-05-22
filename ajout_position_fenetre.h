#ifndef AJOUT_POSITION_FENETRE_H_INCLUDED
#define AJOUT_POSITION_FENETRE_H_INCLUDED


HWND ajout_position;

LRESULT CALLBACK AjoutPositionFenetreProcedure (HWND hwnd, UINT msg, WPARAM wp , LPARAM lp);
void registerAjoutPositionFenetre (HINSTANCE hInstance);
HWND displayAjoutPositionFenetre (HWND hwnd);

#include "ajout_position_fenetre.c"

#endif // AJOUT_POSITION_FENETRE_H_INCLUDED
