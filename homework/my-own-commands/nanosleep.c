/* Written by Michael Fraser. */
/** 
 * This program demonstrates invocation of the 
 * nanosleep system call (35) (64-bit) using the
 * syscall function. 
 */

#include <unistd.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

    struct timespec time_sec; // Input to syscall 35 requires structs
    time_sec.tv_sec = atoi(argv[1]); // utilizes two variables in the structs
    
    // Made the second varible optional, with a default of 0.
    if ( argc > 2 ) {
        time_sec.tv_nsec = atoi(argv[2]);
	} else {
	    time_sec.tv_nsec = 0;
	}
	
	if(syscall(35, &time_sec, &time_sec) < 0) {
	    printf("ERROR: %s\n", strerror(errno)); 
	    // nifty little function - returns the error message
	    // associated with the errno.
	}
	
}
