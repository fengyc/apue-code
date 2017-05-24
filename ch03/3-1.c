/**
 * 测试标准输入是否能设置偏移量
 */

#include "apue.h"

int log_to_stderr = 1;

int main(void)
{
    if (lseek(STDIN_FILENO, 0, SEEK_CUR) == -1) {
        printf("cannot seek\n");
    } else {
        printf("seek OK\n");
    }
    exit(0);
}
