#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

int main() {

    unordered_map<string, int> m;

    // insert
    m.insert(make_pair("Mango", 100));

    pair<string, int> p;
    p.first = "Apple";
    p.second = 100;

    m.insert(p);

    m["Banana"] = 20;

    // search
    string fruit;
    cin>>fruit;

    auto it = m.find(fruit);

    if(it != m.end()) {
        cout<<"Price of "<<fruit<<" is "<<m[fruit]<<endl;
    }
    else {
        cout<<"Fruit not found";
    }

    // another way to fund a particular key
    // it stored unique keys only once
    if(m.count(fruit)) { // count function return 1 or 0 whether fruit is present or not
        cout<<"Price is "<<m[fruit]<<endl;
    }
    else {
        cout<<"couldn't find this fruit"<<endl;
    }

    // erase
    m.erase(fruit);

    // update the price
    m[fruit] += 20;

    m["litchi"] = 60;
    m["pineapple"] = 80;

    // iterate over all the keys
    for(auto it = m.begin(); it != m.end(); it++) {
        cout<<it->first<<" "<<it->second<<endl;
    }

    m.erase(fruit);

    // foreach loop
    for(auto p : m) {
        cout<<p.first<<" : "<<p.second<<endl;
    }


    return 0;
}