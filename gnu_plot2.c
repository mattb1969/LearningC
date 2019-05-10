/*!*********************************************************************
 *
 * Proof of concept of the GNU Plot functionality
 *
 * This plots a number of dots in realtime on the screen
 * 
 */

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>



/*!*********************************************************************
 *
 * Setup the plotting functionality
 *
 * */
FILE *prepare_plot() {

//    FILE *lp;
    
    printf("Preparing Plot\n");

    FILE *lp = popen("gnuplot -persistent", "w");        //persistent ensures it stays on screen when the program completes
                // 
    
    return lp;

}

/*!*********************************************************************
 *
 * Add a value to the plot
 *
 * */
void add_data_to_plot(FILE *p, int x, int y, int element) {

    printf("Adding Data:%d\n", element);

    fprintf(p, "%d %d\n", x, y);                    // Adding data to graph

    return;
}

/*!*********************************************************************
 *
 * Execute the plotting functionality
 *
 * */
void execute_plot(FILE *p) {

    printf("Excuting Plot\n");
    
    fprintf(p, "e\n");

    return;
}


/*!*********************************************************************
 *
 * Close the plotting functionality
 *
 * */
void close_plot(FILE *p) {

    printf("Closing Plot\n");
    
    pclose(p);

    return;
}

/*!********************************************************************/
int main (void){

    int arr_size = 20;
    int x_axis[arr_size];
    int y_axis[arr_size];
    int j;

    
    printf("Doing Graph 1\n");

    FILE *gnu_plot = prepare_plot();

    fprintf(gnu_plot, "set title \"Voltage Levels\"\n");
    fprintf(gnu_plot, "set style line 1 linecolor rgb '#0060ad' linetype 1 linewidth 2\n");

    printf("setting plot -");
    fprintf(gnu_plot, "plot '-' with lines\n");                     // prepare to load values

    for (j=0; j<arr_size; j++)
    {
        x_axis[j] = j;
        y_axis[j] = j + 5;
        
        add_data_to_plot(gnu_plot, x_axis[j], y_axis[j], j);
    }

    execute_plot(gnu_plot);

    close_plot(gnu_plot);

    printf("Doing Graph 2\n");

    gnu_plot = prepare_plot();
    
    fprintf(gnu_plot, "plot '-'\n");                     // prepare to load values

    for (j=0; j<arr_size; j++)
    {
        x_axis[j] = j;
        y_axis[j] = j +1;
        
        add_data_to_plot(gnu_plot, x_axis[j], y_axis[j], j);
    }
    
    execute_plot(gnu_plot);

    // Close the plot

    close_plot(gnu_plot);

    getchar();
    return 0;
}
