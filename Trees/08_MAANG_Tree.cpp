#include<iostream>
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

void zigZagTraversal(node* root) {

    vector<int> result;

    queue<node*> q;
    q.push(root);

    bool leftToRight = true;

    while(!q.empty()) {
        int size = q.size();

        vector<int> ans(size);

        // level process
        for(int i = 0; i < size; i++) {

            node* x = q.front();
            q.pop();

            // normal insert or reverse insert
            int index = leftToRight ? i : size - i - 1;
            ans[index] = x->data;

            if(x->left != NULL) {
                q.push(x->left);
            }
            if(x->right != NULL) {
                q.push(x->right);
            }

        }
        leftToRight = !leftToRight; // changing the direction

        for(auto i : ans) {
            result.push_back(i);
        }
    }

    for(int i = 0; i < result.size(); i++) {
        cout<<result[i]<<" ";
    }

}

void leftTraversal(node* root, vector<int> &ans) {
    if(root == NULL) {
        return ;
    }

    if(root->left == NULL and root->right == NULL) { // leaf node
        return ;
    }

    ans.push_back(root->data);

    leftTraversal(root->left, ans);
    
    leftTraversal(root->right, ans);
    
}

void traverseLeaf(node* root, vector<int> &ans) {
    if(root == NULL) {
        return ;
    }

    if(root->left == NULL and root->right == NULL) {
        ans.push_back(root->data);
    }

    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
}

void rightTraversal(node* root, vector<int> &ans) {
    // base case
    if(root == NULL) {
        return ;
    }
    if(root->right == NULL and root->left == NULL) { // because leaf node alag se include kar rakhi hai
        return ;
    }

    rightTraversal(root->right, ans);
    rightTraversal(root->left, ans); // agar right me sare nodes khatam ho gye to left pe jayenge

    ans.push_back(root->data); /// wapas aate wakt print karana hai
}

void boundaryTraversal(node* root) {
    vector<int> ans;
    // base case
    if(root == NULL) {
        return ;
    }

    ans.push_back(root->data);

    // left part store
    leftTraversal(root->left, ans);

    // leaf nodes store 
    // in LST
    traverseLeaf(root->left, ans);
    // in RST
    traverseLeaf(root->right, ans);

    // right part store
    rightTraversal(root->right, ans);

    for(int i = 0; i < ans.size(); i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

int replaceSum(node* root) {
    if(root == NULL) {
        return 0;
    }

    if(root->left == NULL and root->right == NULL) {
        return root->data;
    }

    int leftSum = replaceSum(root->left);
    int rightSum = replaceSum(root->right);

    int temp = root->data;
    root->data = leftSum + rightSum;

    return root->data + temp;

}


int main() {

    node* root = buildTreeLevelWise();

    
    // printLevelWise(root);

    // zigZagTraversal(root);

    // boundaryTraversal(root);

    replaceSum(root);

    printLevelWise(root);
    


// 8 10 1 -1 -1 6 4 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
    delete root;
    root = NULL;

    return 0;
}