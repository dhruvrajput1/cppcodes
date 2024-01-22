#include<iostream>
using namespace std;

void sortUsingBubbleSort(int* arr, int N, int i, int j){
	
	if(i == N-1){
		return;
	}
	if(j == N-2-i){
		sortUsingBubbleSort(arr, N, i+1, 0);
	}
	else{
		for(int j = 0; j <= N-2-i; j++){
			if(arr[j] > arr[j+1]){
				swap(arr[j], arr[j+1]);
			}
		}
		sortUsingBubbleSort(arr, N, i, j+1);
	}
	
}

int main(){
	// sort an array using bubble sort algorithm using recursion;
	
	int N;
	cin>>N;
	int arr[N];
	for(int i = 0; i <= N-1; i++){
		cin>>arr[i];
	}
	sortUsingBubbleSort(arr, N, 0, 0);

	for(int i = 0; i <= N-1; i++){
		cout<<arr[i]<<" ";
	}

}