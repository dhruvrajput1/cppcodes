#include<iostream>
#include<climits>
using namespace std;

int profit(int* weights, int* prices, int n, int capacity) {
    // base case
    if(n == 0 or capacity == 0) {
        return 0;
    }

    // recursive case

    int include = INT_MIN;
    int exclude = INT_MIN;

    int ans = 0;

    if(weights[n-1] <= capacity) {
        include = prices[n-1] + profit(weights, prices, n - 1, capacity - weights[n-1]);
    }

    exclude = profit(weights, prices, n - 1, capacity);

    ans = max(include, exclude);

    return ans;

}

int main() {

    int weights[] = {1, 2, 3, 5};

    int prices[] = {40, 20, 30, 100};

    int n = 4;
    int capacity = 7;

    cout<<profit(weights, prices, n, capacity)<<endl;

    return 0;
}