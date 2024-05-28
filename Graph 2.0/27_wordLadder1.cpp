#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>
using namespace std;

int main() {

    string startWord = "hit";
    string targetWord = "cog";

    vector<string> wordList {"hot", "dot", "dog", "lot", "log", "cog"};

    queue<pair<string, int>> q;

    unordered_set<string> s (wordList.begin(), wordList.end());

    q.push({startWord, 1});

    s.erase(startWord);

    while(!q.empty()) {
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();

        if(word == targetWord) {
            cout<<steps<<endl;
            return 0;
        }

        for(int i = 0; i < word.size(); i++) {
            char original = word[i];
            for(char ch = 'a'; ch <= 'z'; ch++) {
                word[i] = ch;
                if(s.find(word) != s.end()) {
                    s.erase(word);
                    q.push({word, steps+1});
                }
            }
            word[i] = original;
        }
    }


    

    return 0;
}