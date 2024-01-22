#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> ans;

void makeSubset(vector<int> &A, int sum, vector<int> &output, int i, int k){
    // base case
    if(i == A.size()){
        if(sum == k){
            ans.push_back(output);
        }
        return;
    }


    //recursive case

    // include
    output.push_back(A[i]);
    makeSubset(A, sum + A[i], output, i+1, k);
    output.pop_back();


    // exclude
    makeSubset(A, sum, output, i+1, k);
}

bool comp(vector<int> &a, vector<int> &b){

    return a.size() <= b.size();
}

int main(){
    int N;
    cin>>N;

    vector<int> A(N);
    for(int i = 0; i < N; i++){
        cin>>A[i];
    }

    int k; 
    cin>>k;

    vector<int> output;


    makeSubset(A, 0, output, 0, k);

    sort(ans.begin(), ans.end(), comp);


    for(int i = 0; i < ans.size(); i++){
        for(int j = ans[i].size()-1; j >= 0; j--){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

}