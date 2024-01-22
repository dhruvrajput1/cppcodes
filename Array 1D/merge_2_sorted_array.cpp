#include<iostream>
using namespace std;

void mergeTwoSortedArrays(int arr1[], int arr2[], int m, int n){
    int temp[1000];
    int i = 0; int j = 0; int k = 0;

    while(i < m and j < n){
        if(arr1[i] < arr2[j]){
            temp[k] = arr1[i];
            k++;
            i++;
        }
        else{
            temp[k] = arr2[j]; 
            j++;
            k++; 
        }
    }
    while (i < m){
        temp[k] = arr1[i];
        i++;
        k++;
    }
    while(j < n){
        temp[k] = arr2[j];
        j++;
        k++;
    }    

    for(int i = 0; i <= k-1; i++){
        cout<<temp[i]<<" ";
    }
    cout<<endl;
}

int main(){

    int arr1[] = {1, 3, 5, 7, 9};
    int arr2[] = {2, 4, 6, 8, 10};
    int m = 5;
    int n = 5;

    mergeTwoSortedArrays(arr1, arr2, m, n);

    
    return 0;
}