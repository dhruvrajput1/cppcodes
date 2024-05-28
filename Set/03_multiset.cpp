#include<iostream>
#include<vector>
#include<set>

using namespace std;

int main() {

    multiset<int, greater<int>> s1; // empty multiset container, greater<int> is used for storing in descending order

    s1.insert(30);
    s1.insert(20);
    s1.insert(10);
    s1.insert(40);
    s1.insert(50);

    // 50 and 10 will be added to multiset again unlike set
    s1.insert(50);
    s1.insert(10);

    for(auto it = s1.begin(); it != s1.end(); it++) { // printing the values of multiset s1
        cout << *it << " ";
    }
    cout<<endl;

    multiset<int> s2 (s1.begin(), s1.end()); // copying from s1 to s2 but s2 will be in increasing order

    for(auto it = s2.begin(); it!= s2.end(); it++) { // printing the values of s2
        cout << *it << " ";
    }
    cout<<endl;



    return 0;
}