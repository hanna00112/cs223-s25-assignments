/*----------------------------------------------
 * Author: Hanna Abrahem 
 * Date: Feb 25rd, 2025
 * Description: takes a C file as command line argument & uses a stack to check for matched braces. If not all braces are matched, print the line where
 * mis-matched brace occurs  
 ---------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Node for each brace, also tracks line and column location of brace */
struct node {
	char brace;
	int line;
	int column;
	struct node* next;
};
/*stores items in stack, need functions push, pop, clear, print */

void push(struct node** top, char brace, int line, int column) {
	struct node* new_node = malloc(sizeof(struct node));
	if (new_node == NULL) {
		perror("Memory allocation failed");
		exit(1);
	}
	
	new_node->brace = brace;
	new_node->line = line;
	new_node->column = column;
	new_node->next = *top;
	*top = new_node;
}

struct node* pop(struct node** top) {
	if (*top == NULL) {
		return NULL;
	}
	struct node* temp = *top; //saving top pointer 
	*top = (*top)->next; //moving top pointer to next pointer
	return temp; 

}
void clear_stack(struct node** top) {
	struct node* current = *top;
	struct node* next_node;

	while (current != NULL) {
		next_node = current->next;
		free(current);
		current = next_node;

	}
	*top = NULL;
}


int main(int argc, char* argv[])
{
	//opening file 
	FILE* file = fopen(argv[1], "r");
	if (argv[1] == NULL) {
		printf("Error: unable to read file");
	}

	struct node* stack = NULL;
	int line = 1;
	int column = 0; //beginning of file 
	char ch;
	//reading file character by character
	while ((ch = fgetc(file)) != EOF) {
		column++;

		if (ch == '\n') { 
		line++; // move to next line 
		column = 0; //reset column count
		}
		else if (ch == '{') {
		push(&stack, '{', line, column); 
		}
		else if (ch == '}') {
		struct node* matched = pop(&stack);
		if (matched == NULL) {
		printf("Unmatched brace on line %d and column %d \n", line, column);
		} else {
		printf("Matching braces found: (%d,%d) -> (%d,%d) \n",matched->line, matched->column, line, column);
		free(matched);
		}
		}
		}
	
  fclose(file);
  clear_stack(&stack);
  return 0;
}

