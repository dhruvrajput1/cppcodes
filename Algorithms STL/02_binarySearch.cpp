#include<iostream>
#include<algorithm>
using namespace std;

int main() {

    int arr[] = {20, 30, 40, 40, 40, 50, 100, 1100};
    int n = sizeof(arr)/sizeof(int);

    int key = 111;

    // if array is sorted we'll use binary search instead of linear search

    bool isPresent = binary_search(arr, arr+n, key);

    if(isPresent) {
        cout<<"Present"<<endl;
    }
    else {
        cout<<"Absent!"<<endl;
    }

    // if we want index
    auto lb = lower_bound(arr, arr+n, 40); // it will return the address of first element that is greater than or equal to key
    cout<<(lb-arr)<<endl;

    int* ub = upper_bound(arr, arr+n, 40);// it will return adderss of first element greater than key

    cout<<ub - arr<<endl; 

    cout<<ub-lb<<endl; // it will print the frequency of key
    return 0;
}