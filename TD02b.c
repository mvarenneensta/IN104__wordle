//WEYNANS Billy

#include <stdio.h>
#include "paint.c"
#include <math.h>

int compter_iterations(double x, double y, int max_iter)
{

	double a = 0;
	double b = 0;
	double c = 0;
	int k = 0;
	while ((b*b-a*a<=4) && (k<max_iter)) {
		c=a*b;
		a=a*a-b*b+x;
		b=2*c+y;
		k=k+1;
		//printf("%d \n",k);
	}
	return k;
}

int main()
{

	int width = 600;
	int height = 400;

	int x_left = -2;
	int y_top = 1;

	double x_width = 3;
	double y_height = x_width*height/width;
	/*
	double x=0;
	double y=0.75;
	*/
	int max_iter=100;

	//Creation pixels
	unsigned char* pixels = create_pixels(width,height);

	for (int i=0;i<=width;i++)
	{
		for (int j=0;j<=height;j++)
		{
			//CORRESPONDANCE COORDONNEES
			
			double x = x_left + i*(x_width/(width-1));
			double y = y_top - j*(y_height/(height-1));
			
			/*
			double x = ((width-1)/x_width)*(i-x_left);
			double y = -((height-1)/y_height)*(j-y_top);
			*/
			//TRANSLATION
			double dx = 0.2*x;
			double dy = -0.03*y*y;
			x = x + dx;
			y = y + dy;
			
			//ROTATION
			double a = 0.45;
			double xr = x*cos(a)+y*sin(a);
			y = -x*sin(a)+y*cos(a);
			x = xr;
			
			//MODIF COULEURS
			int nb_iterations=compter_iterations(x,y,max_iter);
			unsigned char r = 0;
			unsigned char g = 0;
			unsigned char b = 0;
			if (nb_iterations!=max_iter) {
				//r = 255*(nb_iterations/max_iter);
				//g = 0 ;
				//b = 255 -r;
				r=255*log(y*nb_iterations/2550)*0.75/nb_iterations;
				g=nb_iterations*nb_iterations*x*x*1.5;
				b=100-tan(nb_iterations)*0.65;
			}
			//printf("%d , %d  :  %f , %f\n",i,j,x,y);
			color_pixel(i,j,r,g,b,width,height,pixels);
			
		
		}
		
	}
	
	
	/* Ecrire vers un fichier BMP */
	save_BMP("image_td02b.bmp", width, height, pixels);

	/* Détruire le canvas pour libérer la mémoire */
	destroy_pixels(pixels);
	//printf("%d itérations",compter_iterations(x,y,max_iter));

}


// Q3 : 6 itérations

// Q4 : max d'itérations

// Q5 : max d'itérations

/* Q6 :

float x = x_left + i*(x_width/width-1);
float y = y_top - j*(y_height/height-1);

*/

// Q7 : PAS d'image car 'Erreur de segmentation ( core dumped )' --> Je n'ai pas réussi à trouver l'erreur après plus d'une heure de recherche..

// Q10 : Ca ne fonctionne pas car on a besoin de la valeur avant-calcul de x pour calculer la valeur prochaine de y. 
