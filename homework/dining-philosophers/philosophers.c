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

#define THINKING 0
#define HUNGRY 1
#define EATING 2

#define MAX_PHILOSOPHERS 10

struct table_info {
    int phil_id[MAX_PHILOSOPHERS];
    int phil_status[MAX_PHILOSOPHERS];
    pthread_mutex_t chopsticks[MAX_PHILOSOPHERS];
    int chopstick_status[MAX_PHILOSOPHERS];
} t_info;

int main(int argc, char** argv) {
    int number_phils;
    
    //remember to atoi, check for # phils > 2
    if (argc < 2) {
        number_phils = 5;
    } else {
        number_phils = argv[1];
    }
    printf("Dining Philosophers Simulation Initialized.\n");    
    
    // define threads for philosophers
    pthread_t phils[number_phils];

    // create mutex for each chophilstick
    
    
    struct table_info t_info = {0};
    
    int i;
    for (i = 0; i < number_phils; i++) {
        t_info.phil_id[i] = i;
        pthread_mutex_init(&t_info.chopsticks[i], NULL);
     //   pthread_create(&philosophers[i], NULL, transition, &philosopher_number[i]);
    }
    
    
    return 0;
}


