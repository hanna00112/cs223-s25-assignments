/***************************************************
 * mathgame.c
 * Author:Hanna Abrahem 
 * Implements a math game
*************************************************/
#include <stdio.h>
#include <stdlib.h>

int main() {
  /* Variable declaration */
  int count = 0; // number of correct answers 
  int questions; // number of questions the user wants

  /* Printing a welcoming message */
  printf("Welcome To a Simple Math Games of Addition Problems");
  printf("How many rounds do you want to play");
  scanf("%d",&questions);


  for (int i = 0; i < questions; i++) {
    /* random int between 0 and 9 */
    int random1 = rand() % 10;
    int random2 = rand() % 10;
    int user_answer;
    int math_problem = random1 + random2;

    printf("%d + %d = ? ", random1, random2);
    scanf("%d", &user_answer);
   
    if(user_answer == math_problem) {
      printf("Correct :)\n");
      count++;
    }
    else {
      printf("Incorrect :( The correct answer was %d.\n", math_problem);
    }
  }

  printf("You answered %d/%d correctly",count, questions);

  return 0;
}
