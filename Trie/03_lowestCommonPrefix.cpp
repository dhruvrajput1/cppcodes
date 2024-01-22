#include<iostream>
#include<vector>
using namespace std;


class node {
public:
    char data;
    node* children[26];
    bool isTerminal;
    int childCount;

    node(char ch) {
        data = ch;

        for(int i = 0; i < 26; i++) {
            children[i] = NULL;
        }

        isTerminal = false;
        childCount = 0;
    }

};

class Trie {
public:

    node* root;

    Trie() {
        root = new node('\0');
    }

    void insertUtil(node* root, string word) {

        // base case
        if(word.length() == 0) {
            root->isTerminal = true;
            return ;
        }

        // recursive case
        int index = word[0] - 'a';

        node* temp;

        if(root->children[index] != NULL) { // present

            temp = root->children[index];

        }
        else { // absent
            temp = new node(word[0]);
            root->childCount++;
            root->children[index] = temp;
        }

        insertUtil(temp, word.substr(1));


    }

    void insertWord(string word) {

        insertUtil(root, word);

    }

    void lcp(string str, string& ans) {

        for(int i = 0; i < str.size(); i++) {

            char ch = str[i];

            if(root->childCount == 1) {
                ans.push_back(ch);
                int index = str[i] - 'a';
                root = root->children[index];
            }
            else {
                break;
            }

            if(root->isTerminal) {
                break;
            }


        }
    }

};


string longestCommonPrefix(vector<string>& strs) {

    Trie t;

    for(int i = 0; i < strs.size(); i++) {
        if(strs[i] == "") {
            return "";
        }
        t.insertWord(strs[i]);
    }

    string first = strs[0];
    string ans = "";

    t.lcp(first, ans);

    return ans;
        
}


int main() {

    vector<string> strs{"flower", "flow", "flight"};

    string ans = longestCommonPrefix(strs);

    cout<<ans<<endl;

    return 0;
}
