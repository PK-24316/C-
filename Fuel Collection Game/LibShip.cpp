#include "LibShip.h"

namespace ShipSpace
{
    int GetRand(int intLower, int intUpper)
    {
        int intRange = intUpper - intLower + 1;
        return rand() % intRange + intLower;
    }

    void InitializeGame(int arrGame[])
    {
        ///Add Sea.
        for (int i = 0; i < SIZE_SEA; i++)
        {
            arrGame[i] = SEA;
        }

        ///Place Fuel Sources.
        for (int i = 0; i < COUNT_FUEL; i++)
        {
            ///Get Random Location.
            int intLocation = GetRand(0, SIZE_SEA - 1);
            arrGame[intLocation] = FUEL;
        }

        ///Place the Ship.
        arrGame[SIZE_SEA/2] = SHIP;
    }

    void PrintGame(int arrGame[], int intFuel)
    {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif // _WIN32

        ///Iterate through the array.
        for (int i = 0; i < SIZE_SEA; i++)
        {
            ///Output relevant characters.
            switch (arrGame[i])
            {
            case SEA:
                {
                    cout << CH_SEA << " ";
                    break;
                }
            case FUEL:
                {
                    cout << CH_FUEL << " ";
                    break;
                }
            case SHIP:
                {
                    cout << CH_SHIP << " ";
                    break;
                }
            cout << " ";
            }
        }
        cout << endl;

        cout << "FUEL LEVEL: " << intFuel << endl;
        cout << "A. MOVE LEFT.\n";
        cout << "D. MOVE RIGHT. \n";
        cout << "X. QUIT. \n";
    }

    int FindShip(int arrGame[])
    {
        int intLocation = -1;

        for (int i = 0; i < SIZE_SEA; i++)
        {
            if (arrGame[i] == SHIP)
            {
                return i;
            }
        }
        return intLocation;
    }

    void MoveShip(int arrGame[], char chKey, int &intFuel, bool& blnVictory)
    {
        int intShipLocation = FindShip(arrGame);

        //Make sure we found the ship.
        if (intShipLocation < 0)
            return;

        int intDestLocation = intShipLocation;

        switch (chKey)
        {
        case 'a':
        case 'A':
            {
                intDestLocation--;
                break;
            }
        case 'd':
        case 'D':
            {
                intDestLocation++;
                break;
            }
        }

        if ((intDestLocation == 0) || (intDestLocation == SIZE_SEA - 1))
            blnVictory = true;

        if (arrGame[intDestLocation] == FUEL)
            intFuel += 6;

        arrGame[intShipLocation] = SEA;
        arrGame[intDestLocation] = SHIP;
        intFuel--;
    }
}
