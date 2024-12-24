/*Our getch and ungetch do not handle a pushed-back EOF correctly, Decide what*/
/*their properties should be if an EOF is pushed baack, and impolement.*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char []);
void push(double);
double pop(void);


#define MAXVAL 100

int sp = 0;
double val[MAXVAL];


int main() {

    int type;
    double op2, op1;
    char s[MAXOP];
    double temp;
    double second;

    while ((type = getop(s)) != EOF) {
        switch(type) {
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
            push(pop() - op2); 
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("Zero divides error");
            break;
        case '%':
            op2 = pop();
            push(abs((int) pop()) % abs((int) op2));
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        case 'g':
            printf("%lf\n", val[sp]);
            break;
        case 'd':
            push(val[sp]);
            break;
        case 's':
            temp = pop();
            second = pop();
            printf("%lf %lf\n", temp, second);
            push(temp);
            push(second);
            break;
        case 'w':
            sp = 0;
            break;
        case 'x':
            push(exp(pop()));
            break;
        case 't':
            push(sin(pop()));
            break;
        case 'p':
            op2 = pop();
            temp = pop();
            if ((op2 != 0 && temp > 0) || (op2 > 0 && isdigit(temp)))
                push(pow(op2, temp));
            else
                printf("Cant do that with powers dawg\n");
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
    return 0;
}


void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else 
        printf("error: stack full, cant push %g\n", f);
}


double pop(void) {
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

int getch(void);
void ungetch(int);

int getop(char s[]) {
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-')
        return c;
    i = 0;
   
    if (c == '-') {
        if (isdigit(s[++i] = c =getch())) {
            ungetch(c);
            --i;
        }
        else {
            ungetch(c);
            c = '-';
            return c;
        }
    }
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

#define BUFSIZE 100

int buf[BUFSIZE]; // not happy with this fix, i had to claude it.. not sure if 
// skill issue or just overthinking the question trying to make big changes.
int bufp = 0;

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE) 
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

void ungetchs(char s[]) {
    if (bufp >=BUFSIZE) {
        printf("ungetch: too many characters\n");
    }
    else  {
        int length = strlen(s);
        for(int i = length; i > 0; i--) {
            buf[bufp++] = s[i];
        }
    }
}