#include<iostream>
#include<algorithm>
using namespace std;

bool compare(int a, int b) { // this comparator will reverse the work of lower bound function
    return a <= b;
}

int main() {

    // given an amount of money, break them in coins

    int coins[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};

    int money = 169;

    int n = sizeof(coins)/sizeof(int);

    while(money > 0) {
        int lb = lower_bound(coins, coins+n, money, compare) - coins - 1;
        int m = coins[lb];
        cout<<m<<endl;
        money = money - m;
    }

    return 0;
}