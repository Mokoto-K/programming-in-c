#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100
#define NUMBER 0 

int getop(char []);
void push(double);
double pop(void);

int main(int argc, char *argv[]) {
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            printf("%f\n", op2);
            push(pop() - op2); 
            break;
        case '/':
            op2 = pop();
            if (op2 != 0)
                push(pop() / op2); 
            else 
                printf("error: zero divisor\n");
            break;
        case '%':
            op2 = pop();
            push((int) pop() % (int) op2);
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
return 0;
}

#include <ctype.h>

int getch(void);
void ungetch(int);

int getop(char *s) {
    int i, c;

    // Skip over blanks and tabs 
    while ((*s = c = getch()) == ' ' || c == '\t')
        ++s;
    // I think we need to put this here incase it's the end of the str
    *++s = '\0';

    // Return c if its not a number 
    if (!isdigit(c) && c != '.' && c != '-')
        return c;

    // check for negative numbers
    if (c == '-') {
        int next = getch();
        if (!isdigit(next) && next != '.') {
            ungetch(next);
            return c;
        }
        else {
            *--s = '-';
            *++s = next; 
            c = next;
        }
    }

    // collect all the digits of the number, including any after a decimal
    if (isdigit(c))
        while (isdigit(*++s = c = getch()))
            ;
    if (c == '.')
        while (isdigit(*++s = c = getch()))
            ;

    // Set the end of the str with the null boi
    *s = '\0';

    // Check for end of file, if not, push back into the input the last getch()
    if (c != EOF)
        ungetch(c);
    // Return a number if we make it all the way down here
    printf("%s\n", s);
    return NUMBER;
}
