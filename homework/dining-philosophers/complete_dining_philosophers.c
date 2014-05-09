
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>

#define THINKING 0
#define HUNGRY 1
#define EATING 2

#define MAX_PHILOSOPHERS 10

int number_phils;
int phil_id[MAX_PHILOSOPHERS];
int phil_status[MAX_PHILOSOPHERS];
pthread_mutex_t chopsticks[MAX_PHILOSOPHERS];
int chopstick_status[MAX_PHILOSOPHERS];

int randomwait(int bound) {
    int wait = rand() % bound;
    sleep(wait);
    return wait;
}

/**
* Used to print representations of the philosopher's different states.
*/
void visualRepresentation() {

    int i;
    
    for (i = 0; i < number_phils; i++) {
        if (phil_status[i] == THINKING) {
            printf("    42    ");
        } else if (phil_status[i] == HUNGRY) {
            printf("   want   ");
        } else if (phil_status[i] == EATING) {
            printf("  NOMNOM  ");
        }
    }
    printf("\n");

}

/**
* Allows for the picking up of a chopstick.
*/
void pickupChopstick(int chopstick) {
    pthread_mutex_lock(&chopsticks[chopstick]);
    chopstick_status[chopstick] = 1;
}

/**
* Allows for the releasing of a chopstick.
*/
void dropChopstick(int chopstick) {
    pthread_mutex_unlock(&chopsticks[chopstick]);
    chopstick_status[chopstick] = 0;
}

void ponderUniverse(int id) {
    randomwait(10);
    phil_status[id] = HUNGRY;
}

void eat(int id) {
    pickupChopstick(id);
    pickupChopstick((id+1) % number_phils);
    phil_status[id] = EATING;
    randomwait(10);
}

void stopEating(int id) {
    dropChopstick(id);
    dropChopstick((id+1) % number_phils);
    phil_status[id] = THINKING;
}

void* transitioning(void* philosopher) {
    int id = *(int*) philosopher;

    while (1) {
        visualRepresentation();        
        if (phil_status[id] == THINKING) {
            ponderUniverse(id);
        } else if (phil_status[id] == HUNGRY) {
            eat(id);
        } else if (phil_status[id] == EATING) {
            stopEating(id);
        }
    
    }

}


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
    
    int i;
    for (i = 0; i < number_phils; i++) {
        phil_id[i] = i;
        pthread_mutex_init(&chopsticks[i], NULL);
        pthread_create(&phils[i], NULL, transitioning, &phil_id[i]);
    }
    for (i=0;i<number_phils;i++) {
        pthread_join(phils[i], NULL);
    }
    
    return 0;
}
