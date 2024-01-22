#include<iostream>
using namespace std;

class node {
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

// length using recursion
int lengthrec(node* head){
    // base case
    if(head == NULL){
        return 0;
    }

    // recursive case

    return 1 + lengthrec(head -> next);
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

void insertAtTail(node* &head, node* &tail, int data){

    node* n = new node(data);

    if(head == NULL){
        head = n;
        tail = n;
        return;
    }
    else{
        tail->next = n;
        tail = n;
    }
}

void insertAtAnyPoint(node* &head, node* &tail, int data, int pos){

    // case 1 pos == 0
    if(pos == 0){
        insertAtFront(head, tail, data);
    }
    else if(pos >= lengthofLL(head)){
        insertAtTail(head, tail, data);
    }
    else{
        node* temp = head;

        node* n = new node(data);

        for(int jump = 1; jump <= pos - 1; jump++){
            temp = temp -> next;
        }

        n->next = temp->next;
        temp->next = n;

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

void deleteAtFront(node* &head, node* &tail){
    // LL empty
    if(head == NULL){
        return;
    }
    
    // single node
    else if(head->next == NULL){

        delete head;
        head == NULL;
        tail == NULL;

    }
    else{
        node* temp = head;
        head = head-> next;
        delete temp;
    }
}

void deleteAtTail(node* &head, node* &tail){
    // LL empty
    if(head == NULL){
        return;
    }
    
    // single node
    else if(head->next == NULL){

        delete head;
        head == NULL;
        tail == NULL;

    }
    else{
        node*temp = head;

        while(temp -> next -> next != NULL){
            temp = temp->next;
        }
        
        delete tail;
        tail = temp;
        
        tail -> next = NULL;
    }
}

void deleteAtAnyPosition(node* &head, node* &tail, int pos){

    if(pos == 0){
        deleteAtFront(head, tail);
    }
    else if(pos >= lengthofLL(head)){
        deleteAtTail(head, tail);
    }
    else{
        node* temp = head;

        for(int jump = 0; jump < pos - 1; jump++){
            temp = temp->next;
        }

        if(temp != NULL and temp->next != NULL){
            node* nodeToDelete = temp->next;
            temp->next = temp->next->next;

            delete nodeToDelete;
        }
    }


}

bool searchIter(node* head, int key){

    while(head != NULL){
        if(head->data == key){
            return true;
        }
        head = head->next;
    }
    return false;
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
 
int main(){

    // node n1(5); // n1 will be object of type node

    // node n2(6);

    // n1.next = &n2;

    // cout<<"Data of n1 is: "<<n1.data<<" Data of n2 using n1: "<<(*n1.next).data<<endl; // n1.next will give address of n2
    
    // cout<<"Data of n1 is: "<<n1.data<<" Data of n2 using n1: "<<n1.next->data<<endl;

    node* head = NULL;
    node* tail = NULL;

    insertAtFront(head, tail, 90);
    insertAtFront(head, tail, 63);
    insertAtFront(head, tail, 20);

    insertAtTail(head, tail, 79);
    insertAtTail(head, tail, 47);

    insertAtAnyPoint(head, tail, 32, 3);
    insertAtAnyPoint(head, tail, 72, 8);

    printlinklist(head);

    deleteAtAnyPosition(head, tail, 3);

    printlinklist(head);

    // deleteAtFront(head, tail);

    // deleteAtTail(head, tail);

    // printlinklist(head);

    // if(searchRec(head, 20)){
    //     cout<<"Yes Key is present"<<endl;
    // }
    // else{
    //     cout<<"Key is not present"<<endl;
    // }


    return 0;
}