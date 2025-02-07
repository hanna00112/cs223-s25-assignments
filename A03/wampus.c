/*----------------------------------------------
 * Author: Hanna Abrahem  
 * Date: Feb 4th, 2025 
 * Description: randomly placing wampus within a NxM grid. Then fill the remaining cells with their distance
 * from the wampus(Manhatten Distance)
 ---------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int manhattan_distance(int x1, int y1, int x2, int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}

int main() {
	/*variable declaration */
	int N; //number of rows 
	int M; //number of columns

	/* welcoming message */
	printf("Please enter a number of rows: \n");
	scanf("%d", &N);

	printf("Please enter a number of columns: \n");
	scanf("%d", &M);

	/*allocating memory based on users matrix size */
	int  *user_matrix = malloc(sizeof(int) * N * M);
	if (user_matrix == NULL) {
		printf("Bad malloc error\n");
		exit(1); // exit the program and indicate error
	}
	
	/*Placing wampus within grid */
	int wumpus_x = rand() % N; //random row index from 0 to N
	int wumpus_y = rand() % M; //random column index from 0 to M
		
	user_matrix[wumpus_x * M + wumpus_y] = 0; //adding W to random spot in matrix

	/* filling remaining cells with Manhattan Distance */
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			 if (!(i == wumpus_x && j == wumpus_y)) {
               			 user_matrix[i * M + j] = manhattan_distance(i, j, wumpus_x, wumpus_y);
			 }
		}
	}
	/*printing the matrix */
	printf("Your Matrix: \n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M;j++) {
			if (user_matrix[i * M + j] == 0) {
               			 printf("  W "); // Print 'W' for Wumpus
            } else {
                printf("%3d ", user_matrix[i * M + j]);
            }
        }
        printf("\n"); // Move to the next line after each row
    }



	/* free malloc */
	free(user_matrix);
	
  return 0;
}
