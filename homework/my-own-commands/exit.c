/**
 * This program demonstrates invocation of the exit
 * system call (1) using the syscall function.
 */
#include <linux/types.h>
#include <linux/unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

  printf("process is running... \n");
  printf("Terminating now. \n");
  int result = syscall(60, 0);
  printf("Hellooooooo\n");

}
