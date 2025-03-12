#include <stdio.h>
#include <string.h>

int main(){
    char *a = "abc";
    char *b = "abd";
    int cond = 0;
    if ((cond = strcmp(a, b)) < 0) 
        printf("%s comes before %s %d", a, b, cond);
    else 
        printf("%s comes before %s", b, a);

    return 0;
}
