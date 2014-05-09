/**
 * Synchronization elements for a bounded buffer solution.
 */
#ifndef __BB_SYNC__
#define __BB_SYNC__

#define THINKING 0
#define HUNGRY 1
#define EATING 2

#define MAX_PHILOSOPHERS 10

#include <pthread.h>
#include <stdio.h>

int number_phils;

struct table_info {
    int phil_id[MAX_PHILOSOPHERS];
    int phil_status[MAX_PHILOSOPHERS];
    pthread_mutex_t chopsticks[MAX_PHILOSOPHERS];
    int chopstick_status[MAX_PHILOSOPHERS];
} t_info;

int randomwait(int bound);

void ponder_universe(int philosopher_id);
void eat(int philosopher_id);
void* transitioning(void* philosopher);

#endif
