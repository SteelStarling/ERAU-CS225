/*****************************************
 * Author:    Taylor Hancock
 * Purpose:   
 * Version:   1.0 09/20/2022
 * Resources: 
 ******************************************/

#include <iostream>
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
    Car c;
    c.setCar("Honda", 26.2, 14.0, 12.8, 3300);
    int userInput = 0;
    c.showCar();
    return 0;

    do {
        cout << "Select" << endl << "1. Go on a joy ride" << endl << "2. Drive a given distance" << endl << "3. Fuel up" << endl << "4. Exit" << endl;
        cin >> userInput;

    } while (userInput != 4);
}



void Car::setCar(string make, double milesPerGallon, double fuelCapacity, double fuel, int odometer) {
    this->make = make;
    this->milesPerGallon = milesPerGallon;
    this->fuelCapacity = fuelCapacity;
    this->fuel = fuel;
    this->odometer = odometer;
}