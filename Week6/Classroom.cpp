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

Classroom::Classroom(string b, int num) {
	building = b;
	roomNum = num;
}

void Classroom::display() {
	cout << "Classroom: " << building << " " << roomNum << endl;
}

class Instructor {
	private:
		string fname;
		string lname;
		int officeNum;
	public:
		Instructor(string, string, int);
		void display();
};

Instructor::Instructor(string first, string last, int num) {
	fname = first;
	lname = last;
	officeNum = num;
}

void Instructor::display() {
	cout << "Instructor: " << fname << " " << lname << endl;
	cout << "Office: " << officeNum << endl;
}

class CollegeCourse {
	private:
		Instructor instructor;
		Classroom room;
		int credits;
	public:
		CollegeCourse(string instructorFirst, string instructorLast,
					  int instructorOfficeNum, string buildingName,
					  int roomNum, int credits) :
					  instructor(instructorFirst, instructorLast,
					  instructorOfficeNum),
					  room(buildingName, roomNum)
					  { this->credits = credits; }

		void display() {
			instructor.display();
			room.display();
			cout << "Credits: " << credits << endl;
		}
};

int main() {
	CollegeCourse cs125("Steve", "France", 42, "STEM Building", 123, 3); // room numbers and credits are random, because I cannot for the life of me remember them
	CollegeCourse cs225("Heather", "Marriott", 1729, "STEM Building", 124, 3);

	cs125.display();
	cs225.display();
}