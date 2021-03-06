/**
 * Standard IO
 */

#include "apue.h"

int log_to_stderr = 1;

int main(void)
{
    int c;
    while ((c = getc(stdin)) != EOF) {
        if (putc(c, stdout) == EOF) {
            err_sys("output error");
        }
    }
    if (ferror(stdin)) {
        err_sys("input error");
    }
    exit(0);
}
