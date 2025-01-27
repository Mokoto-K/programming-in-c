#include <stdio.h>

void reverse(char *);

int main(int argc, char *argv[]) {
    char s[100] = "hello";

    if (argc > 1) 
        *s = *argv[1];
    
    reverse(s);
    printf("%s\n", s);
    return 0;
}

void reverse(char *s) {
    char *end = s;

    while (*end != '\0')
        end++;

    end--;

    while (s < end) {
        
        char *temp = s;
        *s = *end; 
        *end = *temp;  
        
        s++, end--;
    }
}

/*void reverse(char *s) {*/
/*    char temp[100], *p = s;*/
/*    int j, i = 0;*/
/**/
/*    while (*p != '\0') {*/
/*        printf("%d %c\n", i, *p);*/
/*        p++, i++;*/
/*    }*/
/*    p--, i--;*/
/*    printf("%d %c\n", i, *p);*/
/**/
/*    for (j = 0; i >= 0; j++, p--, i--) {*/
/**/
/*        printf("%d %c\n", i, *p);*/
/*        temp[j] = *p;*/
/**/
/*    }*/
/*    printf("%s\n",temp); */
/*    temp[j++] = '\0';*/
/**/
/*    for (i = 0; temp[i] != '\0'; i++, s++)*/
/*         *s = temp[i];*/
/*    *s++ = '\0';*/
/*}*/
/**/
/**/
