/*!*********************************************************************
 *
 * Validation of the pointer functionality
 * 
 * In this example, the function uses pointers and an int for the size to 
 * perform the calculations on.
 * 
 * This has the drawback that the size is fixed and can't be dynamically allocated
 *
 */

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

/*!*********************************************************************
 *
 * Function adds the number in the input array and the array size together
 * putting the answer in the output array
 */ 

int Calculation(int *input_arr, int *output_arr, int arr_size) {
    printf("In Calculation function\n");

    int i;

    for (i=0; i < arr_size; i++)
    {
        output_arr[i] = input_arr[i] + arr_size;
    }

    return 0;
}


int main (void) {
    printf("Starting main function\n");

    int list_size = 5;
    int number_list[list_size];
    int answer_list[list_size];
    int j;
    int returncode;

    number_list[0] = 2;
    number_list[1] = 3;
    number_list[2] = 4;

    printf("List before Calculation\n");
    for (j=0; j < list_size; j++)
    {
        printf("%d : %d\n", j, number_list[j]);
    }

    /* There is no need to pass in pointers for the number and answer list
     * because as they are both arrays, they are already pointers
     * */
    returncode = Calculation(number_list, answer_list, list_size);

    printf("Return Code:%d", returncode);

    printf("\nList AFTER Calculation\n");
    for (j=0; j < list_size; j++)
    {
        printf("%d : %d\n", j, answer_list[j]);
    }

    return 0;
}
