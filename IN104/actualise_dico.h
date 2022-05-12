#ifndef __ACTUALISE_DICO_H__
#define __ACTUALISE_DICO_H__

/*Fonction initalisant le tableau de données utile pour la suite*/
char** create_data();

/*Fonction copiant un tableau de données*/
char** copy(char** data);

/* Fonction qui met à jour les données avec les nouvelles informations apportées par les indices*/
char** update_data(char** data, char* guess, int* indices);

/*Fonction qui informe qu'un mot peut encore être deviné, s'il est jouable*/
bool mot_valide(char** data,char* word);


#endif