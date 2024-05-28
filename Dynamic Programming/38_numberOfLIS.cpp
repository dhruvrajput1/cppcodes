#include<iostream>
#include<vector>
using namespace std;

int main() {

    vector<int> arr {1, 3, 5, 4, 7};

    int n = arr.size();

    int maxi = 1;
    vector<int> dp (n, 1);
    vector<int> cnt(n, 1);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(arr[i] > arr[j] and dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                cnt[i] = cnt[j];
            }
            else if(arr[i] > arr[j] and dp[j] + 1 == dp[i]) {
                cnt[i] += cnt[j];
            }
            maxi = max(maxi, cnt[i]);
        }
    }

    cout<<maxi<<endl;


    return 0;
}