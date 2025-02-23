/*----------------------------------------------
 * Author: Hanna Abrahem 
 * Date: feb 22nd, 2022
 * Description: read and prints the values of a binary file
 ---------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include "read_ppm.h"

int main() {
  int w, h;
  struct ppm_pixel** pixels = read_ppm_2d("feep-raw.ppm", &w, &h);

  // todo: print out the grid of pixels
   for(int i = 0; i < h; i++){
   	for(int j = 0; j < w; j++){
      printf("(%hhu,%hhu,%hhu) ", pixels[i][j].red, pixels[i][j].green, pixels[i][j].blue);
    }
    printf("\n");
  }

  for(int i = 0; i < h; i++){
    free(pixels[i]); // freeing each row 
  }
  free(pixels);
  return 0;
}

