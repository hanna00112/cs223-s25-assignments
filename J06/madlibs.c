#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 32

int main()
{
	int boolean;
	printf("Enter 1 for true & 0 for false: ");
	scanf("%d", &boolean);

	int num_adjectives;
	printf("Enter number of adjectives: ");
	scanf("%d",&num_adjectives);
	getchar();

	//int adjectives[num_adjectives];
	char **adjectives = malloc(sizeof(char *) * num_adjectives);
	for (int i = 0; i < num_adjectives; i++) {
     	   adjectives[i] = malloc(sizeof(char) * 32);
    }
	for (int i = 0; i < num_adjectives; i++) {
		//scanf("%d",&adjectives[i]);
		printf("Adjective: ");
                fgets(adjectives[i], 32, stdin);
	}

	if(boolean) {

	printf("You are the most ");
	for (int i = num_adjectives - 1; i >= 0; i--) {
		printf("%s",adjectives[i]);

	}
	printf("person that I know and you know its true!\n");
	} else {
		printf("I have nothing to say\n");
	}

	free(adjectives);
    return 0;
}
