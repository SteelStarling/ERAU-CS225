#include <iostream>
#include <string>
using namespace std;

class Pokemon {
    private:
        string name;
        int cp;
    public:
        Pokemon(string n, int power = 10) { name = n; cp = power; }
        friend ostream& operator<<(ostream &os, const Pokemon&);
        int operator+(const Pokemon &p);
        bool operator>(const Pokemon &p);
};

ostream& operator<<(ostream &os, const Pokemon &p) {
  os << "The Pokemon " << p.name << " with a combat power of " << p.cp;
  return os;
}

bool Pokemon::operator>(const Pokemon &p) {
  bool val = cp > p.cp;
  return val;
}

int Pokemon::operator+(const Pokemon &p) {
  int totCP = cp + p.cp;
  return totCP;
}

int main(){
  Pokemon p("Pikachu", 250);
  Pokemon p2("Arceus", 470);
  cout << p << endl; 
  cout << p2 << endl;

  cout << "p + p2 = " << (p + p2) << endl;

  Pokemon e("Eevee", 50);
  if (p > e) {
    cout << p << " is the strongest!!!" << endl;
  }
  else {
    cout << e << " is strongest!!!" << endl;
  }

  return 0;
}