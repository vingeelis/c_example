#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <assert.h>

int main() {
    int fdw = open("FIFO", O_WRONLY);
    assert(fdw != -1);
    printf("open success\n");
    char *str = "hello world";
    int i = 0;
    for (; i< strlen(str); ++i) {
        write(fdw, &str[i], 1);
    }
    printf("write success\n");
    close(fdw);
}