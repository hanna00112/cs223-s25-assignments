/*----------------------------------------------
 * Author: Hanna Abrahem 
 * Date: Feb 23rd, 2025
 * Description: takes a PPM image and displays it as ASCII art 
 ---------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include "read_ppm.h"
#include "write_ppm.h"

char ascii_intensity(int intensity) {
	if (intensity >= 0 && intensity <= 25) {
		return '@';
	}
	if (intensity <= 50) {
		return '#';
	}
	if (intensity <= 75) {
		return '%';
	}
	if (intensity <= 100) {
		return '*';
	}
	if (intensity <= 125) {
		return 'o';
	}
	if (intensity <= 150) {
		return ';';
	}
	if (intensity <= 175) {
		return ':';
	}
	if (intensity <= 200) {
		return ',';
	}
	if (intensity <= 225) {
		return '.';
	}
	return ' ';
}



int main(int argc, char* argv[]) {

	if (argc != 2) {
		perror("Error opening file");
            	return 1;
	}

	int w,h;
	struct ppm_pixel** pixels = read_ppm_2d(argv[1], &w, &h);
	if (pixels == NULL) {
		printf("error seeing pixels");
		return 1;
	}
	/* User message */
	printf("Reading %s with the width %d and height %d", argv[1], w, h);

	//Converting image to Ascii
	for (int i=0; i < h; i++) {
		for (int j=0; j < w; j++) {
			struct ppm_pixel pixel = pixels[i][j];
			int intensity = (pixel.red + pixel.blue + pixel.green) / 3;
			printf("%c", ascii_intensity(intensity));

		printf("Pixel (%d, %d) - RGB(%d, %d, %d), Intensity: %d, Char: %c\n",
    i, j, pixel.red, pixel.green, pixel.blue, intensity, ascii_intensity(intensity));

		}
		printf("\n");
	}

	// freeing memory
	for (int i = 0; i < h; i++) {
		free(pixels[i]);
	}
	free(pixels);


  return 0;

}
