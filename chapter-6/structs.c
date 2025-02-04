#include <stdio.h>

struct Person {
    char name[50];
    int age;
};

void printPerson(struct Person p);

int main() {
     
    struct Person p1 = {"alice", 80};
    printPerson(p1);
    return 0;
}

void printPerson(struct Person p) {
    printf("Name: %s, Age: %d\n", p.name, p.age);
}

