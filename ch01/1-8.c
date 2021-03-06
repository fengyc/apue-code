/**
 * strerror and perror
 */

#include "apue.h"
#include <errno.h>

int log_to_stderr = 1;

int main(int argc, char *argv[])
{
    fprintf(stderr, "EACESS: %s\n", strerror(EACCES));
    errno = ENOENT;
    perror(argv[0]);
    exit(0);
}
