#include <stdio.h>

int main(int argc, char** argv)
{
	 if (argc != 2) {
   	 printf("usage: message <file>\n");
   	 return 0;
  }
    FILE* fp = fopen(argv[1], "r");
    char c = fgetc(fp);
    while (c != EOF)
    {
	char shifted_c = ((unsigned char)c) >> 1;    
        printf("%c", shifted_c);
        c = fgetc(fp);
    }


    fclose(fp);
    return 0;
}
