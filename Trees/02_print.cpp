#include<iostream>
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

// preorder
void preOrder(node* root) {
    // base case
    if(root == NULL) {
        return ;
    }

    // recursive case
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

// inorder
void inOrder(node* root) {
    // base case
    if(root == NULL) {
        return ;
    }

    // recursive case
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void postOrder(node* root) {
    // baase case
    if(root == NULL) {
        return ;
    }

    // recurisve case
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

int countNodes(node* root) {
    // base case
    if(root == NULL) {
        return 0;
    }

    // recursive case
    return 1 + countNodes(root->left) + countNodes(root->right);
    
}

int height(node* root) {
    // base case
    if(root == NULL) {
        return 0;
    }

    // recursive case
    return 1 + max(height(root->left), height(root->right));

}

int sumOfNodes(node* root) {
    // base case
    if(root == NULL) {
        return 0;
    }

    // recursive case
    int leftSum = sumOfNodes(root->left);
    int rightSum = sumOfNodes(root->right);

    return rightSum + leftSum + root->data;
}

int diameter(node* root) {
    if(root == NULL) {
        return 0;
    }

    int h1 = height(root->left);
    int h2 = height(root->right);
    int opt1 = h1 + h2; // diameter passes through root node
    int opt2 = diameter(root->left);
    int opt3 = diameter(root->right);

    return max(opt1, max(opt2, opt3));
}

class pairr{
public:
    int height;
    int dia;
};

// O(N)
pairr fastDiameter(node* root) {

    pairr p;

    // bsae case
    if(root == NULL) {
        p.height = 0;
        p.dia = 0;
        return p;
    }
    
    // recursive case
    pairr L = fastDiameter(root->left);
    pairr R = fastDiameter(root->right);

    p.height = max(L.height, R.height) + 1;
    

    int opt1 = L.dia;
    int opt2 = R.dia;
    int opt3 = L.height + R.height;

    p.dia = max(opt1, max(opt2, opt3));

    return p;
}

pair<int, int> fastDiameterr(node* root) {
    // base case
    if(root == NULL) {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> left = fastDiameterr(root->left);
    pair<int, int> right = fastDiameterr(root->right);

    int op1 = left.first; // first holds diameter and second holds height
    int op2 = right.first;
    int op3 = left.second + right.second;

    pair<int, int> ans;
    ans.first = max(op1, max(op2, op3)); // diameter
    ans.second = 1 + max(left.second, right.second); // height

    return ans;

}

int main() {

    node* root = binaryTree();

    cout<<"PreOrder"<<endl;
    preOrder(root);

    cout<<endl;

    cout<<"InOrder"<<endl;
    inOrder(root);

    cout<<endl;

    cout<<"PostOrder"<<endl;
    postOrder(root);

    cout<<endl;

    cout<<"Count is: "<<countNodes(root)<<endl;
    cout<<"Height is: "<<height(root)<<endl;
    cout<<"Sum is: "<<sumOfNodes(root)<<endl;
    cout<<"Diameter is: "<<diameter(root)<<endl;

    pairr x = fastDiameter(root);
    cout<<"Fast diameter is: "<<x.dia<<endl;

    cout<<"Another fast diameter "<<fastDiameterr(root).first<<endl;
    


// 8 10 1 -1 -1 6 4 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
    delete root;
    root = NULL;

    return 0;
}