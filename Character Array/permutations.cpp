#include<iostream>
using namespace std;

int length(char* arr){
    int cnt = 0;
    int i = 0;

    while(arr[i] != '\0'){
        cnt++;
        i++;
    }

    return cnt;
}

bool permutation(char* arr1, char* arr2){
    int freq1[26] = {0};
    int freq2[26] = {0};

    for(int i = 0; i < length(arr1); i++){
        int num = arr1[i] - 'a';
        freq1[num] = freq1[num] + 1;
    }

    
    for(int j = 0; j < length(arr2); j++){
        int num = arr2[j] - 'a';
        freq2[num] = freq2[num] + 1;
    }

    int flag = 0;
    
    for(int i = 0; i < 26; i++){
        if(freq1[i] != freq2[i]){
            return false;
        }
    }
    
    return true;
}

int main(){

    char arr1[100];
    char arr2[100];

    cin.getline(arr1, 100);
    cin.getline(arr2, 100);

    if(permutation(arr1, arr2)){
        cout<<"Permutations"<<endl;
    }
    else{
        cout<<"Not permutations"<<endl;
    }

    return 0;
}