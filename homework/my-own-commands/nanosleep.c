#include <unistd.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[]) {

    struct timespec time_sec;
    time_sec.tv_sec = atoi(argv[1]);
    
    if ( argv[2] ) {
        time_sec.tv_nsec = atoi(argv[2]);
	} else {
	    time_sec.tv_nsec = 0;
	}
	
	if(syscall(35, &time_sec, &time_sec) < 0) {
		char *errorMessage = "Error! Inputs 1 and 2 are integers in seconds and nanoseconds, respectively. Max nanoseconds of 999999999. \n";
		syscall(1, 2, errorMessage, strlen(errorMessage));
	}
}
