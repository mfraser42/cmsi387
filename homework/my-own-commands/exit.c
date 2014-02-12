/**
 * This program demonstrates invocation of the exit
 * system call (1) using the syscall function.
 */
#include <linux/types.h>
#include <linux/unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  int result = syscall(60, 0);



  // A result of -1 means that something went wrong.
  if (result == -1) {
    // Don't use this error message in "real" programs. O_o
    char *errorMessage = "Herp derp mkderp\n";
    syscall(4, 2, errorMessage, strlen(errorMessage));
  }
}
