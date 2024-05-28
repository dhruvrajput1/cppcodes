#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>
using namespace std;

int main() {

    string startWord = "bat";
    string targetWord = "coz";

    vector<string> wordList {"pat", "bot", "pot", "poz", "coz"};

    queue<vector<string>> q;

    unordered_set<string> s (wordList.begin(), wordList.end());

    q.push({startWord});

    vector<string> usedOnLevel;

    usedOnLevel.push_back(startWord);

    int level = 0;

    vector<vector<string>> ans;

    while(!q.empty()) {
        vector<string> vec = q.front();
        q.pop();

        // erase all the words that has been used in previous levels
        if(vec.size() > level) {
            level++;
            for(auto it : usedOnLevel) {
                s.erase(it);
            }
        }

        string word = vec.back();

        if(word == targetWord) {
            if(ans.size() == 0) {
                ans.push_back(vec);
            }
            else if(ans[0].size() == vec.size()) {
                ans.push_back(vec);
            }
        }

        for(int i = 0; i < word.size(); i++) {
            char original = word[i];
            for(char ch = 'a'; ch <= 'z'; ch++) {
                word[i] = ch;
                if(s.find(word) != s.end()) {
                    vec.push_back(word);
                    q.push(vec);
                    usedOnLevel.push_back(word);
                    vec.pop_back();
                }
            }
            word[i] = original;
        }
    }

    for(auto it : ans) {
        for(auto i : it) {
            cout<<i<<" ";
        }
        cout<<endl;
    }

    

    return 0;
}