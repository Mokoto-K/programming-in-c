#include <stdio.h>

#define ALLOCSIZE 10000

char *alloc(int n);
void afree(char *p);

int main() {

    alloc(1);

    return 0;
}
static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n) {
    if (allocbuf + ALLOCSIZE - allocp >= n) {
        printf("%p + %d - %p = %ld >= %d\n", allocbuf, ALLOCSIZE, allocp,\
               (allocbuf + ALLOCSIZE - allocp), n);
        allocp += n;
        return allocp - n; 
    }
    else 
        return 0;
}

void afree(char *p) {
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}
