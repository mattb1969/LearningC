/*!*********************************************************************
 *
 * Validation of the structures functionality
 *
 */


#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>           // to enable time functions

struct readings {
    int     element;
    float   voltage;
    time_t  readtime;
};

/*!*********************************************************************
 *
 * Function creates a structure that contains a single set of values
 */
 void single_struct(void) {
    struct readings values;

    values.element = 2;
    values.voltage = 2.1233457;
    values.readtime = clock();

    printf("Element:%d\n", values.element);
    printf("Volts:%f\n", values.voltage);
    printf("time:%ld\n", values.readtime);
    
	return ;   
}


/*!*********************************************************************
 *
 * Function creates a structure that contains a an array of values
 */
 void array_struct(void) {
    int max_size = 20;
    struct readings values[max_size];
    int i;

    i = 0;
    do {
        
        values[i].element = 2 + i;
        if (i==0)
        {
            values[i].voltage = 0.00000;
        }
        else
        {
            values[i].voltage = i / 7;
        }
        values[i].readtime = clock();
        i++;
    } while (i < max_size);

    i = 0;
    do {
        
        printf("Element:%d\n", values[i].element);
        printf("Volts:%f\n", values[i].voltage);
        printf("time:%ld\n", values[i].readtime);
        i++;
    } while (i < max_size);
    
	return ;   
}

int main(int argc, char **argv)
{
	// create union

    single_struct();

    array_struct();
    
	return 0;
}

