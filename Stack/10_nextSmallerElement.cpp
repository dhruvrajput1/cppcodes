#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main() {

    int arr[] = {2, 1, 4, 3};

    int n = sizeof(arr)/sizeof(int);

    vector<int> ans(n);

    stack<int> s;

    s.push(-1); // for last element

    for(int i = n - 1; i >= 0; i--) {
        int curr = arr[i];

        while(s.top() >= curr) {
            s.pop();
        }

        ans[i] = s.top();

        s.push(curr);

    }

    for(int i = 0; i < n; i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}