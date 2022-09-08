/**
 * File: hw2_TaylorHancock.cpp
 * Author: Taylor Hancock
 * Purpose: Complete Homework 2: Review working with structs and practice more with C++ style I/O
 * Version: 1.0 - 09/07/2022
 * Resources: I figured out how to use the leading zeros from: https://stackoverflow.com/questions/1714515/how-can-i-pad-an-int-with-leading-zeros-when-using-cout-operator
 *            as well as the in-lab discussion on the subject
 */

#include <iomanip>
#include <iostream>
using namespace std;

struct Money {
    int dollars;
    int cents;
};

void fillMoney(Money* money);
void printMoney(Money* money);

int main(void) {
    // create money objects
    Money money1;
    Money money2;
    Money moneySum;

    // handle money1
    fillMoney(&money1); // fill money with values
    cout << "You entered: ";
    printMoney(&money1); // print money values
    cout << endl;

    // handle money2
    fillMoney(&money2); // fill money with values
    cout << "You entered: ";
    printMoney(&money2); // print money values
    cout << endl;

    // handle moneySum
    moneySum.dollars = money1.dollars + money2.dollars; // sum dollars
    moneySum.cents = money1.cents + money2.cents; //sum cents
    if(moneySum.cents > 99) { // if over 99 cents, wrap around to dollars
        moneySum.dollars += moneySum.cents / 100; // add to dollars
        moneySum.cents %= 100; // modulo cents by 100
    }

    // print moneySum
    printMoney(&money1);
    cout << " + ";
    printMoney(&money2);
    cout << " = ";
    printMoney(&moneySum);
    cout << endl;

    return 0;
}

/**
 * @brief A function to request the user for input and fill out the data inside a money struct
 * 
 * @param money The money struct to fill out
 */
void fillMoney(Money* money) {
    // fill dollars
    cout << "Enter dollars: ";
    cin  >> (*money).dollars;
    if(!cin || (*money).dollars < 0) { // check for invalid inputs
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Error: Invalid Input! Setting to 1" << endl;
        (*money).dollars = 1;
    }
    
    // fill cents
    cout << "Enter cents: ";
    cin  >> (*money).cents;
    if(!cin || (*money).cents < 0) { // check for invalid inputs
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Error: Invalid Input! Setting to 1" << endl;
        (*money).cents = 1;
    } else if((*money).cents > 99) { //if 100+ cents, increase dollars
        (*money).dollars += (*money).cents / 100; // increase dollars
        (*money).cents %= 100; // get cents mod 100 
    }
}

/**
 * @brief Prints the values of the money object passed to it
 * 
 * @param money The money object to print the values of
 */
void printMoney(Money* money) {
    cout << "$" << (*money).dollars << "."                  // print dollars
         << setfill('0') << std::setw(2) << (*money).cents; // print cents with leading zero
}