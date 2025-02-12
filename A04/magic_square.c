/* ----------------------------------------------
 * Author: Hanna Abrahem 
 * Date: Febuary 8th, 2025
 * Description: tests if the given matric is magic square. Where a magic square is NxN, and each row, diagonal has the same sum
 ---------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

int is_magic_square(int **matrix, int n) {
     /*Function checks if matrix is magic. First goes through all rows, then column, then lastly the 2 diagonals
      * parameters: matrix, and the size of the row/column of matrix
      * return 1 if magic square */

    // Compute magic constant (sum of first row)
    int magic_constant = 0;
    for (int j = 0; j < n; j++) {
        magic_constant += matrix[0][j];
    }

     // Check rows
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += matrix[i][j];
        }
        if (sum != magic_constant) return 0;
    }
    // Check columns
    for (int j = 0; j < n; j++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += matrix[i][j];
        }
        if (sum != magic_constant) return 0;
    }

    // Check main diagonal
    int sum1 = 0;
    for (int i = 0; i < n; i++) {
        sum1 += matrix[i][i];
    }
    if (sum1 != magic_constant) return 0;

    // Check secondary diagonal
    int sum2 = 0;
    for (int i = 0; i < n; i++) {
        sum2 += matrix[i][n - i - 1];
    }
    if (sum2 != magic_constant) return 0;

    return 1;
}

/*Adding parameters to read file in command line */
int main( int argc, char *argv[]) {

	/*Reading file command line arguments */
	FILE *file = stdin;

	 /* Check if file provided */
	if (argc == 2) {// command line takes 2 arguments
        file = fopen(argv[1], "r");
        if (!file) {
            perror("Error opening file");
            return 1;
        }
    } 
	/* Variable declaration */
	int n, m;

	/* use fprintf and fscanf for files */
	fscanf(file, "%d %d",&n, &m);
	if (n != m) {
		printf("M is not a magic square");
	}	
	if ( n==1) {
		printf("M is a magic square. (magic_constant = 1)");
	}

	// Allocate memory for matrix 
	int **matrix = (int **)malloc(n * sizeof(int *));
	for (int i = 0; i < n; i++) {
		matrix[i] = (int *)malloc(n * sizeof(int));

	}

	//Read matrix values 
	for (int i =0; i < n; i++) {
		for (int j=0; j < n; j++) {
			fscanf(file, "%d", &matrix[i][j]);
		}

	}
	// Print the matrix
   	 printf("Matrix:\n");
   	 for (int i = 0; i < n; i++) {
       		 for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
	if (n != m) {
                printf("M is not a magic square \n");
		exit(1);
        }
//        if ( n==1) {
//                printf("M is a magic square. (magic_constant = 1) \n");
//		exit(1);
//        }


	if (is_magic_square(matrix,n)) {
		printf("M is a magic square \n");
	}
	else{
		printf("M is not a magic square \n");
	}

	 // Free allocated memory
   	 for (int i = 0; i < n; i++) {
        	free(matrix[i]);
   	 }
   	 free(matrix);

	
  return 0;
}
