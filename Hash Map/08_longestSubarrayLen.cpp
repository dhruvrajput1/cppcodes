#include<iostream>
#include<unordered_map>
using namespace std;

int longestLengthWith0Sum(int* arr, int n) {

    unordered_map<int, int> m;

    int pre = 0;
    int len = 0;

    for(int i = 0; i < n; i++) {

        pre += arr[i];

        if(pre == 0) {
            len = max(len, i + 1);
        }
        if(m.find(pre) != m.end()) {
            len = max(len, (i - m[pre]));
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

    cout<<longestLengthWith0Sum(arr, n);
    

    return 0;   
}