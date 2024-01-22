#include<iostream>
using namespace std;

string arr[] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};

void convert2048toWordsInReverse(int N){
    // base case
    if(N == 0){
        return;
    }

    // recursive case

    int rem = N%10;
    cout<<arr[rem]<<" ";

    convert2048toWordsInReverse(N/10);

}

int main(){
    // n will be greater than zero always
    int N;
    cin>>N;

    convert2048toWordsInReverse(N);
 
    return 0;
}