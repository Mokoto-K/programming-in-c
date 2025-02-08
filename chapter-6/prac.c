#include <stdio.h>
#include <string.h>

struct address {
    char street[50];
    char city[50];
    int postcode;
};

struct person {
    char name[30];
    int age;
    struct address addr;
};

void print_person(struct person *p) {
    printf("%s, %d, %f\n", p->name, p->age, p->addr);
}


int main() {

    struct person p = {"bob",3, {"123 fake st", "Fakecity", 111111}};

    printf("%s, %d\n%s, %s, %d\n", p.name, p.age, 
           p.addr.street, p.addr.city, p.addr.postcode);

    return 0;
}
