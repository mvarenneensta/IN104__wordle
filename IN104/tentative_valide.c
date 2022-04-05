

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include "tentative_valide.h"
#define NB_LETTRES (5)
#define NB_MOTS_5LETTRES (4007)




/* Fonction qui vérifie si le mot a le bon nombre de lettres*/
bool verifie_nombre(char* str){
    return(strlen(str)==NB_LETTRES);
}



/*Fonction qui va vérifier si le mot tenté existe bien*/
bool verifie_dico(char* str, char** tab){
    for(int i=0;i<NB_MOTS_5LETTRES;i++){
        if(strcmp(tab[i],str)==0){
            return(true);
        }
    }
    return(0); 
}

