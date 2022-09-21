/*****************************
 * Author: Taylor Hancock (for one line, the rest were provided by Prof. Marriott)
 * Purpose: Quiz 3!
 * Version: 1.0 09/19/2022
 * Resources: Lecture #9
 *****************************/

#include <iostream>
#include <string>
using namespace std; // this was missing

string combineStrings(string & s1, string & s2)
{
    string temp;

    temp = "===>"+s1 +" "+ s2;
    return temp;
}

int main()
{
    string beginning="Hello", input ;
    string result;

    cout << "Enter a name: ";
    getline(cin, input);
 
    result = combineStrings(beginning, input);
    cout << "Result: " << result << endl;
    return 0;
}