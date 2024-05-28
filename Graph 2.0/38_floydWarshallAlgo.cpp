#include<iostream>
#include<vector>
using namespace std;

int main() {

    vector<vector<int>> matrix {
        {0, 1, 43},
        {1, 0, 6},
        {-1, -1, 0}
    };

    int n = matrix.size();

    // converting -1 to inf
    for(int i = 0; i < n; i++) { 
        for(int j = 0; j < n; j++) {
            if(matrix[i][j] == -1) matrix[i][j] = 1e9;
        }
    }

    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }

    // converting inf to -1
    for(int i = 0; i < n; i++) { 
        for(int j = 0; j < n; j++) {
            if(matrix[i][j] == 1e9) matrix[i][j] = -1;
        }
    }

    // printing
    for(int i = 0; i < n; i++) { 
        for(int j = 0; j < n; j++) {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}