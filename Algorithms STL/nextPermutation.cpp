#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {

    int arr[] = {10, 20, 30, 40, 50};

    int n = sizeof(arr)/sizeof(int);

    // rotate(start, from where to rotate, end) --> syntax 

    rotate(arr, arr+2, arr+n);

    for(int i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    vector<int> v {1, 2, 3};

    // rotate(v.begin(), v.begin() + 3, v.end());

    for(int i = 0; i < v.size(); i++) {
        cout<<v[i]<<" ";
    }
    cout<<endl;


    // next permutation

    next_permutation(v.begin(), v.end());

    // for each loop

    for(int x:v) {
        cout<<x<<" ";
    }
    cout<<endl;


    return 0;
}