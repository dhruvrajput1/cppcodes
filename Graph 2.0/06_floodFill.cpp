#include<iostream>
#include<vector>
using namespace std;

void dfs(vector<vector<int>> &image, vector<vector<int>> &ans, int row, int col, int newColor, int initialColor) {
    ans[row][col] = newColor;

    int m = image.size();
    int n = image[0].size();

    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, 1, 0, -1};

    for(int i = 0; i <= 3; i++) {
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];

        if(nrow >= 0 and nrow < m and ncol >= 0 and ncol < n and image[nrow][ncol] == initialColor and ans[nrow][ncol] != newColor) {
            dfs(image, ans, nrow, ncol, newColor, initialColor);
        }
    }
}

int main() {

    vector<vector<int>> image {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };

    int sr = 1;
    int sc = 1;

    int newColor = 2;

    int m = image.size();
    int n = image[0].size();

    int initialColor = image[sr][sc];

    vector<vector<int>> ans = image;

    dfs(image, ans, sr, sc, newColor, initialColor);

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}