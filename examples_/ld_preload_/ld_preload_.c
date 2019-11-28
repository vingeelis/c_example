#include <stdio.h>

/**
run widh ld
    echo "this is test.txt" > test.txt
    gcc ld_preload_.c -o ld_preload_
    gcc -Wall -fPIC -shared myfopen.c -o myfopen.so
    LD_PRELOAD=./myfopen.so ./ld_preload_

run with out ld
    ./ld_preload_
 */
int main(void)
{
    printf("Calling the fopen() function...\n");

    FILE *fd = fopen("test.txt", "r");
    if (!fd)
    {
        printf("fopen() returned NULL\n");
        return 1;
    }

    printf("fopen() succeeded\n");

    return 0;
}