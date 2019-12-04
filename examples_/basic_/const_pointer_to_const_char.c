// const char * const ptr
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char a = 'A', b = 'B';
    const char *const ptr = &a;

    printf("Value pointed to by ptr: %c\n", *ptr);
    printf("Address ptr is pointing to: %p\n\n", ptr);

    // ptr = &b; // illegal statement (assignment of read-only variable ptr)
    // *ptr = b; // illegal statement (assignment of read-only location *ptr)

    return 0;
}
