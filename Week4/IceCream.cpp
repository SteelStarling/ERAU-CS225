/**************************************************
 * Author: Taylor Hancock
 * Purpose: Learn about class destructors and get more experience using classes
 * Version: 1.0  09/21/2022
 * Resources: N/A
 **************************************************/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class IceCreamCone{
private:
    string flavor;
    int scoops;
    string cone;
    bool sprinkles;
    double price;

  public:
    IceCreamCone(string = "vanilla", int = 1, string = "sugar", bool = false);
    ~IceCreamCone();
    void display();
};

IceCreamCone::~IceCreamCone() {
  cout << "Ice cream eaten!" << endl;
}

IceCreamCone::IceCreamCone(string flav, int numScoops, string coneType, bool hasSprinkles)
{
  const double PRICEPERSCOOP = 0.75;
  const double WAFFLEPREMIUM = 0.40;
  const double SPRINKLESCOST = 0.50;
  flavor = flav;
  scoops = numScoops;
  cone = coneType;
  sprinkles = hasSprinkles;
  price = scoops * PRICEPERSCOOP;
  if(cone == "waffle") {
    price += WAFFLEPREMIUM;
  }
  if(sprinkles) {
    price += SPRINKLESCOST;
  }
}

void IceCreamCone::display() { 
  cout<<"Flavor: "<<flavor;
  cout<<" Number Scoops: "<<scoops;
  cout<<" Cone: "<<cone;
  //use std::fixed std::setprecision - to show 2 decimal places
  cout<<" Has Sprinkles: ";
  if(sprinkles) {
    cout << "Yes";
  } else {
    cout << "No";
  }
  cout<<" Price: $"<<fixed<<setprecision(2)<<price<<endl;
}

int main()
{
  // get flavor
  cout << "What flavor do you want? ";
  string flavor;
  getline(cin, flavor);
  while(!cin) {
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    cout << "ERROR: Invalid Input! Please input a valid string!" << endl << "What flavor do you want? ";
    getline(cin, flavor);
  }

  // get scoops
  cout << "How many scoops do you add? ";
  int numScoops;
  cin >> numScoops;
  while(!cin || numScoops < 0) {
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    cout << "ERROR: Invalid Input! Please input a valid integer value greater than 0!" << endl << "How many scoops do you add? ";
    cin >> numScoops;
  }

  // get cone type
  cout << "What cone type do you want (waffle, sugar, cake)? ";
  string coneType;
  getline(cin, coneType);
  while(!cin || (coneType != "waffle" && coneType != "sugar" && coneType != "cake")) {
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    cout << "ERROR: Invalid Input! Please input a valid string!" << endl << "What cone type do you want? ";
    getline(cin, coneType);
  }

  // get sprinkles
  cout << "Do you want sprinkles (1 = yes, 0 = no)? ";
  int sprinkles;
  cin >> sprinkles;
  while(!cin || (sprinkles != 0 && sprinkles != 1)) {
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    cout << "ERROR: Invalid Input! Please input a valid integer in the range!" << endl << "Do you want sprinkles (1 = yes, 0 = no)? ";
    cin >> sprinkles;
  }

  IceCreamCone coneA(flavor, numScoops, coneType, sprinkles);
  coneA.display();
}
