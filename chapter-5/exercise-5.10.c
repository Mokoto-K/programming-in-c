// Write the progream expr which evaluates a reverse polish expression from the cl
// where each operator or operand is a separate arg7ument.
// eg = expr 2 3 4 + * evals too 2 x (3+4)

#include <stdio.h>

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f);
double pop(void);
int getint(char *);

int main(int argc, char *argv[]) {
    int num;
    double answer;

    while (--argc > 0) {
        num = getint(*++argv);
        printf("%c\n", *argv[0]);

        /*printf("%c\n", num); */

        if (num) {
            push(num);
            printf("Pushing: %d\n", num);
        }
        else {
            double one = pop();
            double two = pop();

            switch (*argv[0]) {
                case '+': 
                    answer = two + one;
                    break;
                case '-':
                    answer = two - one;
                    break;
                case '/': 
                    answer = two / one;
                    break;
                case '*': 
                    answer = two * one;
                    break;
            } 
            push(answer);
        }
    }
    printf("%.2f\n", pop());
    return 0;
}

void push(double f) {
    if (sp < MAXVAL) {
        /*printf("%f\n", f);*/
        val[sp++] = f;
    }
    else 
        printf("Error: stack is full %g\n",f);
}

double pop(void) {
    if (sp > 0)
        return val[--sp];
    else {
        /*printf("Error: stack is empty\n");*/
        return 0.0;
    }
}

int getint(char *s) {
    // Check to see if the char is an operator
    if (*s == '+' || *s == '-' || *s == '*' || *s == '/')
        return 0;

    // Check to see if it's a number
    char *p = s;
    int num = 0;
    while (*p) {
        // check if the char is a letter or anything other then a number
        if (*p < '0' || *p > '9')
            return 0;
        num = num * 10 + (*p - '0');
        p++;
    }
    // If you make it here, you must be a number
    return num;
}

