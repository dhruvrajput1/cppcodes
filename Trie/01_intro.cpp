#include<iostream>
using namespace std;

class TrieNode {
public:

    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch) {

        data = ch;
        for(int i = 0; i < 26; i++) {
            children[i] = NULL;
        }

        isTerminal = false;

    }

    
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, string word) {

        // base case
        if(word.length() == 0) {
            root->isTerminal = true;
            return ;
        }

        // recursive case
        // words in caps
        int index = word[0] - 'A';

        TrieNode* temp;

        if(root->children[index] != NULL) { // present

            temp = root->children[index];

        }
        else { // absent
            temp = new TrieNode(word[0]);
            root->children[index] = temp;
        }

        insertUtil(temp, word.substr(1));


    }

    void insertWord(string word) {

        insertUtil(root, word);

    }

    bool searchUtil(TrieNode* root, string word) {

        // base case
        if(word.length() == 0) {
            return root->isTerminal;
        }

        int index = word[0] - 'A';
        TrieNode* temp;

        if(root->children[index] != NULL) { // present

            temp = root->children[index];

        }
        else {
            return false;
        }

        return searchUtil(temp, word.substr(1));

    }

    bool searchWord(string word) {
        return searchUtil(root, word);
    }

};

int main() {

    Trie t;

    t.insertWord("ARM");
    t.insertWord("Do");
    t.insertWord("TIME");

    if(t.searchWord("TIME ")) {
        cout<<"Present"<<endl;
    }
    else {
        cout<<"Not Present"<<endl;
    }


    return 0;
}