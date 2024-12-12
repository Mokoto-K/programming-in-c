#include <stdio.h>

int any(char s1[], char s2[]);

int main() {

    char s1[110] = "mokoto kuyanagi";
    char s2[110] = "aeiou";

    printf("%d\n", any(s1, s2));

    return 0;
}

int any(char s1[], char s2[]) {
    int n = 0;
          
    for (int i = 0; s1[i] != '\n'; ++i) {

        for (int j = 0; s2[j] != '\n'; ++j) {

            if (s2[j] == s1[i] && n == 0) {
                n = i;
            }
        }
    }

    if (n == 0) {
        n = -1;
    }

    return n;
}
