/*Write a program expr, which evaluates a reverse polish expression from the cli, */
/*where each operator or operand is a separate argument. E.g expr 2 3 4 + * = 14*/

#include <stdio.h>

int getint(char c);

int main(int argc, char *argv[]) {

    while (--argc > 0) {
        printf("%s\n", *++argv);
    }

    return 0;
}
