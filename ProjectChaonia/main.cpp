#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

void printSlow(string str, int timeBetween);

int main() {
    printSlow("Hello, world! How are you doing today, I hope that you are doing well, lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.", 50);
    return 0;
}

void printSlow(string str, int timeBetween) {
    int curTime = 0;
    char c = '~';
    for(int i = 0; i < str.length(); i++) {
        c = str.at(i);
        cout << c;
        curTime += timeBetween;
        switch(c) {
            case ' ':
            case '\n':
                std::this_thread::sleep_for(std::chrono::milliseconds(curTime));
                curTime = 0;
        }
    }
}