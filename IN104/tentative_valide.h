#ifndef __TENTATIVE_VALIDE_H__
#define __TENTATIVE_VALIDE_H__

/* Fonction qui vérifie si le mot a le bon nombre de lettres*/
bool verifie_nombre(char* str,int NB_LETTRES);

/*Fonction qui va vérifier si le mot tenté existe bien*/
bool verifie_dico(char* str,char** tab,int TAILLE_DICO);

#endif