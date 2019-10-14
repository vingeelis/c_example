#include <stdio.h>

#ifndef _BOOL_
typedef int BOOL;
#define TRUE 1
#define FALSE 0
#endif

int main(int argc, char const *argv[])
{

    BOOL bflag = TRUE;
    printf("%d", bflag);
}
