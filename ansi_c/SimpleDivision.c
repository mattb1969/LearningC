/*!*********************************************************************
 *
 * Validation of the maths functionality
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

int main(int argc, char **argv)
{
    float       reading=0.00;
    uint8_t     rxBuf[3];
    float         supply_voltage = 3.3;     // SUpply voltage for the A-D
    uint16_t        fsd_range=4096;           // Maximum value from A-D (12 bits)
    int     i;

    
    printf("Performing Division\n");

    rxBuf[0] = 0;
    rxBuf[1] = 0x07;
    rxBuf[2] = 0x9a;

    printf("Input Values:");
    for (i=0; i < 3; i++)
    {
        printf("%02x", rxBuf[i]);
    }
    printf("\n");
    
    reading = (rxBuf[1] << 8) + rxBuf[2];

    printf("Merged Reading (should be 1946) :%04f\n", reading);               // This is correct, the valu eshould be 1946
    
    // Formula for calculation      Digital Output Code = 4096 * Vin
    //                                                    ----------
    //                                                       Vdd
    reading = reading * (supply_voltage / fsd_range);

    printf("Output from calculation:%f", reading);
	return 0;
}

