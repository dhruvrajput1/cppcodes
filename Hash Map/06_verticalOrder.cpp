#include<iostream>
#include<map>
#include<queue>
#include<vector>
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

void verticalOrderPrint(node* root, int d, map<int, vector<int>>& m) {
    // base case
    if(root == NULL) {
        return ;
    }

    // recursive case
    m[d].push_back(root->data);
    verticalOrderPrint(root->left, d-1, m);
    verticalOrderPrint(root->right, d + 1, m);


}

int main() {

    node* root = buildTreeLevelWise();

    map<int, vector<int>> m; // because we want keys to be sorted, that's why we used map
    int d = 0;

    verticalOrderPrint(root, d, m);

    for(auto p : m) {
        for(auto x: p.second) { // p.second is a vector
            cout<<x<<" ";
        }
        cout<<endl;
    }

    return 0;
}