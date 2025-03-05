/*takes an integar as command line and outputs it as binary and hexademical number  */
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv [])
{
        if (argc != 2) {
                printf("There is not 2 arguments");
                return 1;
        }
        printf("Converting to a binary number: ");
        
        int value = atoi(argv[1]); //converting user input to integar
        //printf("debugging: %d \n", value);    
        int length = sizeof(value) * 8; //32 bits
        int leading = 0;
        unsigned int mask = 0x80000000; 

        //most significant to least significant value 
        for (int i= length -1; i >= 0; i--) {
                int bitVal = (value & mask) ? 1 : 0; //extracting the bit, making sure 1 or 0
        //      printf("debugging each %d, at interation %d \n", bitVal, i);

                if (bitVal == 1) {
                        leading = 1;

                } if (leading) {
                        printf("%d", bitVal); //printing the bit
                }
                if (!leading) {
                        printf("0");
                //      if (i % 4 == 0 && i != 0) {
                //              printf(" ");
                }
                if (i % 4 == 0) {
                        printf(" ");
                }       
                
                mask >>= 1; //shifting mask
        }
printf("\n");

  return 0;
}
