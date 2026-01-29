#include "Hangman.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Constructor
Hangman::Hangman() {
    lives = 6;
    loadWord();
    guessedWord = string(word.length(), '_');
}

// Load a random word from file
void Hangman::loadWord() {
    ifstream file("words.txt");
    string words[50];
    int count = 0;

    while (file >> words[count] && count < 50) {
        count++;
    }

    file.close();

    srand(time(0));
    word = words[rand() % count];
}

// Display the guessed word
void Hangman::displayWord() {
    for (char c : guessedWord) {
        cout << c << " ";
    }
    cout << endl;
}

// Process a guessed letter
bool Hangman::guessLetter(char letter) {
    bool found = false;

    for (int i = 0; i < word.length(); i++) {
        if (word[i] == letter && guessedWord[i] == '_') {
            guessedWord[i] = letter;
            found = true;
        }
    }

    if (!found) {
        lives--;
    }

    return found;
}

// Check if player won
bool Hangman::isGameWon() {
    return guessedWord == word;
}

// Check if player lost
bool Hangman::isGameLost() {
    return lives <= 0;
}

// Get remaining lives
int Hangman::getLives() {
    return lives;
}
