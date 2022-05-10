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
extern double log(double x);

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
char** actualise_dico(char** dico,char** new_data,int *size_dico){
    char** new_dico=malloc(sizeof(char*)*(*size_dico));
    for (int i=0; i<*size_dico;i++) {
        new_dico[i]=malloc(sizeof(char)*5);
    }

    for(int i=0;i<*size_dico;i++){
    strcpy(new_dico[i],dico[i]);
    }    
    for (int i = 0; i <*size_dico ;) {
        char* word_i=new_dico[i];    
        if (!mot_valide(new_data,word_i)) {                     // On retire les mots non valides d'après les nouvelles informations
        for (int k = i; k < *size_dico-1; k++) {
            new_dico[k]=new_dico[k+1];
        }
        (*size_dico)--;
        }
        else{
            i++;
        }
    }
   char** new_dico1=realloc(new_dico,*size_dico);
   return (new_dico1);

}
int idxmin(double* t, int sizet) {
    int i=0;
    double m=t[0];
    for (int k=0;k<sizet;k++ ){
        if(t[k]<m) {
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
                            m=0;                                            //nombre de mots encore valide après la réponse
                            for(int k=0;k<size_dico;k++){
                                if (mot_valide(datatest,dico[k])){
                                    m++;
                                    printf("Nombre de mots valides : %s\n",dico[0]);
                                    printf("Nombre d'it 1: %d\n",k);
                                }
                                printf("Nombre d'it 2 : %d\n",m);
                            }
                            double n=m;
                            printf("Nombre de mots valides 2: %d\n",m);
                            double f=n/size_dico; //f<=1
                            double l=log(f); //l<=0
                            h=h-n/size_dico*l;
                            free(datatest);
                        }

                    }
                }
            }
        }
        entropies[i]=h;
        printf("Entropie du mot%f\n",h);
    }
    char* best_word=dico[idxmin(entropies,size_dico)];
    free(entropies);
    return best_word;
}


int main(){
    char* fname="dico.txt";
    char** dico=charger_dico(fname);
    char* mot="ALLER";
    char* guess="LILAS";
    int* indic=indices(guess,mot);
    int size_dic=4007;
    char**data=create_data();
    char** new_data=update_data(data,guess,indic);
    char** new_dico=actualise_dico(dico,new_data,&size_dic);
    char* meilleur_mot=bestword(new_dico,new_data,size_dic);
    printf("%s\n",meilleur_mot);
    for(int i=0;i<size_dic;i++){
        printf("Mot %d : %s\n",i,new_dico[i]);
    }
    
    
    
}