#include<iostream>
using namespace std;

string moveAllX(string s){

    // base case
    if(s.size() == 0){
        return "";
    }

    // recursive case
    string badi_string;
    char first_letter = s[0];
    badi_string = moveAllX(s.substr(1));

    if(first_letter == 'x'){
        return badi_string + first_letter;
    }
    else{
        return first_letter + badi_string;
    }

}

int main(){
    string s; // xxxabxbcx
    cin>>s;
    
    cout<<moveAllX(s);
}