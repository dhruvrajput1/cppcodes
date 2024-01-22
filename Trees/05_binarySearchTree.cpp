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

node* insertInBST(int data, node* root) {

    if(root == NULL) {
        root = new node(data);
        return root;
    }
    
    if(data <= root->data) {
        root->left = insertInBST(data, root->left);
        return root;
    }
    else {
        root->right = insertInBST(data, root->right);
        return root;
    }

}

node* buildBST() {
    node* root = NULL;

    int data;
    cin>>data;


    // loop
    while(data != -1) {
        root = insertInBST(data, root);

        cin>>data;
    }

    return root;
    
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

bool searchInBST(node* root, int key) {
    // base case
    if(root == NULL) {
        return false;
    }

    // recursive case
    if(key == root->data) {
        return true;
    }
    else if(key <= root->data) {
        return searchInBST(root->left, key);
    }
    else {
        return searchInBST(root->right, key);
    }
    
}

int main() {

    
    node* root = buildBST();

    printLevelWise(root);

    if(searchInBST(root, 7)) {
        cout<<"Key is present"<<endl;
    }
    else {
        cout<<"Key not present"<<endl;
    }


// 8 10 1 -1 -1 6 4 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
    delete root;
    root = NULL;

    return 0;
}