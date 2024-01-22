#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int data) {
        this -> data = data;
        next = NULL;
    }

};

class compare {
public:
bool operator() (node* a, node* b) {
    return a->data > b->data;
}
};

node* mergeKSortedLinkedLists(vector<node*> &listArray, int k) {
    priority_queue<node*, vector<node*>, compare> minHeap;

    if(k == 0) {
        return NULL;
    }

    // step1 : insert k elements to LL

    for(int i = 0; i < k; i++) {
        if(listArray[i] != NULL) {
            minHeap.push(listArray[i]);
        }
    }

    node* head = NULL;
    node* tail = NULL;

    while(minHeap.size() > 0) {
        node* top = minHeap.top();
        minHeap.pop();

        if(top->next != NULL) {
            minHeap.push(top->next);
        }

        if(head == NULL) { // answer LL is empty
            head = top;
            tail = top;
        }
        else { // insert at LL
            tail->next = top;
            tail = top;
        }

    }

    return head;

}

int main() {



    return 0;
}