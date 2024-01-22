#include<iostream>
#include<queue>
#include<climits>
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

node* createBSTusingSortedArray(int* arr, int s, int e) {

    // base case
    if(s > e) {
        return NULL;
    }

    
    // recursive case
    int mid = (s + e)/2;

    node* root = new node(arr[mid]);

    root->left = createBSTusingSortedArray(arr, s, mid - 1);
    root->right = createBSTusingSortedArray(arr, mid + 1, e);

    return root;

}

node* deleteInBST(node* root, int key) {

    if(root == NULL) {
        return NULL;
    }

    // key is smaller than root->data
    else if(key < root->data) {
        root->left = deleteInBST(root->left, key);
        return root;
    }
    // key is greater than root->data
    else if(key > root->data) {
        root->right = deleteInBST(root->right, key);
        return root;
    }
    // key is equal to node
    else {
        // case 1 -- root node has no child
        if(root->left == NULL and root->right == NULL) {
            delete root;
            return NULL;
        }
        // case 2(i) -- single child exists in RST
        else if(root->left == NULL and root->right != NULL) {
            node* temp = root->right;
            delete root;
            root = temp;
        }
        // case 2(ii) -- single child exists in LST
        else if(root->left != NULL and root->right == NULL) {
            node* temp = root->left;
            delete root;
            root = temp;
        }
        // case 3 -- both right child and left child exists
        else {

            node* replace = root->right;

            while(replace->left != NULL) {
                replace = replace->left;
            }

            swap(replace->data, root->data);

            root->right = deleteInBST(root->right, key);

            return root;
        }
        
    }
    return root;
}

void rightView(node* root, int level, int &maxLevelTraversedTillNow) {
    // base case
    if(root == NULL) {
        return ;
    }


    // recursive case
    if(level > maxLevelTraversedTillNow) {
        cout<<root->data<<" ";
        maxLevelTraversedTillNow = level;
    }
    
    rightView(root->right, level + 1, maxLevelTraversedTillNow);
    rightView(root->left, level + 1, maxLevelTraversedTillNow);

}

void leftView(node* root, int level, int &maxLevelTraversedTillNow) {
    // base case
    if(root == NULL) {
        return ;
    }


    // recursive case
    if(level > maxLevelTraversedTillNow) {
        cout<<root->data<<" ";
        maxLevelTraversedTillNow = level;
    }
    
    leftView(root->left, level + 1, maxLevelTraversedTillNow);
    leftView(root->right, level + 1, maxLevelTraversedTillNow);

}



int main() {

    int arr[] = {1, 3, 4, 6, 7, 8, 10, 13, 14};

    int n = sizeof(arr)/sizeof(int);

    
    node* root = createBSTusingSortedArray(arr, 0, n - 1);

    printLevelWise(root);

    // cout<<"After deleting"<<endl;

    // root = deleteInBST(root, 4);
    // printLevelWise(root);

    int maxLevelTraversedTillNow = 0;

    // cout<<"Left View: "<<endl;
    // leftView(root, 1, maxLevelTraversedTillNow);

    // cout<<endl;

    // cout<<"Right View: "<<endl;

    // rightView(root, 1, maxLevelTraversedTillNow);


    delete root;
    root = NULL;

    return 0;
}