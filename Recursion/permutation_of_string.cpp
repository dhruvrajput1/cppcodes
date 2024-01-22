#include<iostream>
using namespace std;

void permutations(string s, int N, int index){
	// base case
	if(index == N){
		cout<<s<<endl;
		return;
	}

	// recursive case
	for(int i = index; i <= N-1; i++){
		swap(s[index], s[i]);
		permutations(s, N, index+1);
		// back tracking
		swap(s[index], s[i]);
	}
	
}

int main(){
	string s; // abc
	cin>>s;
	int N = s.size();

	permutations(s, N, 0);

}