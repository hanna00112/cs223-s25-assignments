// creates a 2D array character array that holds given string along its edge 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

	/*variable declaration */	
	char user_input[30];


	/* welcoming message */
	printf("Enter a string:");
	scanf("%s", user_input);

	/*allocating memory based on users word size */
	char *user_word = malloc(sizeof(char) * (strlen(user_input) * 2));
	if (user_word == NULL) {
		printf("Bad malloc error\n");
		exit(1); // exit the program and indicate error
	}

	/* filling user_word array with string */
	for (int i = 0; i < strlen(user_input); i++) {
		for (int j = 0; j < strlen(user_input); j++) {
			char c = user_input[j];

			if (i == 0 || i == strlen(user_input) - 1) {
				user_word[i * strlen(user_input) + j] = c;
			} else if (i == j) {
				user_word[i * strlen(user_input) + j] = c;

			} else {
				user_word[i * strlen(user_input) + j] = ' ';
			}
			
		}
	}

	/*printing the matrix */
	printf("Your Matrix: \n");
	for (int i = 0; i < strlen(user_input); i++) {
		for (int j = 0; j < strlen(user_input);j++) {
			printf("%c", user_word[i * strlen(user_input) + j]);
		}
		printf("\n");
	}
	free(user_word);

  return 0;
}
