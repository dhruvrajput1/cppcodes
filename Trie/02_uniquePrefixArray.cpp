#include<iostream>
using namespace std;

class node {
public:

    int freq;
    node* child[26];

    node() {
        freq = 0;
        for(int i = 0; i < 26; i++) {
            child[i] = NULL;
        }
    }

};

void buildTrie(string s, node* root) {

    node* temp = root;

    for(int i = 0; i < s.size(); i++) {

        int index = s[i] - 'a';
        if(temp->child[index] == NULL) {
            temp->child[index] = new node();

        }

        temp->child[index]->freq++;
        temp = temp->child[index];

    }

}

string buildPrefix(string s, node* root) {

    node* temp = root;

    string ans = "";

    for(int i = 0; i < s.size(); i++) {

        int index = s[i] - 'a';

        if(temp->freq == 1) {
            break;
        }

        ans += s[i];

        temp = temp->child[index];


    }

    return ans;
}

int main() {

    string arr[] = {"cobra", "dog", "dove", "duck"};
    int n = 4;

    node* root = new node();

    for(int i = 0; i < n; i++) {
        buildTrie(arr[i], root);
    }

    for(int i = 0; i < n; i++) {
        cout<<buildPrefix(arr[i], root)<<endl;
    }

    return 0; 
}