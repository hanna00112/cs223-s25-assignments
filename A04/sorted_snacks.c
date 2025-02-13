/*----------------------------------------------
 * Author: Hanna Abrahem 
 * Date: Feb 13, 2025
 * Description: allows users to add snacks to a snackbar, and display them in alabetical order. Use a linked list to store the snacks
 ---------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

/* Node struct -- each snack */
struct node {
	int val;
	struct node* next;
};
/*Insert_first -- create new snack & insert in begnning of the list */
void insert_front(int val, struct node* head) {
	struct node* n = malloc(sizeof(struct node));
	if (n == NULL) {
		printf("ERROR: out of space! \n");
		exit(1);
	}
	n->val = val;
	n->next = head;
	head = n;

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
	*head_ref = NULL;

}

/*printList -- should print contents in the list */
void printList(struct node* head) {
	struct node* temp = head;
	while (temp != NULL) {
		print("%d", temp->data);
		temp = temp->next;
	}
	print("\n");

}

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
