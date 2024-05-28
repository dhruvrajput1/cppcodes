#include<iostream>
using namespace std;

class node {

public:
    int data;
    node* left;
    node* right;

    node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }

};

int count(node* root) {
    if(root == NULL) {
        return 0;
    }

    int ans = 1 + count(root->left) + count(root->right);

    return ans;
}

bool isCBT(node* root, int index, int totalCount) {

    // base case
    if(root == NULL) {
        return true;
    }

    if(index >= totalCount) {
        return false;
    }
    else {
        bool leftAns = isCBT(root->left, 2*index + 1, totalCount);
        bool rightAns = isCBT(root->right, 2*index + 2, totalCount);

        return leftAns and rightAns;
    }

}


bool isMaxOrder(node* root) {

    if(root->left == NULL and root->right == NULL) {
        return true;
    }

    if(root->right == NULL) {
        return root->data > root->left->data;
    }
    else {
        bool left = isMaxOrder(root->left);
        bool right = isMaxOrder(root->right);

        if(left and right and root->data > root->left->data and root->data > root->left->data) {
            return true;
        }
        else {
            return false;
        }
    }

}

bool isMaxOrderAnotherApproach(node* root) {

    if(root->left == NULL and root->right == NULL) {
        return true;
    }

    if(root->right == NULL) {
        return root->data > root->left->data;
    }
    else {

        if(root->data > root->left->data and root->data > root->left->data and isMaxOrderAnotherApproach(root->left) and isMaxOrderAnotherApproach(root->right)) {
            return true;
        }
        else {
            return false;
        }
    }

}

bool isBinaryTreeHeap(node* root) {
    int index = 0;
    int totalCount = count(root);

    if(isCBT(root, index, totalCount) and isMaxOrder(root)) {
        return true;
    }
    else {
        return false;
    }
}

int main() {


    return 0;
}