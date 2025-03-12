#include <ctype.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>

struct key {
    char *word;
    int count;
} keytab[] = {
    "auto", 0,
    "break", 0,
    "case", 0, 
    "char", 0,
    "const", 0,
    "continue", 0, 
    "default", 0,
    "for", 0, 
    "int", 0, 
    "long", 0, 
    "unsigned", 0, 
    "void", 0, 
    "volitile", 0, 
    "while", 0
};

#define MAXWORD 100
#define NKEYS (sizeof(keytab) / sizeof(struct key))

int getword(char *, int);
struct key *binsearch(char *, struct key *, int);

int main() {
    char word[MAXWORD];
    struct key *p;
    
    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            if ((p=binsearch(word, keytab, NKEYS)) != NULL)
                p->count++;
    for (p = keytab; p < keytab + NKEYS; p++)
        if (p->count > 0)
            printf("%4d, %s\n", p->count, p->word);
    return 0;
}

struct key *binsearch(char *word, struct key tab[], int n) {
    int cond;
    struct key *low = &tab[0];
    struct key *high = &tab[n];
    struct key *mid;

    while (low <= high) {
        mid = low  + (high-low) / 2;
        if ((cond = strcmp(word, mid->word)) < 0)
            high = mid;
        else if (cond > 0)
            low = mid + 1; 
        else
            return mid;
    }
    return NULL;
}

int getword(char *word, int lim) {
    int c, getch(void);
    void ungetch(int);
    char *w = word;

    while (isspace(c = getch()))
        ;
    if (c != EOF)
        *w++ = c;

    // deal with hash for preprocessors
    if (c == '#') {
        *w++ = c;
        *w = '\0';
        return '#';
    }

    if (!(isalpha(c) || *w == '_')) {
        *w = '\0';
        return c;
    }
    for ( ; --lim > 0; w++)
        if (!(isalnum(*w = getch()) || *w == '_')) {
            ungetch(*w);
            break;
        }
    *w = '\0';
    return word[0];
}
