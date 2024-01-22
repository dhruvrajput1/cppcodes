#include <stdio.h>
int main() {
    int Num1, Num2, t;
    scanf("%d %d", &Num1, &Num2);

    t = Num1;
    Num1 = Num2;
    Num2 = t;

    printf("Num1 is: %d \n", Num1);
    printf("Num2 is: %d", Num2);

    return 0;
}
