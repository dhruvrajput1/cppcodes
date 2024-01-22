#include<iostream>
#include<vector>
using namespace std;

class stack {

    vector<int> v; // we don't keep it in public because if it is in public, we can acess middle elements, which is not the property of stack

public:

    // top
    int top(){
        return v[v.size() - 1];
    }

    // push
    void push(int data){
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

int main(){

    stack s;
    s.push(2);
    s.push(3);
    s.push(1);
    s.push(4);

    

    cout<<s.top()<<endl;

    s.pop();

    cout<<s.top()<<endl;


    return 0;
}