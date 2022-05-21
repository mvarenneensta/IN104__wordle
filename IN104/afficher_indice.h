#ifndef __TENTATIVE_VALIDE_H__
#define __TENTATIVE_VALIDE_H__
/* Création de la fonction supprimer_doublons, qui va simplifier l'implémentation de la fonction tab_occ*/
char* supprimer_doublons(char* mot);

/* On a besoin de créer une fonction qui crée une table d'occurences, utile pour donner les indices ensuite*/
int* tab_occ(char* word);

/* Création d'un tableau qui va ensuite permettre d'afficher les indices  */
int* indices(char* guess,char* mot,int NB_LETTRES);
/*Fonction affichant les indices*/
void afficher_indices(int* indices,int NB_LETTRES);
#endif