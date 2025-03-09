/*----------------------------------------------
 * Author: Hanna Abrahem 
 * Date: March 7th, 2025
 * Description: reads a PPM file, and asks user for a message to embed within in
 ---------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "read_ppm.h"
#include "write_ppm.h"

int main(int argc, char** argv) {
  if (argc != 2) {
    printf("usage: encode <file.ppm>\n");
    return 0;
  }
  int width, height;
  struct ppm_pixel** pixels = read_ppm_2d(argv[1],&width,&height);

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

 int bit_position = 0; //keeps track of what bit
 int pixel_index = 0; //keeps track of pixel data
 unsigned char mask = 0xFE; 

 //User phrase 
 char encode[200] = "";
 printf("Enter a phrase you would like to encode in the text: ");
 scanf("%c", encode);

 for (int i =0; i < strlen(encode); i++){
	 unsigned char character = encode[i];

	 for (int bit = 7; bit >= 0; bit--) {  // Extract bits from most to least significant
	        int bit_value = (character >> bit) & 1;  // Extract current bit (MSB first)

		pixel_data[pixel_index] = (pixel_data[pixel_index] & mask) | bit_value;
		pixel_index++;

		if (pixel_index >= width * height * 3) {
         	   printf("Warning: Not enough space in image to encode full message!\n");
           	   free(pixels);
           	   return 1;
        }
	 }

 }

 // Output the new image with the encoded message
 char output_filename[256];
 snprintf(output_filename, sizeof(output_filename), "%s-encoded.ppm", argv[1]);
 write_ppm("output.ppm", (struct ppm_pixel*) pixels, width, height);

 printf("Writing file %s\n", output_filename);
 free(pixels);
  return 0;
}

