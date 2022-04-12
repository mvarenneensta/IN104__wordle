#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "chargerdico.h"
#include "afficher_indice.h"
#include "tentative_valide.h"
#include "meilleur_mot.h"
#define NB_LETTRES (5)
#define NB_MOTS_5LETTRES (4007)
extern char** charger_dico(char* fname);
extern bool verifie_nombre(char* mot);
extern bool verifie_dico(char* word,char** dico);
extern int* indices(char*guess, char* mot);
extern void afficher_indices(int* indices);

char* meilleur_mot(char** dico_actualise){

}