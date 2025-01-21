/***************************************************
 * mathgame.c
 * Author: 
 * Implements a math game
 */

#include <stdio.h>

int main() {
  return 0;
}

int mathgame() {

  /* Variable declaration */
  int count = 0; // number of correct answers 
  int questions; // number of questions the user wants 
  /* random int between 0 and 9 */
  int random1 = rand() % 10;
  int random2 = rand() % 10;

  /* Printing a welcoming message */
  printf("Welcome To a Simple Math Games of Addition Problems")
  printf("How many rounds do you want to play")
  scanf("%d", questions)

  for (i = 0; i < questions; i++) {
    print
    math_problem = random1 + random2

    if math_problem is correct {
      printf("Correct :)")
      count += 1;
    }
    else {
      printf("Incorrect :(")
    }
  }
  printf("You answered %d/%d correctly",count, questions);


}
