#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include "actualise_dico.h"
#include "afficher_indice.h"
#include "chargerdico.h"
#define NB_LETTRES (5)
extern int* indices(char* guess, char* word);
extern char** chargerdico(char* fname);

bool garder_mot(char* mot,char* guess,int* index_guess){
    int* index=indices(guess,mot);
    bool garder_mot=false;
    for(int i=0;i<NB_LETTRES;i++){
        if(index[i]!=3){
            return(true);
        }
    }
    return(false);

}
/* Fonction qui actualise le dictionnaire à partir de l'ancien*/ 
char** dico_actualise(char** dico,int* indexes,char* guess,int size_dico){
    char** new_dico=malloc(size_dico*sizeof(char));
    for(int i=0;i<size_dico;i++){
        strcpy(new_dico[i],dico[i]);
    }
    
    for (int i=0; i<size_dico; i++){
        for(int j=i+1;j<size_dico;){
            char* word_i=new_dico[i];
            for(int l=0;l<5;l++){
                if (word_i[l]==guess[l]){
                    for (int k = j; k < size_dico; k++) {
                        dico[k] = dico[k + 1];
            }
            size_dico--;
                }
            }
            
            
        }
    }
    return(new_dico);
}

int main(){
    char* mot="ALLER";
    char* guess="LILAS";
    char** dico=chargerdico("dico.txt");
    int* indexes=indices(guess,mot);
    char** new_dico=dico_actualise(dico,indexes,guess,4007);
    for(int i=0;i<50;i++){
        printf("%s",new_dico[i]);
    }
    free(new_dico);
}