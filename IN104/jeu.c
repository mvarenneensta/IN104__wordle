/*Projet IN104 : Wordle*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include "chargerdico.c"
#include "afficher_indice.c"
#include "tentative_valide.c"
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