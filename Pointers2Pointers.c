/*
*
 * Validation of the pointer functionality
 * 
 * In this example, the function uses pointers to pointers to allow for the size
 * to be dynamically adjusted based on the data received.
 * 
 */


/*
 * void increase(int** data)
 * {
 *     *data = realloc(*data, 5 * sizeof int);
 * }
 * Calling code would then look like:
 * 
 * int *data = malloc(4 * sizeof *data);
 * // do stuff with data 
 * increase(&data);
 * // more stuff
 * free(data);
 */

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

/*!*********************************************************************
 *
 * Function takes the number given in input and then puts the value in each
 * of the output elements based on size_adjust
 */ 

int Calculation(int input, int** output, int size_adjust) {
    printf("In Calculation function\n");

    int i;

	for (i=0; i < size_adjust; i++)
    {

//		printf("Resizing output memory allocation to: %d\n", (i+1) * sizeof(int));
//		*output = (int*)realloc(*output, (i+1) * sizeof(int));
		
		printf("Setting value of output[%d] to %d\n", i, input+(i*3));
		//(*output) dereferences it before use, thus allowing the variable to be set and not the pointer!!
        (*output)[i] = input+(i*3);
		
		// Resize to make it bigger by 1 more than used
		printf("Resizing output memory allocation to: %d\n", (i+1) * sizeof(int));
		*output = (int*)realloc(*output, (i+1) * sizeof(int));
		
		printf("Number of elements:%d\n\n", i);
    }
	// Set the final element to \0 to identify the end
	(*output)[i] = '\0';

    return 0;
}

int main (void) {
    printf("Starting main function\n");
	
	int j = 0;
    int *result = malloc (sizeof(int*));
	result[0] = '\0';
	
    printf("List before Calculation\n");
    while (result[j] != '\0')
    {
        printf("%d : %d\n", j, result[j]);
		j++;
    }
	printf(".\n");

    Calculation(26, &result, 5);

    printf("List AFTER Calculation\n");
	j=0;

    while (result[j] != '\0')
    {
        printf("%d : %d\n", j, result[j]);
		j++;
    }

    return 0;
}
