#include<stdio.h>

int main(){

    FILE *fptr;

    fptr = fopen("StudentDetails.txt", "w");

    char name[100];
    int age;
    float cgpa;

    printf("Enter age: ");
    scanf("%d", &age);
    printf("Enter cgpa: ");
    scanf("%f", &cgpa);
    printf("Enter name: ");
    scanf("%s", name);

    fprintf(fptr, "Student name: %c\n", name);
    fprintf(fptr, "Student age: %d\n", age);
    fprintf(fptr, "Student cgpa: %f\n", cgpa);


    fclose(fptr);

    return 0;
}