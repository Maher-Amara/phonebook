#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

/******************Fonction Taille******************/
int taille_liste_rep(liste_rep l)
{
    int n=0;
    while(l)
    {
        n++;
        l=l->suiv;
    }
    return n;
}

/******************Fonction Recherche Telephone******************/
liste_rep recherche_tel(liste_rep l, char mat[])
{
    liste_rep p=l;
    while(p)
    {
        if(strcmp(p->info.numtel,mat)==0)
            return p;
        p=p->suiv;
    }
    return NULL;
}

/******************Fonction Recherche Nom******************/
liste_rep recherche_nom(liste_rep l, char mat[])
{
    liste_rep p=l;
    while(p)
    {
        if(strcmp(p->info.nom,mat)==0)
            return p;
        p=p->suiv;
    }
    return NULL;
}

/******************Fonction Recherche Ville******************/
liste_rep recherche_ville(liste_rep l, char mat[])
{
    liste_rep p=l;
    while(p)
    {
        if(strcmp(p->info.adresse.ville,mat)==0)
            return p;
        p=p->suiv;
    }
    return NULL;
}

/******************Fonction Recherche Indicatif******************/
liste_rep recherche_indicatif(liste_rep l, char mat[])
{
    liste_rep p=l;
    long int val,num;
    num=atol(mat);
    while(p)
    {
        val=atol(p->info.numtel);
        if(val/1000000==num)
            return p;
        p=p->suiv;
    }
    return NULL;
}

/******************Fonction Taille******************/
int taille_liste_rep(liste_rep l)
{
    int n=0;
    while(l)
    {
        n++;
        l=l->suiv;
    }
    return n;
}

/******************Fonction Recherche Telephone******************/
liste_rep recherche_tel(liste_rep l, char mat[])
{
    liste_rep p=l;
    while(p)
    {
        if(strcmp(p->info.numtel,mat)==0)
            return p;
        p=p->suiv;
    }
    return NULL;
}

/******************Fonction Recherche Nom******************/
liste_rep recherche_nom(liste_rep l, char mat[])
{
    liste_rep p=l;
    while(p)
    {
        if(strcmp(p->info.nom,mat)==0)
            return p;
        p=p->suiv;
    }
    return NULL;
}

/******************Fonction Recherche Ville******************/
liste_rep recherche_ville(liste_rep l, char mat[])
{
    liste_rep p=l;
    while(p)
    {
        if(strcmp(p->info.adresse.ville,mat)==0)
            return p;
        p=p->suiv;
    }
    return NULL;
}

/******************Fonction Recherche Indicatif******************/
liste_rep recherche_indicatif(liste_rep l, char mat[])
{
    liste_rep p=l;
    long int val,num;
    num=atol(mat);
    while(p)
    {
        val=atol(p->info.numtel);
        if(val/1000000==num)
            return p;
        p=p->suiv;
    }
    return NULL;
}

/******************Fonction Taille******************/
int taille_liste_rep(liste_rep l)
{
    int n=0;
    while(l)
    {
        n++;
        l=l->suiv;
    }
    return n;
}

/******************Fonction Recherche Telephone******************/
liste_rep recherche_tel(liste_rep l, char mat[])
{
    liste_rep p=l;
    while(p)
    {
        if(strcmp(p->info.numtel,mat)==0)
            return p;
        p=p->suiv;
    }
    return NULL;
}

/******************Fonction Recherche Nom******************/
liste_rep recherche_nom(liste_rep l, char mat[])
{
    liste_rep p=l;
    while(p)
    {
        if(strcmp(p->info.nom,mat)==0)
            return p;
        p=p->suiv;
    }
    return NULL;
}

/******************Fonction Recherche Ville******************/
liste_rep recherche_ville(liste_rep l, char mat[])
{
    liste_rep p=l;
    while(p)
    {
        if(strcmp(p->info.adresse.ville,mat)==0)
            return p;
        p=p->suiv;
    }
    return NULL;
}

/******************Fonction Recherche Indicatif******************/
liste_rep recherche_indicatif(liste_rep l, char mat[])
{
    liste_rep p=l;
    long int val,num;
    num=atol(mat);
    while(p)
    {
        val=atol(p->info.numtel);
        if(val/1000000==num)
            return p;
        p=p->suiv;
    }
    return NULL;
}
/******************Fonction Valide Ville******************/
int valide_ville(adr x)
{
    int j;
    for(j=0;j<strlen(x.ville);j++)
    {
        if (isdigit(x.ville[j])==1)
            return 0;
    }
}

/******************Fonction Valide Nom******************/
int valide_nom(char x[])
{
    int j;
    for(j=0;j<strlen(x);j++)
    {
        if (isdigit(x[j])==1)
            return 0;
    }
}

