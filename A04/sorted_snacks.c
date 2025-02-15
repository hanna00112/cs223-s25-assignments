/*----------------------------------------------
 * Author: Hanna Abrahem 
 * Date: Feb 13, 2025
 * Description: allows users to add snacks to a snackbar, and display them in alabetical order. Use a linked list to store the snacks
 ---------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Node struct -- each snack */
struct node {
	char name[30];
	int quantity;
	float cost;
	struct node* next;
};
/*Insert_first -- create new snack & insert in begnning of the list */
void insert_front(struct node** head, char* name, float cost, int quantity) {
	struct node* new_node = malloc(sizeof(struct node));
	if (new_node == NULL) {
		printf("ERROR: out of space! \n");
		exit(1);
	}
	strcpy(new_node->name, name);
	new_node->cost = cost;
	new_node->quantity = quantity;
	new_node->next = *head;
	*head = new_node; // updating the header pointer 

}

/*clear -- clear all items in the list */
void clear(struct node** head) {
	struct node* current = *head;
	struct node* next_node;

	while (current != NULL) {
		next_node = current->next;
		free(current);
		current = next_node;
	}
	*head = NULL; //head is set to NULL after clearing

}

/*printList -- should print contents in the list 
 * node is a single pointer because not modifying the lists*/
void printList(struct node* head) {
	struct node* temp = head;
	while (temp != NULL) {
		printf("%s, cost: %.2f, quantity: %d \n", temp->name, temp->cost, temp->quantity);
		temp = temp->next;
	}
	printf("\n");
}



int main() {
	 /* Variable declaration*/
	 int num_snacks;
	 struct node* head = NULL;

	 /* Welcoming message*/
	 printf("Welcome to Hanna's snackbar. How many snacks would you like to input?:");
	 scanf("%d", &num_snacks);

	/* Users inputting their snacks */
	 for (int i=0; i < num_snacks; i++) {
		 char name[30];
		 float cost;
		 int quantity;

 		 printf("Enter snack name: \n");
		 scanf("%s", name);

		 printf("Enter snack cost: \n");
		 scanf("%f", &cost);

		 printf("Enter snack quantity: \n");
		 scanf("%d", &quantity);

		 insert_front(&head, name, cost, quantity);
	 }

		printList(head);
	
 	 return 0;
}
