#include<iostream>
using namespace std;

float squareRoot(int n, int p) {

    int s = 0;
    int e = n;

    float ans = -1;

    while(s <= e) {
        int mid = (s+e)/2; // 25

        if(mid*mid == n) { 
            return mid;
        }

        if(mid*mid > n) {// 25*25 50 se bhot bada hai, matlab ans 25 se chota hi hoga
            e = mid - 1;
        }
        else {
            ans = mid;
            s = mid + 1;
        }
    }

    // if we want correct answer in decimal

    float inc = 0.1;

    for(int times = 1; times <= p; times++) { // p represent upto what decimal place

        while(ans*ans <= n) {
            ans = ans + inc;
        }
        ans = ans - inc;
        inc = inc/10;

    }

    return ans;

}

int main() {

    int n; cin>>n; // 50

    cout<<squareRoot(n, 3)<<endl;

    return 0;
}