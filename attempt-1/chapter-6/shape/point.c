#include <stdio.h>

struct point {
    int x;
    int y; 
};

struct rect {
    struct point pt1;
    struct point pt2;
};

struct point makepoint(int x, int y) {
    struct point temp;

    temp.x = x;
    temp.y = y;
    return temp;
}

int main() {
    struct point pt;
    struct point maxpt = {320, 200};
    
    printf("%d, %d\n", pt.x, pt.y);

    struct point p1 = {1, 1};
    struct point p2 = {40, 40}; 
    struct rect screen = {p1, p2};
    
    printf("(%d, %d), (%d, %d)\n", p1.x, p2.x, p1.y, p2.y);

   return 0;
}

