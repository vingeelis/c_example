// char* const p
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    char a = 'A', b = 'B';
    char *const ptr = &a;
    printf("Value pointed to by ptr: %c\n", *ptr);
    printf("Address ptr is pointing to: %p\n\n", ptr);

    // ptr = &b; // illegal statement (assignment of read-only variable ptr)

    // changing the value at the address ptr is pointing to
    *ptr = b;
    printf("Value pointed to by ptr: %c\n", *ptr);
    printf("Address ptr is pointing to: %p\n\n", ptr);
    return 0;
}
