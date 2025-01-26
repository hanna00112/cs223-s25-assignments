/***************************************************
 * Author: Hanna Abrahem 
 * Date: Jan 25th, 2025
 * Description: Asks user for a word then encodes it using a shift cypher.
 */
#include <stdio.h>
#include <string.h>

char shift_char(char c, int shift) {
  return 'a' + (c - 'a' + shift + 26) % 26;
}
int main() {
 /* Variable declaration */
 char word[50];
 int shift;

 /* Welcoming Message */
 printf("Enter a word to encode:");
 scanf("%s", word);

 printf("Enter a shift for your word:");
 scanf("%d", &shift);

 for(int i=0; i<strlen(word); i++) {
   word[i] = shift_char(word[i], shift);
}

 printf("Your cypher word is: %s\n", word);

  return 0;
}
