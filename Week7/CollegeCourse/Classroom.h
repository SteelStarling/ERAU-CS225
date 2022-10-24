#ifndef CLASSROOM_H
#define CLASSROOM_H

#include <iostream>
using namespace std;

class Classroom {
	private:
		string building;
		int roomNum;
	public:
		Classroom(string, int);
		void display();
};

#endif /* CLASSROOM_H */