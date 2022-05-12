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
#define NB_LETTRES (5)
#define NB_MOTS_5LETTRES (4007)
extern char** charger_dico(char* fname);
extern bool verifie_nombre(char* mot);
extern bool verifie_dico(char* word,char** dico);
extern int* indices(char*guess, char* mot);
extern void afficher_indices(int* indices);
extern char** create_data();
extern char** copy(char** data);
extern char** update_data(char** data, char* guess, int* indices);
extern bool mot_valide(char** data,char* word);
extern char** actualise_dico(char** dico,char** new_data,int *size_dico);
extern char* bestword(char** dico, char** data, int size_dico);






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
    printf("Vous avez 6 essais pour deviner un mot de 5 lettres : bonne chance !\n");
    printf("O -> bien placé\n");
    printf("~ -> dans le mot et mal placé\n");
    printf("X -> mal placé et pas dans le mot\n");


    /* On détermine le mot à deviner de manière aléatoire*/

    char* fname="dico.txt";
    char** dico=charger_dico(fname);

    int compteur=0;
    int nb_rand;
    srand(time(NULL));
    nb_rand=rand()%NB_MOTS_5LETTRES;
    char* mot_rand=dico[nb_rand];
    int size_dic=4007;
    char** data=create_data();
    /* Début des essais*/
    while(compteur<6){
        //L'utilisateur tente un mot
        char* guess=malloc(NB_LETTRES*sizeof(char));
        printf("\nMot tenté :");
        scanf("%s",guess);
        //Vérification de la taille du mot
        if(!verifie_nombre(guess)){
            printf("Mot trop court !\n");
            compteur++;
        }
        //Vérification de l'existence du mot
        if(!verifie_dico(guess,dico)){
            printf("Ce mot n'existe pas !\n");
            compteur++;
        }
        // Cas du mot juste
        if(strcmp(guess,mot_rand)==0){
            printf("Vous avez gagné !!\n");
            break;
        }
        if(verifie_nombre(guess) && verifie_dico(guess,dico)){
            int* tab_indices;
            tab_indices=indices(guess,mot_rand);
            afficher_indices(tab_indices);
            compteur++;
            //Conseil de l'ordinateur
            char** new_data=update_data(data,guess,tab_indices);
            char** new_dico=actualise_dico(dico,new_data,&size_dic);
            printf("%d\n",size_dic);
            char* meilleur_mot=bestword(new_dico,new_data,size_dic);
            printf("Meilleur mot à jouer : %s\n",meilleur_mot);
            dico=new_dico;
            data=new_data;
        }

    }
    if(compteur>=6){
        printf("Perdu ! Le mot était : %s",mot_rand);
    }
    free(dico);
    free(data);



    
}