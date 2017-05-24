/**
 * 创建空洞文件，vi 打开 file.hole 可看到一些空洞标记^@
 */

#include "apue.h"
#include <fcntl.h>

int log_to_stderr = 1;

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int main(void)
{
    int fd;

    if ((fd = creat("file.hole", FILE_MODE)) < 0) {
        err_sys("creat error");
    }

    if (write(fd, buf1, 10) != 10) {
        err_sys("buf1 write error");
    }
    /* offset now = 10 */

    if (lseek(fd, 16384, SEEK_SET) == -1) {
        err_sys("lseek error");
    }
    /* offset now = 16384 */

    if (write(fd, buf2, 10) != 10) {
        err_sys("buf2 write error");
    }
    /* offset now = 16394 */

    exit(0);
}
