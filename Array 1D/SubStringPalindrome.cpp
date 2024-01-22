#include<iostream>
using namespace std;
int main(){

    string s;
    cin>>s;
    int N = s.size();
    int count = N;

    for(int i = 0; i <= N-1; i++){
        int k = i-1; int j = i+1;
        while (k >= 0 and j <= N-1 and s[k] == s[j]){
            count++;
            k--;
            j++;
        }

        k = i; j = i+1;
        while (k >= 0 and j <= N-1 and s[k] ==s[j]){
            count++;
            k--;
            j++;
        }
    }
    cout<<count<<endl;
 
return 0;
}