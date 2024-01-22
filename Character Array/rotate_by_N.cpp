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

void rotateByN(char* arr, int N){

    int k = length(arr);
    int l = length(arr);

    for(int j = k; j >= 0; j--){
        arr[j+N] = arr[j];
    }

    for(int i = 0; i < N; i++){
        arr[i] = arr[k];
        k++;
    }

    arr[l] = '\0';

    cout<<arr<<endl;
}

int main(){

    int N;

    char arr[100];
    cin.getline(arr, 100); // hello
    cin>>N;

    rotateByN(arr, N);


    return 0;
}