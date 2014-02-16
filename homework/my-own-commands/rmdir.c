/* Written by Michael Fraser */
/**
 * This program demonstrates invocation of the rmdir
 * system call (84) (64-bit) using the syscall function.
 * Can handle multiple directories and removes all of them.
 * Has no way of handling non-empty directories. 
 */
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

	int i = argc - 1;
    while ( i > 0 ) {
        if (syscall(84, argv[i]) == -1) { // 40 is 32-bit sys call
            printf("ERROR: %s\n", strerror(errno)); 
        }
        i--;
    }
	
}
