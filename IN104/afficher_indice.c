
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#define NB_LETTRES (5)








/* Création d'un tableau qui va ensuite permettre d'afficher les indices */

/* On a besoin de créer une fonction qui va nous permmettre de compter les occurences de lettres*/


/* Création de la fonction supprimer_doublons, qui va simplifier l'implémentation de la fonction tab_occ*/
char* supprimer_doublons(char* mot){
    int size=strlen(mot);
    for (int i = 0; i <size ; i++) {
      for (int j = i + 1; j < size;) {
         if (mot[j] == mot[i]) {
            for (int k = j; k < size; k++) {
               mot[k] = mot[k + 1];
            }
            size--;
         } else
            j++;
      }
   }
   return(mot);

}




int* tab_occ(char* word){
    int* tab= malloc(NB_LETTRES*sizeof(char));
    for(int i=0; i<strlen(word);i++){
    
        int occurrence=0;
        for(int j= 0; j<strlen(word); ++i){
            if(word[j] == word[i]){
                occurrence++;
            }

        }
        tab[i]=occurrence;
    }
    return tab;
}

int* afficher_indices(char* guess, char* mot){
    int *tab = malloc (sizeof (int) * NB_LETTRES);
    
    for (int i=0;i<NB_LETTRES;i++){
        if (guess[i]==mot[i]){                              // Bonne lettre à la bonne place 
            tab[i]=1;
        }
    }
    for (int i=0;i<NB_LETTRES;i++){
        for (int j=0;j<NB_LETTRES;j++){
            if (guess[i]==mot[j] && tab[i]!=1 && i!=j){     // Bonne lettre à la mauvaise place
                tab[i]=2;
            }
        }
    }
    for (int i=0;i<NB_LETTRES;i++){
        if(tab[i]!=1 && tab[i]!=2){                          // La lettre n'est pas dans le mot 
            tab[i]=3;
        }
    }
    return tab;

}