#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "chargerdico.h"
#define NB_MOTS (78855)
#define NB_LETTRES (5)

/* Création d'un dictionnaire de mots de 5 lettres */
char** charger_dico(char* fname){
    FILE *in=fopen(fname,"rb");
    if (in==NULL){
    printf("erreur lors de l'ouverture du fichier");
    }

    char str[50];
    char** tab=malloc(NB_MOTS*sizeof(char*));
    if (tab==NULL){
        printf("erreur lors de l'allocation");
    }

    int compteur=0;
    fscanf (in,"%s",str);
    
    for(int i=0;i<NB_MOTS;i++){
       if (strlen(str)==NB_LETTRES){
            tab[compteur] = malloc ((1 + strlen (str)) * sizeof (char)) ;
            strcpy(tab[compteur],str);
            compteur ++;
       }
       fscanf (in,"%s",str);

    } 
    return tab;
}





