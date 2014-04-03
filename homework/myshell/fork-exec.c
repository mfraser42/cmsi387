#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_TKNS 15
#define MAX_COMMAND_LENGTH 100
#define MAX_DIRECTORY_LENGTH 512

/**
* This method tokenizes the input from the user, and stores the 'string'
* commands in an array. Command goes in as a string and is separated 
* into different arguments.
*/
int tokenize_input_commands (char* command, char* arguments[]) {
    int index = 0;
    char* deliminate = " \n"; // split based on new line and spaces
    char* diffArguments = strtok(command, deliminate); // separate the arguments array into the different arguments
    
    while (diffArguments != NULL) { // While there is more in the command
        arguments[index] = diffArguments; // place the taken argument into array
        diffArguments = strtok(NULL, deliminate); // take the rest of the command
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
    char command[MAX_COMMAND_LENGTH];
    char* arguments[MAX_TKNS];
    char cwd[MAX_DIRECTORY_LENGTH];
    
    char* prompt = "> ";
    char* message = "Basic Shell Initialized. Boop doop de boop: robot.\n";
    
    // Prints message to stdout
    fputs (message, stdout);
    
    while (!feof(stdin)) {  // checks for the end of file input, using stdin as the file input

        int background = 0;
        getcwd(cwd, sizeof(cwd)); // gets the current directory
        fputs(cwd, stdout); // prints current directory to let the user know where they are
        
        fputs(prompt, stdout); // puts the little prompt symbol
        fgets(command, sizeof(command), stdin);
        
        /* Remove the remaining trailing spaces that would otherwise cause issues. */
        command[strlen(command) - 1] = '\0';
		while (command[strlen(command) - 1] == ' ') {
			command[strlen(command) - 1] = '\0';
		}

		/* Length needs to be greater than 0, otherwise theres nothing to run.*/
		if (strlen(command) > 0) {
			/* Look for '&' and remove if present  */
			if (command[strlen(command) - 1] == '&') {
				command[strlen(command) - 1] = '\0';
				background = 1;

				/* Get rid of annoying extra spaces, in the event of "command arg        &" */
				while (command[strlen(command) - 1] == ' ') {
					command[strlen(command) - 1] = '\0';
				}
			}

			/* Convert the command into different arguments */
			tokenize_input_commands(command, arguments);

			/* Checks the command for these special cases: "cd" "exit" "secret-system-call" */
			if (strcmp("cd", arguments[0]) == 0) {
				chdir(arguments[1]);
			} else if (strcmp("exit", arguments[0]) == 0) {
				return 1;
			} else if (strcmp("secret-system-call", arguments[0]) == 0) {
				long int result = syscall(350);
			} else {

				/* Variable that will store the fork result. */
				pid_t pid;

				/* Perform the actual fork. */
				pid = fork();

				if (pid < 0) {

					/* Error condition. */
					fprintf(stderr, "Fork failed\n");
					return -1;

				} else if (pid == 0) {

					/* Child process. Take argument from array and store remaining arguments back into arguments*/
					execvp(arguments[0], arguments);

				} else {

					/* Parent process. */
					int result;
					if (!background) {
						wait(&result);	
					}
				}
			}
		}
	}
    return 0;
}
