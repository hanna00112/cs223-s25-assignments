/***************************************************
 * Author: Hanna Abrahem 
 * Date: March 28th, 2025
 * Description: implements a program that used N processes to search for a keyword in a set of files
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>       // For timing functions
#include <sys/time.h>   // For gettimeofday

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

/* argv0 = grep
 * argv1 = NumProcesses
 * argv2 = Keyword
 * arg3 = files  */
/*N child that searches subset of files, each will open files */
int main(int argc, char** argv) {
	if (argc < 4) {
		printf("Usage: %s <NumProcesses> <Keyword> <Files>\n", argv[0]);
		return 0;
	}
	/*Parsing Command-Line Arguments */
	int num_processes = atoi(argv[1]); //converting NumProcesses to an integer
	char* keyword = argv[2];
	char** files = &argv[3];
	int num_files = argc - 3; //number of files

	printf("Searching %d files for keyword: %s\n", num_files, keyword);

	/*Subdivide the files among the N processes */
	int files_per_process = num_files / num_processes;
	int extra_files = num_files % num_processes; //extra files 
	int file_index = 0;

	struct timeval start, end;
	gettimeofday(&start, NULL); //start timing
	
	pid_t* pids = malloc(num_processes * sizeof(pid_t));  // Allocate memory dynamically
	if (!pids) {
    		perror("Memory allocation failed");
    		return 1;
		}
	pid_t* pids[num_processes];

	for (int i = 0; i < num_processes; i++) {
		int count = files_per_process+ (i < extra_files ? 1 : 0); //distributing extra files
		pids[i] = fork();

		if (pids[i] == 0) {
			int matches = 0;
			printf("Process [%d] searching %d files\n", getpid(), count);
		
		for (int j = 0; j < count; j++) {
			char* filename = files[file_index++];
			FILE* file = fopen(filename, "r");
			if (!file){
				printf(ANSI_COLOR_RED "Process [%d] Error: Cannot open file %s\n" ANSI_COLOR_RESET, getpid(), filename); //used to make file color red
			}
			char line[1024];
			while (fgets(line, sizeof(line), file)) {
				if (strstr(line, keyword)) {
					matches++;
					printf("Process [%d] Found match in %s: %s", getpid(), filename, line); 
				}
			}
			fclose(file);
		}
		exit(matches);
	}
	}

	int total_matches = 0;
	for (int i = 0; i < num_processes; i++){
		int status;
		waitpid(pids[i], &status, 0); // waiting for each child 
		if (WIFEXITED(status)){
			total_matches += WEXITSTATUS(status);
		}
	}
	gettimeofday(&end, NULL); // end timing
	double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_sec - start.tv_usec) / 1e6;

	printf("Total occurrences: %d\n", total_matches);
        printf("Elapsed time: %.6f seconds\n", elapsed);
	free(pids);



  return 0;
}
