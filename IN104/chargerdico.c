#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define NB_MOTS (78855)


char** chargerdico(int nb_lettres,char* fname){
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
    while(feof(in)){
       if (strlen(str)==nb_lettres){
           tab[compteur]=str;
            compteur ++;
       }
       fscanf (in,"%s",str);

    }
    return tab;
}

int main(int argc, char const *argv[])
{
    int nb_lettres=5;
    char* fname="dico.txt";
    chargerdico(nb_lettres,fname);
    return 0;
}



