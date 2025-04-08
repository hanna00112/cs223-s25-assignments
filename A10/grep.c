/***************************************************
 * Author: Hanna Abrahem 
 * Date: April 2nd, 2025
 * Description: grep searches a list of files for a given keyword or expression. Implemented using N threads to search for a
 * keyword in a set of files
 ******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

typedef struct {
	char** files;
	int start;
	int end;
	char* keyword;
} ThreadArgs;

//function for each thread to seach for keyword in file
void* search_files(void* arg) {
	ThreadArgs* args = (ThreadArgs*)arg;

	for (int i = args->start; i < args-> end; i++){
		FILE* file = fopen(args-> files[i], "r");
		if (!file) {
			perror("Error opening file");
			continue;
		}
		char line[1024];
		while (fgets(line, 1024, file)){
			if (strstr(line, args->keyword)){//finding matching keywords
				printf("[%s] %s", args->files[i], line);
			}
		}
		fclose(file);
	}
	return NULL;

}

int main(int argc, char** argv) {
	if (argc < 4) {
		printf("Usage: %s <NumProcesses> <Keyword> <Files>\n", argv[0]);
		return 0;
	}
	/*Parsing Command-Line Arguments */
	int num_threads = atoi(argv[1]); //converting NumProcesses to an integer
	char* keyword = argv[2];
	char** files = &argv[3];
	int num_files = argc - 3; //number of files

	printf("Searching %d files for keyword: %s\n", num_files, keyword);

	/*Subdivide the files among the N processes */
	int files_per_thread = num_files / num_threads;
	int extra_files = num_files % num_threads; //extra files
	int file_index = 0;

	pthread_t* threads = malloc(num_threads * sizeof(pthread_t));
	ThreadArgs* args = malloc(num_threads * sizeof(ThreadArgs));

	for (int i = 0; i < num_threads; i++) {
		args[i].files = files;
		args[i].start = file_index;
		args[i].end = file_index + files_per_thread + (i < extra_files ? 1 : 0);
		args[i].keyword = keyword;
		file_index = args[i].end;

		pthread_create(&threads[i], NULL, search_files, &args[i]);
	}
	for (int i = 0; i < num_threads; i++) {
		pthread_join(threads[i], NULL);
	}
  return 0;
}
