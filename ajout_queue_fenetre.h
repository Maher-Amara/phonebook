#ifndef AJOUT_QUEUE_FENETRE_H_INCLUDED
#define AJOUT_QUEUE_FENETRE_H_INCLUDED

HWND ajout_queue_fenetre;

LRESULT CALLBACK AjoutQueueFenetre (HWND hwnd, UINT msg, WPARAM wp , LPARAM lp);
void registerAjoutQueueClass (HINSTANCE hInstance);
HWND displayAjoutQueueFenetre (HWND hwnd);

#include "ajout_queue_fenetre.c"
#endif // AJOUT_QUEUE_FENETRE_H_INCLUDED
