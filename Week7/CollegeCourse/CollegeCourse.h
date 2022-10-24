#ifndef COLLEGECOURSE_H
#define COLLEGECOURSE_H

#include <iostream>
using namespace std;

#include "Instructor.h"
#include "Classroom.h"

class CollegeCourse {
	private:
		Instructor instructor;
		Classroom room;
		int credits;
	public:
		CollegeCourse(string instructorFirst, string instructorLast,
					  int instructorOfficeNum, string buildingName,
					  int roomNum, int credits);

		void display();
};

#endif /* COLLEGECOURSE_H */