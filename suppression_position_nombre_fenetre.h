#ifndef SUPPRESSION_POSITION_NOMBRE_FENETRE_H_INCLUDED
#define SUPPRESSION_POSITION_NOMBRE_FENETRE_H_INCLUDED

LRESULT CALLBACK SuppressionPositionNombreFenetreProcedure (HWND hwnd, UINT msg, WPARAM wp , LPARAM lp);
void registerSuppressionPositionNombreFenetre (HINSTANCE hInstance);
HWND displaySuppressionPositionNombreFenetre (HWND hwnd);

HWND suppression_position_nombre;
int position_suppression;

#include "suppression_position_nombre_fenetre.c"

#endif // SUPPRESSION_POSITION_NOMBRE_FENETRE_H_INCLUDED
