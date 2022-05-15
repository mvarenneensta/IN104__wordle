

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include "tentative_valide.h"




/* Fonction qui vérifie si le mot a le bon nombre de lettres*/
bool verifie_nombre(char* str, int NB_LETTRES){
    return(strlen(str)==NB_LETTRES);
}



/*Fonction qui va vérifier si le mot tenté existe bien*/
bool verifie_dico(char* str, char** tab,int TAILLE_DICO){
    for(int i=0;i<(TAILLE_DICO);i++){
        if(strcmp(tab[i],str)==0){
            return(true);
        }
    }
    return(false); 
}

