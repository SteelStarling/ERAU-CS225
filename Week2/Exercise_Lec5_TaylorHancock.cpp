#include <iostream>
using namespace std;

void displayMessage();
void displayMessage(int n);
// float displayMessage(int n); // no, you can't overload via return types
void displayMessage(string name);

int main() {
    displayMessage();
    displayMessage(5);
    displayMessage('!'); // it prints it that char's ASCII value times
    displayMessage("Steve");
}

void displayMessage() {
    cout << "Hello There" << endl;
}

void displayMessage(int n) {
    for(int i = 0; i < n; i++) {
        cout << "Hello There!" << endl;
    }
}

void displayMessage(string name) {
    cout << "Hello There " << name << endl;
}