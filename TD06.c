#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct image_t{
	int height;
	int width;
	int max_pixels;
	int *pixels;
	};
	
struct image_t load_pgm(char *path){
	char chaine[20];
	int read;
	struct image_t image;

	image.pixels=NULL;
	FILE * file = fopen(path,"rb");
	if (file==NULL){
		fclose(file);
		return image;
		}
	char* chaine = P2;

	read = fscanf(file,"%s",chaine);
	if (read!=1){
		fclose(file);
		return image;
		}
	read=fscanf(file,"%d","%d",&image.height,&image.width);
	if (read!=2){
		fclose(file);
		return image;
		}
		
	size=image.height*image.width;
	read=fscanf(file,"%d",&image.max_pixels);
	if (read!=1){
		fclose(file);
		return image;
		}
		
	if (size<=0)){
		fclose(file);
		return image;
	}
	
	int *pixels=malloc(size*sizeof(int));
	
	for (int i=0;i<size,i++){
	read=fscanf(file,"%d",&pixels[i]);
	if (read!=1){
		fclose(file);
		return image;
	}
	image.pixels=pixels
	
	fclose(file);
	return image;
	}
	
	

}


