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

node* binaryTree() {

    int data;
    cin>>data;

    if(data == -1) {
        return NULL;
    }
    else {
        node* root = new node(data);
        root->left = binaryTree();
        root->right = binaryTree();

        return root;
    }
}

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

    // =loop
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

void rightView(node* root, int level, int &maxLevel) {
    // base case
    if(root == NULL) {
        return ;
    }

    // recursive case

    if(level > maxLevel) { // if we discover a new level
        cout<<root->data<<" ";
        maxLevel = level;
    }

    rightView(root->right, level + 1, maxLevel);
    rightView(root->left, level + 1, maxLevel);
}

int main() {

    node* root = buildTreeLevelWise();

    
    printLevelWise(root);

    int maxLevel = -1;

    rightView(root, 0, maxLevel);
    


// 8 10 1 -1 -1 6 4 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
    delete root;
    root = NULL;

    return 0;
}