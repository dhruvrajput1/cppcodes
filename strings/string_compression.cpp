#include<iostream>
using namespace std;

void stringCompression(string s, int N){

    for(int i = 0; i < N; i++){

        int count = 1;
        
        while(i < N-1 and s[i] == s[i+1]){
            count++;
            i = i+1;
        }

        cout<<s[i]<<count;
    }

}

int main(){

    string s;
    cin>>s;
    int N = s.size();

    stringCompression(s, N);

    return 0;
}