#include <iostream>
#include "game.h"

using namespace std;

int main()
{
    char playAgain;

    do
    {
        playGame();

        cout << "\nDo you want to play again? (y/n):";
        cin >> playAgain;

        cout << "\n";
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing! Goodbye :)\n";


    return 0;
}
