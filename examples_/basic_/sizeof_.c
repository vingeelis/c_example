#include <stdio.h>

int main(int argc, char const *argv[]) {
    printf("Unit : bytes\n");

    printf("The size of char is %zu\n", sizeof(char));
    printf("The size of short is %zu\n", sizeof(short));
    printf("The size of unsigned short is %zu\n", sizeof(unsigned short));
    printf("The size of integer is %zu\n", sizeof(int));
    printf("The size of unsigned integer is %zu\n", sizeof(unsigned int));
    printf("The size of long is %zu\n", sizeof(long));
    printf("The size of unsigned long is %zu\n", sizeof(unsigned long));
    printf("The size of long long is %zu\n", sizeof(long long));
    printf("The size of unsigned long long is %zu\n", sizeof(unsigned long long));
    printf("The size of float is %zu\n", sizeof(float));
    printf("The size of double is %zu\n", sizeof(double));

    printf("The size of pointer char is %zu\n", sizeof(char *));
    printf("The size of pointer short is %zu\n", sizeof(short *));
    printf("The size of pointer unsigned short is %zu\n", sizeof(unsigned short *));
    printf("The size of pointer integer is %zu\n", sizeof(int *));
    printf("The size of pointer unsigned integer is %zu\n", sizeof(unsigned int *));
    printf("The size of pointer long is %zu\n", sizeof(long *));
    printf("The size of pointer unsigned long is %zu\n", sizeof(unsigned long *));
    printf("The size of pointer long long is %zu\n", sizeof(long long *));
    printf("The size of pointer unsigned long long is %zu\n", sizeof(unsigned long long *));
    printf("The size of pointer float is %zu\n", sizeof(float *));
    printf("The size of pointer double is %zu\n", sizeof(double *));

    return 0;
}
