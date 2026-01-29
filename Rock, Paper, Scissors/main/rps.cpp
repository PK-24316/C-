#include "rps.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

///Convert enum choice to string for display
string choiceToString(Choice choice)
{
    switch (choice)
    {
        case ROCK:      return "Rock";
        case PAPER:     return "Paper";
        case SCISSORS:  return "Scissors";
        default:        return "Unknown";
    }
}

///Determine Winner
///Returns: 0 = Tie, 1 = Player wins, -1 = Computer Wins
int determineWinner(Choice player, Choice computer)
{
    ///Tie
    if (player == computer)
        return 0;

    ///Player 1 wins
    if ((player == ROCK && computer == SCISSORS) ||
        (player == PAPER && computer == ROCK) ||
        (player == SCISSORS && computer == PAPER))
            return 1;

    ///Computer wins
    return -1;
}

///Main Game Function
void playRPS()
{
    srand(static_cast<unsigned int>(time(0)));

    int playerScore = 0;
    int computerScore = 0;

    char playAgain;

    do
    {
        int playerInput;
        cout << "\n======= Rock, Paper, Scissors ======\n";
        cout << "1. Rock\n";
        cout << "2. Paper\n";
        cout << "3. Scissors\n";
        cout << "Choose (1-3): ";
        cin >> playerInput;

        ///Basic input validation
        if (playerInput < 1 || playerInput > 3 || cin.fail())
        {
            cout << "Invalid Choice, Try Again.\n";
            continue;
        }

        Choice playerChoice = static_cast<Choice>(playerInput);
        Choice computerChoice = static_cast<Choice>(rand() % 3 + 1);

        cout << "You Chose: " << choiceToString(playerChoice) << endl;
        cout << "Computer Chose: " << choiceToString(computerChoice) << endl;

        int result = determineWinner(playerChoice, computerChoice);

        if (result == 1)
        {
            cout << "You win this round!\n";
            playerScore++;
        }
        else if (result == -1)
        {
            cout << "Computer wins this round!\n";
            computerScore++;
        }
        else
        {
            cout << "It's a tie.\n";
        }

        cout << "Score -> You: " << playerScore << " | Computer: " << computerScore << endl;

        cout << "Play another round? (y/n): ";
        cin >> playAgain;
    }while (playAgain == 'y' || playAgain == 'Y');

    cout << "\nFinal Score:\n";
    cout << "You: " << playerScore << endl;
    cout << "Computer: " << computerScore << endl;
    cout << "Thanks for playing Rock, Paper, Scissors! \n";
}
