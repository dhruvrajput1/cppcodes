#include<iostream>
using namespace std;

int length(char* ch){
	int count = 0;
	for(int i = 0; ch[i] != '\0'; i++){
		count++;
	}
	return count;

}

void append(char* ar1, char* ar2){
	int i = 0;
	int j = length(ar1);
	while(i <length(ar2)){
		ar1[j] = ar2[i];
		i++;
		j++;
	}
	cout<<"arr1 is : "<<ar1<<endl;
	cout<<"arr2 is : "<<ar2<<endl;
}

int main(){
	// Write a function which takes two strings A and B and appends B to A.

	char arr1[100];
	char arr2[100];
	cin.getline(arr1, 100);
	cin.getline(arr2, 100);
	
	append(arr1, arr2);

	

 
return 0;
}