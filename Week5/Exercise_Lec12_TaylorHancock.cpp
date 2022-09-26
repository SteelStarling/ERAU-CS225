#include <string>
#include <iostream>
using namespace std;

class Pet {
public:
  string name;
  float weight;
  Pet(string name = "Frank", float weight = 3.141592) { this->name = name; this->weight = weight; cout << "Pet is here" << endl; }
  ~Pet() { cout << "Pet is gone" << endl; }
  virtual void sayHello() { cout<<"Greeting"<<endl; }
};

class Cat : public Pet {
public:
  Cat(string name = "Kitty", float weight = 10) { this->name = name; this->weight = weight; cout << "Cat is here" << endl; }
  ~Cat() { cout << "Cat is gone" << endl; }
  void sayHello(){ cout<<"Meow"<<endl; }
  void catchMouse(){ };
};

class Dog : public Pet {
public:
  Dog(string name = "Fido", float weight = 20) { this->name = name; this->weight = weight; cout << "Dog is here" << endl; }
  ~Dog() { cout << "Dog is gone" << endl; }
  void sayHello(){ cout<<"Woof"<<endl; }
};

class Bird : public Pet {
public:
  Bird(string name = "Birdy", float weight = 1) { this->name = name; this->weight = weight; cout << "Bird is here" << endl; }
  ~Bird() { cout << "Bird is gone" << endl; }
  void sayHello(){ cout << "Chirp" << endl; }
};

  
int main () {
  const int NUM = 3;
  string type;

  Pet *pets[NUM];
  for (int x = 0; x < NUM; x++){
    cout << "Is pet #" << x+1 << " a cat, dog, or bird?" << endl;
    cin >> type;
    if(type == "cat") {
      pets[x] = new Cat;
    } else if(type == "dog") {
      pets[x] = new Dog;
    } else {
      pets[x] = new Bird;
    }
  }

  cout<<"Pet greetings..."<<endl;
  for (int x=0; x<NUM; x++){
    pets[x]->sayHello();
    delete pets[x];
  }
  return 0;
}