#include<iostream>
#include<stack>
using namespace std;

bool isOperator(char ch) {
    if(ch == '+' or ch == '-' or ch == '*' or ch == '/') return true;

    return false;
}

string preToPost(string pre_exp) {
    stack<string> s;

    int n = pre_exp.size();

    for(int i = n - 1; i >= 0; i--) {
        if(isOperator(pre_exp[i])) {
            string a = s.top();
            s.pop();
            string b = s.top();
            s.pop();

            string temp = a + b + pre_exp[i];

            s.push(temp);
        }
        // if symbol is an operand
        else {
            // push the operand to the stack
            s.push(string(1, pre_exp[i]));
        }
    }

    return s.top();
}

int main() {

    string pre_exp = "*-A/BC-/AKL";

    cout<<preToPost(pre_exp)<<endl;

    return 0;
}