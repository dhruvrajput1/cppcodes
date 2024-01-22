#include<iostream>
using namespace std;

int stringToInteger(string s, int l){
    // base case
    if(l == 0){
        return 0;
    }

    // recursive case
    int digit = s[l - 1] - '0';

    return stringToInteger(s, l-1)*10 + digit;
}

int main(){
    string s; // 1234
    cin>>s;
    int l = s.size();

    cout<<stringToInteger(s, l)<<endl;

    return 0;
}