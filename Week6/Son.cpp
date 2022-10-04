/**************************************************
 * File:      Son.cpp
 * Author:    Taylor Hancock
 * Purpose:   
 * Version:   1.0 Oct 03, 2022
 * Resources: 
 **************************************************/

#include <iostream>
#include <string>
using namespace std;

class Mother {
  protected:
    string eyeColor;
    string hairColor;
  public:
    Mother() { eyeColor = "brown";  hairColor = "brown"; }
};

class Father {
  protected:
    string eyeColor;
    float height;
  public:
    Father() { eyeColor = "blue"; height = 6.2; }
};

class Son : public Mother, public Father {
  public:
    void display();
};

void Son::display(){   // FILL IN CODE HERE
}

int main () {
  Son ivan;
  ivan.display();
}

