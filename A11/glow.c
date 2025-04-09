/*----------------------------------------------
 * Author: Hanna Abrahem 
 * Date: April 8th, 2025
 * Description: creating a program to apply a glow effect on the image "earth-small.ppm".  
 ---------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <time.h>
#include <pthread.h>
#include "read_ppm.h"
#include "write_ppm.h"

int main(int argc, char* argv[]) {
    /**hardcoding the file **/
    FILE *file;
    char *filename = "earth-small.ppm"; // Replace with your file name
    
    file = fopen(filename, "r"); // "r" for read mode

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }
    /**reading ppm file **/
    int width, height;
    struct ppm_pixel** pixels = read_ppm_2d(file,&width,&height);

    //if could not read pixels
     if (!pixels) {
	  fprintf(stderr, "Error unable to read pixels from file %s \n", argv[1]);
	return 1;
  }
     /**Extracting bright areas into a separate image **/
     int threshold = 200; //compare brightness too
     int blur_box = 25; 
     int radius = blur_box / 2;
     
     //allocating space for the new image
     struct ppm_pixel** bright_pixels = malloc(height * sizeof(struct ppm_pixel*));
     for (int i = 0; i < height; i++){
	     bright_pixels[i] = malloc(width * sizeof(struct ppm_pixel*));
     }
     struct ppm_pixel** blurred_pixels = malloc(height * sizeof(struct ppm_pixel*));
     for (int i = 0; i < height; i++){
             blurred_pixels[i] = malloc(width * sizeof(struct ppm_pixel*));
     }

     //looping through every pixel 
     for (int h = 0; h < height; h++) {
	     for (int w = 0; w < width; w++) {
		     struct ppm_pixel px = pixels[h][w];
		     int brightness = (px.red + px.blue + px.green) / 3;

		     if (brightness > threshold) {
			     bright_pixels[h][w] = px; //keeping the bright pixels
		     } else {
			     // setting none bright pixels to black
			     bright_pixels[h][w].red = 0;
			     bright_pixels[h][w].blue = 0;
			     bright_pixels[h][w].green = 0;
		     }
		/***Blur box to each pixel ***/
		     int count = 0;
		     int sum_red = 0, int sum_green = 0, int sum_blue = 0;


		     for (int j = -radius; j < radius; j++) {
			     for (int k = -radius; k < radius; k++) {
				     int new_height = h + j;
			             int new_width = w + k;
			     }
		     }

	     }

     }



}
