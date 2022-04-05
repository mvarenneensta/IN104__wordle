
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include "afficher_indice.h"
#define NB_LETTRES (5)




/* Création de la fonction supprimer_doublons, qui va simplifier l'implémentation de la fonction tab_occ*/

char* supprimer_doublons(char* mot){
    int size=strlen(mot);
    char* word=malloc(size*sizeof(char));
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
    int* tab= malloc(size*sizeof(char));
    for(int i=0; i<strlen(word);i++){
        for(int j=0;j<size;j++){
            if(word[i]==mot_sansdoublons[j]){
                tab[j]++;
            }

        }
    }   
    return tab;
}

/* Création d'un tableau qui va ensuite permettre d'afficher les indices  */
int* indices(char* guess, char* mot){
    

    char* mot_sansdoublons=supprimer_doublons(mot);     // Création de la table d'occurences du mot
    int* mot_tab_occ=tab_occ(mot);              
    int size=strlen(mot_sansdoublons);             
    
    int *tab = malloc (sizeof (int) * NB_LETTRES); // Création du tableau des indices
    for (int i=0;i<NB_LETTRES;i++){
        for(int j=0;j<size;j++){
        
            if (guess[i]==mot[i] && mot[i]==mot_sansdoublons[j]){
                                                                     // Bonne lettre à la bonne place 
                tab[i]=1;
                mot_tab_occ[j]--;

            }
        }
    }
    
    
    for(int i=0;i<NB_LETTRES;i++){
        for(int j=0;j<size;j++){
            if (guess[i]==mot_sansdoublons[j] && tab[i]!=1 && mot_tab_occ[j]!=0){     //Bonne lettre à la mauvaise place
                tab[i]=2;
                mot_tab_occ[j]--;
            }
        }
    }
     
    printf("\n");
    for (int i=0;i<NB_LETTRES;i++){
        if(tab[i]!=1 && tab[i]!=2){                                                   // La lettre n'est pas dans le mot 
            tab[i]=3;
        }
    }
    return tab;

}
/*Fonction affichant les indices*/
void afficher_indices(int* indices){
    for(int i=0;i<NB_LETTRES;i++){
        if(indices[i]==1){
            printf("o");
        }
        if(indices[i]==2){
            printf("~");
        }
        if(indices[i]==3){
            printf("x");
        }
    }
}
