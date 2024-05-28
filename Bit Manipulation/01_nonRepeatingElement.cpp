#include<iostream>
#include<vector>
using namespace std;

int main() {

    vector<int> arr {5, 4, 1, 4, 3, 5, 1};

    int n = arr.size();

    int ans = 0;

    for(int i = 0; i < n; i++) {
        ans = ans^arr[i];
    }

    cout<<ans<<endl;


    return 0;
}