#include <iostream>
using namespace std;

void generateStrings(char *input, int i, char *output, int j) {
    // base case
    if(input[i] == '\0') {
        output[j] = '\0';
        cout<<output<<endl;
        return ;
    }

    // recursive case

    // taking one digit at a time
    int digit = input[i] - '0';
    char ch = digit + 'A' - 1;
    output[j] = ch;
    generateStrings(input, i + 1, output, j + 1);

    // taking two digits at a time
    if(input[i+1] != '\0') {
        int secondDigit = input[i+1] - '0';
        int num = digit*10 + secondDigit;

        if(num <= 26) {
            char ch = num + 'A' - 1;
            output[j] = ch;
            generateStrings(input, i + 2, output, j + 1);
        }
    }

}

int main() {

    char input[10000] = "1234";

    char output[10000];

    generateStrings(input, 0, output, 0);

    return 0;
}