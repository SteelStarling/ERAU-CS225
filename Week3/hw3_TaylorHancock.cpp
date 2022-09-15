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
#include <random>
#include <wordleList.hpp>
using namespace std;

const int WORD_COUNT = 6; // holds number of words
const int WORD_LENGTH = 5; // holds length of words

class Word {
    private:
        bool isValid; // determines if the string is a valid wordle string (length and dictionary match)
        std::string word; // contains the word itself
    public:
        Word(std::string input); // constructor for word function
        Word(std::string input, std::string answer); // constructor for word function

        bool getValid() {return isValid;} // isValid getter
        string getWord() {return word;} // word getter
};

class Board {
    private:
        Word answer; // contains the answer word
        Word words[WORD_COUNT]; // contains all words typed
        int curWord = 0;    // contains which word is currently active
    public:
        Board(); // constructor for board function
        void reset(); // resets the board

        Word getWord() {return answer;} // word getter
        Word* getWordsArray() {return words;} // words array getter
        int getCurWord() {return curWord;} // returns index of current word
};

// function prototypes
bool strExistsInList(string input, const string stringList[], int end, int start);
int getRandInt(int start, int end);

int main() {
    


    return 0;
}

Word::Word(std::string input) {
    word = input;

    if(word.length() != 6) { // if wrong length, invalid, don't bother checking
        isValid = false;
    } else { // if right length, check if input actually exists in The List™
        isValid = strExistsInList(input, wordleList, wordleLength);
    }
}

Word::Word(std::string input, std::string answer) {
    word = input;

    if(word.length() != 6) { // if wrong length, invalid, don't bother checking
        isValid = false;
    } else if (word == answer) { // checks if it's the answer (possible speed up, unsure if it's actually effective in any way)
        isValid = true;
    } else { // if right length, check if input actually exists in The List™
        isValid = strExistsInList(word, wordleList, wordleLength);
    }
}

// recursive binary search algorithm (position doesn't matter here, just has to exist)
bool strExistsInList(string input, const string stringList[], int end, int start = 0) {
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

Board::Board() {
    reset();
}

void Board::reset() {
    answer = answerList[getRandInt(0, answerLength - 1)]; // get random answer and store it
    curWord = 0;
}

// gets a random int between start and end, code grabbed wholesale from https://cplusplus.com/reference/random/, as we haven't learned anything about this stuff yet
int getRandInt(int start, int end) {
    default_random_engine generator;
    uniform_int_distribution<int> distribution(start, end);
    return distribution(generator);  // generates number in the specified range
}