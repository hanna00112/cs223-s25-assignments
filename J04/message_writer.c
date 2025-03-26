/*loads a file containing binary data and then outputs the contents */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct meta_data {
	float version;
	unsigned int year;
	unsigned int length;
};
int main(int argc, char *argv[])

{
	 if (argc != 2) {// command line takes 2 arguments
                return 1;
        }
	 FILE* file = fopen(argv[1], "wb");
	 if (file == NULL){
		 perror("Error opening file");
	 }
	 //having hardcoded comment
	 const char* comment = "# This is a test comment";
	 if (fputs(comment, file)== EOF) {
		 fprintf(stderr, "Error writing comment");
		 return 1;
	 }
	 //defining meta data
	 struct meta_data meta = {1.0,2025,15};

	 //Writing meta data
	 if (fwrite(&meta, sizeof(struct meta_data), 1, file) != 1) {
		 fprintf(stderr, "Error writing meta data \n");
		 return 1;
	 }
	 const char* message = "Hello World! \n";

	 //writing message data
	 if (fwrite(message, 1, meta.length, file) != meta.length) {
		 fprintf(stderr, "Error writing message\n");
		 return 1;
	 }
	 fclose(file);
	
return 0;
}
