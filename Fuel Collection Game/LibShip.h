#ifndef LIBSHIP_H
#define LIBSHIP_H

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

namespace ShipSpace
{
    const int SIZE_SEA = 50;
    const int COUNT_FUEL = 4;
    const int INIT_FUEL = 20;

    const int SEA = 0;
    const int FUEL = 1;
    const int SHIP = 2;

    const char CH_SEA = '_';
    const char CH_FUEL = '^';
    const char CH_SHIP = '&';

    int GetRand(int intLower, int intUpper);
    void InitializeGame(int arrGame[]);
    void PrintGame(int arrGame[], int intFuel);
    int FindShip(int arrGame[]);
    void MoveShip(int arrGame[], char chKey, int &intFuel, bool& blnVictory);
}


#endif ///LIBSHIP_H
