#include <stdio.h>
#include <limits.h>


int main() {
    
    printf("Unsigned character size: %d\n",UCHAR_MAX);
    printf("Signed character min size: %d\n",SCHAR_MAX);
    printf("Signed character max size: %d\n",UCHAR_MAX);
    printf("Unsighed short size: %d\n",USHRT_MAX);
    printf("Sighed short Min size: %d\n", SHRT_MIN);
    printf("Sighed short Max size: %d\n", SHRT_MAX);
    printf("Unsighed int size: %d\n",UINT_MAX);
    printf("Sighed int Min size: %d\n", INT_MIN);
    printf("Sighed int Max size: %d\n", INT_MAX);
    printf("Unsighed Long size: %ld\n", ULONG_MAX);
    printf("Sighed Long Min size: %ld\n", LONG_MIN);
    printf("Sighed Long Max size: %ld\n", LONG_MAX);

    printf("-----------Computed mathmatically with bitwise opps----------\n");

    // Sizes of chars
    int c = sizeof(char) * 8;
    int s_char_min = -(1 << (c - 1));
    int s_char_max = (1 << (c - 1)) - 1;
    unsigned int u_char = (1U << c) - 1;

    printf("Size of a char: %d\n", c);
    printf("Min/Max size of a signed char: %d, %d\n", s_char_min, s_char_max);
    printf("Unsigned char size: %u\n", u_char);
    printf("\n");


    // Sizes of short 
    int s = sizeof(short) * 8;
    int s_short_min = -(1 << (s - 1));
    int s_short_max= (1 << (s - 1)) - 1;
    unsigned int u_short = (1U << s) - 1;

    printf("Size of a short: %d\n", s);
    printf("Min/Max size of a signed short: %d, %d\n", s_short_min, s_short_max);
    printf("Unsigned short size: %u\n", u_short);
    printf("\n");


    // Sizes of int 
    int i = sizeof(int) * 8;
    int s_int_min = -(1 << (i - 1));
    int s_int_max = (1 << (i - 1)) -1;
    unsigned int u_int = 1U << (i - 1);

    printf("Size of a int: %d\n", i);
    printf("Min/Max size of a signed int: %d, %d\n", s_int_min, s_int_max);
    printf("Unsigned int size: %u\n", u_int);
    printf("\n");

    
    // Sizes of long 
    int l = sizeof(long) * 8;
    long s_long_min = -(1 << (l - 1));
    long s_long_max = (1 << (l - 1)) - 1;
    unsigned long u_long = 1UL << (l - 1);

    printf("Size of a long: %d\n", l);
    printf("Min/Max size of a signed long: %ld, %ld\n", s_long_min, s_long_max);
    printf("Unsigned long size: %lu\n", u_long);
    printf("\n");
    return 0;
}
