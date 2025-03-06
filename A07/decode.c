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
  struct ppm_pixel** pixels = read_ppm_2d(argv[1],&width,&height);


//  int max_char = (width * height * 3) / 8;
//  printf("Reading %s with a width: %d and height: %d \n", argv[1], width, height);
//  printf("Max characters in images: %d \n", max_char);

  //if could not read pixels 
  if (!pixels) {
	  fprintf(stderr, "Error unable to read pixels from file %s \n", argv[1]);
	  return 1;
  }
  // 3 colors, and 8 bits per character 
  int max_char = (width * height * 3) / 8;
  printf("Reading %s with a width: %d and height: %d \n", argv[1], width, height);
  printf("Max characters in images: %d \n", max_char);

 // pixel_data = simple 1d array of bites
 unsigned char* pixel_data = (unsigned char*) pixels; 


   printf("First few pixel values:\n");
   for (int i = 0; i < 10; i++) {  // Print first 10 bytes for debugging
    printf("%02X ", pixel_data[i]);
}

 //variables for the loop
 unsigned char character = 0; //saving new character 
 int bit_count = 0; //counter for 8 bits 

 //Each byte -- convert to character 
 for (int i=0; i < width; i++) {
	 for (int j = 0; j < height; j++) {
		 unsigned char colors[3] = {pixel.red, pixel.green, pixel.blue};

		 for (int k=0; k < 3; k++) {
			  //taking least significant bit
		         character = (character << 1) | (pixel_data[i] & 1); //going through each bit
        		 //printf("%c", character);
        		 bit_count++;

			 //once we have 8 bits, convert to character
	         if (bit_count == 8) {
                 if (character == '\0') {
                         break;
                 }
                 printf("%c", character);
                 bit_count = 0; //reseting for next byte
                 character = 0;

         }
		 }
	 }
 }

 printf("\n");
 free(pixels);

  return 0;
}

