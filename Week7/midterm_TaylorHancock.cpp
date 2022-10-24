/**************************************************
 * File:      midterm_TaylorHancock.cpp
 * Author:    Taylor Hancock
 * Purpose:   
 * Version:   1.0 Oct 10, 2022
 * Resources: 
 **************************************************/

#include <iostream>
#include <random>
using namespace std;

class Player {
    private:
        int money;
        string name;
    public:
        Player(string name, int money = 10) : name(name), money(money) {}
        ~Player() { cout << "Player " << name << " ended the game with $" << money << endl; }
        void setMoney(int money) { this->money = money; }
        int getMoney() { return money; }
};

class CoinTossGame {
    public:
        // while I normally hate the ternary logic operator, it helps here
        static char flip() { return (rand() % 2) ? 'h' : 't'; }
};

int main() {
    
    return 0;
}