/**
 * fcntl 设置 fd 标志前（无论是清理还是加上标志），要先获取原来的标志
 */

#include "apue.h"
#include <fcntl.h>

int log_to_stderr = 1;

void set_fl(int fd, int flags)
{
    int val;

    if ((val = fcntl(fd, F_GETFL, 0)) < 0) {
        err_sys("fcntl F_GETFL error");
    }

    val |= flags;

    if (fcntl(fd, F_SETFL, val) < 0) {
        err_sys("fctnl F_SETFL error");
    }
}

void clr_fl(int fd, int flags)
{
    int val;

    if ((val = fcntl(fd, F_GETFL, 0)) < 0) {
        err_sys("fcntl F_GETFL error");
    }

    val &= ~flags;

    if (fcntl(fd, F_SETFL, val) < 0) {
        err_sys("fctnl F_SETFL error");
    }
}

int main(void)
{
    exit(0);
}

