#include "LibShip.h"
#include <iostream>

using namespace std;
using namespace ShipSpace;

int main()
{
    srand(time(0));

    bool blnContinue = true;
    bool blnVictory = false;
    int intCurrentFuel = INIT_FUEL;
    char chKey = '\0';
    int arrGame[SIZE_SEA];

    ///Initialize Game.
    InitializeGame(arrGame);

    do
    {
        ///Output the Screen.
        PrintGame(arrGame, intCurrentFuel);

        ///Get Input.
        cin >> chKey;

        ///Handle Movement.
        MoveShip(arrGame, chKey, intCurrentFuel, blnVictory);

        ///Check if Game Over.
        if (intCurrentFuel == 0)
            blnContinue = false;

        if (blnVictory)
            blnContinue = false;
    } while (blnContinue);

    ///Output the final state of the game.
    PrintGame(arrGame, intCurrentFuel);

    ///Print Messages.
    if (blnVictory)
        cout << "Congrats, The Ship has successfully sailed over the sea. \n";
    else
        cout << "I'm Sorry, The Ship has ran out of fuel. \n";

    return 0;
}
