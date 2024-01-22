#include<iostream>
#include<climits>
using namespace std;
int main(){
    int N; cin>>N;
    cin.ignore();

    string s;
    string output;

    int large = INT_MIN;

    for(int i = 0; i < N; i++){
        cin>>s;
        int n = s.size();
        if(n > large){
            large = n;
            output = s;
        }
        
    }
    cout<<output;
}