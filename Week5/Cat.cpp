/**************************************************
 * File:      Cat.cpp
 * Author:    Taylor Hancock (with 95% of the core stuff provided by Dr. Marriott)
 * Purpose:   To get practice with the "this" keyword
 * Version:   1.0 Sep 28, 2022
 * Resources: Lecture notes
 **************************************************/

#include <string>
#include <iostream>
using namespace std;

class Pet {
private:
	float weight;
	string name;
public:
	Pet(float weight, string name) {
		// moved setting values to *before* they're printed just for the sake of best practices
		this->weight = weight;
		this->name = name;

		cout << "In pet constructor: weight = " << weight;
		cout << " name = " << name << endl;
	}

	Pet();

	virtual void greeting(string saying) { 
		cout << name << " (" << weight << ") pounds";
	    cout<< " says " << saying << endl;
	}
};

Pet::Pet() {
	cout << "Input the weight: ";
	cin >> weight;
	while(!cin || weight <= 0) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "ERROR: Invalid weight! Must be float and greater than 0!" << endl;
		cout << "Input the weight: ";
		cin >> weight;
	}

	cin.ignore(INT_MAX, '\n'); // ignore before searching (prevents weird bugs)

	cout << "Input the name: ";
	getline(cin, name);
}

class Cat : public Pet {
public:
	//Note: the line below is correct.
	//to call a non-default parent constructor - use
	//an initialization list.
	Cat(float weight, string name):Pet(weight, name) {  }
	Cat(string name) : Pet(10, name) { }
	Cat() : Pet() { }

	void greeting(string saying) {
		cout << "The cat says " << saying << endl;
	}
	
};

int main() {
	Cat garfield(35, "Garfield");
	Cat theInternationalStandardCat("Standard Cat");
	garfield.greeting("Hi");
	theInternationalStandardCat.greeting("Boy oh boy, am I a standard cat by international treaty!");
	Pet* mystery;

	string type;
	cout << "Would you like a Cat or a Pet (answer in lowercase)? ";
	cin >> type;
	// data checking
	while(type != "pet" && type != "cat") {
		cout << "ERROR: Invalid type!" << endl;
		cout << "Would you like a Cat or a Pet (answer in lowercase)? ";
		cin >> type;
	}

	if(type == "pet") {
		mystery = new Pet();
	} else if(type == "cat") {
		mystery = new Cat();
	}

	mystery->greeting("Aloha");
	return 0;
}