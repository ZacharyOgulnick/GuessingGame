#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

void rules();

int main()
{
    string playerName;
    double playerBalance;
    double playerBet;
    int numberGuess;
    int numberResult;
    char choice;
    const int minValue = 1;
    const int maxValue = 10;

    unsigned seed = time(0);
    srand(seed);
    
    rules();
    
    cout << "Want to play? Enter Y to continue, or N to quit. ";
    cin >> choice;

    while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
    {
        cout << "Invalid input. Please try again. ";
        cin >> choice;
    }

    if (choice == 'Y' || choice == 'y')
    {
        cout << "Name: ";
        cin >> playerName;
        cout << "Initial deposit: ";
        cin >> playerBalance;

        do
        {
            cout << "Make a guess between 1 and 10. ";
            cin >> numberGuess;
            while (numberGuess > 10 || numberGuess < 1)
            {
                cout << "Invalid guess. Please try again. ";
                cin >> numberGuess;
            }

            cout << "How much do you want to bet? ";
            cin >> playerBet;
            while (playerBet > playerBalance || playerBet < 1)
            {
                cout << "Invalid bet. Please try again. ";
                cin >> playerBet;
            }

            numberResult = (rand() % (maxValue - minValue + 1) + minValue);

            if (numberGuess == numberResult)
            {
                cout << "Congratulations " << playerName << "! You won $" << playerBet * 2 << ".\n";
                cout << "New balance is $" << playerBalance + (playerBet * 2) << ".\n";
                playerBalance = playerBalance + (playerBet * 2);
                cout << "Play again? Enter P to play again or any other key to quit. ";
                cin >> choice;
            }   
            else
            {
                cout << "Sorry you lose! New balance is $" << playerBalance - playerBet << ".\n";
                cout << "Play again? Enter P to play again or any other key to quit. ";
                playerBalance = playerBalance - playerBet;
                cin >> choice;
            }
        }
        while (choice == 'P' || choice == 'p');

    }
    else if (choice == 'N' || choice == 'n')
    {
        cout << "See you next time!";
    }
    
    return 0;
}

void rules()
{
    cout << "Welcome to the Guessing Game!\n";
    cout << "The rules are simple, place your bet, correctly guess the number, and double your money!\n";
}