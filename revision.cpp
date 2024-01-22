#include<iostream>
using namespace std;

int strToInt(string s, int l) {
    // base case
    if(l == 0) {
        return 0;
    }

    // recursive case
    int digit = s[l - 1] - '0';
    return strToInt(s, l - 1)*10 + digit;
    
}

int main() {

    string s = "2764";

    int l = s.size();

    cout<<strToInt(s, l) + 1<<endl;;

    return 0;
}