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

class Pair {
public:
    int branchSum;
    int maxSum;

    Pair() {
        branchSum = 0;
        maxSum = 0;
    }
};

Pair maxSumPath(node* root) {

    Pair p;

    if(root == NULL) {
        return p;
    }

    Pair left = maxSumPath(root->left);
    Pair right = maxSumPath(root->right);

    // construct 2 values
    int op1 = root->data;
    int op2 = left.branchSum + root->data;
    int op3 = right.branchSum + root->data;
    int op4 = left.branchSum + right.branchSum + root->data;

    int currAnsThroughRoot = max(op1, max(op2, max(op3, op4)));

    // branch sum of the current root 
    
    p.branchSum = max(left.branchSum, max(right.branchSum, 0)) + root->data;
    p.maxSum = max(left.maxSum, max(right.maxSum, currAnsThroughRoot));

    return p;

}


int main() {

    node* root = buildTreeLevelWise();

    cout<<maxSumPath(root).maxSum;

    delete root;
    root = NULL;

    return 0;
}