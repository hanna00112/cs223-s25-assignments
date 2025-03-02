/*----------------------------------------------
 * Author: Hanna Abrahem 
 * Date: Feb 28rd, 2025
 * Description: builds a binary search tree of given set of files. After building the tree, the program should give the user a prompt
 * where they can list the processed files in alphabetical order, then query the dependencies of the file by giving the filename  
 ---------------------------------------------*/
#include <stdio.h>
#include "tree.h"

struct tree_node {
	char filename[200]; //store filename
        char dependencies[10][200]; //storing dependencies 
	char dep_count; //number of dependencies
	struct tree_node* left;
	struct tree_node* right;	
}

int main()
{
	
  return 0;
}
