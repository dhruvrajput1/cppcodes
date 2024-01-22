#include<iostream>
using namespace std;

int main() {

    int** arr;

    int r, c; cin>>r>>c;

    // creating an array of row heads
    arr = new int*[r];

    // creating an 2D array

    for(int i = 0; i < r; i++) {
        arr[i] = new int[c];
    }

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin>>arr[i][j];
        }
    }

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    delete [] arr;

    return 0;
}