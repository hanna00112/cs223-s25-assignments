/*----------------------------------------------
 * Author: Hanna Abrahem 
 * Date: Feb 28rd, 2025
 * Description: creating a binary tree in C!  
 ---------------------------------------------*/
#include "tree.h"
#include "stdio.h"
#include "stdlib.h"
#include <string.h>

struct tree_node* find(const char* name, struct tree_node* root)
{
	if (root == NULL) {
		return NULL; // base case if tree is empty
	}

	if (strcmp(name, root->data.name) < 0) {
		return (find(name, root->left));
	}
	else if (strcmp(name, root->data.name) > 0) {
		return (find(name, root->right));
	}
	else {
		return root;
	}
  return NULL;
}

struct tree_node* insert(const char* name, struct tree_node* root)
{
	if (root == NULL) {
		root =(struct tree_node*) malloc(sizeof(struct tree_node));
		if (root == NULL) {
			fprintf(stderr, "Out of space!\n");
			exit(1);
	}
		strcpy(root->data.name, name);
		root->left = root->right = NULL;
	}	
	else if (strcmp(name, root->data.name < 0)) {
			root->left = insert(name, root->left);
		} 
	} else if (strcmp(name, root->data.name > 0)) {
			root->right = insert(name, root->right);
		}
	}
	}
	return root;

  return NULL;
}

void clear(struct tree_node* root)
{
}

void print(struct tree_node* root)
{
}

void printSorted(struct tree_node* root)
{
}

