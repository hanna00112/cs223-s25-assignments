/*----------------------------------------------
  * Author:Hanna Abrahem 
  * Date: Feb 1st, 2025
  * Description: asks a user for a string, and integar then repeats the string integar times
  ---------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	/* Variable declaration */
	char s[32];
	int n;

	/* Printing welcoming message */
	printf("Enter a word you want repeated:");
	scanf("%s", s);

	printf("Enter the amount of times you want word repeated:");
	scanf("%d", &n);

	/* Allocating the memory needed based on how many times repeated */
	char *result = NULL;
	result = malloc((sizeof(char) * strlen(s) *n)+1);

	for (int i=0; i < n; i++) {
		strcpy(result, s); //result is currently "", and s is what you need to add to result
	}
	printf("%s \n", result);

	free(result);

	return 0;
}
