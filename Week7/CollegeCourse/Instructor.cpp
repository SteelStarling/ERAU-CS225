/**************************************************
 * File:      Instructor.cpp
 * Author:    Taylor Hancock
 * Purpose:   Practice working with .h files
 * Version:   1.1 Oct 12, 2022
 * Resources: Lecture notes
 **************************************************/

#include <iostream>
using namespace std;

#include "Instructor.h"

// creates an instructor
Instructor::Instructor(string first, string last, int num) {
	fname = first;
	lname = last;
	officeNum = num;
}

// displays values
void Instructor::display() {
	cout << "Instructor: " << fname << " " << lname << endl;
	cout << "Office: " << officeNum << endl;
}