/**************************************************
 * File:      main.cpp
 * Author:    Taylor Hancock
 * Purpose:   Practice working with .h files
 * Version:   1.1 Oct 12, 2022
 * Resources: Lecture notes
 **************************************************/

#include <iostream>
using namespace std;

#include "CollegeCourse.h"

int main() {
	CollegeCourse cs125("Steve", "France", 42, "STEM Building", 123, 3); // room numbers and credits are random, because I cannot for the life of me remember them
	CollegeCourse cs225("Heather", "Marriott", 1729, "STEM Building", 124, 3);

	cs125.display();
	cout << "*******************************" << endl;
	cs225.display();
}