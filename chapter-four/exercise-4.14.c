#include <stdio.h>

#define swap(t, x, y) (t = x, x = y, y = t)
    

int main() {
    char t, x, y;
    x = 'a';
    y = 'b';

    printf("t = %c, x = %c, y = %c\n", t, x, y);

    swap(t, x, y);

    printf("t = %c, x = %c, y = %c\n", t, x, y);
    

    return 0;
}
