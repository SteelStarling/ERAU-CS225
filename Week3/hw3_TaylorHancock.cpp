/**************************************************
 * File:      hw3_TaylorHancock.cpp
 * Author:    Taylor Hancock
 * Purpose:   Allows the user to play a game of Wordle
 * Version:   1.0 Sep 13, 2022
 * Resources: GitHub user CFreshman, who kindly provides a list of *ALL* the Wordle Guess Words and Wordle Answer Words in
 *              https://gist.github.com/cfreshman/d5fb56316158a1575898bba1eed3b5da and https://gist.github.com/cfreshman/a7b776506c73284511034e63af1017ee,
 *              as well as https://alphabetizer.flap.tv/ which helped me alphabetize the combined lists, as well as add quotes
 *              and commas for them all (I could've Regex'd it, but that would've required too much thinking :P).
 **************************************************/

#include <string>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <time.h>
//#include "wordleList.hpp" // this one is too large, so it refuses to run... :(
#include "babyWordleList.hpp"
using namespace std;

const int WORD_COUNT = 6; // holds number of words
const int WORD_LENGTH = 5; // holds length of words

// defines terms for occurrence checking
const int NO_MATCH = 0;
const int WRONG_LOCATION = 1;
const int MATCH = 2;

class Word {
    private:
        bool isValid; // determines if the string is a valid wordle string (length and dictionary match)
        std::string word; // contains the word itself
        int colors[WORD_LENGTH]; //contains numbers corresponding to colors to print each letter in

        void printLetter(int i); // prints the specified letter of the word
    public:
        Word(std::string input = "invalid"); // constructor for word function (if nothing is passed, an invalid input will be given)
        Word(std::string input, std::string answer); // constructor for word function

        void calcOccurrences(Word answer); // calculates if each letter is matching the provided answer
        void printWord(); // prints the word with the correct colors

        bool getValid() {return isValid;} // isValid getter
        string getWord() {return word;} // word getter
};

class Board {
    private:
        Word answer; // contains the answer word
        Word words[WORD_COUNT]; // contains all words typed
        int activeWordIndex = 0;    // index of which word is currently active
    public:
        Board(); // constructor for board function
        void reset(); // resets the board

        void playGame();

        Word getWord() {return answer;} // word getter
        Word* getWordsArray() {return words;} // words array getter
        int getActiveWordIndex() {return activeWordIndex;} // returns index of current word
};

// function prototypes
bool strExistsInList(string input, const string stringList[], int end, int start = 0);
int getRandInt(int max);
bool calcValid(string word);
void printStars();

int main() {
    srand(time(NULL));
    Board wordleGame;
    wordleGame.playGame();
    return 0;
}

Board::Board() {
    reset();
}

void Board::reset() {
    answer = Word(answerList[getRandInt(answerLength)]); // get random answer and store it as a word
    activeWordIndex = 0; // reset index
}

void Board::playGame() {
    for(int i = 0; i < WORD_COUNT; i++) {
        string input;
        while(input.length() != WORD_LENGTH) { // loop while an invalid length
            cout << endl << "Guess #" << (i + 1) << ": Enter a 5 letter word: __ __ __ __ __" << endl; // prints guess start message
            cin >> input;
            if(input.length() != WORD_LENGTH) {
                cout << "ERROR: You must enter a 5 Letter Word." << endl;
                printStars();
            }
        }
        words[i] = Word(input, answer.getWord()); // save guess

        if(words[i].getWord() == answer.getWord()) { // check if correct answer
            cout << "You guessed it! The word was " << answer.getWord() << "!" << endl << endl;;
            break; // end loop
        }

        printStars();

        words[i].calcOccurrences(answer);

        words[i].printWord(); // print the word formatted in the right style

        if(i == WORD_COUNT - 1) { // check if out of guesses
            cout << "Out of guesses. The word was: " << answer.getWord() << "!" << endl;
        }
    }
    reset();
}

Word::Word(string input) {
    word = input;

    if(word.length() != WORD_LENGTH) { // if wrong length, invalid, don't bother checking
        isValid = false;
    } else { // if right length, check if input actually exists in The List™
        isValid = strExistsInList(word, wordleList, wordleLength);
    }
}

Word::Word(string input, string answer) {
    word = input;

    if(word.length() != WORD_LENGTH) { // if wrong length, invalid, don't bother checking
        isValid = false;
    } else if (word == answer) { // checks if it's the answer (possible speed up, unsure if it's actually effective in any way)
        isValid = true;
    } else { // if right length, check if input actually exists in The List™
        isValid = strExistsInList(word, wordleList, wordleLength);
    }
}

void Word::calcOccurrences(Word answer) {
    string answerStr = answer.getWord(); // get string from answer

    // fill answer chars (once matches are found, values will be deleted from chars to ensure no duplicate counts)
    char answerChars[WORD_LENGTH];
    for(int i = 0; i < WORD_LENGTH; i++) {
        answerChars[i] = answerStr.at(i);
    }

    // step 1: check for correctness
    for(int i = 0; i < WORD_LENGTH; i++) {
        if(answerChars[i] == word.at(i)) { // check if equal
            colors[i] = MATCH;
            answerChars[i] = -1; // flag as already checked (-1 cannot match with ascii values)
        }
    }

    // step 2: check for correct letters in incorrect locations
    for(int i = 0; i < WORD_LENGTH; i++) {
        if(answerChars[i] != -1) { // check if position is already invalid (already matched)
            for(int j = 0; j < WORD_LENGTH; j++) {
                if(i != j && answerChars[i] == word.at(j)) { // ignore matching spaces (already been checked), then check if equal
                    colors[j] = WRONG_LOCATION;
                    answerChars[i] = -1; // flag as already checked (-1 cannot match with ascii values)
                }
            }
        }
    }
}

void Word::printWord() {
    for(int i = 0; i < WORD_LENGTH; i++) { // print each letter
        printLetter(i);
    }
    cout << endl; // print the newline
}

void Word::printLetter(int i) {
    if(i < WORD_LENGTH && i >= 0) { // only print within range (should never be given weird values, but just to be sure)
        if(colors[i] == MATCH) { // print letter in correct style (called color for if I ever implement colors, as VS Code makes them...wonky)
            cout << " (" << word.at(i) << ") ";
        } else if(colors[i] == WRONG_LOCATION) {
            cout << " _" << word.at(i) << "_ ";
        } else {
            cout << " ___ ";
        }
    }
}

bool calcValid(string word) {
    if(word.length() != WORD_LENGTH) { // if wrong length, invalid, don't bother checking
        return false;
    } else { // if right length, check if input actually exists in The List™
        return strExistsInList(word, wordleList, wordleLength);
    }
}

// recursive binary search algorithm (position doesn't matter here, just has to exist)
bool strExistsInList(string input, const string stringList[], int end, int start) {
    if(end > start) { // if looped over everything (hasn't been found), return false
        return false;
    }

    int mid = (start + end) / 2; // calculate midpoint

    int compareEval = input.compare(stringList[mid]); // do comparison calculation *once* and save it

    if(compareEval < 0) { // check if too high
        return strExistsInList(input, stringList, mid - 1, start);
    } else if(compareEval > 0) { // check if too low
        return strExistsInList(input, stringList, end, mid + 1);
    } else { // it's been found!
        return true;
    }
}

// gets a random int between 0 and max
int getRandInt(int max) {
    return rand() % max;
}

void printStars() {
    cout << "****************************************" << endl;
}