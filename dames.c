#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*Q1.1
Grandes étapes du programme : 
	1) Charger le contenu du fichier texte et créer un tableau du damier 
	2) Vérifier si une dame est possible dans la position (x,y)
	3) Retourner "Dame en x coups" ou "Dame impossible" selon les cas.
*/
/*Q1.2
La fonction chargeant le contenu du fichier va prendre en argument le nom du fichier. Elle va retourner un tableau d'entiers qui prennent la valeur 1(case occupé par un pion) ou 0(case vide). 
Grandes étapes :
	- Ouvrir le fichier texte en lecture
	- Vérifier qu'il n'est pas vide
	- Lire la  largeur du fichier
	- Si lecture échouée, fichier corrompu
	- Si taille <=0, fichier corrompu
	- Allouer tableaux d'entiers
	- Lire les "size" lignes du fichier, et écrire une à une les cases de pixels avec 1 si on a "X" et 0 si on a ".". Si une des lectures échoue ou si les lignes ne respectent pas le format demandé (chaîne de size caractères avec des X et des .) ,fichier corrompu.
	
	- Fermer le fichier
	- Retourner le tableau
*/

/*Q1.3 
Le nombre de coups maximal pour obtenir une dame est de 2,6 et 12 pour une taille de 3,5 et 7 respectivement. Il est difficile à évaluer, nous prendrons par la suite la valeur arbitraire 2*size que l'on considère assez grande ici. Ce nombre nous servira pour sortir de la boucle while quand le nombre de coups est trop grand qui veux dire qu'une dame est impossible.
*/

/*Q1.4
On parcourt le damier avec le tableau tab, constitué de zéros et de 1 et crée à partir de la fonction load_txt. La position (x,y) dans le damier correspond à l'entier tab[x+y*size].
On réalise une boucle while :
- tant qu'un compteur de tours est inférieur au nombre de coups max
- on regarde si les cases voisines de (x,y), sans compter celles en diagonale et en vérifiant qu'elles existent bien ont un 1 dans le tableau et si la case juste après dans l'alignement a un 0 (en vérifiant qu'elle existe bien).
-si plusieurs cases vérifient cette condition, on choisit la case tel que y est le plus grand.
- on réinitialise la position 
*/




int* load_txt(char *fname){
	char buffer[20];
	int size,read;
	int *tab=NULL; //on l'initialise à 0 pour retourner une valeur nulle en cas d'erreur
	
	FILE *file=fopen(fname,"rb");
	if (file=NULL){
		fclose(file);
		return tab;
		}
	read=fscanf(file,"%d",&size);
	if (read!=1){
		fclose(file);
		return tab;
		}
	if(size<=0){
		fclose(file);
		return tab;
		}
	for(int i=0;i<size;i++){
	read=fscanf(file,"%s",buffer);
	if (read!=1){
		fclose(file);
		return tab;
		}
		for(int j=0;j<size;j++){
			if(&buffer[j]=="X"){
				tab[size*i+j]=1;
			}
			if(&buffer[j]=="."){
				tab[size*i+j]=0;
			}
			else{
			fclose(file);
			return tab;
			}
		}
	}
	fclose(file);
	return tab;
}

void damepossible(int* tab,int x, int y,int size){
	if(x>=size || x<0 || y>=size || x<0){
		printf("Dame impossible.\n");
		}
	int compteur=0;
	while(compteur<2*size && y!=size){
	if (y<=size-2){
	if (tab[x+(y+1)*size]==1 && tab[x+(y+2)*size]==0){
		y=y+2;
	}
	}
	if (x+2<size || x-2>=0){
	if (tab[(x+1)+y*size]==1 && tab[(x+2)+y*size]==0){
		x=x+2;
		}
	if (tab[(x-1)+y*size]==1 && tab[(x-2)+y*size]==0){
		x=x-2;
		}
	}
	else{
		printf("Dame impossible.\n");
	}
	}
	printf("Dame possible en %d coups",compteur); 
}


int main(int argc, char *argv[]){
// le nom du fichier, la position x et la position y sont en argument de commande
char* fname=argv[1];
int x=atoi(argv[2]);
int y=atoi(argv[3]);

//on charge le tableau représentant le damier
int* tab=load_txt(fname);
/*On récupère la taille du tableau. Je n'ai pas pu y parvenir car la fonction strlen ne marche qu'avec des chaines de caractères.
int i,l=strlen(tab);
int size=pow(l,0.5);
*/

//on effectue le test sur la position (x,y) une fois le tableau récupéré
damepossible(tab,x,y,size);



}
