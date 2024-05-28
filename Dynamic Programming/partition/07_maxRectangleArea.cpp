#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> nextSmaller(vector<int> heights) {
        int n = heights.size();

        vector<int> ans(n);

        stack<int> s;
        s.push(-1);

        for(int i = n-1; i >= 0; i--) {
            int curr = heights[i];

            while(s.top() != -1 and heights[s.top()] >= curr) {
                s.pop();
            }   

            ans[i] = s.top();

            s.push(i);
        }

        return ans;
    }

    vector<int> prevSmaller(vector<int> height) {
        stack<int> s;

        s.push(-1);

        int n = height.size();

        vector<int> ans(n);

        for (int i = 0; i < n; i++)
        {
            int curr = height[i];

            while (s.top() != -1 and height[s.top()] >= curr)
            {
                s.pop();
            }

            ans[i] = s.top();

            s.push(i);
        }

        return ans;
    }
int maxHistogramArea(vector<int>& height) {

    int n = height.size();

    vector<int> next(n);
    next = nextSmaller(height);

    vector<int> prev(n);
    prev = prevSmaller(height);

    int maxArea = -1e9;

    for (int i = 0; i < n; i++)
    {
        int l = height[i];

        if (next[i] == -1)
        {
            next[i] = n;
        }

        int b = next[i] - prev[i] - 1;

        int area = l * b;

        maxArea = max(area, maxArea);
    }

    return maxArea;
}

int main() {

    vector<vector<int>> grid {
        {1, 0, 1, 0, 0},
        {1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 0, 0, 1, 0}
    };

    int m = grid.size();
    int n = grid[0].size();

    int maxArea = 0;

    vector<int> height(n, 0);

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == 1) {
                height[j]++;
            }
            else {
                height[j] = 0;
            }
        }
        int area = maxHistogramArea(height);
        maxArea = max(maxArea, area);
    }

    cout << maxArea << endl;

    return 0;
}