/**
 * 确定文件描述符个数限制
 */

#include "apue.h"
#include <errno.h>
#include <limits.h>

int log_to_stderr = 1;

#ifdef OPEN_MAX
static long openmax = OPEN_MAX;
#else
static long openmax = 0;
#endif

/*
 * If OPEN_MAX is indeterminate, this might be inadequate.
 */
#define OPEN_MAX_GUESS 256

long open_max(void)
{
    if (openmax == 0) {
        errno = 0;
        if ((openmax = sysconf(_SC_OPEN_MAX)) < 0) {
            if (errno == 0) {
                openmax = OPEN_MAX_GUESS;   /* it's indeterminate */
            } else {
                err_sys("sysconf error for _SC_OPEN_MAX");
            }
        }
    }
    return (openmax);
}

int main(void)
{
    long openmax = open_max();
    printf("openmax is %ld\n", openmax);

    exit(0);
}
