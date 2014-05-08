/** philosophers.c - Written by Michael Fraser.
*   Some code from github user Dondi.
*   Runs the simulation for dining philosophers.
*   Takes an input for the number of desired philosophers, 
*   but if none present it will default to 5.
*   5-8-2014
*/

#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>

int main(int argc, char** argv) {
    int number_philosophers;
    
    //remember to atoi, check for # phils > 2
    if (argc < 2) {
        number_philosophers = 5;
    } else {
        number_philosophers = argv[1];
    }
    printf("Dining Philosophers Simulation Initialized.\n");    
    
    // define threads for philosophers
    pthread_t philosophers[number_philosophers];
    // create array used to identify which philosophers is being interacted with
    int philosopher_id[number_philosophers];
    // array to hold the state of the philosophers
    int philosopher_state[number_philosophers];
    //array to determine the state of a chopstick
    int chopstick_state[number_philsophers];
    // create mutex for each chopstick
    pthread_mutex_t chopsticks[number_philosophers];
    
    
    
    return 0;
}


