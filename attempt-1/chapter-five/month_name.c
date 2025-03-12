#include <stdio.h>

char *month_name(int n);

int main() {
    int n = 2;

    printf("%s\n", month_name(n));

    return 0;
}

char *month_name(int n) {

    static char *name[] = {
        "Illegal month", "January", "February", "March", "April", "May", "June",
        "July", "August", "Semptember", "October", "November", "December"
    };

    return (n < 1 || n > 12) ? name[0] : name[n];
    }
