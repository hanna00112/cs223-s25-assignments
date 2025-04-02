/***************************************************
 * Author: Hanna Abrahem 
 * Date: April 2nd, 2025
 * Description: uses signals to coornidate between 2 processes
 ******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <unistd.h>

//when user presses m, parent sends SIGALARM
//when child recieves SIGALARM, child prints "MARCO" & sends SIGALARM to parent
//when parent recieves SIGALARM, parent prints "POLO"

//signal handler for child process
void child_handler(int sigum){
	if (sigum == SIGALRM) {
		printf("Marco [%d]\n", getpid());
		kill(getppid(), SIGALRM); // send SIGALRM to parent
	}
}

//signal handler for parent process
void parent_handler(int sigum) {
	if (sigum == SIGALRM) {
		printf("Polo [%d]\n", getpid());
	}
}

int main()
{
	pid_t ret;
	ret = fork();
	if (ret == 0) { //child process
		signal(SIGALRM, child_handler);
		while (1) {
			pause();
		}
		}

	else { //parent process
		signal(SIGALRM, parent_handler);
		printf("Parent is %d\n", getpid());
		printf("Child is %d\n", ret);

		char input;
		while (1) {
			input = getchar();
			if (input == 'm') {
				kill(ret, SIGALRM); // send sigalrm to child
			} else if (input == 'q') {
				kill(ret, SIGTERM); //terminate child process
				exit(0);
			}
		}
	}

  return 0;
}
