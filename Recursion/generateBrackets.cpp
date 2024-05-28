#include<iostream>
using namespace std;

void generateBrackets(char* out, int n, int idx, int open, int close) {
    // base case
    if(idx == 2*n) {
        out[idx] = '\0';
        cout<<out<<endl;
        return ;
    }

    // recursive case
    // 2 options
    if(open < n) {
        out[idx] = '(';
        generateBrackets(out, n, idx + 1, open + 1, close);
    }
    if(close < open) {
        out[idx] = ')';
        generateBrackets(out, n, idx + 1, open, close + 1);
    }

}

int main() {

    int n; cin>>n;

    char out[10000];

    int idx = 0;

    generateBrackets(out, n, idx, 0, 0);

    return 0;
}