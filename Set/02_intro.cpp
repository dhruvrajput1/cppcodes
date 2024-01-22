#include<iostream>
#include<set>
using namespace std;

int main() {

    set<pair<int, int>> s;

    s.insert(make_pair(10, 1));
    s.insert(make_pair(10, 5));
    s.insert(make_pair(20, 1));
    s.insert(make_pair(20, 100));
    s.insert(make_pair(5, 1));
    s.insert(make_pair(5, 3));
    s.insert(make_pair(10, 1));

    s.erase(make_pair(5, 3));
    s.insert(make_pair(5, 4));

    auto it = s.lower_bound(make_pair(20, 1));
    cout<<it->first<<" "<<it->second<<endl;

    auto itt = s.upper_bound(make_pair(20, 1));
    cout<<itt->first<<" "<<itt->second<<endl;

    // for(auto i : s) {
    //     cout<<i.first<<" and "<<i.second<<endl; 
    // }


    return 0;
}