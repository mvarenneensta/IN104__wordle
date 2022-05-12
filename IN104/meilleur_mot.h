#ifndef __MEILLEUR_MOT_H__
#define __MEILLEUR_MOT_H__

int idxmin(double* t, int sizet);

/*Fonction qui retourne le meilleur mot à jouer à chaque tour*/
char* bestword(char** dico, char** data, int size_dico);

#endif
