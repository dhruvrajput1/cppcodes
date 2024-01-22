#include<iostream>
using namespace std;

void incSequence(int N){

    if(N == 0){ // base case
        return; // terminate the program
    }
    // recursive case
    incSequence(N-1);
    cout<<N<<" ";
     
}

int main(){
    int N;
    cin>>N;
    incSequence(N);
 
    return 0;
}