#include <iostream>
#include <string>
using namespace std;

class Dog
{
  friend ostream& operator<<(ostream&, const Dog&);
  friend istream& operator>>(istream&, Dog&);

  private:
    string breed;
    string eyeColor;
};

ostream& operator<<(ostream &out, const Dog &dog)
{
  out<<dog.breed<<" with "<<
    dog.eyeColor<<" eyes";
  return out;
}

istream& operator>>(istream &in, Dog &dog)
{
  cout<<"Enter dog breed: ";
  in>>dog.breed;
  cout<<"Enter eye color: ";
  in>>dog.eyeColor;
  return in;
}

class PetStore {
  friend ostream& operator<<(ostream&, const PetStore&);

  private: 
    Dog* dogs;
    int numDogs;
  public:
    PetStore();
    ~PetStore();
};

PetStore::PetStore(){
  // get number of dogs
  cout << "How many dogs should be in the store? ";
  cin >> numDogs;
  while(!cin || numDogs < 0) { // error handling
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    cout << "ERROR: Invalid input! Number of dogs must be positive integer!" << endl;
    cout << "How many dogs should be in the store? ";
    cin >> numDogs;
  }

  dogs = new Dog[numDogs]; // allocate memory for dogs

  for(int i = 0; i < numDogs; i++) {
    cin >> dogs[i];
  }
}
PetStore::~PetStore(){
  delete dogs;
}

ostream& operator<<(ostream &out, const PetStore &ps)
{
  out << "Pet Store Dogs......" << endl;

  for(int i = 0; i < ps.numDogs; i++) {
    cout << ps.dogs[i] << endl;
  }

  return out;
}


int main()
{
  PetStore ps;
  cout<<ps;
  return 0;
}
