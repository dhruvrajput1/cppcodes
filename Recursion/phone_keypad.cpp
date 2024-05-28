#include<iostream>
using namespace std;

char arr[][1000] = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

void phoneKeyPad(char *inputarr, int i, char* out, int j){
    // base case
    if(inputarr[i] == '\0'){
        out[j] = '\0';
        cout<<out<<endl;
        return;
    }


    // recursive case
    char ch = inputarr[i];
    int index = ch - '0';

    for(int k = 0; arr[index][k] != '\0'; k++){
        out[j] = arr[index][k];
        phoneKeyPad(inputarr, i+1, out, j+1);
    }

}

int main(){
    char inputarr[1000]; // 23
    char out[1000];
    cin>>inputarr;

    phoneKeyPad(inputarr, 0, out, 0);
    
}