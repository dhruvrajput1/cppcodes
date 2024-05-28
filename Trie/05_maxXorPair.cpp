#include<iostream>
#include<vector>
using namespace std;

class TrieNode {
public:
    TrieNode* left; // for 0
    TrieNode* right; // for 1

    TrieNode() {
        left = NULL;
        right = NULL;
    }

};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    // insertion
    void insert(int n) { // we will store the number in form of bits

        TrieNode* temp = root;

        for(int i = 31; i >= 0; i--) {
            int bit = (n>>i)&1;

            if(bit == 0) {
                if(temp->left == NULL) {
                    temp->left = new TrieNode();
                }
                temp = temp->left;
            }
            else {
                if(temp->right == NULL) {
                    temp->right = new TrieNode();
                }
                temp = temp->right;
            }
        }

    }

    // helper function to find the max xor till now
    int maxXorhelper(int value) {
        int currentAnswer = 0;

        TrieNode* temp = root;

        for(int i = 31; i >= 0; i--) {
            int bit = (value>>i)&1;

            if(bit == 0) { // we have to look for 1 bit(right)
                if(temp->right != NULL) {
                    temp = temp->right;
                    currentAnswer += (1<<i);
                }
                else {
                    temp = temp->left;
                }
            }
            else { // current bit is 1
            // we have to look for 0 bit(left)

                if(temp->left != NULL) {
                    temp = temp->left;
                    currentAnswer += (1<<i);
                }
                else {
                    temp = temp->right;
                }
            }
        }

        return currentAnswer;
    }

    int maxXor(vector<int> &nums) {

        int ans = 0;

        for(int i = 0; i < nums.size(); i++) {
            int val = nums[i];
            insert(val); // inserting to trie
            int currentXor = maxXorhelper(val);
            ans = max(ans, currentXor);
        }

        return ans;
    }


};

int main() {

    vector<int> nums {3, 10, 5, 25, 2, 8};

    Trie t;

    cout<<t.maxXor(nums);


    return 0;
}