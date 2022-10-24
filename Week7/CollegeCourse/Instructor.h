#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

#include <iostream>
using namespace std;

class Instructor {
	private:
		string fname;
		string lname;
		int officeNum;
	public:
		Instructor(string, string, int);
		void display();
};

#endif /* INSTRUCTOR_H */