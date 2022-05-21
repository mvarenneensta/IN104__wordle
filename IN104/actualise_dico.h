#ifndef __ACTUALISE_DICO_H__
#define __ACTUALISE_DICO_H__

/*Fonction initalisant le tableau de données utile pour la suite*/
char** create_data(int NB_LETTRES);

/*Fonction copiant un tableau de données*/
char** copy(char** data,int NB_LETTRES);

/* Fonction qui met à jour les données avec les nouvelles informations apportées par les indices*/
char** update_data(char** data, char* guess, int* indices,int NB_LETTRES);

/*Fonction qui informe qu'un mot peut encore être deviné, s'il est jouable*/
bool mot_valide(char** data,char* word,int NB_LETTRES);

/* Fonction qui actualise le dictionnaire en retirant à chaque tour les mots non valide*/
char** actualise_dico(char** dico,char** new_data,int *size_dico,int NB_LETTRES);


#endif