/*****************************************
 * Author:    Taylor Hancock
 * Purpose:   
 * Version:   1.0 09/20/2022
 * Resources: 
 ******************************************/

#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

class Car {
    private:
        string make;
        double milesPerGallon;
        double fuel;
        double fuelCapacity;
        int odometer;
    public:
        string getMake() {return make;}
        double getMilesPerGallon() {return milesPerGallon;}
        double getFuel() {return fuel;}
        double getFuelCapacity() {return fuelCapacity;}
        void showCar();
        void fuelUp(double fuelAmount);
        void drive();
        void drive(int distance);
        void setCar(string make, double milesPerGallon, double fuelCapacity, double fuel, int odometer);
};

int main() {
    srand(time(NULL));   // initialize srand

    Car c;
    c.setCar("Honda", 26.2, 14.0, 12.8, 3300);
    int userInput = 0;
    c.showCar();
    return 0;

    do {
        c.showCar();
        cout << "Select" << endl << "1. Go on a joy ride" << endl << "2. Drive a given distance" << endl << "3. Fuel up" << endl << "4. Exit" << endl;
        cin >> userInput;
        if(!cin) { // if cin is invalid
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "Error: Invalid Input! Please input a valid integer in the range 1-4!" << endl;
        } else if(userInput == 1) {
            c.drive();
        } else if(userInput == 2) {
            cout << "How far do you drive? ";
            int dist;
            cin >> dist;
            while(!cin) {
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cout << "ERROR: Invalid Input! Please input a valid integer!" << endl << "How far do you drive? ";
                cin >> dist;
            }
            c.drive(dist);
        } else if(userInput == 3) {
            cout << "How much fuel do you add? ";
            int fuelAmt;
            cin >> fuelAmt;
            while(!cin) {
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cout << "ERROR: Invalid Input! Please input a valid double value!" << endl << "How much fuel do you add? ";
                cin >> fuelAmt;
            }
            c.fuelUp(fuelAmt);
        }
    } while (userInput != 4);
}

void Car::showCar() {
    cout << "*********************************" << endl
         << "Make:             " << make << endl
         << "Fuel Capacity:    " << fuelCapacity << endl
         << "Miles per Gallon: " << milesPerGallon << endl
         << "Fuel in Tank:     " << fuel << endl
         << "Odometer Reading: " << odometer << endl
         << "*********************************" << endl;
}

void Car::fuelUp(double fuelAmount) {
    cout << "You fill your tank with " << fuelAmount << " gallons of fuel." << endl;
    if(fuelAmount + fuel >= fuelCapacity) { // too much fuel
        fuel = fuelCapacity;
        cout << "Sadly, your tank does not have room, and you spill " << fuelCapacity - (fuelAmount + fuel) << " gallons of fuel on the ground." << endl
             << "This is a fire hazard, and you should probably do something about it, but sadly there is no option to in the menu, so you carry on." << endl;
    } else { // reasonable amount of fuel
        fuel += fuelAmount;
        cout << "You now have " << fuel << " gallons of fuel." << endl;
    }
}

void Car::drive() {
    drive(rand() % 101);
}

void Car::drive(int distance) {
    cout << "You drive " << distance << "miles." << endl;
    if(fuel == 0) { // if no fuel
        cout << "You have no gas, so you get out, and push your car to the destination. You are now very tired. Why on earth did you do that?" << endl;
    } else if(distance / milesPerGallon > fuel) { // if too far for current gas
        fuel = 0;
        odometer += fuel * milesPerGallon;
        cout << "You run out of gas " << fuel * milesPerGallon << "miles short of your destination. You get out, and push your car to the destination. You are now very tired." << endl;
    } else { // if enough fuel
        fuel -= distance / milesPerGallon;
        odometer += distance;
    }
}

void Car::setCar(string make, double milesPerGallon, double fuelCapacity, double fuel, int odometer) {
    this->make = make;
    this->milesPerGallon = milesPerGallon;
    this->fuelCapacity = fuelCapacity;
    if(fuel > fuelCapacity) { // no overfilling
        this->fuel = fuelCapacity;
    } else {
        this->fuel = fuel;
    }
    this->odometer = odometer;
}