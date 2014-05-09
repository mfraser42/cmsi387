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
void printPhilosophers () {

}
