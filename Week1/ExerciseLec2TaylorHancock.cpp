/***************************************
 * Author:  Taylor Hancock
 * Program: ExerciseLec2TaylorHancock
 * Date:    08/31/2022
 ***************************************/

#include<iostream>
using namespace std;

struct Employee
{
  int idNumber;
  double hourlySalary;
};

int main()
{
  // employee #1
  Employee oneStaffMember;
  oneStaffMember.idNumber = 2345;
  oneStaffMember.hourlySalary = 12.95;

  // employee #2
  Employee anotherStaffMember;
  anotherStaffMember.idNumber = 1729;
  anotherStaffMember.hourlySalary = 15.01;

  // give a raise
  oneStaffMember.hourlySalary += 5;
  anotherStaffMember.hourlySalary += 5;

  // print staff info
  cout << "One Staff Member:" << endl;
  cout << "ID number is "     << oneStaffMember.idNumber << endl;
  cout << "Hourly rate is "   << oneStaffMember.hourlySalary << endl << endl;
  
  // print staff info
  cout << "Another Staff Member:" << endl;
  cout << "ID number is "         << anotherStaffMember.idNumber << endl;
  cout << "Hourly rate is "       << anotherStaffMember.hourlySalary << endl;
  
  return 0;
}