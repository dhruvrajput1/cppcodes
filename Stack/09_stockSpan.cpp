#include<iostream>
#include<stack>
using namespace std;

void stockSpan(int* price, int n, int* span) {

    stack<int> s; // it will store indices of price
    s.push(0);

    span[0] = 1;

    for(int i = 1; i < n; i++) { // for rest of the indices
        int currentPrice = price[i];
        //topmost element that is higher than current price
        while(!s.empty() and currentPrice >= price[s.top()]) {
            s.pop();
        }

        if(!s.empty()) {
            int prevHighest = s.top();
            span[i] = i - prevHighest;
        }
        else {
            span[i] = i + 1;
        }

        s.push(i);
    }

}

int main() {

    int price[] = {100, 80, 60, 70, 60, 75, 85};

    int n = sizeof(price)/sizeof(int);

    int span[10000] = {0};

    stockSpan(price, n, span);

    for(int i = 0; i < n; i++) {
        cout<<span[i]<<" ";
    }
    cout<<endl;

    return 0;
}