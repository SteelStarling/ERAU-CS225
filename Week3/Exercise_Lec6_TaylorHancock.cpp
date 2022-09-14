#include<iostream>
#include<string>
#include<windows.h>
using namespace std;

class Balloon {  //class definition
private:    //member variables
	int length;
	string color;
	bool broken;
	bool inflated;
public:     //member function prototypes �
	void setValues(string color);
	void inflate(int increase);
    void pop();
};

void Balloon::setValues(string c) {
	const int INITIALSIZE = 11;
	length = INITIALSIZE;
	color = c;
	inflated = false;
	broken = false;
}
void Balloon::inflate(int len) {
	const int MAXBALLOONSIZE = 36;
	if (!broken) {
		inflated = true;
		for (int x = 0; x < len; x++) {
			length += 1;
			cout << "New balloon size " << length << endl;
			if (length > MAXBALLOONSIZE) {
				pop();
				break;
			}
			Sleep(1000);
		}
	}
	else {
		cout << "Can't inflate broken balloon." << endl;
	}
}
void Balloon::pop() {
    if(!broken && inflated) {
        broken = true;
        inflated = false;
        length = 0;
        cout << "Balloon popped :( " << endl;
    }
}
int main()
{
	Balloon b1;
	b1.setValues("green");
	Balloon b2;
	b2.setValues("red");
	Balloon b3;
	b3.setValues("yellow");
	b3.inflate(10);
	return 0;
}
