/*takes an integar as command line and outputs it as binary and hexademical number  */
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv [])
{
        if (argc != 2) {
                printf("usage: %s <integer>\n", argv[0]);
                return 1;
        }

	//Binary conversion
        printf("Converting to a binary number: 0b");
        
	/*Variable declaration */
        int value = atoi(argv[1]); //converting user input to integar
        int length = sizeof(value) * 8; //32 bits
        int leading = 0;
        unsigned int mask = 0x80000000;	

        //most significant to least significant value 
        for (int i= length -1; i >= 0; i--) {
                int bitVal = (value & mask) ? 1 : 0; //extracting the bit, making sure 1 or 0
        //      printf("debugging each %d, at interation %d \n", bitVal, i);

                if (bitVal == 1) {
                        leading = 1;
                }
	       	if (leading) {
                        printf("%d", bitVal); //printing the bit
                }
                if (!leading) {
                        printf("0");
                }
                if (i % 4 == 0) {
                        printf(" ");
                }       
                
		mask >>= 1; //shifting mask
        }
	printf("\n");
	

	//HexaDemical Conversion
	printf("Converting to Hexademical number: 0x ");
	unsigned int hexMask = 0xF0000000;
	const char* hex = "0123456789ABCDEF";
	int hexLeading = 0;
	int hexCount = 0;

	for (int i = 28; i >= 0; i-=4) { //goes from 28,24,20,16,12,8,4,0
		int bitVal = (value & hexMask) >> i;

		if (bitVal != 0 || hexLeading) {
			hexLeading = 1;
			printf("%c", hex[bitVal]);

		}
		if (!hexLeading) {
			printf("0");
		}
		hexMask >>= 4;
	}
	printf("\n");


  return 0;
}
