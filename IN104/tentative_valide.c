

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include "dico.txt"
#include "chargerdico.c"
#define NB_LETTRES (5)




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

int main(){
    char* fname="dico.txt";
    char** dico=chargerdico(NB_LETTRES,fname);
    bool in_dico=verifie_dico("patte",dico,NB_MOTS);
    if(in_dico){
    printf("True");
    }
}