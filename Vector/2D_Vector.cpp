#include<iostream>
#include<vector>

using namespace std;

void printVector(vector<int> A){
    
    for(int i = 0; i < A.size(); i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

int main(){

    vector<int> A;

    A.push_back(2);
    A.push_back(5);
    A.push_back(3);


    printVector(A);


    vector<int> B(5);

    printVector(B);

    B.push_back(7);

    printVector(B);

    vector<vector<int>> daksh(3, vector<int>(2, 45));

    cout<<"Printing 2D Vector daksh"<<endl;

    for(int i = 0; i < daksh.size(); i++){
        for(int j = 0; j < daksh[i].size(); j++){
            cout<<daksh[i][j]<<" ";
        }
        cout<<endl;
    }

    vector<vector<vector<int>>> dev(3, vector<vector<int>>(4, vector<int>(2, 1)));

    


    return 0;
}