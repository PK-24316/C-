#include "game.h"
#include <iostream>
#include <cstdlib> ///For rand() and srand()
#include <ctime> ///for time()

using namespace std;

///function that runs the game
void playGame()
{
    ///Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    int secretNumber = rand() % 100 + 1; ///Random Number 1 - 100
    int guess = 0, attempts = 0;

    cout << "=============================================\n";
    cout << "\tWelcome to Guess the Number!\n";
    cout << "=============================================\n";
    cout << "I'm thinking of a number between 1 and 100.\n";

    ///Main guessing loop
    while (true)
    {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess > secretNumber)
        {
            cout << "Too high, Try again!\n";
        }
        else if (guess < secretNumber)
        {
             cout << "Too low, Try again!\n";
        }
        else
        {
            cout << "Correct! You guessed it in " << attempts << " attempts.\n";
            break;
        }
    }
}


























































