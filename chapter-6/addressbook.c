#include <stdio.h>
#include <string.h>

struct Person {
    char name[50];
    int age;
    char phone[15];
};


void personinfo(struct Person p) {
    printf("Name: %s\tAge: %d\tPh: %s\n", p.name, p.age, p.phone);
}

void fillperson(struct Person *p) {
    printf("Enter Name: ");
    strcpy(p->name, "Mokoto"); 
    printf("Enter Age: ");
    p->age = 50;
    printf("Enter Phone number: ");
    strcpy((*p).phone, "0010101110110");
}

int main() {
    struct Person alias;

    printf("Enter details for your alias:\n");
    fillperson(&alias);

    printf("\nYour friends details: \n");
    personinfo(alias);

    return 0;

}


