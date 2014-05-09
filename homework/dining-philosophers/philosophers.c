/** philosophers.c - Written by Michael Fraser.
*   Some code from github user Dondi.
*   Runs the simulation for dining philosophers.
*   Takes an input for the number of desired philosophers, 
*   but if none present it will default to 5.
*   5-8-2014
*/

#include "tableStuff.h"

int main(int argc, char** argv) {
    
    //remember to atoi, check for # phils > 2
    if (argc < 2) {
        number_phils = 5;
    } else {
        number_phils = argv[1];
    }
    printf("Dining Philosophers Simulation Initialized.\n");    
    
    // define threads for philosophers
    pthread_t phils[number_phils];    
    
    struct table_info t_info = {0};
    
    int i;
    for (i = 0; i < number_phils; i++) {
        t_info.phil_id[i] = i;
        pthread_mutex_init(&t_info.chopsticks[i], NULL);
        pthread_create(&phils[i], NULL, transitioning, &t_info.phil_id[i]);
    }
    
    
    return 0;
}


