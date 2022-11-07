#include <iostream>
using namespace std;

void enterPassword();

int main() {
    try {
        enterPassword();
    } catch(string msg) {
        cout << msg << endl;
    }
}

void enterPassword() {
    cout << "Please enter a password: ";
    string password;
    getline(cin, password);

    if(password.length() < 8) {
        throw(string("ERROR: Password must be over 8 characters long!"));
    } else if(!(password.compare("password") && password.compare("password"))) {
        throw(string("ERROR: Password must not be based on a dictionary word!"));
    }
}

