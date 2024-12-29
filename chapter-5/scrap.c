#include <stdio.h>

void swap(int *a, int *b);
int stringlen(char *s);
int main() {

    int a[10];
    int x;
    int *pa;
    
    a[0] = 69;
    a[1] = 666;
    a[2] = 420;

    pa = &a[0];

    x = 1;
    
    //*(pa+1);

    printf("%p, %p\n", &a[x], a+x);

    char word[] = "hello, world";

    printf("%s is %d characters long \n", word, stringlen(word));


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
