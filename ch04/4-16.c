/**
 * 使用 unlink 处理文件链接
 */

#include "apue.h"
#include <fcntl.h>

int log_to_stderr = 1;

int main(void)
{
    pid_t pid;
    int fd;
    const char *pathTmp = "/proc/%d/fd/%d";
    char path[FILENAME_MAX];
    struct stat stat1;

    if ((fd = open("tempfile", O_RDWR|O_CREAT)) < 0) {
        err_sys("open error");
    }
    if (unlink("tempfile") < 0) {
        err_sys("unlink error");
    }
    printf("file unlinked\n");

    /* unlinked but could be found in /proc/<pid>/fd/<fd> */
    pid = getpid();
    sprintf(path, pathTmp, pid, fd);
    if (lstat(path, &stat1) < 0) {
        err_ret("lstat error for %s\n", path);
    } else {
        printf("lstat OK for %s\n", path);
    }

    sleep(15);
    printf("done\n");
    exit(0);
}
