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

void mirrorOfABinaryTree(node* root) {
    // base case
    if(root == NULL) {
        return ;
    }
    
    // recursive case
    swap(root->left, root->right);
    mirrorOfABinaryTree(root->left);
    mirrorOfABinaryTree(root->right);
}

// preorder - 8 3 1 6 4 7 10 14 13
// inorder - 1 3 4 6 7 8 10 13 14


int i = 0;
node* createTree(int* pre, int* in, int start, int end) {

    if(start > end) {
        return NULL;
    }

    int element = pre[i];
    i++;

    int k = -1;

    for(int j = start; j <= end; j++) {
        if(in[j] == element) {
            k = j; // k = 5
            break;
        }
    }

    node* root = new node(element);

    root->left = createTree(pre, in, start, k - 1);
    root->right = createTree(pre, in, k + 1, end);

    return root;

}

int main() {

    // node* root = buildTreeLevelWise();

    
    // printLevelWise(root);

    // mirrorOfABinaryTree(root);

    

    int pre[] = {8, 3, 1, 6, 4, 7, 10, 14, 13};
    int in[] = {1, 3, 4, 6, 7, 8, 10, 13, 14};

    int n = sizeof(pre)/sizeof(int);
    
    node* root = createTree(pre, in, 0, n-1);

    printLevelWise(root);

// 8 10 1 -1 -1 6 4 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
    delete root;
    root = NULL;

    return 0;
}