#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isComparable(string s1, string s2) {
    if(s1.size() != s2.size() + 1) {
        return false;
    }

    int first = 0;
    int second = 0;

    while(first < s1.size()) {
        if(s1[first] == s2[second]) {
            first++;
            second++;
        }
        else {
            first++;
        }
    }

    if(first == s1.size() and second == s2.size()) {
        return true;
    }

    return false;
}

bool cmp(string s1, string s2) {
    return s1.size() < s2.size();
}

int main() {

    vector<string> words {"a", "b", "ba", "bca", "bda", "bdca"};

    sort(words.begin(), words.end(), cmp);

    int n = words.size();

    vector<int> dp (n, 1);

    int maxi = 1;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(isComparable(words[i], words[j]) and dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
            }
            maxi = max(maxi, dp[i]);
        }
    }

    cout<<maxi<<endl;

    return 0;
}