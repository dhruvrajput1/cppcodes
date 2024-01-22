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


node* mid(node* head){
    node* fast = head;
    node* slow = head;

    while(fast != NULL and fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

bool isCyclic(node* head) {
    node* slow = head;
    node* fast = head;

    while(fast != NULL and fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            return true;
        }
    }
    return false;
}

void createCycle(node* &head, node* &tail){
    tail->next = head->next->next;
}

void breakCycle(node* head){
    // step 1 -> is cycle present or not
    node* slow = head;
    node* fast = head;
    node* prev;

    while(fast != NULL and fast->next != NULL){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            break;
        }
    }
    // agar loop ke bahar aaye to matlab cycle mil gya

    slow = head; 

    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
        prev = prev->next;
    }
    prev->next = NULL;

}
 
int main(){

    node* h1 = NULL;
    node* t1 = NULL;


    int N;
    int data;

    cin>>N;


    for(int i = 0; i < N; i++){
        cin>>data;
        insertAtFront(h1, t1, data); // 5 4 3 2 1
    }

    

    printlinklist(h1);

    createCycle(h1, t1);
    breakCycle(h1);

    // printlinklist(h1); // keep printing

    if(isCyclic(h1)){
        cout<<"List is cyclic"<<endl;
    }
    else{
        cout<<"List is not cyclic"<<endl;
    }

    return 0;
}