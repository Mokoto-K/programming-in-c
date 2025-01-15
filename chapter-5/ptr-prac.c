#include <stdio.h>

void swap(int *i, int *j);

int stringlen(char *s);

int main() {
    int *ip;
    int x = 1;
    int y = 2; 

    ip = &x;

    printf("%p, %d\n", ip, *ip);

    printf("x = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("A swap has occured\n");
    printf("x = %d, y = %d\n", x, y);
    
    char string[] = "hello";

    int length = stringlen(string);

    printf("string %s is %d chars long\n", string, length);

    char *s = "abcdefghijklmnop";

    printf("%c\n", *s);
    printf("%c\n", *(++s));
    return 0;

}

void swap(int *i, int *j) {
    int temp = *i;

    *i = *j;
    *j = temp;
}

int stringlen(char *s) {
    int i;

    for (i = 0; *s++ != '\0'; ++i) 
        ;

    return i;
}
