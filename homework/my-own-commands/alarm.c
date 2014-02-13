/**
 * This program demonstrates invocation of the exit
 * system call (1) using the syscall function.
 */
#include <linux/types.h>
#include <linux/unistd.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

  int result = syscall(27, atoi(argv[1]));
  unsigned long counter = 0;
  while (true) {
    printf("%ld\n", counter);
    counter++;
  }

}
