/**************************************************
 * File:      Animals.cpp
 * Author:    Taylor Hancock
 * Purpose:   
 * Version:   1.0 Oct 03, 2022
 * Resources: 
 **************************************************/

#include <iostream>
#include <string>
using namespace std;


class Animal {
protected:
    string name;
public:
    virtual void eat(){ cout<<"Animal eating"<<endl; };
};


class Mammal : virtual public Animal {
public:
    void breathe(){};
    virtual void eat(){ cout << "Mammal eating" << endl; }
};


class FlyingAnimal : virtual public Animal {
public:
    void fly(){};
    virtual void eat(){ cout << "Flyer eating" << endl; }
};

class Bat : public FlyingAnimal, public Mammal {
public:
    Bat(string name) {
        this->name = name;
    }
    void eat() { cout << "Bat eating" << endl; }
    void display() { cout << "Name is " << name << endl; }
};

int main(){
    FlyingAnimal f;
    Animal& a = f;
    a.eat();
    Animal a2;
    a2.eat();
    Bat b("Batman");
    b.fly();
    b.eat();
    b.breathe();
    b.display();
    return 0;
}