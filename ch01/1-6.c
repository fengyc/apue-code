/**
 * Print the process ID
 */

#include "apue.h"

int log_to_stderr = 1;

int main(void)
{
    printf("hello world from process ID %ld\n", (long)getpid());
    exit(0);
}
