#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {

    vector<int> arr {1, 7, 8, 4, 5, 6, -1, 9};

    int n = arr.size();

    vector<int> temp;


    temp.push_back(arr[0]);

    for(int i = 1; i < n; i++) {
        if(arr[i] > temp.back()) {
            temp.push_back(arr[i]);
        }
        else {
            int idx = lower_bound(temp.begin(), temp.end(), arr[i])-temp.begin();
            temp[idx] = arr[i];
        }
    }

    cout<<temp.size()<<endl;


    return 0;
}