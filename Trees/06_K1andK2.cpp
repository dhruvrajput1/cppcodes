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

// print in a range k1 and k2
void printInRange(node* root, int k1, int k2) {
    // base case
    if(root == NULL) {
        return ;
    }

    // recursive case
    printInRange(root->left, k1, k2);
    if(k1 <= root->data and k2 >= root->data) {
        cout<<root->data<<" ";
    }
    printInRange(root->right, k1, k2);

}

bool isBST(node* root, int min = INT_MIN, int max = INT_MAX) {
    // base case
    if(root == NULL) {
        return true;
    }

    // recursive case
    if(root->data >= min and root->data <= max and isBST(root->left, min, root->data) and isBST(root->right, root->data, max)) {
        return true;
    }

    return false;

}

int height(node* root) {
    if(root == NULL) {
        return 0;
    }

    int op1 = height(root->left);
    int op2 = height(root->right);

    return 1 + max(op1, op2);
}

bool isBalanced(node* root) {
    // base case
    if(root == NULL) {
        return true;
    }

    // recursive case
    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);

    bool diff = abs(height(root->left) - height(root->right)) <= 1;

    if(left and right and diff) {
        return true;
    }
    else {
        return false;
    }
}

pair<int, bool> isHeightBalancedd(node* root) {
    // base case
    if(root == NULL) {
        pair<int, bool> p = make_pair(0, true);
        return p;
    }

    // recursive case
    pair<int, bool> left = isHeightBalancedd(root->left);
    pair<int, bool> right = isHeightBalancedd(root->right);

    int op1 = left.first;
    int op2 = right.first;

    bool diff = abs(op1 - op2) <= 1;

    pair<int, bool> ans;
    ans.first = 1 + max(op1, op2);
    if(diff and left.second and right.second) {
        ans.second = true;
    }
    else {
        ans.second = false;
    }
}

class pairr{
public:
    int height;
    bool isBalanced;

    pairr() {
        height = 0;
        isBalanced = true;
    }
};

pairr isHeightBalanced(node* root) {

    pairr p; 
    

    // base case
    if(root == NULL) {
        return p;
    }

    // recursive case
    pairr l = isHeightBalanced(root->left);
    pairr r = isHeightBalanced(root->right);
    p.height = max(l.height, r.height) + 1;

    if(l.isBalanced == true and r.isBalanced == true and abs(l.height - r.height) <= 1) {
        p.isBalanced = true;
    }
    else {
        p.isBalanced = false;
    }
    
    return p;

}

class LinkedList{
public:
    node* head;
    node* tail;

    // LinkedList() {
    //     head = NULL;
    //     tail = NULL;
    // }
};

LinkedList BSTtoLL(node* root) {

    LinkedList l;

    // base case
    if(root == NULL) {
        l.head = NULL;
        l.tail = NULL;
        return l;
    }

    // recursive case
    // case 1 - no child exists
    if(root->left == NULL and root->right == NULL) {
        l.head = root;
        l.tail = root;
        return l;
    }

    // case 2 - only LST exists
    else if(root->left != NULL and root->right == NULL) {
        LinkedList x = BSTtoLL(root->left);
        x.tail->right = root;
        l.head = x.head;
        l.tail = root;

        return l;

    }

    // case 3 - only RST exists
    else if(root->left == NULL and root->right != NULL) {
        LinkedList y = BSTtoLL(root->right);
        root->right = y.head;
        l.head = root;
        l.tail = y.tail;

        return l;
        
    }

    // case 4- both LST and RST exists
    else {
        LinkedList x = BSTtoLL(root->left);
        LinkedList y = BSTtoLL(root->right);

        x.tail->right = root;
        root->right = y.head;

        l.head = x.head;
        l.tail = y.tail;

        return l;
    }
}

void printLL(node* head) {

    while(head != NULL) {
        cout<<head->data<<" ";
        head = head->right ;
    }
    cout<<endl;
}

int main() {

    
    node* root = buildBST();

    printInRange(root, 7, 13);
    cout<<endl;

    // if(isBST(root)) {
    //     cout<<"True"<<endl;
    // }
    // else {
    //     cout<<"False"<<endl;
    // }

    // pairr x = isHeightBalanced(root);

    // if(x.isBalanced) {
    //     cout<<"Balanced"<<endl;
    // }
    // else {
    //     cout<<"Not balanced"<<endl;
    // }

    // LinkedList l = BSTtoLL(root);

    // printLL(l.head);

    // printLevelWise(root);


// 8 10 1 -1 -1 6 4 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
    delete root;
    root = NULL;

    return 0;
}