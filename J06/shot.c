#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <unistd.h>

void handler(int sigum) {
	printf("I've been shot \n");
	exit(0);
}

int main()
{
	signal(SIGINT, handler);
	while (1);
  return 0;
}
