#include<iostream>
#include<queue>
using namespace std;

void printQueue(queue<int> q) {
    while(!q.empty()) {
        cout<<q.front()<<" ";
        q.pop();
    }
}

int main() {

    queue<int> q;

    q.push(5);
    q.push(6);
    q.push(7);

    printQueue(q);


    return 0;
}