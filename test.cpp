#include<bits/stdc++.h>
using namespace std;

void subsequences(int i, int* arr, vector<int> temp, int n) {
    // base case
    if(i == n) {
        for(int j = 0; j < temp.size(); j++) {
            cout<<temp[j]<<" ";
        }
        cout<<endl;
        return ;
    }

    // recursive case
    // not take
    subsequences(i+1, arr, temp, n);

    // take
    temp.push_back(arr[i]);
    subsequences(i+1, arr, temp, n);
    temp.pop_back();
}

int main() {

    int arr[] = {3, 1, 2};
    int n = sizeof(arr)/sizeof(arr[0]);

    vector<int> temp;

    subsequences(0, arr, temp, n);

    return 0;
}