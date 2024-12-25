#include <stdio.h>

#define MAXLENGTH 100

void printd(int s, char c[]);

int main() {
    int num = 123;
    char converted[MAXLENGTH];

    printd(num, converted);

    printf("%s\n", converted); 
    return 0;
}

void printd(int s, char converted[]) {
    int mod = 0; 
    static int i = 0;

    if (s / 10 > 0) {
        mod = s /10;
        printd(mod, converted);
    }
        
    mod = s % 10;
    converted[i++] = mod + '0';
}
 
