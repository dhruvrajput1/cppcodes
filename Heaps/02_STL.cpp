#include<iostream>
#include<queue>
using namespace std;

int main() {
    
    // max heap
    priority_queue<int> pq;

    pq.push(4);
    pq.push(5);
    pq.push(2);
    pq.push(1);

    cout<<"Top element is "<<pq.top()<<endl;
    pq.pop();
    cout<<"Top element is "<<pq.top()<<endl;

    cout<<"Size of heap is "<<pq.size()<<endl;


    // min heap
    priority_queue<int, vector<int>, greater<int>> minHeap;

    minHeap.push(4);
    minHeap.push(5);
    minHeap.push(2);
    minHeap.push(1);

    cout<<"Top element is "<<minHeap.top()<<endl;
    minHeap.pop();
    cout<<"Top element is "<<minHeap.top()<<endl;

    return 0;
}