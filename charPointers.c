/*!*********************************************************************
 *
 * Validation of the pointer functionality
 * 
 * In this example, the function uses char pointers and an int for the size to 
 * perform the text merge on.
 * 
 * This has the drawback that the size is fixed and can't be dynamically allocated
 *
 */

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

/*!*********************************************************************
 *
 * Function filles the output char array with the input char to completely fill it
 * putting the answer in the output array
 */ 

int arrayFill(char input_char, char *output_char, int times) {
    printf("In array fill function\n");

    int i;

    for (i=0; i < times; i++)
    {
        output_char[i] = input_char;
    }

	// Add some extra bits to check string length
    strcat(output_char,"e");
    strcat(output_char,"d");
    return 0;
}


int main (void) {
    printf("Starting main function\n");

    int list_size = 5;
    int returncode;
	char answer_list[] =  "aaaaa";

    printf("List before Calculation\n");
	printf("%s\n", answer_list);
	
    /* There is no need to pass in pointers for the number and answer list
     * because as they are both arrays, they are already pointers
     * */
    returncode = arrayFill('b', answer_list, list_size);

    printf("Return Code:%d", returncode);

    printf("\nList AFTER Calculation\n");
	printf("%s\n", answer_list);

    return 0;
}
