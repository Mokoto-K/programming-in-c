#include <stdio.h>

void swap(int *a, int *b);
int stringlen(char *s);

int main() {

    int a[10];

    int *pa;

    /*a[0] = 69;*/
    pa = &a[0];

    printf("%p %d\n", pa, *pa); 

    int x;

    x = *pa;

    pa++;
    printf("%p %d\n", pa, *pa); 
    

    
    /*int x = 1, y = 2, z[10];*/
    /*int *ip;*/
    /**/
    /*printf("x = %d, y = %d\n", x, y);*/
    /**/
    /*ip = &x;*/
    /*printf("ip = &x | %p\n", ip);*/
    /**/
    /*y = *ip;*/
    /*printf("y = *ip | %d\n", y);*/
    /**/
    /**ip = 0;*/
    /*printf("*ip = 0 | %d\n", x);*/
    /**/
    /*ip = &z[0];*/
    /*printf("ip = &z[0] | %p\n", ip);*/
    /**/
    /*printf("x = %d | y = %d\n", x, y);*/
    /*swap(&x, &y);*/
    /*printf("x = %d | y = %d\n", x, y);*/

    return 0;
}

void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int stringlen(char *s) {

    int n;
    for (n = 0; s[n] != '\0'; n++)
        ;
    return n;
}
