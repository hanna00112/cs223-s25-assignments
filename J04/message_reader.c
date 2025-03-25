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
	FILE* data = fopen(argv[1], "rb"); //reading file in binary
        /* Check if file provided */
        if (argc != 2) {// command line takes 2 arguments
                return 1;
        }
         if (data == NULL) {
                perror("Error opening file");
                return 1;
        }
        //reading comment line
        char comment[256];
        if (fgets(comment, 256, data) != 1) {
                fprintf(stderr, "Error reading comment \n");
        }

        //read meta data
        struct meta_data meta;
        if(fread(&meta, sizeof(struct meta_data), data) == NULL) {
                fprintf(stderr, "Error reading data");

        }
        //allocating memory for message
         char* message = malloc(meta.length + 1);
         if (!message) {
                return 1;
        }
        //reading message data
        if (fread(message, 1, meta.length + 1) != meta.length + 1) {
                fprintf(stderr, "Error reading message\n");
                free(message);
                fclose(data);
        }
        //printing everything
        printf("Comment: %s\n", comment);
        printf("Version: %f\n", meta.version);
        printf("Year: %d\n", meta.year);
        printf("Length: %d\n", meta.length);
        printf("Message: %s\n", message);

  free(message);
  fclose(data);
  return 0;
}
