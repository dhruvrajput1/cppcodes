#include<iostream>
using namespace std;

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

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
        int index = word[0] - 'a';

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
    
    void printSuggestions(TrieNode* curr, vector<string> &temp, string prefix) {
        // base case
        if(curr->isTerminal) {
            temp.push_back(prefix);
        }
        
        // recursive case
        // search for all characters if they are present or not
        
        for(char ch = 'a'; ch <= 'z'; ch++) {
            
            TrieNode* next = curr->children[ch - 'a'];
            
            if(next != NULL) {
                prefix.push_back(ch);
                printSuggestions(next, temp, prefix);
                prefix.pop_back();
            }
            
        }
    }
    
    vector<vector<string>> getSuggestions(string str) {
        TrieNode* prev = root;
        
        vector<vector<string>> output;
        
        string prefix = "";
        
        for(int i = 0; i < str.size(); i++) {
            char lastCh = str[i];
            
            prefix.push_back(lastCh);
            
            // search for lastCh
            TrieNode* curr = prev->children[lastCh - 'a'];
            
            // if not found
            if(curr == NULL) {
                break;
            }
            
            // if found
            
            vector<string> temp;
            
            printSuggestions(curr, temp, prefix); // temp will store all the suggestions 
            
            output.push_back(temp);
            temp.clear();
            prev = curr;
        }
        
        return output;
    }

};


    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        Trie t; // create a trie
        
        // insert all the string in trie
        
        for(int i = 0; i < n; i++) {
            t.insertWord(contact[i]);
        }
        
        return t.getSuggestions(s);
    }




int main() {

    int n = 3;
    string contact[] = {"geeikistest", "geeksforgeeks", "geeksfortest"};
    string s = "geeips";

    vector<vector<string>> ans = displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }


    return 0;
}