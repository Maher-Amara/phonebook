#ifndef AFFICHAGE_H_INCLUDED
#define AFFICHAGE_H_INCLUDED

LRESULT CALLBACK AffichageProcedure (HWND hwnd, UINT msg, WPARAM wp , LPARAM lp);
void registerAffichageClass(HINSTANCE hInstance);
HWND displayAffichage (HWND hwnd);

HWND affichage_window;
HWND hListView;

#include "affichage.c"

#endif // AFFICHAGE_H_INCLUDED
