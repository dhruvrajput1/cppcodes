#include<iostream>
using namespace std;

int power(int x, int n){

    // base case
    if(n == 0){
        return 1;
    }
    // recursive case
    return x*power(x, n-1);

}

int main(){
    int x, n;
    cin>>x>>n;
    cout<<power(x, n);
 
    return 0;
}