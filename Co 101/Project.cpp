#include<algorithm>
#include<iostream>
#include<string>
#include<sstream>
#include<vector>

using namespace std;

vector<string>Morse {".-", "-...", "-.-.", "-..",".", "..-.", "--.", "....", "..", ".---",
                   "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
                   "..-", "...-", ".--", "-..-", "-.--", "--..", ".----", "..---", "...--",
                   "....-", ".....", "-....", "--...", "---..", "----.", "-----", ".-.-.-",
                   "--..--", "..--..","/"};
vector<string>Letter {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J",
                    "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T",
                    "U", "V", "W", "X", "Y", "Z", "1", "2", "3", "4",
                    "5", "6", "7", "8", "9", "0", "Stop", ",", "?"," "};

int main()
{
    int a;
    cout<<"Welcome to program, press 1 to continue"<<endl;
    cin>>a;
    if(a != 1){
        return 0;
    }
    int b;
    cout<<"What would you like to choose"<<endl;
    cout<<"Press 1 for decrypting Morse code"<<endl;
    cout<<"Press 2 for encrypting Morse Code"<<endl;
    cout<<"Press 3 for creating your own language"<<endl;
    cin>>b;

    if(b == 1){
        string morse_code;

    cout << "Enter a Coded Morse Message (e.g. .- -... -.-.) \n";
    cout << "\nSeparate Morse Code by blanks:\n";
    getline(cin,morse_code);
    cout << "You entered:\n";
    cout << morse_code;
    cout << "\n\nThe decoded message is:\n";

    stringstream mors(morse_code);
    string letter;

        while (mors >> letter) {
        vector<string>::iterator it;
        it = find(Morse.begin(), Morse.end(), letter);
        size_t dist = distance(Morse.begin(), it);
        cout << Letter[dist] ;
        }
    }
    
    if(b == 3){
        vector<string> code(40);
    string _code;

    string alphabet[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J",
                    "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T",
                    "U", "V", "W", "X", "Y", "Z", "1", "2", "3", "4",
                    "5", "6", "7", "8", "9", "0", "Stop", ",", "?"," "};

    for(int m = 0; m < code.size(); m++){
        cout<<"Enter your code corresponding to "<<alphabet[m]<<" : ";
        cin>>code[m];
    }
    
    cout<<"Enter your code: ";
    getline(cin, _code);

    for(int j = 0; j < 26; j++){
        cout<<_code[j]<<" ";
    }

    stringstream sample(_code);
    string letter;

        while (sample >> letter) {
        vector<string>::iterator it;
        it = find(code.begin(), code.end(), letter);
        size_t dist = distance(code.begin(), it);
        cout << Letter[dist] ;
        }
    }

    

    return 0;
}