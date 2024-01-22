#include<iostream>
#include<stack>
using namespace std;

bool isBalanced(string str) {

    stack<char> s;
    
    for(int i = 0; i < str.size(); i++) {
        char ch = str[i];  // [({})()]

        if(ch == '[' or ch == '{' or ch == '(') {
            s.push(ch);
        }
        else if(ch == ']') {
            if(!s.empty() and s.top() == '[') {
                s.pop();
            }
            else {
                return false;
            }
            
        }
        else if(ch == '}') {
            if(!s.empty() and s.top() == '{') {
                s.pop();
            }
            else {
                return false;
            }
            
        }
        else if(ch == ')') {
            if(!s.empty() and s.top() == '(') {
                s.pop();
            }
            else {
                return false;
            }
            
        }

    }

    if(!s.empty()) {
        return false;
    }
    
        return true;
    
}

int main() {

    string str = "[({})()]";

    if(isBalanced(str)) {
        cout<<"Balanced"<<endl;
    }
    else {
        cout<<"Not balanced"<<endl;
    }
 
    return 0;
}