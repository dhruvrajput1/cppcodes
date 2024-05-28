#include<iostream>
#include<vector>
using namespace std;

int main() {

    int n = 10; // print all the prime number less than or equal to 10

    vector<bool> isPrime(n+1, true);

    for(int i = 2; i*i <= n; i++) {

        if(isPrime[i] == true) {
            // Update all multiples of p greater than or
            // equal to the square of it numbers which are
            // multiple of p and are less than p^2 are
            // already been marked.
            for (int j = i*i; j <= n; j += i)
                isPrime[j] = false;
        }
    }

    // printing all the prime numbers
    cout<<"Prime numbers less than or equal to 10 are:"<<endl;
    for(int i = 2; i <= n; i++) {
        if(isPrime[i]) {
            cout<<i<<" ";
        }
    }



    return 0;
}