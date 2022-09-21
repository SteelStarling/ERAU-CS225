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

void IceCreamCone::display(){ 
  cout<<"Flavor: "<<flavor;
  cout<<" Number Scoops: "<<scoops;
  cout<<" Cone: "<<cone;
  //use std::fixed std::setprecision - to show 2 decimal places
  cout<<" Price: $"<<fixed<<setprecision(2)<<price<<endl;
}

int main()
{
  cout << "What flavor do you want? ";
  string flavor;
  getline(cin, flavor);
  while(cin.)

  IceCreamCone coneA;
  IceCreamCone coneB("chocolate",2,"waffle");
  IceCreamCone coneC("strawberry",4,"sugar");
  coneA.display();
  coneB.display();
  coneC.display();
}
