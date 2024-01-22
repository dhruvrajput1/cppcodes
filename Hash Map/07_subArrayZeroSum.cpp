#include<iostream>
#include<unordered_set>
using namespace std;

bool checkSum(int* arr, int n) {
    
    unordered_set<int> s;

    int pre = 0;

    for(int i = 0; i < n; i++) {
        pre += arr[i];

        // before inserting new element, check whether the element was already present or not
        if(pre == 0 or s.find(pre) != s.end()) {
            return true;
        }

        s.insert(pre);
    }

    return false;

}

int main() {

    int arr[] = {6, -1, 2, -1, 2,  -1};
    int n = sizeof(arr)/sizeof(int);

    if(checkSum(arr, n)) {
        cout<<"Present"<<endl;
    }
    else {
        cout<<"Not Present"<<endl;
    }

    return 0;   
}