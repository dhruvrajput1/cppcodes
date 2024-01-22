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

node* lowestCommonAncestor(node* root, int a, int b) {

    if(root == NULL) {
        return NULL;
    }

    if(root->data == a or root->data == b) {
        return root;
    }

    // search in LST and RST
    node* leftAns = lowestCommonAncestor(root->left, a, b);
    node* rightAns = lowestCommonAncestor(root->right, a, b);

    if(leftAns != NULL and rightAns != NULL) {
        return root;
    }

    if(leftAns != NULL) {
        return leftAns;
    }
    return rightAns;


} 

// finding the level of given node from the root node/ any given node
int search(node* root, int key, int level) {
    if(root == NULL) {
        return -1;
    }

    if(root->data == key) {
        return level;
    }

    int left = search(root->left, key, level + 1);

    if(left != -1) {
        return left;
    }

    return search(root->right, key, level + 1);

}

// function to find dist between 2 nodes

int findDistance(node* root, int a, int b) {

    node* LCA_node = lowestCommonAncestor(root, a, b);

    int l1 = search(LCA_node, a, 0);
    int l2 = search(LCA_node, b, 0);

    return l1 + l2;
}


int main() {

    node* root = buildTreeLevelWise();

    cout<<findDistance(root, 7, 9)<<endl;
    
    
    delete root;
    root = NULL;

    return 0;
}