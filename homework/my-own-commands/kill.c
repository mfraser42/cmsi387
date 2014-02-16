/**
 * Utilizes 64-bit system calls.
 * This program demonstrates invocation of the kill
 * system call (37) using the syscall function.
 * This force kills the process (signal 9), use
 * with caution.
 * Input required is a process ID number. 
 */
#include <linux/types.h>
#include <signal.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

  int result = syscall(62, atoi(argv[1]), 9); // 37 is sys call for 32-bit.

  // A result of -1 means that something went wrong. 
  if (result == -1) {
    char *errorMessage = "Error killing process. Process may still be active.\n";
    syscall(1, 2, errorMessage, strlen(errorMessage));
  }
  
}
