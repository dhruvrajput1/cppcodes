#include<iostream>
#include<queue>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

void printLevelWise(node* root) {
    // take a queue of node* type
    queue<node*> q;

    // push root node
    q.push(root);

    // push null
    q.push(NULL);

    while(!q.empty()) {
        node* x = q.front();
        q.pop();

        // if(x is NULL)
        if(x == NULL) {
            cout<<endl;

            if(!q.empty()) { // agar empty ke bad bhi null push kr diya to infinite loop chal jayega
                q.push(NULL);
            }    
        }

        // if x is not NULL
        else {
            cout<<x->data<<" ";
            if(x->left != NULL) { // left child exist karta hai
                q.push(x->left);
            }
            if(x->right != NULL) {
                q.push(x->right);
            }
        }
    }    
}

node* buildTreeLevelWise() {

    node* root = NULL;

    int data;
    cin>>data;

    if(data == -1) {
        return NULL;
    }

    root = new node(data);

    queue<node*> q;

    q.push(root);

    // loop
    while(!q.empty()) {

        node* x =q.front();
        q.pop();

        cout<<"Enter children of "<<x->data<<endl;
        int leftChild, rightChild;
        cin>>leftChild>>rightChild;

        if(leftChild != -1) {
            x->left = new node(leftChild);
            q.push(x->left);
        }

        if(rightChild != -1) {
            x->right = new node(rightChild);
            q.push(x->right);
        }
    } 
    
    return root;

}

void printAtLevelK(node* root, int k) {
    // base case
    if(root == NULL) {
        return ;
    }
    
    // recursive case
    if(k == 0) {
        cout<<root->data<<" ";
        return ;
    }
    
    printAtLevelK(root->left, k - 1);
    printAtLevelK(root->right, k - 1);
}

int printAtDistanceK(node* root, node* target, int k) {
    // base case
    if(root == NULL) {
        return -1;
    }

    // if we reach the target node
    if(root == target) {
        printAtLevelK(target, k);
        return 0;
    }

    // next step - ancestor
    int DL = printAtDistanceK(root->left, target, k);

    if(DL != -1) {
        // there are 2 cases
        // either print ancestor itself or go to RST

        if(DL + 1 == k) { // print the ancestor
            cout<<root->data<<" ";
        }
        else {
            printAtLevelK(root->right, k - 2 - DL);
        }

        return 1 + DL;
    }

    int DR = printAtDistanceK(root->right, target, k);

    if(DR != -1) {
        if(DR + 1 == k) {
            cout<<root->data<<" ";
        }
        else {
            printAtLevelK(root->left, k - 2 - DR);
        }

        return 1 + DR;
    }

    return -1; // target node was not present in RST and LST
}


int main() {

    node* root = buildTreeLevelWise();

    node* target = root->left->left; // 4

    printAtDistanceK(root, target, 2);

    
    delete root;
    root = NULL;

    return 0;
}