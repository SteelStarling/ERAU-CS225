/**************************************************
 * File:      Classroom.cpp
 * Author:    Taylor Hancock
 * Purpose:   Practice working with .h files
 * Version:   1.1 Oct 12, 2022
 * Resources: Lecture notes
 **************************************************/

#include <iostream>
using namespace std;

#include "Classroom.h"

// creates a classroom
Classroom::Classroom(string b, int num) {
	building = b;
	roomNum = num;
}

// displays classroom info
void Classroom::display() {
	cout << "Classroom: " << building << " " << roomNum << endl;
}