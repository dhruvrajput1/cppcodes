#include<iostream>
using namespace std;

int main() {

    // print all prime numbers in a range

    cout<<"Enter the lower bound"<<endl;
    int a; cin>>a;

    cout<<"Enter the upper bound"<<endl;
    int b; cin>>b;

    for(int i = a; i <= b; i++) {

        int flag = 1;

        if(i == 0 or i == 1) { // because 0 and 1 are neither prime nor composite
            continue;
        }

        for(int j = 2; j < i; j++) {
            if(i%j == 0) {
                flag = 0; 
                break;
            }
        }

        if(flag == 1) {
            cout<<i<<" ";
        }
    }

    return 0;
}