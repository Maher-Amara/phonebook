#include<windows.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "variables.h"



 /****************************************************************************
*
*
*    FONCTION: taille_liste_rep
*
*    BUT: renvoie la taille du r�paertoire t�l�phonique.
*
****************************************************************************/


int taille_liste_rep (repertoire rt){

    repertoire r = rt;
    int taille = 0;
    while( r != NULL){
        taille ++;
        r = r->suiv;
    }

    return taille;

}

 /****************************************************************************
*
*
*    FONCTION: recherche_tel
*
*    BUT: v�rifie si un numero est d�ja existant.
*
****************************************************************************/

 int recherche_tel (repertoire rt, char num[35] ){

    repertoire r =rt;
    while (r != NULL){
        if (strcmp(r->cont.numero,num) == 0){
            return -1;
        }
        r=r->suiv;
    }
    return 1;

 }
  /****************************************************************************
*
*
*    FONCTION: insere_tete_tel
*
*    BUT: inserer un contact en t�te du r�pertoire
*
****************************************************************************/

repertoire insere_tete_tel(repertoire rt, contact cont){

    repertoire r;
    r = (repertoire)malloc(sizeof(contact));
    r ->suiv = rt;
    r->cont = cont;
    rt = r;
    return rt;
}

 /****************************************************************************
*
*
*    FONCTION: insere_queue_tel
*
*    BUT: inserer un contact en queue du r�pertoire
*
****************************************************************************/

repertoire insere_queue_tel (repertoire rt, contact cont){

    repertoire r1, r2;
    r1 = (repertoire) malloc(sizeof(contact));
    r1->cont = cont;
    r1->suiv =  NULL;
    if (rt == NULL){
        rt = r1;
    }
    else{
        r2 = rt;
        while (r2->suiv != NULL){
            r2 = r2->suiv;
        }
        r2->suiv = r1;
    }

    return rt;

}
 /****************************************************************************
*
*
*    FONCTION: insere_pos_tel
*
*    BUT: inserer un contact dans une position pr�cis�e dans le r�pertoire.
*
****************************************************************************/
void insere_pos_tel (repertoire rt, contact cont, int position){

    repertoire r2, r1 = rt;
    int i = 1;
    while (i<position - 1){
        r1 = r1->suiv;
        i ++;
    }

    r2 = (repertoire) malloc (sizeof(contact));
    r2->cont = cont;
    r2->suiv = r1 -> suiv;
    r1->suiv = r2;



}
 /****************************************************************************
*
*
*    FONCTION: supprimer_tete_tel
*
*    BUT: supprimer un contact en t�te du r�pertoire
*
****************************************************************************/

repertoire supprimer_tete_tel(repertoire rt){

    repertoire r = NULL;
    r = rt;
    rt = rt->suiv;
    free (r);
    return rt;


}

 /****************************************************************************
*
*
*    FONCTION: supprimer_queue_tel
*
*    BUT: supprimer un contact en queue du r�pertoire
*
****************************************************************************/

repertoire supprimer_queue_tel (repertoire rt){

    repertoire r1 = rt;

    while (r1->suiv->suiv != NULL){
        r1 = r1->suiv;
    }
    free(r1->suiv);
    r1->suiv = NULL;
    return rt;

}
 /****************************************************************************
*
*
*    FONCTION: supprimer_pos_tel
*
*    BUT: supprimer un contact dans une position donn�e
*
****************************************************************************/

void supprimer_pos_tel (repertoire rt, int position){

    repertoire r1 = rt, r2;


    if (position == 1){
        free(r1->suiv);
        r1->suiv = NULL;
    }

    else{
        int i =1;
        while (i < position - 1){
            r1 = r1->suiv;
            i++;
        }

        r2 = r1->suiv->suiv;
        free(r1->suiv);
        r1 ->suiv = r2;
    }


}


 /****************************************************************************
*
*
*    FONCTION: creation
*
*    BUT: creation d'un contact � partir d'un String
*    (� utiliser avec la fonction recuperation).
*
****************************************************************************/

contact creation (char contact_info [500]){

    char *ptr = strtok(contact_info,",");
    char *data [9]; // contient la date apr�s s�paration jour,mois,ann�e
    int i =0;

    while (ptr != NULL){
        data[i++] = ptr;
        ptr = strtok(NULL,",");
    }

    contact cont ;
    strcpy(cont.numero,data[0]);
    strcpy(cont.nom,data[1]);
    strcpy(cont.prenom,data[2]);
    strcpy(cont.date_naissance,data[3]);
    strcpy(cont.email,data[4]);
    strcpy(cont.adr.ville,data[5]);
    strcpy(cont.adr.rue,data [6]);
    strcpy(cont.adr.code,data [7]);

    return cont;


}
 /****************************************************************************
*
*
*    FONCTION: verifier_date
*
*    BUT: v�rifie si une date de naissance est l�gitime.
*
****************************************************************************/

