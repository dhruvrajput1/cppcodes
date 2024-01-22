#include<iostream>
using namespace std;

void decSequence(int N){

    if(N == 0){ // base case
        return; // terminate the program
    }
    // recursive case
    cout<<N<<" ";
    decSequence(N-1); 
}

int main(){
    int N;
    cin>>N;
    decSequence(N);
 
    return 0;
}