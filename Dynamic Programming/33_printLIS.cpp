#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {

    vector<int> arr {5, 4, 11, 1, 16, 8};

    int n = arr.size();

    vector<int> dp (n, 1);
    vector<int> hash(n);

    int maxi = 1;
    int lastIndex = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(arr[j] < arr[i] and dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                hash[i] = j;
            }
        }
        if(dp[i] > maxi) {
            maxi = dp[i];
            lastIndex = i;
        }
    }

    vector<int> temp;
    temp.push_back(arr[lastIndex]);

    while(hash[lastIndex] != lastIndex) {
        lastIndex = hash[lastIndex];
        temp.push_back(arr[lastIndex]);
    }

    reverse(temp.begin(), temp.end());

    for(int i = 0; i < temp.size(); i++) {
        cout<<temp[i]<<" ";
    }
    cout<<endl;

    return 0;
}