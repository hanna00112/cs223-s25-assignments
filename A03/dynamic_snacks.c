/*----------------------------------------------
 * Author:Hanna Abrahem 
 * Date: Feb 2nd, 2025 
 * Description: allows users to add snacks to a snackbar
 ---------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

struct snack {
 char name[30];
 int quantity;
 float cost;
};

int main() {
 /* Variable declaration*/
 int num_snacks;
 

 /* Welcoming message*/
 printf("Welcome to Hanna's snackbar. How many snacks would you like to input?:");
 scanf("%d", &num_snacks);


 /* Allocating the memory based on how many snacks user inputs */
 struct snack *snack_list = malloc(sizeof(struct snack) * num_snacks);
 if (snack_list == NULL) {
  printf("Memory allocation failed.\n");
        return 1;  // Exit if memory allocation fails
}

/* Users inputting their snacks */
 for (int i=0; i < num_snacks; i++) {
  printf("Enter snack name: \n");
  scanf("%s", snack_list[i].name);

  printf("Enter a cost: \n");
  scanf("%f",&snack_list[i].cost);

  printf("Enter a quantity: \n");
  scanf("%d", &snack_list[i].quantity);
}

/* Displaying snacks */
 for (int i=0; i < num_snacks; i++) {
  printf("%d)%s, cost: %.2f, quantity: %d\n",i, snack_list[i].name, snack_list[i].cost, snack_list[i].quantity);
}

free(snack_list);
  return 0;
}
