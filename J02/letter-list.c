
// stores the characters given word using a linked list and then allows user to delete a character from 
// the word

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

/*Node for each word */
struct node {
	char letter;
	struct node* next;
};

/*adding new letter to front of the linked list */
void insert_front(struct node** head, char letter) {
	struct node* new_node = malloc(sizeof(struct node));
	if (new_node == NULL) {
		printf("ERROR: out of space! \n");
		exit(1);
	}
	 new_node->letter = letter;
        *head = new_node;
}

/*clearing all items in the list */
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
void printWord(struct node* head) {
	struct node* temp = head;
	while (temp != NULL) {
	       printf("%c", temp->letter);
       	       temp = temp->next;	       
	}
	printf("/n");
}


int main()
{

	/* Variable declaration*/
	char user_word[30];
	char char_remove;
	struct node* head = NULL;

	/* Welcoming message*/
	printf("Enter a word: \n");
	scanf("%s", user_word);

	//printf("Enter a character to remove:");
	//scanf("%c",&char_remove);


	/*Populating the user_word into individuals letters in linked list */
	for (int i=0; i < strlen(user_word); i++) {
		insert_front(&head, user_word[i]);
	}

	printWord(head);

  return 0;
}
