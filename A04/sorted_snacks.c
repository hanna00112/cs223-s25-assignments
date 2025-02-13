/*----------------------------------------------
 * Author: Hanna Abrahem 
 * Date: Feb 13, 2025
 * Description: allows users to add snacks to a snackbar, and display them in alabetical order. Use a linked list to store the snacks
 ---------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

/* Node struct */
struct node {
	int val;
	struct node* next;
};

int main() {
	 /* Variable declaration*/
	 int num_snacks;

	 /* Welcoming message*/
	 printf("Welcome to Hanna's snackbar. How many snacks would you like to input?:");
	 scanf("%d", &num_snacks);

	/* Allocating the memory based on how many snacks user inputs */
	 struct node* n = malloc(sizeof(struct node));
	 if (n == NULL) {
		 printf("ERROR: out of space!\n");
		 exit(1);
	 }




 	 return 0;
}
