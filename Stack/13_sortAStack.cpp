#include<iostream>
#include<stack>
using namespace std;

void sort(stack<int>& s) {
    stack<int> st;
    
    while(!s.empty()) {
        int curr = s.top();
        s.pop();
        
        while(!st.empty() and st.top() < curr) {
            s.push(st.top());
            st.pop();
        }
        
        st.push(curr);
    }
    
    while(!st.empty()) {
        s.push(st.top());
        st.pop();
    }

}

int main() {

    stack<int> s;
    s.push(2);
    s.push(5);
    s.push(1);
    s.push(7);

    sort(s);

    while(!s.empty()) {
        cout<<s.top()<<endl;
        s.pop();
    }

    return 0;
}

