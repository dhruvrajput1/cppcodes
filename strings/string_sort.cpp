#include<iostream>
#include<algorithm>
using namespace std;

bool myCompare(string s1, string s2){ // bat batman

    int N1 = s1.size();
    int N2 = s2.size();

    if(N1 <= N2 and s2.substr(0, N1) == s1){
        return false;
    }

    if(N1 >= N2 and s1.substr(0, N2) == s2){
        return true;
    }
    
    else{
        if(s1 < s2){ // apple bat  because s1 later wali string ko leta hai
            return true;
        }
        else{
            return false;
        } 
    }
}

int main(){

    string arr[1000];
    int N; cin>>N;
    cin.ignore();


    

    for(int i = 0; i < N; i++){
        cin>>arr[i];
    }

    sort(arr, arr+N, myCompare);

    for(int i = 0; i < N; i++){
        cout<<arr[i]<<" ";
    }

 
    return 0;
}