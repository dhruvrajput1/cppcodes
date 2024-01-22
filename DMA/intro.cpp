#include<iostream>
using namespace std;

int main() {

    // static memory;
    int a; 
    a = 10;

    int arr[100];

    cout<<sizeof(arr)<<endl;

    // dynamic memory

    int *b = new int;
    *b = 20;


    delete b;


    int n; cin>>n;

    int* brr = new int[n];

    for(int i = 0; i < n; i++) {
        cin>>brr[i];
        cout<<brr[i]<<" ";
    }

    delete [] brr;


    return 0;
}