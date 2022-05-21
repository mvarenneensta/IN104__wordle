
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include "afficher_indice.h"




/* Création de la fonction supprimer_doublons, qui va simplifier l'implémentation de la fonction tab_occ*/

char* supprimer_doublons(char* mot){
    int size=strlen(mot);
    char* word=malloc(size*sizeof(char));
    if(word==NULL){
        printf("erreur lors de l'allocation du mot sans doublons");
    }
    strcpy(word,mot);
    for (int i = 0; i <size ; i++) {
      for (int j = i + 1; j < size;) {
         if (word[j] == word[i]) {
            for (int k = j; k < size; k++) {
               word[k] = word[k + 1];
            }
            size--;
         } else
            j++;
      }
   }
   return(word);

}


/* On a besoin de créer une fonction qui crée une table d'occurences, utile pour donner les indices ensuite*/

int* tab_occ(char* word){
    char* mot_sansdoublons=supprimer_doublons(word);
    int size=strlen(mot_sansdoublons);
    int* tab= malloc((size+1)*sizeof(char));
    if(tab==NULL){
        printf("erreur lors de l'allocation du tableau d'occurences");
    }

    for(int i=0; i<strlen(word);i++){
        for(int j=0;j<size;j++){
            if(word[i]==mot_sansdoublons[j]){
                tab[j]++;
            }

        }
    }   
    free(mot_sansdoublons);
    return tab;
}

/* Création d'un tableau qui va ensuite permettre d'afficher les indices  */
int* indices(char* guess, char* mot,int NB_LETTRES){
    

    char* mot_sansdoublons=supprimer_doublons(mot);     // Création de la table d'occurences du mot
    int* mot_tab_occ=tab_occ(mot);              
    int size=strlen(mot_sansdoublons);             
    
    int *tab = malloc (sizeof (int) * NB_LETTRES); // Création du tableau des indices
    if(tab==NULL){
        printf("erreur lors de l'allocation du tableau des indices");
    }

    for (int i=0;i<NB_LETTRES;i++){
        tab[i]=-1;                      //on initialise le tableau à -1 car on utilisera la valeur 0
    }           
    for (int i=0;i<NB_LETTRES;i++){
        tab[i]=-1;                      //on initialise le tableau à -1
    }           
    for (int i=0;i<NB_LETTRES;i++){
        for(int j=0;j<size;j++){
        
            if (guess[i]==mot[i] && mot[i]==mot_sansdoublons[j]){
                                                                     // 0 : Bonne lettre à la bonne place 
                tab[i]=0;
                mot_tab_occ[j]--;

            }
        }
    }
    
    
    for(int i=0;i<NB_LETTRES;i++){
        for(int j=0;j<size;j++){
            if (guess[i]==mot_sansdoublons[j] && tab[i]!=0 && mot_tab_occ[j]!=0){     // 1 : Bonne lettre à la mauvaise place
                tab[i]=1;
                mot_tab_occ[j]--;
            }
        }
    }
     
    printf("\n");
    for (int i=0;i<NB_LETTRES;i++){
        if(tab[i]!=0 && tab[i]!=1){                                                   // 2 : La lettre n'est pas dans le mot 
            tab[i]=2;
        }
    }
    free(mot_sansdoublons);
    free(mot_tab_occ);
    return tab;

}
/*Fonction affichant les indices*/
void afficher_indices(int* indices,int NB_LETTRES){
    for(int i=0;i<NB_LETTRES;i++){
        if(indices[i]==0){
            printf("o");
        }
        if(indices[i]==1){
            printf("~");
        }
        if(indices[i]==2){
            printf("x");
        }
    }
}
