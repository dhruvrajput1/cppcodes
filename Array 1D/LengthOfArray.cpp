#include<iostream>
using namespace std;

int length(char *ch){
    int count = 0;
    for (int i = 0; ch[i] != '\0'; i++){
        count++;
    }
    
    return count;

}

int main(){
    
   // write a prgoram to calculate the length of character array;
    char arr[100];
    cin.getline(arr, 100);

    cout<<"Length of array is: "<<length(arr)<<endl;


return 0;
}