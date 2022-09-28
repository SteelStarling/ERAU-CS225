/**************************************************
 * File:      hw5_TaylorHancock.cpp
 * Author:    Taylor Hancock
 * Purpose:   
 * Version:   1.0 Sep 26, 2022
 * Resources: 
 **************************************************/

#include <iostream>
using namespace std;

class Fraction {
    private:
        int wholeNumber;
        int numerator;
        int denominator;
    public:
        int setWholeNumber(int num) { wholeNumber = num; }
        int setNumerator(int num)   { numerator = num;   }
        int setDenominator(int num) { denominator = num; }
        int getWholeNumber() const { return wholeNumber; }
        int getNumerator()   const { return numerator;   }
        int getDenominator() const { return denominator; }
        void reduce();
        Fraction(int numerator, int denominator, int wholeNumber = 0);
        Fraction();
};

void Fraction::reduce() {
    // if denominator is negative, make positive and make numerator negative
    if(denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }

    // increment whole number by the numerator / denominator
    wholeNumber += numerator / denominator;

    // reset numerator to numerator % denominator
    numerator %= denominator;

    // deal with 2/4 -> 1/2
    if(denominator % numerator == 0) { // if numerator is a factor of denominator
        numerator /= 
    }
}

// display the correctly formatted fraction
void display(const Fraction& f) {
    if(f.getWholeNumber() != 0) { // only show whole number if not 0
        cout << f.getWholeNumber() << " ";
    }

    if(f.getNumerator() != 0) {
        cout << f.getNumerator() << " " << f.getDenominator();
    }

    if(f.getWholeNumber() == f.getNumerator() == 0)
}

Fraction multiply(const Fraction& fraction1, const Fraction& fraction2) {

}

// creates a fraction based on provided info
Fraction::Fraction(int numerator, int denominator, int wholeNumber = 0) {
    this->numerator = numerator;
    this->denominator = denominator;
    this->wholeNumber = wholeNumber;

    reduce();
}

// creates a fraction based on user input
Fraction::Fraction() {
    // get inputs
    this->wholeNumber = getUserInt("Enter the whole number: ");
    this->numerator = getUserInt("Enter the numerator: ");
    this->denominator = getUserInt("Enter the denominator: ");
}

// gets an integer from a user, providing them with a given prompt
int getUserInt(string prompt) {
    int input;
    cout << prompt;
    cin >> input;
    while(!cin) { // ensure valid input
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "ERROR: Invalid integer! Please input a valid integer!" << endl;
        cout << prompt;
        cin >> input;
    }

    return input;
}

int main() {

}