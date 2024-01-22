#include<iostream>
using namespace std;

void toh(int N, char source, char helper, char destination){
    // base case
    if(N == 0){
        return;
    }

    // recursive case
    toh(N-1, source, destination, helper);
    cout<<"Move the disc "<<N<<" from "<<source<<" to "<<destination<<endl;
    toh(N-1, helper, source, destination);

}

int main(){
    int N;
    cin>>N;
    toh(N, 'A', 'B', 'C');
}