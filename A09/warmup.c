/*implementing a forking algorithm based on a picture */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	pid_t b0;
	printf("%d] A0\n", getpid());

	b0 = fork();
	if (b0 == 0) {
		printf("%d] B0\n", getpid());

		pid_t b1 = fork();
		if (b1 == 0) {
			printf("%d] B1\n", getpid());
			printf("%d] Bye\n", getpid());
			return 0;
		}
		return 0;
	}	
		pid_t c0;
		c0 = fork();
		if(c0 == 0){
			printf("%d] C0\n", getpid());

			pid_t c1 = fork();
			if (c1 == 0){
				printf("%d] C1\n", getpid());
				printf("%d] Bye\n", getpid());
				return 0;
			}
			return 0;
		}


	
	//printf("%d] Bye\n", getpid());


  return 0;
}