/******************Fonction Valide Email******************/
int valide_email(char x[])
{
    int i,rep=0,j;
    for (j=0;j<strlen(x);j++)
    {
        if (x[j]=='@')
            rep++;
    }
    if (rep!=1)
        return 0;
    else
        if (x[1]=='@')
            return 0;
        else
            for(i=1;i<strlen(x)-5;i++)
            {
                if (x[i]=='@')
                    return 1;
            }
}

/******************Fonction Saisie Date******************/
date saisie_date()
{
    date d;
    do
    {
        printf("Donner la date sous la forme jj/mm/aaaa: ");
        fflush(stdin);
        scanf("%d/%d/%d",&d.j,&d.m,&d.a);
    }while(!valide(d));
    return d;
}
/******************Fonction Insersion Tete du Telephone******************/
liste_rep insere_tete_tel(liste_rep l ,repertoire e)
{
    liste_rep p;
    p=malloc(sizeof(struct cellule1));
    p->info=e;
    p->suiv=l;
    l=p;
    return l;
}

/******************Fonction Insersion Queue du Telephone******************/
liste_rep insere_queue_tel(liste_rep l,repertoire e)
{
    liste_rep p,q=l;
    if(l==NULL)
        l=insere_tete_tel(l,e);
    else
    {
        while(q->suiv)
            q=q->suiv;
        p=malloc(sizeof(struct cellule1));
        p->info=e;
        p->suiv=NULL;
        q->suiv=p;

    }
return l;
}

/******************Fonction Insersion Pos du Telephone******************/
liste_rep insere_pos_tel(liste_rep l,repertoire e,int pos)
{
    int cp=1;
    liste_rep p,q=l;
    while(cp<pos-1)
    {
        cp++;
        q=q->suiv;
    }
    p=malloc(sizeof(struct cellule1));
    p->info=e;
    p->suiv=q->suiv;
    q->suiv=p;
    return l;
}
/******************Fonction Supprimer Tete du Telephone******************/
liste_rep supprimer_tete_tel(liste_rep l)
{liste_rep p=l;

    if(l==NULL)
        printf("\n Liste Vide\n");
    else
    {
        l=l->suiv;
        free(p);
    }
    return l;
}

/******************Fonction Supprimer Queue du Telephone******************/
liste_rep supprimer_queue_tel(liste_rep l)
{
    liste_rep p1=l;
    if(!l)
        printf("\n Liste Vide\n");
    else
    if(l->suiv==NULL)
    {
        l=l->suiv;
        free(p1);
    }
    else
    {
        while((p1->suiv)->suiv)
            p1=p1->suiv;
        free(p1->suiv);
        p1->suiv=NULL;
    }
    return l;
}

/******************Fonction Suppression Pos du Telephone******************/
void suppression_pos_tel(liste_rep l,int pos)
{
    liste_rep p1=l,p2;
    int i=1;
    if(pos!=1&&pos!=taille_liste_rep(l))
    {
        while(i<pos-1)
        {
            i++;
            p1=p1->suiv;
        }
        p2=p1->suiv;
        p1->suiv=p2->suiv;
        free(p2);
    }
}
/******************Fonction Affiche d'un Telephone donne******************/
void affiche_tel_donne(liste_rep l)
{
    char nump[10];
    do
    {
        printf("Donner le numero telephone du contact que vous voulez afficher: ");
        fflush(stdin);gets(nump);
    }while(!(recherche_tel(l,nump)&&strlen(nump)==8&&valide_num(nump)!=0));
    printf("\nTel\t\tNom\tPrenom\t\tDate de naissance\tAdresse\t\t\tEmail\n\n");
    affiche1(l,nump);
}

/******************Fonction Affiche d'un Nom Donne******************/
void affiche_nom_donne(liste_rep l)
{
    liste_rep p1=l;
    char nvnom[10];
    do
    {
        printf("Donner le nom du contact que vous voulez afficher: ");
        fflush(stdin);gets(nvnom);
    }while(!(recherche_nom(l,nvnom)&&valide_nom(nvnom)!=0));
    printf("\nTel\t\tNom\tPrenom\t\tDate de naissance\tAdresse\t\t\tEmail\n\n");
    while(p1)
    {
        if (strcmp(p1->info.nom,nvnom)==0)
            affiche1(l,p1->info.numtel);
        p1=p1->suiv;
    }
}

