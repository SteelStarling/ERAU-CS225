#include <iostream>
#include <random>
#include <fstream>
using namespace std;

int main() {
    ofstream fout("numbers.txt");
    if(fout.good()) { // only run if good
        for(int i = 0; i < 50; i++) {
            fout << (rand() % 100) + 1 << endl;
        }
    } else {
        perror("ofstream failed");
    }

    ifstream fin("numbers.txt");
    int min = INT_MAX;
    int max = 0;
    int avg = 0;
    if(fin.good()) {
        for(int i = 0; i < 50; i++) {
            int val;
            fin >> val;
            if(val < min) {
                min = val;
            }
            if(val > max) {
                max = val;
            }
            avg += val;
        }
        avg /= 50;

        cout << "Min: " << min << endl;
        cout << "Max: " << max << endl;
        cout << "Avg: " << avg << endl;
    } else {
        perror("ifstream failed");
    }
}