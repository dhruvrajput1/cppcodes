#include<iostream>
using namespace std;

string arr[] = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wx", "yz"};
int count = 0;

void phoneKeyPad(string s, int i, string out){
    // base case
    if(s[i] == '\0'){
        cout<<out<<" ";
        count++;
        return;
    }


    // recursive case
    char ch = s[i];
    int index = ch - '0';
    
    for(int k = 0; arr[index][k] != '\0'; k++){
        
        phoneKeyPad(s, i+1, out + arr[index][k]);
        
    }


}

int main(){
    string s; // 12
    cin>>s;
    
   

    phoneKeyPad(s, 0, "");
    cout<<endl;
    cout<<count<<endl;
}