/* ----------------------------------------------
 * Author: Hanna Abrahem 
 * Date: Febuary 8th, 2025
 * Description: tests if the given matric is magic square. Where a magic square is NxN, and each row, diagonal has the same sum
 ---------------------------------------------*/
#include <stdio.h>

/*Adding parameters to read file in command line */
int main( int argc, char *argv[]) {

	FILE *file = stdin;

	 /* Check if file provided */
	if (argc == 2) {// command line takes 2 arguments
        file = fopen(argv[1], "r");
        if (!file) {
            perror("Error opening file");
            return 1;
        }
    } 

	
  return 0;
}
