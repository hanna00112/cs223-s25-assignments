/*----------------------------------------------
 * Author: Hanna Abrahem 
 * Date: March 2nd, 2025
 * Description: reads a PPM file, then outputs any message that mine be stored in the least significant bits of each color
 ---------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include "read_ppm.h"

int main(int argc, char** argv) {
  if (argc != 2) {
    printf("usage: decode <file.ppm>\n");
    return 0;
  }
  int width, height;
  struct ppm_pixel* pixels = read_ppm_2d(argv[1],&width,&height);

  //if could not read pixels 
  if (!pixels) {
	  fprintf(stderr, "Error unable to read pixels from file %s", argv[1]);
	  return 1;
  }
  // 3 colors, and 8 bits per character 
  int max_char = (width * height * 3) / 8;
  printf("Reading %s with a width: %d and height: %d", argv[1], width, height);
  printf("Max characters in images: %d", max_char);

  


  return 0;
}

