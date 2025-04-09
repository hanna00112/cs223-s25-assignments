#include "write_ppm.h"
#include <stdio.h>
#include <string.h>

void write_ppm(const char* filename, struct ppm_pixel* pixels, int w, int h) {
}

void write_ppm_2d(const char* filename, struct ppm_pixel** pxs, int w, int h) {

	FILE* ppmfile = fopen(filename, "wb");

	char dimensions[3];
	dimensions[0] = w + '0';
 	dimensions[1] = ' ';
 	dimensions[2] = h + '0';

	fprintf(ppmfile, "%s", "P6\n");
 	fprintf(ppmfile, "%s", "#Created by GIMP version 2.10.24 PNM plug-in\n");
 	fprintf(ppmfile, "%s", dimensions);
  	fprintf(ppmfile, "%s", "\n255\n");

	for(int i = 0; i < w; i++){
  	 for(int j = 0; j < h; j++){
   		 fwrite(&pixels[i][j], sizeof(struct ppm_pixel), 1, ppmfile);
  	 }
  }

	fclose(ppmfile);
}
