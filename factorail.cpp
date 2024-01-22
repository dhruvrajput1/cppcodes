#include<iostream>
using namespace std;

void multiply(int fact[], int x, int &idx) {

    int carry = 0;

    for(int i = 0; i <= idx; i++) {
        int val = fact[i]*x + carry;
        fact[i] = val%10;
        carry = val/10;
    }

    // after all this, we might still have some carry left

    while(carry > 0) {
        idx++;

        fact[idx] = carry%10;
        carry = carry/10;
    }

}

int main() {

    int n; cin>>n;

    int fact[2000] = {0};

    fact[0] = 1;

    int idx = 0;

    for(int i = 1; i <= n; i++) {
        multiply(fact, i, idx);
    }

    for(int i = idx; i >= 0; i--) cout<<fact[i];

    cout<<endl;

    return 0;
}