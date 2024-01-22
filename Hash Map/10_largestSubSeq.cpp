#include<iostream>
#include<unordered_map>
using namespace std;

int findLargestSubsequence(int* arr, int n) {

    unordered_map<int, int> m; // number, streaklength

    for(int i = 0; i < n; i++) {
        int num = arr[i];

        if(m.count(num - 1) == 0 and m.count(num + 1) == 0) { // one smaller and one greater number both are not available
            m[num] = 1;
        }
        else if(m.count(num - 1) and m.count(num + 1)) { // both are present
            int leftStreakLength = m[num - 1];
            int rightStreakLength = m[num + 1];

            int streak = leftStreakLength + rightStreakLength + 1;

            m[num - leftStreakLength] = streak; // updating starting and ending length
            m[num + rightStreakLength] = streak;

        }
        else if(m.count(num - 1) and !m.count(num + 1)) {
            int len = m[num - 1];
            int streak = len + 1;
            m[num] = streak;
            m[num - len] = streak;
        }
        else {
            int len = m[num + 1];
            int streak = len + 1;
            m[num] = streak;
            m[num + len] = streak;
        }
    }

    int largest = 0;
    for(auto p : m) {
        largest = max(largest, p.second);
    }

    return largest;

}

int main() {

    int arr[] = {14, 5, 1, 2, 6, 3, 7, 8, 9, 13, 15, 11, 12, 13, 17, 10};
    int n = sizeof(arr)/sizeof(int);

    cout<<findLargestSubsequence(arr, n)<<endl;

    return 0;
}