/*Projet IN104 : Wordle*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "chargerdico.h"
#include "afficher_indice.h"
#include "tentative_valide.h"
#include "actualise_dico.h"
#include "meilleur_mot.h"
extern char** charger_dico(char* fname,int NB_LETTRES,int *TAILLE_DICO);
extern bool verifie_nombre(char* mot,int NB_LETTRES);
extern bool verifie_dico(char* word,char** dico,int TAILLE_DICO);
extern int* indices(char*guess, char* mot,int NB_LETTRES);
extern void afficher_indices(int* indices,int NB_LETTRES);
extern char** create_data(int NB_LETTRES);
extern char** copy(char** data,int NB_LETTRES);
extern char** update_data(char** data, char* guess, int* indices,int NB_LETTRES);
extern bool mot_valide(char** data,char* word,int NB_LETTRES);
extern char** actualise_dico(char** dico,char** new_data,int *size_dico,int NB_LETTRES);
extern char* bestword(char** dico, char** data, int size_dico,int NB_LETTRES);






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
    /* Début du jeu : rappel des règles*/
    printf("Vous avez 6 essais pour deviner le mot : bonne chance !\n");
    printf("O -> bien placé\n");
    printf("~ -> dans le mot et mal placé\n");
    printf("X -> mal placé et pas dans le mot\n");

    /*On demande à l'utilisateur avec combien de lettres il veut jouer*/
    printf("\nNombre de lettres :");
    int NB_LETTRES;
    scanf("%d",&NB_LETTRES);

    /* On détermine le mot à deviner de manière aléatoire*/

    char* fname="dico.txt";
    int size_dic;
    char** dico=charger_dico(fname,NB_LETTRES,&size_dic);
    int compteur=0;
    int nb_rand;
    srand(time(NULL));
    nb_rand=rand()%(size_dic+1);
    char* mot_rand=dico[nb_rand];
    char** data=create_data(NB_LETTRES);
    /* Début des essais*/
    while(compteur<6){
        //L'utilisateur tente un mot
        char* guess=malloc(NB_LETTRES*sizeof(char));
        printf("\nMot tenté :");
        scanf("%s",guess);
        //Vérification de la taille du mot
        if(!verifie_nombre(guess,NB_LETTRES)){
            printf("Nombre de lettres incorrect !\n");
            compteur++;
        }
        //Vérification de l'existence du mot
        if(!verifie_dico(guess,dico,size_dic)){
            printf("Ce mot n'existe pas !\n");
            compteur++;
        }
        // Cas du mot juste
        if(strcmp(guess,mot_rand)==0){
            printf("Vous avez gagné !!\n");
            break;
        }
        if(verifie_nombre(guess,NB_LETTRES) && verifie_dico(guess,dico,size_dic)){
            int* tab_indices;
            tab_indices=indices(guess,mot_rand,NB_LETTRES);
            afficher_indices(tab_indices,NB_LETTRES);
            compteur++;
            //Conseil de l'ordinateur
            data=update_data(data,guess,tab_indices,NB_LETTRES);
            dico=actualise_dico(dico,data,&size_dic,NB_LETTRES);
            printf("%d\n",size_dic);
            char* meilleur_mot=bestword(dico,data,size_dic,NB_LETTRES);
            printf("Meilleur mot à jouer : %s\n",meilleur_mot);
            printf("Nombre de mots possibles restants : %d\n",size_dic);
        }
        free(guess);

    }
    if(compteur>=6){
        printf("Perdu ! Le mot était : %s\n",mot_rand);
    }
    free(dico);
    free(data);



    
}