#include<iostream>
using namespace std;

int fibo(int N){

    if(N == 0 || N == 1){
        return N;
    }

    return fibo(N-1) + fibo(N-2);
}

int main(){
    // write a program which will return the nth place digit of fibonacci series
    int N; cin>>N;
    cout<<N<<" digit of fibonacci series is: "<<fibo(N)<<endl;

    return 0;
}