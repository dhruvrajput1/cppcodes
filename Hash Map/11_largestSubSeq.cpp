#include<iostream>
#include<unordered_set>
using namespace std;

int findLargestSubsequence(int* arr, int n) {

    unordered_set<int> s;

    for(int i = 0; i < n; i++) {
        s.insert(arr[i]);
    }

    int maxStreak = 1;

    // iterate over all elements
    // target those elements from which a streak can start
    for(int i = 0; i < n; i++) {

        if(s.find(arr[i] - 1) == s.end()) { // we can't find a number one less than the curr element
            // arr[i] is a starting point of streak
            // traverse the entire ramge that is contained in that streak
            int nextNum = arr[i] + 1;
            int streakLength = 1;
            while(s.find(nextNum) != s.end()) {
                nextNum++;
                streakLength++;
            }
            maxStreak = max(maxStreak, streakLength);
        }

    }

    return maxStreak;

}

int main() {

    int arr[] = {14, 5, 1, 2, 6, 3, 7, 8, 9, 13, 15, 11, 12, 13, 17, 10};
    int n = sizeof(arr)/sizeof(int);

    cout<<findLargestSubsequence(arr, n)<<endl;

    return 0;
}