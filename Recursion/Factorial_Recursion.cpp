#include<iostream>
using namespace std;

int fact(int N){

    if(N == 0){
        return 1;
    }

    return N*fact(N-1);
}

int main(){
    // recursion; --> when a function calls itself repeatatidly;
    int N; cin>>N;
    cout<<"Factorial of "<<N<<" is : "<<fact(N);

    return 0;
}