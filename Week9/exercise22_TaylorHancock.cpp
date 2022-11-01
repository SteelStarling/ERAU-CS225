#include <iostream>
using namespace std;

int main() {
    const int numInts = 5;

    for(int i = 0; i < numInts; i++) {
        cout << "Enter a decimal number: ";
        int val;
        cin >> val;
        cin.ignore(INT_MAX, '\n');
        cout << "Enter h (for hex), d (for decimal), or o (for octal): ";
        char c;
        cin >> c;
        cin.ignore(INT_MAX, '\n');

        if(c == 'h') {
            cout.unsetf(ios::dec | ios::oct);
            cout.setf(ios::hex | ios::showbase);
        } else if(c == 'd') {
            cout.unsetf(ios::hex | ios::oct);
            cout.setf(ios::dec | ios::showbase);
        } else {
            cout.unsetf(ios::dec | ios::hex);
            cout.setf(ios::oct | ios::showbase);
        }

        cout << val << endl;
    }
}