/**
 * 使用 truncat 截断文件，但用 futimens 保留之前的文件修改时间
 */

#include "apue.h"
#include <fcntl.h>

int log_to_stderr = 1;

int main(int argc, char *argv[])
{
    int i, fd;
    struct stat statbuf;
    struct timespec times[2];


    for (i=1;i < argc; i++) {
        if (stat(argv[i], &statbuf) < 0) {
            err_ret("%s: stat error", argv[i]);
            continue;
        }
        if ((fd=open(argv[i], O_RDWR|O_TRUNC)) < 0) {
            err_ret("%s: open error", argv[i]);
            continue;
        }
        times[0] = statbuf.st_atim;
        times[1] = statbuf.st_mtim;
        if (futimens(fd, times) < 0) {
            err_ret("%s: futimes error", argv[i]);
        }
        close(fd);
    }

    exit(0);
}
