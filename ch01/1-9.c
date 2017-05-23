/**
 * Print user ID and group ID
 */

#include "apue.h"

int log_to_stderr = 1;

int main(void)
{
    printf("uid = %d, gid = %d\n", getuid(), getgid());
    exit(0);
}
