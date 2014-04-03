#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
* This method tokenizes the input from the user, and stores the 'string'
* commands in an array. Command goes in as a string and is separated 
* into different arguments.
*/
int tokenize_input_commands (char* command, char* arguments[]) {
    int index = 0;
    int waitPresent = 0;
    char* deliminate = " \n"; // split based on new line and spaces
    char* diffArguments = strtok(command, deliminate); // separate the arguments array into the different arguments
    
    while (diffArguments != NULL) { // While there is more in the command
        arguments[index] = diffArguments; // place the taken argument into array
        diffArguments = strtok(NULL, deliminator); // take the rest of the command
        index++; // keep track of how many arguments there are
    }
    
    arguments[index] = NULL; // terminate the array
    return 0;
    
}


/**
* The main method handles the majority of the shell operations. 
* Based around Dondi's fork-exec.c.
*/

int main() {
    /* String to hold the command to run. */
    char command[256];
    printf("Enter the command to run: ");
    scanf("%s", command);

    /* Variable that will store the fork result. */
    pid_t pid;

    /* Perform the actual fork. */
    pid = fork();
    if (pid < 0) {
        /* Error condition. */
        fprintf(stderr, "Fork failed\n");
        return -1;
    } else if (pid == 0) {
        /* Child process. */
        printf("Running...\n");
        execlp(command, command, NULL);
    } else {
        /* Parent process. */
        int result;
        wait(&result);
        printf("All done; result = %d\n", result);
    }

    return 0;
}
