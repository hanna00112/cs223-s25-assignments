/*----------------------------------------------
 * Author: Hanna Abrahem 
 * Date: Feb 21st, 2025
 * Description: Creating a test program for write_ppm.c
 ---------------------------------------------*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "read_ppm.h"
#include "write_ppm.h"

int main(int argc, char** argv) {
  int w, h;
  struct ppm_pixel** pixels = read_ppm_2d("feep-raw.ppm", &w, &h);

  printf("Testing file feep-raw.ppm: %d %d ", w, h);

  // writing image in new file 
  write_ppm_2d("test.ppm", pixels, w, h);

  // reading new file 
  struct ppm_pixel** testPixels = read_ppm_2d("test.ppm", &w, &h);

  for (int i=0; i < h; i++) {
	  for (int j=0; j < w; j++) {
		  printf("(%d, %d, %d)", testPixels[i][j].red, testPixels[i][j].green, testPixels[i][j].blue);
	  }
	  printf("\n");
  }
  
  // freeing memory 
  for (int i=0; i<h; i++) {
	  free(pixels[i]);
	  free(testPixels[i]);
  }

  // test writing the file to test.ppm, reload it, and print the contents
  free(pixels);
  free(testPixels);
  return 0;
}
