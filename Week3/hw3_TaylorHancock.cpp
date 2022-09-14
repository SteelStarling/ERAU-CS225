/**************************************************
 * File:      hw3_TaylorHancock.cpp
 * Author:    Taylor Hancock
 * Purpose:   
 * Version:   1.0 Sep 13, 2022
 * Resources: 
 **************************************************/

#include <string>
#include <iostream>
#include <wordleList.hpp>
using namespace std;

const int WORD_COUNT = 6; // holds number of words
const int WORD_LENGTH = 5; // holds length of words

class Word {
    private:
        static string wordList[] = wordleList;
        bool isValid; // determines if the string is a valid wordle string (length and dictionary match)
        std::string word; // contains the word itself
    public:
        Word(std::string input); // constructor for word function
};

Word::Word(std::string input) {
    word = input;


}

class Board {
    private:
        Word answer; // contains the answer word
        Word words[WORD_COUNT]; // contains all words typed
        int curWord = 0;    // contains which word is currently active
    public:
        Board(); // constructor for board function
        void reset(); // resets the board
};



int main() {
    


    return 0;
}