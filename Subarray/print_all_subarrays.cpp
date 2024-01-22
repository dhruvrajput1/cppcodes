#include<iostream>
using namespace std;

int main() {

    // print all subarrays

    int arr[] = {1, 2, 3, 4};

    int n = sizeof(arr)/sizeof(int);

    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            
            // printing
            for(int k = i; k <= j; k++) {
                cout<<arr[k]<<" ";
            }
            cout<<endl;
        }
    }

    return 0;
}