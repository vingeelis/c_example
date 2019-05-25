#define _GNU_SOURCE
#include <sched.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

#define IS_OK(ret_v, msg) \
    {                     \
        if (ret_v == -1)  \
        {                 \
            perror(msg);  \
            exit(-1);     \
        }                 \
    }

int main(int argc, char *argv[])
{
    int fd, ret;

    if (argc < 2)
    {
        printf("%s /proc/PID/ns/FILE\n", argv[0]);
        return -1;
    }

    // 获取 namespace 对应文件的描述符
    fd = open(argv[1], O_RDONLY);
    IS_OK(fd, "open");

    // 执行完setns后，当前进程将加入指定的namespace
    // 这里第二个参数为0，表示由系统自己检测fd对应的是哪种类型的namespace
    ret = setns(fd, 0);
    IS_OK(ret, "open");

    execlp("bash", "bash", (char *)NULL);

    return 0;
}