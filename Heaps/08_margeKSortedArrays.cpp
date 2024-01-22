#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class node {
public:
    int data;
    int i;
    int j;

    node(int data, int row, int col) {
        this->data = data;
        i = row;
        j = col;
    }
};


class compare {
public:
    bool operator() (node* a, node* b) {
        return a->data > b->data;
    }

};

vector<int> mergeKSortedArrays(vector<vector<int>> kArrays, int k) {

    priority_queue<node*, vector<node*>, compare> minHeap;

    // step 1 : insert first element of each array into heap

    for(int i = 0; i < k; i++) {
        node* temp = new node(kArrays[i][0], i, 0);
        minHeap.push(temp);
    }

    vector<int> ans;

    while(minHeap.size() > 0) {
        node* temp = minHeap.top();
        ans.push_back(temp->data);
        minHeap.pop();

        int i = temp->i;
        int j = temp->j;

        if(j + 1 < kArrays[i].size()) {
            node* next = new node(kArrays[i][j+1], i, j + 1);
            minHeap.push(next);
        }
    }

    return ans;

}

int main() {

    vector<int> arr1{1, 3, 5, 7, 9};
    vector<int> arr2{2, 4, 6, 8};

    vector<vector<int>> kArrays;

    kArrays.push_back(arr1);
    kArrays.push_back(arr2);

   vector<int> ans = mergeKSortedArrays(kArrays, 2);

   for(int i = 0; i < ans.size(); i++) {
    cout<<ans[i]<<" ";
   }

    return 0;
}