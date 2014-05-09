/** Written by Michael Fraser
*   Functions for the philosophers in the dining philosophers simulation.
*   5-8-2014
*/

#include "tableStuff.h"

void ponderUniverse(int id) {
    randomWait(10);
    t_info.phil_status[id] = HUNGRY;
}

void eat(int id) {
    pickupChopstick(id);
    pickupChopstick((id+1) % number_phils);
    t_info.philosopher_state[id] = EATING;
    randomwait(10);
}

void stopEating(int id) {
    dropChopstick(id);
    dropChopstick((id+1) % phil_number);
    t_info.phil_status[id] = THINKING;
}


