/*!*********************************************************************
 *
 * Proof of concept of using time related functions
 *
 * 
 *
 *  
 * 
 */

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>

/*!*********************************************************************
 *
 * Display the amount of time in clocks & time since the program started
 *
 * */

void program_time(void){
    clock_t running_time;
    
    running_time = clock();
    printf("Clocks since start:%ld\n", running_time);
    printf("Clocks per second:%ld\n", CLOCKS_PER_SEC);
    printf("Program Running Time:%f\n", ((float)running_time / CLOCKS_PER_SEC));
    return;
}
/*!*********************************************************************
 *
 * Display the current time in the format mm/dd hh:mm:ss
 *
 * */

void current_time(void){
    time_t current_time;
    char human_time[30] = "";
    char fmt_time[20] = "%d/%m %H:%M:%S";

    current_time = 0;
    time(&current_time);                         // will return the current time, but also assigns it to current_time
    printf("Current time:%ld\n", current_time);

    // localtime converts the time_t to a structure tm for the given time.
    strftime(human_time, sizeof(human_time), fmt_time, localtime(&current_time));
    printf("Converted:%s\n", human_time);
    return;
}


/*!*********************************************************************
 *
 * Perform a timeout function by running for a period and then exiting
 *
 * This one uses the function clock as time only returns to the nearest second
 *
 * */
void timeout(void) {
    time_t currenttime, endtime, starttime;
    int wait_period = 3;                        // How to wait for in seconds

    printf("\nWaiting %d seconds\n", wait_period);

    // load the current time into the counter
    currenttime = clock();
    starttime = currenttime;
    endtime = currenttime + (wait_period * CLOCKS_PER_SEC);
    
    do {
        currenttime = clock();
        //printf("%ld\n", currenttime);         // debug to check it ran for the right time
    } while (currenttime < endtime);

    printf("Duration:%f", (float)(currenttime - starttime)/CLOCKS_PER_SEC);
    return;
}

int main(void){

    current_time();

    timeout();
    printf("\n");
    current_time();    
    program_time();
    return 0;
}

