/**
 * This program demonstrates invocation of the kill
 * system call (37) using the syscall function.
 */
#include <linux/types.h>
#include <signal.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

  int result = syscall(62, atoi(argv[1]), 9);

  // A result of -1 means that something went wrong. 
  if (result == -1) {
    // Don't use this error message in "real" programs. O_o
    char *errorMessage = "Herp derp mkderp\n";
    syscall(4, 2, errorMessage, strlen(errorMessage));
  }
}
