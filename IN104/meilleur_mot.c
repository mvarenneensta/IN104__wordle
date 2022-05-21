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
#include "actualise_dico.h"
extern int* indices(char* guess, char* word);
extern char** create_data();
extern char** copy(char** data,int NB_LETTRES);
extern char** update_data(char** data, char* guess, int* indices,int NB_LETTRES);
extern bool mot_valide(char** data,char* word,int NB_LETTRES);
extern char** actualise_dico(char** dico,char** new_data,int *size_dico,int NB_LETTRES);

int idxmax(double* t, int sizet) {
    int i=0;
    double m=t[0];
    for (int k=0;k<sizet;k++ ){
        if(t[k]>m) {
            m=t[k];
            i=k;
        }
    }
    return i;
} 


/*Fonction qui retourne le meilleur mot à jouer à chaque tour*/
char* bestword(char** dico, char** data, int size_dico,int NB_LETTRES) {
    int m;
    double* entropies=malloc(sizeof(double)*size_dico);                 //tableau où on stocke la qté d'information gagné pour chaque mot encore jouable
    if(entropies==NULL){
        printf("erreur lors de l'allocation du tableau des entropies");
    }

    for (int i=0;i<size_dico;i++){
        char* word_i=dico[i];                                           //on prend un mot du dico
        double h=0;                                                     //calcul de l'entropie de shannon pour chaque mot
        int* ans=malloc(sizeof(int)*NB_LETTRES);                                            //on fait varier la réponse du wordle
        for (int k=0;k<(3^NB_LETTRES);k++) {
            int a=k;
            int d;
            for (int p=NB_LETTRES-1; p>(-1);p--) {                      //On remplit le tableau ans
                d=a/3^p;
                ans[NB_LETTRES-p-1]=d;
                a=a-d*(3^p);
            }
            char** datatest = create_data(NB_LETTRES);
            datatest=update_data(datatest,word_i,ans, NB_LETTRES);      //on actualise les data avec une des réponses hypothétiques
            m=0;                                                        //nombre de mots encore valide après la réponse
            for(int k=0;k<size_dico;k++){
                if (mot_valide(datatest,dico[k],NB_LETTRES)){
                    m++;
                }   
            }
            if(m!=0){
                double n=m;                       //printf("Nombre de mots valides 2: %d\n",m);
                double f=n/size_dico;            //f<=1
                double l=log(f);                //l<=0
                h=h-n/size_dico*l;
            }
            free(datatest);
         }
        entropies[i]=h;
        free(ans);
    }
    char* best_word=dico[idxmax(entropies,size_dico)];
    free(entropies);
    return best_word;
}
