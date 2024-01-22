#include<iostream>
using namespace std;

string replaceAllPi(string s){
    // base case
    if(s.size() == 0){
        return "";
    }

    // recursive case
    string test_string = s.substr(0, 2);

    if(test_string == "pi"){
        return "3.14" + replaceAllPi(s.substr(2));
    }
    else{
        return s[0] + replaceAllPi(s.substr(1));
    }

}

int main(){
    string s;
    s = "pibadipic";

    cout<<replaceAllPi(s);

    return 0;
}