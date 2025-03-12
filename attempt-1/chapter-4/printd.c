#include <stdio.h>

void printd(int i);
int mytoi(char *);

int main(int argc, char *argv[]) {
    
    int i = (argc > 1) ? mytoi(argv[1]) : 1;
    printd(i);
    printf("\n");
    return 0;
}

void printd(int i) {
    if (i < 0) {
        putchar('-');
        i = -i;
    }

    if (i / 10)
        printd(i / 10);
    putchar(i % 10 + '0');
}

int mytoi(char *s) {
    int n = 0;
    for (; *s != '\0'; s++)
        n = n * 10 + (*s - '0'); 
    return n;
}
