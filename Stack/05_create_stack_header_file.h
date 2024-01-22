#include<iostream>
#include<vector>
using namespace std;

// templates
// program generalize
template<typename T>

class stack {

    vector<T> v; // we don't keep it in public because if it is in public, we can acess middle elements, which is not the property of stack

public:

    // top
    T top(){
        return v[v.size() - 1];
    }

    // push
    void push(T data){
        v.push_back(data);
    }

    // pop
    void pop(){
        v.pop_back();
    }

    // size
    int size(){
        return v.size();
    }

    // empty
    bool empty(){
        if(v.size() == 0){
            return true;
        }
        return false;
    }
};

