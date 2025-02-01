#include <stdio.h>

#define MAXLINE 5000
#define MAXLEN 10000

int mygetline(char *, int n);

int main(int argc, char *argv[]) {
    char *lines[MAXLINE];
    char line[MAXLEN];
    int len, pos = 0;
    int i, n = 0;

    for (i = 0; i < MAXLINE && (len = mygetline(line, pos)) != 0; i++) {
        lines[i] = &line[pos];
        pos = len;
}
    
    if (argc > 1) {
        char *temp = argv[1];
        
        for (int k = 0; *temp != '\0'; k++) {

            n = n * k + (*temp++ - '0');
        }

        printf("%d\n", n);
        n = i - n;
    }
    else 
        n = i - 2;

    for (int j = n; j < i; j++)
        printf("Position %d, Value: %s\n", j, lines[j]);
    
    return 0;
}

int mygetline(char *line, int pos) {
    int i, c, temp;
    temp = pos;
    for (i = pos; i < MAXLEN && (c = getchar()) != '\n'; i++) {
        line[i] = c;
    }

    if (temp != i) {
        line[++i] = '\0';
    }
    else 
        i = 0;

    return i;
}

