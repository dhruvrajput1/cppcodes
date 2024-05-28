#include <iostream>
#include <stack>
#include <vector>
#include <climits>
using namespace std;

vector<int> nextSmallerElement(vector<int> height, int n)
{
    stack<int> s;

    s.push(-1);

    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {
        int curr = height[i];

        while (s.top() != -1 and s.top() >= curr)
        {
            s.pop();
        }

        ans[i] = s.top();

        s.push(curr);
    }

    return ans;
}

vector<int> prevSmallerElement(vector<int> height, int n)
{
    stack<int> s;

    s.push(-1);

    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {
        int curr = height[i];

        while (s.top() != -1 and s.top() >= curr)
        {
            s.pop();
        }

        ans[i] = s.top();

        s.push(curr);
    }

    return ans;
}

int main()
{

    vector<int> height{2, 1, 5, 6, 2, 3};

    int n = height.size();

    vector<int> next(n);
    next = nextSmallerElement(height, n);

    vector<int> prev(n);
    prev = prevSmallerElement(height, n);

    int maxArea = INT_MIN;

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

    cout << maxArea << endl;

    return 0;
}