int verifier_date (char date [20]){


        char date_naissance [20];
        strcpy(date_naissance,date);
        int i =0;


       char *ptr = strtok(date_naissance,"/");
       char *data [3]; // contient la date apr�s s�paration jour,mois,ann�e

       while (ptr != NULL){
        data[i++] = ptr;
        ptr = strtok(NULL,"/");
       }


        if (strlen(date) != 10 || strlen(data[0]) != 2 || // v�rifier si la date est sous la forme jj/mm/aaaa
            strlen(data[1]) != 2 || strlen(data[2]) != 4 || i != 3 ){
                return -1;
            }

        int jour = atoi(data[0]); // convertir jour , mois annee en intger
        int mois = atoi(data[1]);
        int annee = atoi(data[2]);

        int bissextile = 0;
        int mois_max = 12;
        int jour_max = 0;

        // verifier si l'ann�e est bissextile
        if (((annee%4 == 0) && (annee%100 != 0)) || annee%400 == 0){

            bissextile = 1;
        }
        else{
            bissextile = 0;
        }

        // verifier si mois>0 && mois<=12
        if (mois <0 || mois > mois_max){
            return -1;
        }

        switch(mois){
        case 4:
        case 6:
        case 9:
        case 11:
            jour_max = 30;
            break;
        case 2:
            if (bissextile == 1){
                jour_max = 29;
            }
            else{
                jour_max = 28;
            }
            break;
        default:
            jour_max = 31;


        }

        if (jour<0 || jour>jour_max){
            return -1;
        }



        return 1;




}

 /****************************************************************************
*
*
*    FONCTION: verifier_numero
*
*    BUT: v�rifie si un num�ro est l�gitime (compos� de 8 numero)
*
****************************************************************************/

int verifier_numero(char numero [30]){

    int num_telephone;
    char indicatif [10];
    int i = 0;
    int k = 0;
    char num_telephone_string [15];


    int len = strlen(numero);
    printf("%d\n",len);

    for (i=4; i <= len; i++){
        num_telephone_string[k] = numero[i];
        k ++;
    }
    printf("%s\n",num_telephone_string);

    strncpy(indicatif,numero,4);
    printf("%s\n",indicatif);

    num_telephone = atoi(num_telephone_string);
    printf("%d\n",num_telephone);

    int longueur = floor(log10(num_telephone))+1; // longeur du numero doit �tre compos� de 8 num�ros.

    if (strchr(indicatif,'+') < 0){
        return -1 ;
    }

    if ((longueur < 8) || num_telephone < 0 || strlen(numero) != 12 || strlen(num_telephone_string) != 8)
        return -1;

    return 1; // numero valide

}

 /****************************************************************************
*
*
*    FONCTION: afficher
*
*    BUT: afficher tout les contacts
*
****************************************************************************/

void afficher (repertoire rt){

    repertoire r = rt;
    if (r == NULL)
        printf("Liste vide");
    else {
        while (r != NULL){
           printf("%s\n",r->cont.numero);
           printf("%s\n",r->cont.nom);
           printf("%s\n",r->cont.prenom);
           printf("%s\n",r->cont.date_naissance);
           printf("%s\n",r->cont.email);
           printf("%s\n",r->cont.adr.code);
           printf("%s\n",r->cont.adr.ville);
           printf("%s\n",r->cont.adr.rue);
            r = r->suiv;
        }
    }

}

 /****************************************************************************
*
*
*    FONCTION: saisie_contact
*
*    BUT: saisie des donn�es d'un contact
*
****************************************************************************/

contact saisie_contact(char numero [30],char nom [30], char prenom [30], char date [30],
                       char email [35], char ville [35], char rue [35], char code [35] ){

            contact cont;

            strcpy(cont.numero,numero);
            strcpy(cont.nom,nom);
            strcpy(cont.prenom,prenom);
            strcpy(cont.date_naissance,date);
            strcpy(cont.email,email);
            strcpy(cont.adr.ville,ville);
            strcpy(cont.adr.rue,rue);
            strcpy(cont.adr.code,code);

            return cont;
}
