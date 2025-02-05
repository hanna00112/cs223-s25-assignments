// Hanna Abrahem 
// Feb 4th, 2025
// asks a user to compete with 2 computer contestants for a high-end dishwasher
// should compute a random price between $3000 and $5000, and the closest answer between 
// the user and 2 AI contestants wins 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
	/* variable declaration */
	int user_guess;

	/* Welcoming messages */
	printf("Welcome to the Price is Right! \n");
	printf("Enter a guess to win a luxurious dishwasher:");
	scanf("%d", &user_guess);

	/* Generating random numbers */
	int max = 5000;
	int min = 3000;
	int AI_guess1 = rand() % (max - min + 1) + min;
        int AI_guess2 = rand() % (max - min + 1) + min;
	int dishwasher_cost = rand() % (max - min + 1) + min;	

	/* Displaying values */
	printf("AI contestant #1 guesses: %d \n", AI_guess1);
	printf("AI contestant #1 guesses: %d \n", AI_guess2);
	printf("The dishwasher cost is: %d \n", dishwasher_cost);

	/* Finding the closest guess */
	int user_diff = abs(dishwasher_cost - user_guess);
	int AI1_diff = abs(dishwasher_cost - AI_guess1);
	int AI2_diff = abs(dishwasher_cost - AI_guess2);


	if (user_diff < AI1_diff && user_diff < AI2_diff) {
		printf("Congratulations! You win the dishwasher! \n");
	} else if (AI1_diff < user_diff && AI1_diff < AI2_diff) {
		printf("AI contestant #1 wins the dishwasher \n");

	} else {
		printf("AI constestant #2 wins the dishwasher \n");
	}


   return 0;

}
