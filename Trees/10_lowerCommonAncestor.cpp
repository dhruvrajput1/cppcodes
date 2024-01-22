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


int main() {

    node* root = buildTreeLevelWise();

    node* ans = lowestCommonAncestor(root, 5, 6);

    cout<<ans->data<<endl;
    
    delete root;
    root = NULL;

    return 0;
}