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
extern char** charger_dico(char* fname);

/*Fonction initalisant le tableau de données utile pour la suite*/
char** create_data() {
    char** data=malloc (sizeof(char*)*26);
    for (int i=0; i<26;i++) {
        data [i]=malloc(sizeof(char)*6);
    }
    data[0][0]='A';data[1][0]='B';data[2][0]='C';data[3][0]='D';data[4][0]='E';data[5][0]='F';data[6][0]='G';data[7][0]='H';data[8][0]='I';data[9][0]='J';data[10][0]='K';data[11][0]='L';data[12][0]='M';data[13][0]='N';data[14][0]='O';data[15][0]='P';data[16][0]='Q';data[17][0]='R';data[18][0]='S';data[19][0]='T';data[20][0]='U';data[21][0]='V';data[22][0]='W';data[23][0]='X';data[24][0]='Y';data[25][0]='Z';
   for (int k=0;k<26;k++) {
       for (int j=1;j<6;j++){
           data[k][j]='u';//au départ on ne sait rien
       }
   }
    return data;
}

/*Fonction copiant un tableau de données*/
char** copy(char** data){
    char** copydata=malloc(sizeof(char*)*26);
    for (int i=0; i<26;i++) {
        copydata [i]=malloc(sizeof(char)*6);
    }
    for (int i=0; i<26;i++) {
        for (int j=0; j<6;j++) {
            copydata[i][j]=data[i][j];
        }
    }
    return copydata;
}
/* Fonction qui met à jour les données avec les nouvelles informations apportées par les indices*/
 char** update_data(char** data, char* guess, int* indices){
    char** new_data=copy(data); 
    for(int i=0;i<26;i++){
        for(int j=1;j<6;j++){
            if(new_data[i][0]==guess[j-1]){
                if(indices[j-1]==1){
                    new_data[i][j]='k';
                }
                if(indices[j-1]==2){
                    new_data[i][j]='i';
                }
                if(indices[j-1]==3){
                    new_data[i][j]='n';
                }


            }
        }
    }
    return(new_data);
 }
 //Fonction qui informe qu'un mot peut encore être deviné, s'il est jouable
bool mot_valide(char** data,char* word) {
    for (int i=1;i<6;i++){      //On vérifie que les lettres plus jouables ne sont pas dans le mot
        int c=0;
        char letter=word[i-1];
        while (letter != data[c][0]) {
            c++;
        }
        if (data[c][i]=='n'){
            return false;
        }
    }
    for(int i=0;i<26;i++){      //On vérifie que les lettres sont bien placées 
    for(int j=1;j<6;j++){
        if(data[i][j]=='k' && data[i][0]!=word[j-1]){
            return false;

        }
    }
}
    return true;
}
/* Fonction qui actualise le dictionnaire en retirant à chaque tour les mots non valide*/
char** actualise_dico(char** dico,char* guess,int * indices,int *size_dico){
    char** new_dico=malloc(sizeof(char*)*(*size_dico));
    for (int i=0; i<*size_dico;i++) {
        new_dico[i]=malloc(sizeof(char)*5);
    }
    for(int i=0;i<*size_dico;i++){
    strcpy(new_dico[i],dico[i]);
    }    
    char** data=create_data();
    char** new_data=update_data(data,guess,indices);        //on met à jour les informations sur le mot
    
    for (int i = 0; i <*size_dico ;) {
    char* word_i=dico[i];                                   
    if (!mot_valide(new_data,word_i)) {                     // On retire les mots non valides d'après les nouvelles informations
    for (int k = i; k < *size_dico-1; k++) {
        new_dico[k]=new_dico[k+1];
    }
    size_dico--;
    }
    else{
        i++;
    }
    }
   
   return (new_dico);

}


int main(){
    char* fname="dico.txt";
    char** dico=charger_dico(fname);
    char* mot="ALLER";
    char* guess="LILAS";
    int* indic=indices(guess,mot);
    int size_dic=4007;
    char** new_dico=actualise_dico(dico,guess,indic,&size_dic);
    printf("%s",new_dico[0]);


}