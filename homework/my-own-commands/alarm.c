/* Written by Dondi, improved upon by Michael */
/**
 * This program demonstrates invocation of the alarm
 * system call (37) using the syscall function.
 * The required input should be a value in seconds. 
 * This value is the amount of time until which
 * an infinite loop is terminated by the syscall. 
 */
#include <linux/types.h>
#include <linux/unistd.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

  int result = syscall(37, atoi(argv[1]));  // 27 is 32-bit sys call.
  unsigned long counter = 0;
  while (true) {
    printf("%ld\n", counter);
    counter++;
    sleep(1); 
    // supposedly messing with alarm clock and sleep simultaneously
    // can be risky, but it seems to work fine here.
  }
  // According to tutorialspoint, there are no errors for this syscall.
}
