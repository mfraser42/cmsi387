/**
 * Utility implementation.
 */
 
#include "tableStuff.h"
#include <stdlib.h>
#include <unistd.h>

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
        if (t_info.phil_status[i] == THINKING) {
            printf("42");
        } else if (t_info.phil_status[i] == HUNGRY) {
            printf("hungry");
        } else if (t_info.phil_status[i] == EATING) {
            printf("nomming");
        }
    }
    printf("\n");

}
