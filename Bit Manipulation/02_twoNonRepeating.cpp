#include<iostream>
#include<vector>
using namespace std;

int main() {

    vector<int> nums {5, 4, 1, 4, 3, 5, 1, 2};

    int n = nums.size();

    int num1 = 0;
    int num2 = 0; // numbers we want to find

    int res = 0;

    for(int i = 0; i < n; i++) {
        res = res^nums[i];
    }

    cout<<res<<endl;


    // get the rightmost bit in res
    int setBitNo = res & (-res); // (-res) is 2's complement

    cout<<setBitNo<<endl;


    // dividing into two sets
    for(int i = 0; i < n; i++) {
        // xor of first set
        if(nums[i] & setBitNo) {
            num1 = num1^nums[i];
        }
        // xor of second set
        else {
            num2 = num2^nums[i];
        }
    }

    cout<<num1<<" "<<num2<<endl;


    return 0;
}