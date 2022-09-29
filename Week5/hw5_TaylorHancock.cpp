/**************************************************
 * File:      hw5_TaylorHancock.cpp
 * Author:    Taylor Hancock
 * Purpose:   To get practice working with constructors, the
 *                  const keyword, and some basic math.
 * Version:   1.0 Sep 26, 2022
 * Resources: Lecture notes and Prof. Marriott's office hours
 **************************************************/

#include <iostream>
using namespace std;

class Fraction {
    private:
        int wholeNumber;
        int numerator;
        int denominator;
    public:
        void setWholeNumber(int num) { wholeNumber = num; }
        void setNumerator(int num)   { numerator = num;   }
        void setDenominator(int num) { denominator = num; }
        int getWholeNumber() const { return wholeNumber; }
        int getNumerator()   const { return numerator;   }
        int getDenominator() const { return denominator; }
        void reduce(); // reduces a fraction
        Fraction unreduce() const; // converts a reduced fraction into a fully unreduced fraction (useful for math)
        Fraction(int numerator, int denominator, int wholeNumber = 0);
        Fraction();
};

void display(const Fraction& f);
Fraction multiply(const Fraction& fraction1, const Fraction& fraction2);
int getUserInt(string prompt);

int main() {
    Fraction f1;
    Fraction f2;

    Fraction f3 = multiply(f1, f2);

    display(f1);
    cout << " * ";
    display(f2);
    cout << " = ";
    display(f3);
    cout << endl;
}

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
    for(int i = numerator; i > 1; i--) {
        if(numerator % i == 0 && denominator % i == 0) { // check if divisible, if they are, divide
            numerator /= i;
            denominator /= i;
        }
    }
}

Fraction Fraction::unreduce() const {
    // add whole number * denominator to numerator
    if(numerator == 0) { // if numerator is 0, set denominator to 1
        return Fraction(wholeNumber, 1);
    }
    return Fraction((wholeNumber * denominator) + numerator, denominator);
}

// display the correctly formatted fraction
void display(const Fraction& f) {
    if(f.getWholeNumber() != 0) { // only show whole number if not 0
        cout << f.getWholeNumber();
    }

    if(f.getWholeNumber() != 0 && f.getNumerator() != 0) { // print a space between whole number and fraction
        cout << " ";
    }

    if(f.getNumerator() != 0) { // only show fraction if not 0
        cout << f.getNumerator() << "/" << f.getDenominator();
    }

    if(f.getWholeNumber() == 0 && f.getNumerator() == 0) {  // if all 0, print a 0
        cout << "0";
    }
}

Fraction multiply(const Fraction& fraction1, const Fraction& fraction2) {
    // convert to unreduced values (makes math much easier)
    Fraction frac1Conv = fraction1.unreduce();
    Fraction frac2Conv = fraction2.unreduce();

    // multiply
    Fraction multiple(frac1Conv.getNumerator() * frac2Conv.getNumerator(),
                      frac1Conv.getDenominator() * frac2Conv.getDenominator());

    // reduce
    multiple.reduce();
    return multiple;
}

// creates a fraction based on provided info
Fraction::Fraction(int numerator, int denominator, int wholeNumber) {
    this->numerator = numerator;
    this->denominator = denominator;
    this->wholeNumber = wholeNumber;
}

// creates a fraction based on user input
Fraction::Fraction() {
    // get inputs
    this->wholeNumber = getUserInt("Enter the whole number: ");
    this->numerator = getUserInt("Enter the numerator: ");
    this->denominator = getUserInt("Enter the denominator: ");

    while(denominator == 0 && numerator != 0) { // ensure denominator isn't 0
        cout << "ERROR: Denominator has to be greater than 0!" << endl;
        denominator = getUserInt("Enter the denominator: ");
    }

    if(denominator == 0 && numerator == 0) { // no div by 0
        denominator = 1;
    }

    reduce();
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