/*Program that takes either hexademical or binary number and converts it to demical */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
	if (argc != 2){
		printf("Usage: %s <integar> \n", argv[0]);
		return 1;
	}

	/*
	 * if first 2 values are 0x = hexademical
	 * if first 2 values are 0b = binary */ 
	
	char* user_input = argv[1];
	int value = 0; // result

	//preform binary to demical 
	if (user_input[1] == 'b') {
		for (int c = 2; c < strlen(user_input); c++) {
			int bitVal = 0;
			if (user_input[c] == '1') {
				bitVal = 1;
			} else {
				bitVal = 0;
			}
			value = (value << 1) | bitVal;
		}
		printf("Binary -> Decimal: %d \n", value);
	}


	//preform hexademical to decimal
	else if (user_input[1] == 'x') {
		for (int c=2; c <strlen(user_input); c++){
			char bitVal = 0;
			if (user_input[c] >= '0' && user_input[c] <= '9') {
				char bitVal = user_input[c]; 
			}
			else if (user_input[c] >= 'A' && user_input[c] <= 'F') {
				bitVal = user_input[c] - 'A';
			}
			value = (value << 4) | bitVal;
		}
		printf("Hexademical -> Decimal: %d \n", value);
	}
return 0;
}
