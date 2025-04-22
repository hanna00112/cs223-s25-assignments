#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read_ppm.h"

struct ppm_pixel* read_ppm(const char* filename, int* w, int* h) {

  return NULL;
}

struct ppm_pixel** read_ppm_2d(const char* filename, int* w, int* h) {
	FILE* ppmData = fopen(filename, "rb"); //opening file in binary mode

	if (ppmData == NULL) {
		perror("Error opening file");
		return NULL;
	}
struct ppm_pixel** binary = NULL;
char buff[1000];
int index = 0;
while (fgets(buff, 100, ppmData)) {
	if(index == 2) { // 3 line of file is contains width and height
		sscanf(buff, "%d %d",w,h);
//	printf(" Width = %d, Height = %d\n", *w, *h);
	} if(index == 3) { // the rest of the header is unnecessary
		break;
	}
	index++;
}


binary = malloc(sizeof(struct ppm_pixel*)* *h);

//alocates memory for each row in 2D array
for (int i = 0; i < *h; i++) {
	binary[i] = malloc(sizeof(struct ppm_pixel) * *w);
	if (binary[i] == NULL) {
		perror("Error allocating memory");
		return NULL;
	}
	// Read pixel data row by row
	for (int j=0; j < *w; j++) {
       		 fread(&binary[i][j], sizeof(struct ppm_pixel), 1, ppmData);
	}
}

fclose(ppmData);
return binary;


  return NULL;
}

  
