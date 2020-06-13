


#include <pthread.h>
#include <signal.h>
#include <stdio.h>
#include <stdbool.h>
#include <syslog.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


void sig_handler(int sig);          // MB:function definition for the interrupt handler
                                    // MB: Create variable that is GLOBAL and set it to the initial condition

//MB: note that these are volatile, this tells the compiler that things outside of the code around it
//     may change it without knowledge locally, e.g. the interrupt handler changing the value.
volatile bool systemloop=true;

// MB: this is the interrupt handler for the program
// MB: the various items are being captured and handled correctly.
// MB: see the use of systemloop here that means this running loop ends.
void sig_handler(int sig){
	printf("Got Signal %d\n",sig);
	switch (sig){
		case SIGHUP:
			// Sig HUP, Do a reload
			printf("Sig: Got SIGHUP\n");
		break;
		case SIGINT: // 2
			// Interupt (Ctrl c From command line) - Graceful shutdown
			printf("Sig: Got SIGINT - Shutting down\n");
			systemloop=false;
		break;
		case 15:
			// TERM
			printf("Sig: Got SIGTERM\n");
		break;
		case 16:
			// USR1
			printf("Sig: Got SIGUSR1\n");
		break;
		case 17:
			// USR2
			printf("Sig: Got SIGUSR2\n");
		break;
	}
}




int main (int argc, char **argv){

    printf("starting signal handling program\n");

    // MB: openlog and syslog create and manage log files for program logging
    // MB: see syslog.h
	//openlog("HabTrack", LOG_CONS, LOG_LOCAL3);
	//syslog(LOG_NOTICE,"HAB Tracker mk1 Starting with pid %d",getpid());

    // MB: The following bit registers the various signal definitiions with the handler below.
    // MB: see signal.h for the definition of what they mean
    // MB: one of the SIGXXX below is for CTRL-C for example (SIGQUIT or SIGKILL perhaps)
	signal(SIGHUP,sig_handler);
	signal(SIGTERM,sig_handler);
	signal(SIGUSR1,sig_handler);
	signal(SIGUSR2,sig_handler);

	signal(SIGQUIT,sig_handler);
	signal(SIGINT,sig_handler);
	signal(SIGKILL,sig_handler);

    printf("Starting main loop\n");
    // MB: the loop below is the main loop of the program
	while (systemloop){
        printf(".\n");
		sleep(2);
	}

    printf("Main loop completed, exiting\n");
	return(0);
}

