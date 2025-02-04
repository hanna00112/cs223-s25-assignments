 //Hanna & Isabella
 // Feb 4th, 2025
 // Asks user for a series of digits, then prints the digits in sorted order. 

#include <stdio.h>
#include <string.h>

int main() {
 /* variables */
char user_array[32];
int counts[10];

/* Creating a array of all 0 */
 for (int i=0; i < 10; i++) {
  counts[i] = 0;
}

 /* welcoming messages */
 printf("Enter digits: \n");
 scanf("%s", user_array); 

 /*populating the counts array with amount of each number in user_array*/
 for (int i=0; i <strlen(user_array); i++) {
  if (user_array[i] >= '0' &&  user_array[i] <= '9') {
   int v = user_array[i] - '0'; // index number
    counts[v] += 1;
}
}

 // print the amount of times -- index
 printf("Sorted Array: \n");
 
 for (int i=0; i < 10; i++) { // looping through digits 1-9
  for (int j = 0; j < counts[i]; j++) {  // Print each digit count[i] times
            printf("%d", i);
        }
    }
 printf("\n");
   return 0;
}
