/**************************************************
 * File:      Pizza.cpp
 * Author:    Taylor Hancock (editing a file created by Prof. Marriott)
 * Purpose:   Practice operator overloading
 * Version:   1.0 Oct 10, 2022
 * Resources: Lecture 18 slides
 **************************************************/

#include <iostream>
#include <string>
using namespace std;

class Pizza {
  private:
    string topping;
    int diameter;
    double price;
    const static string STDTOP;
    const static int STDSIZE;
    const static double STDPRICE;
  public:
    Pizza(const string = STDTOP, const int = STDSIZE, const double = STDPRICE);
    friend ostream& operator<<(ostream &os, const Pizza &p);
    Pizza operator++(int x);
    void setValues();
    void displayValues();

};

const string Pizza::STDTOP = "cheese";
const int Pizza::STDSIZE = 12;
const double Pizza::STDPRICE = 8.99;

Pizza::Pizza(const string top, const int size, const double price) {
  topping = top;
  diameter = size;
  this->price = price;
}

void Pizza::displayValues() {
  cout << "a " << diameter << " inch " << topping << " pizza. Price $" << price << endl;
}

void Pizza::setValues() {
  const double TOPPINGPREMIUM = 1.00;
  const double SIZEPREMIUM = 1.50;
  cout << "Enter topping ";
  cin >> topping;
  if(topping != STDTOP)
    price = STDPRICE + TOPPINGPREMIUM;
  cout << "Enter size ";
  cin >> diameter;
  if(diameter > STDSIZE)
    price += SIZEPREMIUM;
}

// new displayValues system
ostream& operator<<(ostream &os, const Pizza &p) {
  os << "a " << p.diameter << " inch " << p.topping << " pizza. Price $" << p.price << endl;
  return os;
}

// new postincrement operator
Pizza Pizza::operator++(int x) { // post-increment
  Pizza temp = (*this);
  price++;
  return temp;
}

int main() {
  Pizza aPizza;
  char standard;
  cout << "The standard pizza is: ";
  cout << aPizza;
  aPizza++;
  aPizza++;
  cout << "Or, with 2 dollars of extra tips: ";
  cout << aPizza;
  Pizza bPizza;
  cout << "Let me take your order" << endl;
  cout << "Do you want the standard pizza - y or n? ";
  cin >> standard;
  if(standard != 'y') {
    bPizza.setValues();
  }
  cout << "Your order is ";
  cout << bPizza;
}
   
