#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<assert.h>
#include<unistd.h>

void main() {
    int fdr = open("FIFO", O_RDONLY);
    assert(fdr != -1);
    printf("open success\n");
    sleep(1);
    char buff[2] = {0};
    int i = 0;
    for(;i<11;++i) {
        read(fdr, buff, 1);
        printf("read::%s\n", buff);
    }
    close(fdr);
}