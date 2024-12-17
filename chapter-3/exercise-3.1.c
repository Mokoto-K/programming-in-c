#include <stdio.h>

int binsearch(int x, int v[], int n);

int main() {
    int x = 2;
    int n = 10;
    int v[] = {1, 2, 3 ,4 ,5 ,6 ,7 ,8 ,9 ,10};

    printf("%d\n", binsearch(x, v, n));
    return 0;
}

int binsearch(int x, int v[], int n) {

    int low, mid, high;

    low = 0;
    high = n - 1;
    while (low < high) {
        mid = (low + high) / 2;
        if (x > v[mid])
            low = mid + 1;
        else 
            high = mid;
    }
    return (x == v[low]) ? low : -1;
}
