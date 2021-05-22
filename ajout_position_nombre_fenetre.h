#ifndef AJOUT_POSITION_NOMBRE_FENETRE_H_INCLUDED
#define AJOUT_POSITION_NOMBRE_FENETRE_H_INCLUDED


HWND ajout_position_nombre;
int position;


LRESULT CALLBACK AjoutPositionNombreFenetreProcedure (HWND hwnd, UINT msg, WPARAM wp , LPARAM lp);
void registerAjoutPositionNombreFenetre (HINSTANCE hInstance);
HWND displayAjoutPositionNombreFenetre (HWND hwnd);


#include "ajout_position_nombre_fenetre.c"


#endif // AJOUT_POSITION_NOMBRE_FENETRE_H_INCLUDED
