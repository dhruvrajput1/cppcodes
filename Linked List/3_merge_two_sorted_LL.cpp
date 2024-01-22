#include<iostream>
using namespace std;

class node{
public:
    int data;
    node* next;

    node(int d){
        data = d;
        next = NULL;
    }

};

int lengthofLL(node* head){
    node* temp = head;
    int count = 0;

    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}



void insertAtFront(node* &head, node* &tail, int data){

    node*n = new node(data);

    if(head == NULL){
        head = n;
        tail = n;
        return ;
    }
    else{
        n->next = head;
        head = n;
    }
}


void printlinklist(node* head){ // temp is a pointer
    // node* temp = head;

    // while(temp != NULL){
    //     cout<<temp->data<<"->";
    //     temp = temp->next;
    // }

     while(head != NULL){  // head pass by valur hua h to value change nhi hogi
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<endl;
}


bool searchRec(node* head, int key){
    // base case
    if(head == NULL){
        return false;
    }


    // recursive case
    if(head->data == key){
        return true;
    }

    return searchRec(head->next, key);

}

node* mid(node* head){
    node* fast = head;
    node* slow = head;

    while(fast != NULL and fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}



void reverse(node* &head){
    node* curr = head; 
    node* prev = NULL;

    node* n;


    while(curr != NULL){
        n = curr->next;
        curr->next = prev; 
        prev = curr;

        curr = n;
    
    }

    head = prev;
    
}

node* merge(node* &h1, node* &h2){
    // base case


    // if(h1 == NULL and h2 == NULL){
    //     return NULL;
    // }
    // if(h1 != NULL and h2 == NULL){ // L2 does not exists
    //     return h1;
    // }
    // if(h1 == NULL and h2 != NULL){ // L1 does not exists
    //     return h2;
    // }

    if(h1 == NULL){
        return h2;
    }
    if(h2 == NULL){
        return h1;
    }

    // recursive case

    node* newHead;
    if(h1->data < h2->data){
        newHead = h1;
        newHead->next = merge(h1->next, h2); 
    }
    if(h1->data > h2->data){
        newHead = h2;
        newHead->next = merge(h1, h2->next); 
    }

    
    return newHead;
}

node* mergeSort(node* head){
    if(head == NULL or head->next == NULL){
        return head;
    }

    node* m = mid(head);
    node* l1h = head;
    node* l2h = m->next;

    m->next = NULL;

    l1h = mergeSort(l1h);
    l2h = mergeSort(l2h);

    node* finalANs = merge(l1h, l2h);

    return finalANs;
}
 
int main() {

    node* h1 = NULL;
    node* t1 = NULL;
    node* h2 = NULL;
    node* t2 = NULL;

    int N, M;
    int data;

    cin>>N;
    // cin>>M;

    for(int i = 0; i < N; i++){
        cin>>data;
        insertAtFront(h1, t1, data);
    }

    // for(int i = 0; i < M; i++){
    //     cin>>data;
    //     insertAtFront(h2, t2, data);
    // }

    // node* fans = merge(h1, h2);
    // printlinklist(fans);

    node* fans = mergeSort(h1);
    printlinklist(fans);

    return 0;
}