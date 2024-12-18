#include <stdio.h>

#define MAX 2000

void expand(char s1[], char s2[]);

int main() {
    char s1[] = "hello, can you type a-z for me real quick, or 0-9, or A-G, or a-z0-9";
    char s2[MAX];

    expand(s1, s2);
    printf("%s\n", s2);
    return 0;
}

void expand(char s1[], char s2[]) {

    int i, j = 0;
    for (i = 0; s1[i] != '\0'; ++i) {
        if (s1[i] == '-' && i > 0 && s1[i+1] != '\0') {

            int prev = s1[i-1];
            int next = s1[i+1];
            
            int cond1 = prev >= 'a' && next <= 'z';
            int cond2 = prev >= 'A' && next <= 'Z';
            int cond3 = prev >= '0' && next <= '9';

            if (cond1 || cond2 || cond3) {
                for (int k = prev+1; k < next; k++) {
                    s2[j++] = k;
                }
            }
            else {
                s2[j] = s1[i];
                j++;
            }
        }
        else {
            s2[j] = s1[i];
            j++;
        }
    }
    s2[j] = '\0';

}
