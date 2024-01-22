#include<stdio.h>

int main(){
    int radius;
    float circumfrence;
    printf("Enter the radius \n");
    scanf("%d", &radius);
    circumfrence = 2*3.14*radius;
    printf("Circumfrence is: %f", circumfrence);
}