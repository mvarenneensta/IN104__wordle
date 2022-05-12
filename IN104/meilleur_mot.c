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
#define NB_LETTRES (5)
#define NB_MOTS_5LETTRES (4007)
extern int* indices(char* guess, char* word);
extern char** create_data();
extern char** copy(char** data);
extern char** update_data(char** data, char* guess, int* indices);
extern bool mot_valide(char** data,char* word);
extern char** actualise_dico(char** dico,char** new_data,int *size_dico);

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
char* bestword(char** dico, char** data, int size_dico) {
    int m;
    int ans[5];
    double* entropies=malloc(sizeof(double)*size_dico);//tableau où on stock la qté d'information gagné pour chaque mot encore jouable
    for (int i=0;i<size_dico;i++){
        char* word_i=dico[i];                       //on prend un mot du dico
        double h=0;                                 //calcul de l'entropie de shannon pour chaque mot
        for (int i1=1;i1<4;i1++){
            for (int i2=1;i2<4;i2++){
                for (int i3=1;i3<4;i3++){
                    for (int i4=1;i4<4;i4++){
                        for (int i5=1;i5<4;i5 ++){
                            ans[0]=i1;
                            ans[1]=i2;
                            ans[2]=i3;
                            ans[3]=i4;
                            ans[4]=i5;
                            char** datatest = create_data();
                            datatest=update_data(datatest,word_i,ans);      //on actualise les data avec une des réponses hypothétiques
                            m=0;                                           //nombre de mots encore valide après la réponse
                            for(int k=0;k<size_dico;k++){
                                if (mot_valide(datatest,dico[k])){
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

                    }
                }
            }
        }
        entropies[i]=h;
    }
    char* best_word=dico[idxmax(entropies,size_dico)];
    free(entropies);
    return best_word;
}
