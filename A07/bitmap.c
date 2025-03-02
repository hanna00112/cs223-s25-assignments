/*----------------------------------------------
 * Author: Hanna Abrahem 
 * Date: March 2nd, 2025
 * Description: reads in a single 64-bit unsigned integer and outputs it as an 8x8 1bbq sprite
 ---------------------------------------------*/
#include <stdio.h>

int main() {
  unsigned long img;
  scanf(" %lx", &img);
  printf("Image (unsigned long): %lx\n", img);

  // todo: your code here
  for (int i=0; i < 64; i++) {
	  unsigned long mask = 0x1ul << (63 - i); //starting in the leftmost bit

	  //checking if its a 0 or 1 
	  if (img & mask) {
		  printf("@"); // if 1
	  } else {
		  printf(" "); //if 0
	  }

	  //new line after 8 bits 
	  if ((i+1) % 8 == 0){
		  printf("\n");
	  }

  }
  return 0;
}
