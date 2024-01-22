#include<iostream>
using namespace std;

int gcd(int a, int b) {

	int ans;

	for(int i = max(a, b); i >= 1; i--) {
		if(a%i == 0 and b%i == 0) {
			ans = i;
			break;
		}
	}

	return ans;
}

int findGcd(int* arr, int n) {
	int result = arr[0];

	for(int i = 1; i < n; i++) {
		result = gcd(arr[i], result);
		if(result == 1) {
			return 1;
		}
	}

	return result;
}

int main() {

	int n; cin>>n;

	int arr[n];

	for(int i = 0; i < n; i++) {
		cin>>arr[i];
	}

	cout<<findGcd(arr, n)<<endl;

	return 0;
}