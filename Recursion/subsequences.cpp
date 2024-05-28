#include<iostream>
using namespace std;

void subsequences(char inputarr[], int i, char outputarr[], int j){
    // base case
    if(inputarr[i] == '\0'){
        outputarr[j] = '\0';
        cout<<outputarr<<endl;
        return;
    }

    // recursive case
    // without a // exclude
    // excluding the current character
    subsequences(inputarr, i+1, outputarr, j); 


    // with a // include
    // include the current character
    outputarr[j] = inputarr[i];
    subsequences(inputarr, i+1, outputarr, j+1);
}

int main(){
    char inputarr[100];
    cin>>inputarr;

    char outputarr[100];

    subsequences(inputarr, 0, outputarr, 0);
}