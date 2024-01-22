// 1st approach-----------------------------------------------------------------------------------------------------------------------------
#include<iostream>
using namespace std;

int length(char* ch){
    int count = 0;
    for(int i = 0; ch[i] != '\0'; i++){
        count++;
    }
    return count;
}

bool isPalindrome(char* ar){
    int i = 0;
    int j = length(ar)-1;
    while (i <j){
        if(ar[i] != ar[j]){
        return false;
        }
        i++;
        j--;
    }
    

    return true;
}

int main(){

    // write a program to find whehter the string is palindromic or not;
    char arr[100];
    cin.getline(arr, 100);
    length(arr);
    
    if (isPalindrome(arr)){
        cout<<"Palindrome"<<endl;
    }
    else{
        cout<<"Not palindrome"<<endl;
    }

return 0;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------


// 2nd approach ---------------------------------------------------------------------------------------------------------------------------------------------
#include<iostream>
using namespace std;

bool isPalindrome(string s, int N){
	int i = 0;
	int j = N-1;
    int flag = 0;
	while(i < j){
		if(s[i] != s[j]){
			flag = 1;
		}
		
		i++;
		j--;
	}
	
    if(flag == 1){
        return false;
    }
    else{
        return true;
    }
}

int main() {
	string s;
	cin>>s;
	int N = s.size();
	if(isPalindrome(s, N)){
		cout<<"true"<<endl;
	}
	else{
		cout<<"false"<<endl;
	}
	return 0;
}