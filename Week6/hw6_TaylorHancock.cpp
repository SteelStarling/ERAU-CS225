/**************************************************
 * File:      hw6_TaylorHancock.cpp
 * Author:    Taylor Hancock
 * Purpose:   Get practice working with polymorphism and arrays of pointers to a parent class
 * Version:   1.0 Oct 03, 2022
 * Resources: Course notes for Lecture 12 to check my work
 **************************************************/

#include <iostream>
#include <random>
#include <string>
using namespace std;

class Monster {
    protected:
        static int numMonsters;
        int strength;
    public:
        Monster() {
            strength = (rand() % 30) + 1;
            numMonsters++;
            cout << "Monster #" << numMonsters << " with strength " << strength << " appears" << endl;
        }
        int getStrength() { return strength; }
        virtual void speak() { cout << "Boo" << endl; }
};

int Monster::numMonsters = 0;

class Zombie : public Monster {
    public:
        Zombie() { cout << "  It's a Zombie!" << endl; }
        void speak() { cout << "Brains!" << endl; }
};

class Werewolf : public Monster {
    public:
        Werewolf() { cout << "  It's a Werewolf!" << endl; }
        void speak() { cout << "Awoo!" << endl; }
};

class Vampire : public Monster {
    public:
        Vampire() { cout << "  It's a Vampire!" << endl; }
        void speak() { cout << "One *hahaha* Two *hahaha* Three *hahaha*..." << endl; }
};

string toLower(string input);
Monster* createMonster();


int main() {

    const int numMonsters = 5;
    Monster* monsterArr[numMonsters];

    for(int i = 0; i < numMonsters; i++) { // create monsters
        monsterArr[i] = createMonster();
    }

    cout << endl << "Monster Greetings:" << endl; // new line and header to make parsing easier

    int sumStr = 0; // holds total strength
    for(int i = 0; i < numMonsters; i++) { // speak and sum strength
        monsterArr[i]->speak();
        sumStr += monsterArr[i]->getStrength();
    }

    cout << "Total strength of the monsters is: " << sumStr << endl;

    return 0;
}


// converts a string to lowercase
string toLower(string input) {
    for(int i = 0; i < input.length(); i++) {
        input[i] = tolower(input[i]);
    }

    return input;
}

// creates a monster
Monster* createMonster() {
    Monster* m;
    string type;

    cout << "Please enter the monster type you wish to use (Zombie, Vampire, Werewolf): ";
    getline(cin, type);

    type = toLower(type); // convert to lower for better reading

    while(type != "werewolf" && type != "vampire" && type != "zombie") { // error checking!
        cout << "ERROR: Inputs must be either werewolf, vampire, or zombie (case insensitive)!" << endl;
        cout << "Please enter the monster type you wish to use (Zombie, Vampire, Werewolf): ";
        getline(cin, type);

        type = toLower(type); // convert to lower for better reading
    }

    if(type == "werewolf") { // if werewolf, create werewolf and cast to monster
        m = new Werewolf;
    } else if(type == "vampire") { // if vampire, create vampire and cast to monster
        m = new Vampire;
    } else {  // if zombie (other options checked), create zombie and cast to monster
        m = new Zombie;
    }

    return m;
}