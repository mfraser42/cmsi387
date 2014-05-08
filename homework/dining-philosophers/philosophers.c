/** philosophers.c - Written by Michael Fraser.
*   Some code from github user Dondi.
*   Runs the simulation for dining philosophers.
*   Takes an input for the number of desired philosophers, 
*   but if none present it will default to 5.
*/

#include <pthread.h>
#include <stdio.h>

int main(int argc, char** argv) {
    printf("Dining Philosophers Simulation Initialized.\n");
    int number_philosophers;
    
    if (argc < 2) {
        number_philosophers = 5;
    } else {
        number_philosophers = argv[1];
    }
}


