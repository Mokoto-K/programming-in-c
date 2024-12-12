#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 9
int htoi(char hex[]);

int main() {
    char user_input[MAX];
    char c;

    printf("Type a Hexidecimal number starting with '0x' you wish to convert\n");
    for (int i = 0; i < MAX && (c = getchar()) != '\n'; ++i) {
        user_input[i] = c;
        printf("%s\n",user_input);
    }
    printf("%d\n", htoi(user_input));
    return 0;
}

int htoi(char s[]) {
    int n = 0;

    // Get the len of the string
    int len = strlen(s);

    // Iterate over each index in the string
    for (int i = 0; i < len-1 && s[i] != '\n'; ++i) {
        // Change each letter to lower case
        s[i] = tolower(s[i]);

        // If the char is a digit, - 0, else -87 to get the letters int value
        if (i > 1 && isdigit(s[i])) {
            n = 16 * n + (s[i] - '0');
        }
        else if (i > 1 && s[i]){
            n = 16 * n + (s[i] - 87);
        } 
    } 
    return n;
}
