#include <stdio.h>

int main() {

    int a[10];

    for (int i = 0; i < 10; ++i)
        a[i] = i;

    int *ip = &a[0];

    printf("%d\n", *++ip);
    return 0;
}
