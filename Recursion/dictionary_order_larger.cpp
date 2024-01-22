#include<iostream>
#include<algorithm>
using namespace std;

string arr[1000000];
int k = 0;

void dictionaryLarge(string str, int N, int index, string key2){
	// base case
	if(index == N){
		if(str > key2){
			arr[k] = str;
			k++;
		}
		return;
	}


	// recursive case
	for(int i = index; i < N; i++){
		swap(str[index], str[i]);
		dictionaryLarge(str, N, index +1, key2);
		swap(str[index], str[i]);
	}

}

int main(){
	string key;
	cin>>key;   // abc
	int N = key.size();
    string key2=key;

    sort(key.begin(),key.end());

	dictionaryLarge(key, N, 0, key2);

    sort(arr,arr+k);
    
	for(int i = 0; i < k; i++){
		cout<<arr[i]<<endl;
	}
}