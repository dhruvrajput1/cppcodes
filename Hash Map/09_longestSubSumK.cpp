#include<iostream>
#include<unordered_map>
using namespace std;

int longestLengthWith0Sum(int* arr, int n, int k) {

    unordered_map<int, int> m;

    int pre = 0;
    int len = 0;

    for(int i = 0; i < n; i++) {

        pre += arr[i];

        if(pre == k) {
            len = max(len, i + 1);
        }
        if(m.find(pre - k) != m.end()) {
            len = max(len, (i - m[pre - k]));
        }
        else {
            m[pre] = i; // storing the first occurence
        }

    }

    return len;

}


int main() {

    int arr[] = {0, -1, 1, 2, 5, -5, -2};
    int n = sizeof(arr)/sizeof(int);

    int k = 3;

    cout<<longestLengthWith0Sum(arr, n, k);
    

    return 0;   
}