/** Written by Michael Fraser.
*   Handles the chopstick functionality of the dining philosophers simulation.
*   5-8-2014
*/

#include "tableStuff.h"

/**
* Allows for the picking up of a chopstick.
*/
void pickupChopstick(int chopstick) {
    pthread_mutex_lock(&t_info.chopsticks[chopstick]);
    t_info.chopstick_status[chopstick] = 1;
}

/**
* Allows for the releasing of a chopstick.
*/
void dropChopstick(int chopstick) {
    pthread_mutex_unlock(&t_info.chopsticks[chopstick]);
    t_info.chopstick_status[chopstick]=0;
}
