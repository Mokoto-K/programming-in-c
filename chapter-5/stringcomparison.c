#include <stdio.h>
#include <stdbool.h>

int main(int argc, char **argv) {

    char word[] = "hello";
    char *sp; 
    bool cond = false;

    sp = word;
    sp++;

    if (*word > *sp)
        printf("%c comes before %c in %s\n", *word, *sp, word);
    else 
        printf("%c comes after %c in %s\n", *word, *sp, word);

    return 0;
}
