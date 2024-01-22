#include <iostream>
#include <string>  // Needed to use strings
#include <cstdlib> // Needed to use random numbers
#include <ctime>
using namespace std;

void rules()
{
    system("cls");
    cout << "\t\t======CASINO NUMBER GUESSING RULES!======\n";
    cout << "\t1. Choose a number between 1 to 10\n";
    cout << "\t2. Winner gets 10 times of the money bet\n";
    cout << "\t3. Wrong bet, and you lose the amount you bet\n\n";
}

int main()
{
    string playerName;
    int balance; // stores player's balance
    int bettingAmount;
    int guess;
    int dice; // stores the random number
    char choice;
    srand(time(0)); // "Seed" the random generator

    cout << "\n\t\t========WELCOME TO CASINO WORLD=======\n\n";

    cout<<"\n===============================================================================================";
    cout<<"\n   CCCCC      A        SSSSSSSSS   IIIIIIIII  NN     NN    OOOOOOOO     ";
    cout<<"\n CC          A  A      SS             III     NN N   NN   OO      OO    ";
    cout<<"\nCC          A    A     SSSSSSSSS      III     NN  N  NN   OO      OO    ";
    cout<<"\n CC        AAAAAAAA           SS      III     NN   N NN   OO      OO    ";
    cout<<"\n   CCCCC  A        A   SSSSSSSSS   IIIIIIIII  NN     NN    OOOOOOOO     ";
    cout<<"\n===============================================================================================\n";

    cout << "\n\nWhat's your Name : ";

    getline(cin, playerName);

    cout << "\n\nEnter the starting balance to play game : Rs.";
    cin >> balance;
    do
    {
        system("cls");
        rules();
        cout << "\n\nYour current balance is Rs. " << balance << "\n";
        // Get player's betting balance
        do
        {
            cout << "Hey, " << playerName << ", enter amount to bet : Rs.";
            cin >> bettingAmount;
            if (bettingAmount > balance)
                cout << "Betting balance can't be more than current balance!\n"
                     << "\nRe-enter balance\n ";
        } while (bettingAmount > balance);
        // Get player's numbeRs.
        do
        {
            cout << "Guess any betting number between 1 & 10 :";
            cin >> guess;
            if (guess <= 0 || guess > 10)
                cout << "\nNumber should be between 1 to 10\n"
                     << "Re-enter number:\n ";
        } 
        while (guess <= 0 || guess > 10);

        dice = rand() % 10 + 1;

        if (dice == guess)
        {
            cout << "\n\nYou are in luck!! You have won Rs.." << bettingAmount * 10;
            balance = balance + bettingAmount * 10;
        }
        else
        {
            cout << "Oops, better luck next time !! You lost Rs. " << bettingAmount << "\n";
            balance = balance - bettingAmount;
        }
        cout << "\nThe winning number was : " << dice << "\n";
        cout << "\n"
             << playerName << ", You have balance of Rs. " << balance << "\n";
        if (balance == 0)
        {
            cout << "You have no money to play ";
            break;
        }
        cout << "\n\n-->Do you want to play again (y/n)? ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');


    cout << "\n\n\n";
    cout << "\n\nThanks for playing the game. Your balance is Rs. " << balance << "\n\n";


    return 0;
}
