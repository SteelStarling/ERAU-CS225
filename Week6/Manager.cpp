#include <iostream>
using namespace std;

class Salary {
private:
	double healthBenefits;
	double travelAllowance;
	double salary;
public:
	double getSalary() { return salary; }
	void setSalary(double s) { salary = s; }
	Salary(double salary) { this->salary = salary; }
};

class Employee {
private:
	int empno;
	Salary salary; //composition: salary object is contained inside employee
public:
	Employee(int = 999);
	void display() {
		cout << "Employee #:" << empno << " salary:" << salary.getSalary() << endl;
	}
};
Employee::Employee(int num) : salary(40000) {
	empno = num;
}


class Manager {
private:
	int empno;
	Salary salary; //composition: salary object is contained inside employee
	Employee employees[20];
public:
	Manager() : salary(100000){}
};

int main() {
	Manager jim;
}

