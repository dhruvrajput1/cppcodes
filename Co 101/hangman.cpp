#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

void hangman(int a, int score)
{ // defining hangman
    
    if(a == 1)
    {
        cout << "\n Amount of wrong letters: \n\n"<< a;
        cout << ("  _______\n");
        cout << ("  |\n");
        cout << ("  |\n");
        cout << ("  |\n");
        cout << ("  |\n");
        cout << ("  |\n");
        cout << ("__|_________\n\n");
        cout << "\n Your score = "<< score;
        cout << "\n Chances Left="<< 5 - a;
        
    }

    else if(a == 2){
        cout << "\n Amount of wrong letters: \n\n"<< a;
        cout << ("  _______\n");
        cout << ("  |/   | \n");
        cout << ("  |    O \n");
        cout << ("  |\n");
        cout << ("  |\n");
        cout << ("  |\n");
        cout << ("  |\n");
        cout << ("__|_________\n\n");
        cout << "\n Your score = " << score;
        cout << "\n Chances Left="<< 5 - a;

    }

    else if(a == 3){
        cout << "\n Amount of wrong letters: \n\n"<< a;
        cout << ("  _______\n");
        cout << ("  |/   | \n");
        cout << ("  |    O \n");
        cout << ("  |    |\n");
        cout << ("  |    |\n");
        cout << ("  |\n");
        cout << ("__|_________\n\n");
        cout << "\n Your score = " << score;
        cout << "\n Chances Left="<< 5 - a;

    }

    else if(a == 4){
        cout << "\n Amount of wrong letters: \n\n"<< a;
        cout << ("  _______\n");
        cout << ("  |/   | \n");
        cout << ("  |    O \n");
        cout << ("  |   \\|/\n");
        cout << ("  |    | \n");
        cout << ("  |   /\n");
        cout << ("__|_________\n\n");
        cout << "\n Your score = "<< score;
        cout << "\n Chances Left="<< 5 - a;

    }

    else if(a == 5){
        cout << ("\n Amount of wrong letters: %d\n\n", a);
        cout << ("  _______\n");
        cout << ("  |/   | \n");
        cout << ("  |    X \n");
        cout << ("  |   \\|/\n");
        cout << ("  |    | \n");
        cout << ("  |   / \\\n");
        cout << ("__|_________\n\n");
        cout << "\n Total score = "<< score;
        cout << "\n  Chances Left=%d"<< 5 - a;
        cout << "\n\n YOU ARE DEAD ! GAME OVER!";
        exit(0);
    }
    
}


int main()
{
    cout << ("\t\t--------------------------------------------\n");
    cout << ("\t\t| #  #   #   #   #  #### #   #   #   #   # |\n");
    cout << ("\t\t| #  #  # #  ##  # #     ## ##  # #  ##  # |\n");
    cout << ("\t\t| #### ##### # # # #  ## # # # ##### # # # |\n");
    cout << ("\t\t| #  # #   # #  ## #   # #   # #   # #  ## |\n");
    cout << ("\t\t| #  # #   # #   #  ###  #   # #   # #   # |\n");
    cout << ("\t\t--------------------------------------------\n\n");
    cout << "RULES: \n";
    cout << "One player thinks of a word or phrase, the others try to guess what it is one letter at a time. \nThe player draws a number of dashes equivalent to the number of letters in the word.\nIf a guessing player suggests a letter that occurs in the word, the other player fills in the blanks with that letter in the right places. \nIf the word does not contain the suggested letter, the other player draws on element of a hangmans gallows. \nAs the game progresses, a segment of the gallows and of a victim is added for every suggested letter not in the word.\nThe number of incorrect guesses before the game ends is 5 and total attempts one player gets is equivalent to the length of the word given, but completing a character in a noose provides a minimum of six wrong answers until the game ends.\nThe first player to guess the correct answer thinks of the word for the next game.";
    cout << "\n ****************************************************************************************";
    cout << "\n ****************************************************************************************";
    cout << "\n **************************************************************************************** \n";
    int score1 = 0;
    int score2 = 0;
    int rounds;
    cout << "Enter number of rounds to be played \n";
    cin >> rounds;
    int len;
    while (rounds >0)
    {
        int a=0;
        string n;
        string ans;
        cout << "Type in the Word for Player: \n";
        cin >> n;
        len = n.length();
        
            // 1. Create a string variable for the secret word
            string hidden(n);
            // 2. Create a string variable for the answer
            for (int j = 0; j < len; j++)
            {
                ans = ans + "*";
            }
            string answer(ans);


            for (int i = 0; i < len; i++)
        {
            // 3. Create a char variable for the letter the user will guess
            char guess;
            // 4. Ask the user to enter a letter
            cout << "\n Type a letter and hit Return or Enter at will... \n";

            // 5. Place this in a loop so the user can enter another letter
                cout << "Uncovered: >>" << answer << "<< \n Your guess pls: \n"; /* alas same prompt also for run-in cycle */
                cin >> guess;
                // 6. Use Replace command to replace correct letter guessed with letters of secret word.
                /* do not know replace() */
                int m;
                int k=0;
                for( m=0;m<len;m++){
                    if (guess== hidden[m])
                    {
                        answer[m] = guess;
                        score2++;
                        
                        
                    }
                    else
                    {
                    k++;
                    }
                    
                    
                }
                if (k==len){
                    a++;
                    hangman(a,score2);
                }             
                // 7. Stop the program and “hang” the user after 5 incorrect guesses or win       
                if (answer == n)
                {
                    cout << "\n Your answer is " << n ;
                    cout << "\n Given word is " << answer << "\n";
                    cout << "\n Score of P2 " << score2 << "\n";
                    cout<<"You guessed it correctly. Great Job! ";
                }
                else{
                    cout<<"you ran out of chances";
                }
               
        }
            
        
        rounds--;
    }
    return 0;
}


