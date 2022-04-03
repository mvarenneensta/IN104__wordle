/*Projet IN104 : Wordle*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include "chargerdico.c"
#include "afficher_indice.c"
#define NB_LETTRES (5)




/*O -> bien placé
X -> mal placé et pas dans le mot
~ -> dans le mot et mal placé

Plan du programme :
-> Créer un tableau classant les mots du dico par nombre de lettres

-> Demander nb lettres/essais 

-> Tentative d'un mot :
    -> Vérifier si bon nb de lettres
    -> Vérifier que le mot est dans le dico
    -> Afficher lettres bien placées/ lettres dans le mot et mal placées
    -> Afficher si gagner -> finir la partie
    -> Si fin du nb d'esssais : révéler le mot et annoncer défaite :-(
-> afficher un clavier avec les lettres pouvant encore être jouées
*/

/* Fonction qui vérifie si le mot a le bon nombre de lettres*/
bool verifie_nombre(char* str){
    return(strlen(str)==NB_LETTRES);
}



/*Fonction qui va vérifier si le mot tenté existe bien*/
bool verifie_dico(char* str, char** tab,int size){
    for(int i=0;i<size;i++){
        if(tab[i]==str){
            return(true);
        }
    }
    return(false);
}

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




int main(int argc, char const *argv[])
{
    //printf("O -> bien placé \nX -> mal placé et pas dans le mot \n~ -> dans le mot et mal placé");
    
    //char* fname="dico.txt";

    /*int* tab=afficher_indices("mot","violent");
    printf("\n");
    for (int i=0 ; i<7 ; i++){
	printf ("%d\t", tab[i]);
    }
*/
char* mot_sansocc=supprimer_doublons("reverbere");
printf("%s",mot_sansocc);
    return 0;
}