#include<iostream>
#include<stack>
using namespace std;

int evaluatePostfix(string exp) {
    stack<int> s;

    for(int i = 0; i < exp.size(); i++) {

        if(exp[i] >= '0' and exp[i] <= '9') {
            s.push(exp[i] - '0');
        }

        else {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();

            if(exp[i] == '+') {
                s.push(a + b);
            }
            else if(exp[i] == '-') {
                s.push(b - a);
            }
            else if(exp[i] == '*') {
                s.push(a * b);
            }
            else if(exp[i] == '/') {
                s.push(b / a);
            }
        }
    }

    return s.top();
}

int main() {

    string exp = "231*+9-";

    cout<<evaluatePostfix(exp);

    return 0;
}