/******************Fonction Affiche d'un Indicatif Donne******************/
void affiche_indicatif_donne(liste_rep l)
{
    liste_rep p1=l;
    long int val,num;
    char ind[10];
    do
    {
        printf("Donner un indicatif du contact que vous voulez afficher (2 chiffres): ");
        fflush(stdin);gets(ind);
    }while(!(valide_num(ind)!=0&&strlen(ind)==2&&recherche_indicatif(l,ind)));
    num=atol(ind);
    printf("\nTel\t\tNom\tPrenom\t\tDate de naissance\tAdresse\t\t\tEmail\n\n");
    while(p1)
    {
        val=atol(p1->info.numtel);
        if (val/1000000==num)
            affiche1(l,p1->info.numtel);
        p1=p1->suiv;
    }
}

/******************Fonction Affiche d'une Ville Donnee******************/
void affiche_ville_donne(liste_rep l)
{
    liste_rep p1=l;
    adr nv;
    do
    {
        printf("\n\tDonner la ville du contact que vous voulez afficher: ");
        fflush(stdin);gets(nv.ville);
    }while(!(recherche_ville(l,nv.ville)&&valide_ville(nv)!=0));
    printf("\nTel\t\tNom\tPrenom\t\tDate de naissance\tAdresse\t\t\tEmail\n\n");
    while(p1)
    {
        if (strcmp(p1->info.adresse.ville,nv.ville)==0)
            affiche1(l,p1->info.numtel);
        p1=p1->suiv;
    }
}

/******************Fonction Affiche1******************/
void affiche1(liste_rep l,char x[])
{
    liste_rep p=l;
    while(p)
    {
        if (strcmp(x,p->info.numtel)==0)
        {
            printf("%s\t%s\t%s\t\t%d/%d/%d\t\t%s %s %s\t%s\n",p->info.numtel,p->info.nom,p->info.prenom,p->info.dn.j,p->info.dn.m,p->info.dn.a,p->info.adresse.rue,p->info.adresse.ville,p->info.adresse.codep,p->info.email);
            break;
        }
        else
            p=p->suiv;
    }
}
/******************Fonction Creation******************/
liste_rep CREATION(liste_rep l)
{
    int pos,t,rep;
    repertoire e;
    do
    {
        t=taille_liste_rep(l);
        do
        {
            printf("\nSaisir la position entre 1 et %d : ",t+1);fflush(stdin);
            scanf("%d",&pos);
        }while(pos<1||pos>t+1);
        e=saisie_repertoire(l);
        if(pos==1)
            l=insere_tete_tel(l,e);
        else
            if(pos==t+1)
                l=insere_queue_tel(l,e);
            else
                l=insere_pos_tel(l,e,pos);
        do
        {
            printf("Voulez vous ajouter un autre telephone? O/N (0 pour Non,1 pour Oui): ");fflush(stdin);
            scanf("%d",&rep);
        }while(rep!=1&&rep!=0);
    }while(rep==1);
    return l;
}
/******************Fonction Enregistrement d'un Repertoire******************/
void enregistrement_repertoire(liste_rep l)
{
    int i;
    FILE *fp;
    fp=fopen("liste_repertoire.txt","w");
    while(l)
    {

        fprintf(fp,"|%s|%s|%s|%d/%d/%d|%s|%s|%s|%s|\n",l->info.numtel,l->info.nom,l->info.prenom,l->info.dn.j,l->info.dn.m,l->info.dn.a,l->info.adresse.rue,l->info.adresse.ville,l->info.adresse.codep,l->info.email);
        l=l->suiv;
    }
    fclose(fp);
    printf ("\nEnregistrement de la liste dans le fichier %s \n","fichier_rep.txt");
}

/******************Fonction Recuperation d'un Repertoire******************/
liste_rep recuperation_repertoire(){

    FILE *fp;
    liste_rep p=NULL;
    repertoire e;
    int pos;
    char ligne[100];
    char ch[5];
    char etape[3];
    fp=fopen("liste_repertoire.txt","r");

    if(fp==NULL)
         printf("LISTE REPERTOIRE VIDE\\");
    else
       while(fgets(ligne,100,fp)!=NULL)
       {
            pos=construction(ligne,1,'|',e.numtel);
            pos=construction(ligne,pos,'|',e.nom);
            pos=construction(ligne,pos,'|',e.prenom);
            pos=construction(ligne,pos,'/',ch);
            e.dn.j=atoi(ch);
            pos=construction(ligne,pos,'/',ch);
            e.dn.m=atoi(ch);
            pos=construction(ligne,pos,'|',ch);
            e.dn.a=atoi(ch);
            pos=construction(ligne,pos,'|',e.adresse.rue);
            pos=construction(ligne,pos,'|',e.adresse.ville);
            pos=construction(ligne,pos,'|',e.adresse.codep);
            pos=construction(ligne,pos,'|',e.email);
            p=insere_queue_tel(p,e);
       }
    fclose(fp);
    return p;
}