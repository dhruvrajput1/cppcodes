#include<iostream>
#include<algorithm>
using namespace std;

int main() {

    int arr[] = {1, 10, 11, 9, 100};
    int n = sizeof(arr)/sizeof(int);

    int key = 11;

    auto it = find(arr, arr+n, key);

    cout<<it<<endl; // it will print the address of key

    int index = it - arr; // if we subtract base address of arr from address of key, we'll get index

    cout<<index<<endl;

    // if key is not present in array, it will return nth index

    return 0;
}