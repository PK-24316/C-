#include <iostream>
#include "Hangman.h"

using namespace std;

int main()
{
    Hangman game;
    char guess;

    cout << "=== HANGMAN GAME ===" << endl;

    while (!game.isGameWon() && !game.isGameLost())
    {
        cout << "\nWord: ";
        game.displayWord();

        cout << "Lives left: " << game.getLives() << endl;
        cout << "Enter a letter: ";
        cin >> guess;

        if (game.guessLetter(guess))
        {
            cout << "Correct!" << endl;
        }
        else
        {
            cout << "Wrong Guess!" << endl;
        }
    }

    if (game.isGameWon())
        cout << "\nYou won! Well Done!\n";
    else
        cout << "\nGame Over! Better Luck Next Time.\n";

    return 0;
}
