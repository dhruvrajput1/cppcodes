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

void mid(node* head){
    node* fast = head;
    node* slow = head;

    while(fast != NULL and fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }

    cout<<slow->data<<endl;
}

// void mid(node* head){
//     node* fast = head->next; // agar hume even wale me N/2 wala element chahiye
//     node* slow = head;

//     while(fast != NULL and fast->next != NULL){
//         fast = fast->next->next;
//         slow = slow->next;
//     }

//     cout<<slow->data<<endl;
// }

void reverse(node* &head){
    node* curr = head; 
    node* prev = NULL;

    node* n;


    while(curr != NULL){
        // save the next node
        n = curr->next;

        // make the current node point to previous
        curr->next = prev; 

        // update previous and current
        prev = curr;
        curr = n;
    
    }

    head = prev;
    
}
 
int main(){

    
    node*head = NULL;
    node*tail = NULL;

    insertAtFront(head, tail, 90);
    insertAtFront(head, tail, 63);
    insertAtFront(head, tail, 20);
    insertAtFront(head, tail, 19);
    insertAtFront(head, tail, 59);
    insertAtFront(head, tail, 79);

    printlinklist(head);
    reverse(head); 

    printlinklist(head);

    // if(searchRec(head, 20)){
    //     cout<<"Yes Key is present"<<endl;
    // }
    // else{
    //     cout<<"Key is not present"<<endl;
    // }

    mid(head);


    return 0;
}