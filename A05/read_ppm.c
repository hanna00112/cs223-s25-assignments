/*----------------------------------------------
 * Author: Hanna Abrahem  
 * Date: Feb 16th, 2025
 * Description: read PPM files stored in binary format. 
 ---------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read_ppm.h"

// Choose *one* to implement (do not remove the other one!)

struct ppm_pixel* read_ppm(const char* filename, int* w, int* h) {
  return NULL;
}

/*return an array or arrays */
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
		sscanf(buff, "%d %d", w, h); 
	} if(index == 3) { // the rest of the header is unnecessarily 
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
	for (int j = 0; j < *w; j++) {
		fread(&binary[i][j], sizeof(struct ppm_pixel), 1, ppmData); 

	}	

}

fclose(ppmData);
return binary;


  return NULL;
}
