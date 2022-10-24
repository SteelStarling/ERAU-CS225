/**************************************************
 * File:      CollegeCourse.cpp
 * Author:    Taylor Hancock
 * Purpose:   Practice working with .h files
 * Version:   1.1 Oct 12, 2022
 * Resources: Lecture notes
 **************************************************/

#include <iostream>
using namespace std;

#include "CollegeCourse.h"

CollegeCourse::CollegeCourse(string instructorFirst, string instructorLast,
					          int instructorOfficeNum, string buildingName,
					          int roomNum, int credits) :
					          instructor(instructorFirst, instructorLast,
					          instructorOfficeNum),
					          room(buildingName, roomNum)
					          { this->credits = credits; }

void CollegeCourse::display() {
	instructor.display();
	room.display();
	cout << "Credits: " << credits << endl;
}