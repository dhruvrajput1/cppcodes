#include <stdio.h>
int main() {
    int dividend, quotient, remainder, divisor;

    scanf("%d", &dividend);
    scanf("%d", &divisor);

    remainder = dividend%divisor;
    quotient = dividend/divisor;

    printf("Quotient is: %d \n", quotient);
    printf("Remainder is: %d", remainder);

    return 0;

}
