#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

vector<string> Morse{".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
                     "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
                     "..-", "...-", ".--", "-..-", "-.--", "--..", ".----", "..---", "...--",
                     "....-", ".....", "-....", "--...", "---..", "----.", "-----", ".-.-.-",
                     "--..--", "..--..", "/"};
vector<string> Letter{"A", "B", "C", "D", "E", "F", "G", "H", "I", "J",
                      "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T",
                      "U", "V", "W", "X", "Y", "Z", "1", "2", "3", "4",
                      "5", "6", "7", "8", "9", "0", "Stop", ",", "?", " "};
vector<string> kitij;
string getString(char x)
{
    string s(1, x);
    return s;   
}
int main()
{
    int a;
    cout << "Welcome to program, press 1 to continue" << endl;
    cin >> a;
    if (a != 1)
    {
        cout<<"Shut up, Wrong!!"<<endl;
        return 0;
    }
    int b;
    cout << "What would you like to choose" << endl;
    cout << "Press 1 for decrypting Morse code" << endl;
    cout << "Press 2 for encrypting Morse Code" << endl;
    cout << "Press 3 for creating your own language" << endl;
    cin >> b;

    if (b == 1)
    {
        string morse_code;

        cout << "Enter a Coded Morse Message (e.g. .- -... -.-.) \n";
        cout << "\nSeparate Morse Code by blanks:\n";
        cin.ignore();
        getline(cin, morse_code);
        cout << "You entered:\n";
        cout << morse_code;
        cout << "\n\nThe decoded message is:\n";

        stringstream mors(morse_code);
        string letter;

        while (mors >> letter)
        {
            vector<string>::iterator it;
            it = find(Morse.begin(), Morse.end(), letter);
            size_t dist = distance(Morse.begin(), it);
            cout << Letter[dist];
        }
    }
    if (b==2){
        string xero;

        cout << "Enter a Coded Morse Message (e.g. HELLO) \n";
        cout << "\nSeparate Morse Code by blanks:\n";
        cin.ignore();
        getline(cin, xero);
        cout << "You entered:\n";
        cout << xero;
        cout << "\n\nThe encoded message is:\n";

        int i=0;
        
        while(xero[i]!='\0'){
            vector<string>::iterator it;
            it = find(Letter.begin(), Letter.end(), getString(xero[i]));
            size_t dist = distance(Letter.begin(), it);
            cout << Morse[dist]<<" ";
            i++;
        }











    }
    if(b == 3){
        vector<string> kitij(40);
    string _code;

    string alphabet[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J",
                    "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T",
                    "U", "V", "W", "X", "Y", "Z", "1", "2", "3", "4",
                    "5", "6", "7", "8", "9", "0", "Stop", ",", "?"," "};

    for(int m = 0; m < kitij.size(); m++){
        cout<<"Enter your code corresponding to "<<alphabet[m]<<" : ";
        cin>>kitij[m];
    }
    
    cout<<"Enter your code: ";
    cin.ignore();
    getline(cin, _code);

    for(int j = 0; j < 26; j++){
        cout<<_code[j]<<" ";
    }

    stringstream sample(_code);
    string letter;

        while (sample >> letter) {
        vector<string>::iterator it;
        it = find(kitij.begin(), kitij.end(), letter);
        size_t dist = distance(kitij.begin(), it);
        cout << Letter[dist] ;
        }
    }
    // if (b == 3)
    // {
    //     // vector<string> code(40);
    //     string _code;

    //     string alphabet[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J",
    //                          "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T",
    //                          "U", "V", "W", "X", "Y", "Z", "1", "2", "3", "4",
    //                          "5", "6", "7", "8", "9", "0", "Stop", ",", "?", " "};

    //     for (int m = 0; m < _code.size(); m++)
    //     {
    //         cout << "Enter your code corresponding to " << alphabet[m] << " : ";
    //         cin >> _code[m];
    //     }
    //     cin.ignore();
    //     cout << "Enter your code: ";
    //     getline(cin, _code);

    //     for (int j = 0; j < 26; j++)
    //     {
    //         cout << _code[j] << " ";
    //     }

    //     stringstream sample(_code);
    //     string letter;

    //     while (sample >> letter)
    //     {
    //         vector<string>::iterator it;
    //         it = find(kitij.begin(), kitij.end(), letter);
    //         size_t dist = distance(_code.begin(), it);
    //         cout << Letter[dist];
    //     }
    // }

    return 0;
}