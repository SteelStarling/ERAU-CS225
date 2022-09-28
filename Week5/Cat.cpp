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

	void greeting(string saying) { 
		cout << name << " (" << weight << ") pounds";
	    cout<< " says " << saying << endl;
	}
};

class Cat : public Pet {
public:
	//Note: the line below is correct.
	//to call a non-default parent constructor - use
	//an initialization list.
	Cat(float weight, string name):Pet(weight, name) {  }
	Cat(string name) : Pet(10, name) { }
	
};

int main() {
	Cat garfield(35, "Garfield");
	Cat theInternationalStandardCat("Standard Cat");
	garfield.greeting("Hi");
	theInternationalStandardCat.greeting("Boy oh boy, am I a standard cat by international treaty!");
	Pet* mystery;

	// no data checking for now
	string type;
	cout << "Would you like a Cat or a Pet (answer in lowercase)? ";
	cin >> type;
	if(type == "pet") {
		
	} else {
		
	}
	return 0;
}