#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right; 

    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

node* buildTree() {
    
    int data;
    cin>>data; // 8 3 1 -1 -1 6 4 -1 -1 7 -1 -1 10 -1 14 13 -1 -1 -1

    if(data == -1){
        return NULL;
    }
    else{
        node* root = new node(data);

        root-> left = buildTree(); // left sub tree
        root-> right = buildTree(); // right sub tree

        return root;
    }
    

} 


int main() {

    node* root = buildTree();

    return 0;
}