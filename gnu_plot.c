/*!*********************************************************************
 *
 * Proof of concept of the GNU Plot functionality
 *
 * This simply plots a number of dots on the screen
 *
 */

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>



/*!*********************************************************************
 *
 * Plot the given array of size 'n'
 *
 * */
void plot_array(int *x, int *y, int n) {

    int i;
    FILE *p = popen("gnuplot -persistent", "w");        //persistent ensures it stays on screen when the program completes

    fprintf(p, "plot '-'\n");

    for(i = 0; i < n; i++)
    fprintf(p, "%d %d\n", x[i], y[i]);

    //fprintf(p, "e\n");                                // Ends the displaying of the graph

    pclose(p);
}

/*!*********************************************************************
 *
 * Build an array of size array_size, filled with numbers
 *
 * */
void build_array(int *x, int *y, int array_size) {

    int i;
    for (i=0; i < array_size; i++)
    {
        x[i] = i;
        y[i] = i +5;
    }
    return;
}

int main (void){

    int arr_size = 20;
    int x_axis[arr_size];
    int y_axis[arr_size];
    
    printf("Doing a Graph");

    build_array(x_axis, y_axis, arr_size);

    plot_array(x_axis, y_axis, arr_size);
    return 0;
}
