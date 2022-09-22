/*****************************************
 * Author:    Taylor Hancock
 * Purpose:   Practice working with classes and their basic operations
 * Version:   1.0 09/20/2022
 * Resources: N/A
 ******************************************/

#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

class Car {
    private:
        string make;            // the car's make
        double milesPerGallon;  // the car's miles per gallon
        double fuel;            // the amount of fuel in the car's tank
        double fuelCapacity;    // the car's fuel capacity
        int odometer;           // the reading on the car's odometer (miles driven)
    public:
        string getMake() {return make;}
        double getMilesPerGallon() {return milesPerGallon;}
        double getFuel() {return fuel;}
        double getFuelCapacity() {return fuelCapacity;}
        void showCar();                 // prints info about the car
        void fuelUp(double fuelAmount); // fuels the car up by some amount (or can siphon fuel from the tank)
        void drive();                   // has the car drive some distance between 0-100 miles
        void drive(int distance);       // drives the car some number of miles
        void setCar(string make, double milesPerGallon, double fuelCapacity, double fuel, int odometer); // initializes the car (should probably be a constructor, but the homework doesn't say to do that)
};

int main() {
    srand(time(NULL));   // initialize srand

    // setup car
    Car c;
    c.setCar("Honda", 26.2, 14.0, 12.8, 3300);
    int userInput = 0;

    do {
        c.showCar();
        cout << "Select" << endl << "1. Go on a joy ride" << endl << "2. Drive a given distance" << endl << "3. Fuel up" << endl << "4. Exit" << endl;
        cin >> userInput;
        if(!cin) { // if cin is invalid
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "Error: Invalid Input! Please input a valid integer in the range 1-4!" << endl;
        } else if(userInput == 1) { // joy ride
            c.drive();
        } else if(userInput == 2) { // drive a distance
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
        } else if(userInput == 3) { // add fuel
            cout << "How much fuel do you add? ";
            double fuelAmt;
            cin >> fuelAmt;
            while(!cin) {
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cout << "ERROR: Invalid Input! Please input a valid double value!" << endl << "How much fuel do you add? ";
                cin >> fuelAmt;
            }
            c.fuelUp(fuelAmt);
        }
    } while (userInput != 4); // exit loop

    cout << "You are done driving for today! Goodbye." << endl;

    return 0;
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
    if(fuelAmount < 0) { // if negative fuel
        cout << "You...you input a negative...uhh...sure, I guess we'll siphon " << fuelAmount * -1 << " gallons of fuel out of your tank." << endl;
    } else if(fuelAmount == 0) { // if zero fuel
        cout << "...this just entails doing nothing, but sure, you add a whopping zero gallons of fuel to your tank. Great job." << endl;
    } else { // if fuel
        cout << "You fill your tank with " << fuelAmount << " gallons of fuel." << endl;
    }
    if(fuelAmount + fuel > fuelCapacity) { // too much fuel
        cout << "Sadly, your tank does not have room, and you spill " << (fuelAmount + fuel) - fuelCapacity << " gallons of fuel on the ground." << endl
            << "This is a fire hazard, and you should probably do something about it, but sadly there is no option to in the menu, so you carry on." << endl;
        fuel = fuelCapacity;
    } else if(fuelAmount + fuel < 0) { // if the amount drops the tank below 0 (for negatives "siphoning")
        cout << "You run out of fuel before you can siphon " << fuelAmount * -1 << " gallons out of your tank, but you now have zero gallons of fuel in your tank." << endl;
        fuel = 0;
    } else { // reasonable amount of fuel
        fuel += fuelAmount;
        cout << "You now have " << fuel << " gallons of fuel." << endl;
    }
}

void Car::drive() {
    drive(rand() % 101); // drive a random distance from 0 to 100
}

void Car::drive(int distance) {
    if(distance == 0) { // if 0 distance
        cout << "You...you want to drive no distance? Why...why did you even put that in? Do you want me to congratulate you? Wow, you've driven 0 miles! *sigh*" << endl;
    } else { // if not zero, print distance
        if(distance < 0) { // if negative distance
            cout << "You seriously expect to drive a negative distance? I'm just gonna interpret that as a positive value." << endl;
            distance *= -1; // flip sign of distance
        }
        cout << "You drive " << distance << " miles." << endl;
        if(fuel == 0) { // if no fuel
            cout << "You have no gas, so you get out, and push your car to the destination. You are now very tired. Why on earth did you do that?" << endl;
        } else if(distance / milesPerGallon > fuel) { // if too far for current gas
            odometer += fuel * milesPerGallon; // your odometer is electric and doesn't run when the car is off (mental reason for why you can push the car but not rack up driven miles)
            cout << "You run out of gas " << fuel * milesPerGallon << "miles short of your destination. You get out, and push your car to the destination. You are now very tired." << endl;
            fuel = 0;
        } else { // if enough fuel
            fuel -= distance / milesPerGallon;
            odometer += distance;
        }
    }
}

// we'll just assume set car is being used safely in this instance, as the inputs are being checked when users input (I know it's not best practices, but I figure it should be enough for this assignment)
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