/*
*
 * Validation of the pointer functionality
 * 
 * In this example, the function uses pointers to pointers to allow for the size
 * to be dynamically adjusted based on the data received.
 * 
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

int Calculation(int input, int size_adjust, int** output, int *element) 
{
    printf("In Calculation function\n");

    int i;
	int *temp = malloc (sizeof(int));										// <<- Key line

	for (i=0; i < size_adjust; i++)
    {	
		// Resize to make it bigger by 1 more than used
		printf("Resizing output memory allocation to: %d\n", (i+1) * sizeof(int));
		*output = (int*)realloc(temp, (i+1) * sizeof(int));

		printf("Setting value of output[%d] to %d\n", i, input+(i*3));
		temp[i] = input+(i*3);
		
    }
	// Set the final element to \0 to identify the end
	// The (*output) deferences the pointer so that the element can be accessed.
	//(*output)[i] = '\0';
	printf("Number of elements:%d\n\n", i);
	*element = i;
	
    return 0;
}

int ArrayFill(char input, int size_adjust, char** output, int *element) 
{
    printf("In Merge function\n");

    int i = 0;
	char *temp = malloc (sizeof(char));										// <<- Key line

	while (i < size_adjust)
    {	
		// Resize to make it bigger by 1 more than used
		printf("Resizing output memory allocation to: %d\n", (i+1) * sizeof(char));
		*output = (char*)realloc(temp, (i+1) * sizeof(char));

		printf("Setting value of output[%d] to %c\n", i, input);
		temp[i] = input;
		i++;
		
    }
	// Set the final element to \0 to identify the end
	temp[i] = '\0';
	printf("Number of elements:%d\n\n", i);
	*element = i;
	
    return 0;
}

int main (void) {
    printf("Starting main function\n");
	
	int j = 0;
    int *result = malloc (sizeof(int*));
	int *last_element = malloc (sizeof(int*));
	result[0] = '\0';
	
    printf("List before Calculation\n");
    while (result[j] != '\0')
    {
        printf("%d : %d\n", j, result[j]);
		j++;
    }
	printf(".\n");

    Calculation(26, 5, &result, last_element);

    printf("List AFTER Calculation\n");
	j=0;

    while (result[j] != '\0')
    {
        printf("%d : %d\n", j, result[j]);
		j++;
    }
	printf("Last Element of Output:%d\n", *last_element);
	
	//-----------------------------------------------------------------//
	
	char *arr_fill = malloc (sizeof(char*));
	int *last_arr_element = malloc (sizeof(char*));
	
			
	ArrayFill('w', 7, &arr_fill, last_arr_element);
	
    printf("List AFTER Array Fill\n");
	j=0;

    while (arr_fill[j] != '\0')
    {
        printf("%d : %c\n", j, arr_fill[j]);
		j++;
    }
	printf("Full Array:%s\n", arr_fill);
	printf("Last Element of Output:%d\n", *last_arr_element);	
	
    return 0;
}
