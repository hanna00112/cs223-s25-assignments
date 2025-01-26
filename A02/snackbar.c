/***************************************************
 * Author:Hanna Abrahem 
 * Date: Jan 25th, 2025
 * Description: maintains a list of snakcs available for purchase 
 */
#include <stdio.h>


 struct snack {
   char name[30]; // name of snack
   float cost;  //cost of snack
   int quantity; // quantity of snack
};
 
int main() {

 /* Variable declaration*/
 float amount = 0.00; // amount of money user has
 int choice; // users choice of snack


 /* Welcoming message*/
  printf("Welcome to Hanna's Struct Snack Bar.\n");
  printf("How much money do you have? ");
  scanf("%f", &amount);

 /* Array of snacks */
  struct snack snacks[4] = {  
   {"0)chickpeas", 3.50, 10},
   {"1)pita chips", 5.00, 3},
   {"2)cookies", 6.00, 6},
   {"3)pretzels", 4.50, 2}
};
 /* Display snack options*/
 for (int i = 0; i < 4; i++) {
     printf("%s, cost: %.2f, quantity: %d\n", snacks[i].name, snacks[i].cost, snacks[i].quantity);
};

  /* Getting the users snack */
  printf("What snack would you like to buy [0,1,2,3]? ");
  scanf("%d", &choice);
  
  if (choice <0 || choice >= 4){
    printf("Invalid choice. Please select a valid snack.\n");
} else {
    if (amount >= snacks[choice].cost){
       if (snacks[choice].quantity > 0){
	  amount -= snacks[choice].cost;
	  snacks[choice].quantity--;
          printf("You bought %s.", snacks[choice].name);
	  printf("You have %.2f left. \n", amount);

   } else { 
	printf("Sorry, we are out of %s\n", snacks[choice].name);
}
} else {
    printf("You can't afford %s\n", snacks[choice].name);
}
 }
  return 0;
}
