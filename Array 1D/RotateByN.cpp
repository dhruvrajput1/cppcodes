#include<iostream>
using namespace std;

// Rotate a string by N;

int length(char* str){
    int count = 0;
    for(int i = 0; str[i] != '\0'; i++){
        count = count +1;
    }
    return count;
}

void rotateByN(char *str,int N ){
    int k = length(str);
    for(int i = k; i >= 0; i--){
        str[k + N] = str[k -1];
    }
    int j = 0;
    for(int count = 0; count <= N; count++){
        str[j] = str[k];
        j++;
        k++;
    }
    str[k] = '\0';
    cout<<str<<endl;
}

int main(){
    char str[100];
    cin.getline(str, 100);
    int N;
    cin>>N;

    length(str);
    rotateByN(str, N);
 
return 0;
}