/*loads a file containing binary data and then outputs the contents */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*read meta data with a single call to fread*/
struct meta_data {
	float version;
	unsigned int year;
	unsigned int length;
};
/*
struct meta_data* reader(const char* filename) {
	FILE* data = fopen(filename, "rb"); //reading file in binary

	if (data == NULL) {
		perror("Error opening file");
		return NULL;
	}
	char buffer[256];
	if (fgets(buffer, sizeof(buffer), data) != NULL){
		printf("Comment: %s", buffer);
	} else {
		printf("Error reading comment\n");
	}

	struct binary = malloc(sizeof(struct meta_data));
	if (binary == NULL) {
		return NULL;
	}
	if (freed(binary, sizeof(struct meta_data), 1, data) != 1){
		free(binary);
		return NULL;
	}
	//allocates memory to message 
	char* message = malloc(binary->length + 1);
	if (!message) {
		free(binary);
		return NULL;
	}

	printf("Year: %d /n", meta_data->version);

fclose(data);
return(binary);

}
*/
int main(int argc, char *argv[])

{
	 FILE* data = fopen(filename, "rb"); //reading file in binary
	
	/* Check if file provided */
        if (argc != 2) {// command line takes 2 arguments
                return NULL;
        }
         if (data == NULL) {
                perror("Error opening file");
                return NULL;
        }
	//reading comment line
	char comment[256];
	if (fgets(comment, 256, data) != 1) {
		fprintf(stderr, "Error reading comment \n");
	}

	//read meta data
	struct meta_data meta;
	if(fread(&meta, sizeof(meta_data), data) == NULL) {
		fprintf(stderr, "Error reading data");

	}
	//allocating memory for message
	 char* message = malloc(meta->length + 1);
         if (!message) {
                return NULL;
        }
	//reading message data 
	if (fread(message, 1, meta.length + 1) != meta.length + 1) {
		fprintf(stderr, "Error reading message\n");
      	        free(message);
                fclose(file);
	}
	//printing everything
	printf("Comment: %s\n", comment);
	printf("Version: %f\n", meta.version);
	printf("Year: %d\n", meta.year);
	printf("Length: %d\n", meta.length);
	printf("Message: %s\n", message);

	

  return 0;
}
