/**
 * Utilizes 64-bit system calls.
 * This program demonstrates invocation of the exit
 * system call (1) using the syscall function.
 */
#include <linux/types.h>
#include <linux/unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

  printf("Process is running... \n");
  printf("Terminating now. \n");
  int result = syscall(60, 0); // 1 is exit sys call for 32-bit
  if (result == -1) {
    char* errorMessage = "There was an error with the exit system call.\n";
    syscall(1, 2, errorMessage, strlen(errorMessage)); 
  }
  printf("Example of code section not reached due to the system call. \n");
  
}
