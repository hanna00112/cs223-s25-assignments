/***************************************************
 * Author: Hanna Abrahem 
 * Date: Jan 25th, 2025
 * Description: Asks user for a word and creates a bad password from it
 */
#include <stdio.h>
#include <string.h>

int main() {
  /* Variable declaration */
  char password[50];

  /* Printing welcoming message */
  printf("Enter a word:");
  scanf("%s", password);

  for (int i = 0; i < strlen(password); i++) {
	if (password[i] == 'e') {
	  password[i] = '3';
}
	else if (password[i] == 'l') {
	  password[i] = '1';
}
	else if (password[i] == 'a') {
	  password[i] = '@';
}
}

  printf("Your bad password is %s\n", password);

  return 0;
}

