#ifndef HANGMAN_H
#define HANGMAN_H

#include <string>
using namespace std;

class Hangman
{
private:
    string word; ///Word to guess
    string guessedWord; ///Displayed word (_ _ _)
    int lives; ///Remaining attempts

public:
    Hangman();
    void loadWord();
    void displayWord();
    bool guessLetter(char letter);
    bool isGameWon();
    bool isGameLost();
    int getLives();
};

#endif // HANGMAN_H
