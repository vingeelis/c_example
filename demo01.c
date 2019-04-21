#include <stdio.h>
#include <stdlib.h>

int StrToInt(char* string)
{
    int number = 0;
    while(*string != 0)
    {
        number = number * 10 + *string - '0';
        ++string;
    }

    return number;
}

void main(void) {
    int num;
    char* str = "hello";
    num = StrToInt(str);
    printf("%d\n", num);
}
