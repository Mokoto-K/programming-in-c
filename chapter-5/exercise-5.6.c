#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
#define GIGA 5000000
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines, char everything[]);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

int main() {
    int nlines;
    char everything[GIGA];

    if ((nlines = readlines(lineptr, MAXLINES, everything)) >= 0) {
        qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    }
    else {
        printf("error: input too big to sort\n");
    }
}

#define MAXLEN 1000

int mygetline(char *s, int lim) {
    int c, i;

    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i) 
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

int readlines(char *lineptr[], int maxlines, char everything[]) {
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = mygetline(line, MAXLEN)) > 0 )
        if (nlines >= maxlines || (p + len >= everything + GIGA)) 
            return -1;
        else {
            line[len-1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
            p += len;
        }
    return nlines;
}

void writelines(char *lineptr[], int nlines) {
    while (nlines-- > 0)
        printf("%s\n", *lineptr++);
}

void qsort(char*v[], int left, int right) {    
    int i, last;
    void swap(char *v[], int i, int j);
    
    if (left >= right)
        return;
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0) 
             swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last -1);
    qsort(v, last + 1, right);
}

void swap(char *v[], int i, int j) {
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

