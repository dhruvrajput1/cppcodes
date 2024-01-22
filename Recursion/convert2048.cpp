#include<iostream>
using namespace std;

string arr[] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};

void convert2048toWordsIn(int N){
    // base case
    if(N == 0){
        return;
    }

    // recursive case

    convert2048toWordsIn(N/10);

    int rem = N%10;
    cout<<arr[rem]<<" ";

    
}

int main(){
    // n will be greater than zero always
    int N;
    cin>>N;

    convert2048toWordsIn(N);
 
    return 0;
}