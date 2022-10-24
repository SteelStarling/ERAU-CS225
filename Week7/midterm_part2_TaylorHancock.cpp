/**************************************************
 * File:      midterm_part2_TaylorHancock.cpp
 * Author:    Taylor Hancock
 * Purpose:   Complete part 2 of the midterm :)
 * Version:   1.0 Oct 11, 2022
 * Resources: My solutions to HW5 and HW6
 **************************************************/

#include <iostream>
using namespace std;

class Book {
    private:
        string title;
        int pageCount;
    public:
        Book(string title = "Default Book", int pageCount = 42);
        string getTitle() { return title; }
        int getPageCount() { return pageCount; }
        void setValues(string title, int pageCount);
        virtual void display() { cout << "Book: " << title << ", " << pageCount << " pages" << endl; };
};

// book constructor
Book::Book(string title, int pageCount) {
    setValues(title, pageCount); // handle everything
}

// sets the values of a book class
void Book::setValues(string title, int pageCount) {
    this->title = title;
    if(pageCount < 0) { // ensure no negative books
        this->pageCount = 100;
    } else {
        this->pageCount = pageCount;
    }
    
}


class AudioBook : public Book {
    private:
        string reader;
    public:
        AudioBook(string title = "Default Audiobook", int pages = 42, string reader = "Narrator");
        ~AudioBook() { cout << "Finished listening to " << getTitle() << endl; }
        void display() { cout << "AudioBook: " << getTitle() << ", " << getPageCount() << " pages read by " << reader << endl; }
};

AudioBook::AudioBook(string title, int pageCount, string reader) {
    setValues(title, pageCount);
    this->reader = reader;
}

int getUserInt(string prompt);


int main() {

    const int numBooks = 10;

    // this is actually the last audiobook I listened to
    AudioBook a("The Murder on the Links", 298, "BJ Harrison");
    a.display();

    // initialize book array
    Book* library[numBooks];
    int libSize = 0; // number of books stored in the array

    for(libSize = 0; libSize < numBooks; libSize++) {
        // initialize default book
        library[libSize] = new Book();

        // read input
        cout << "What is book #" << (libSize + 1) << "'s title? ";
        string title;
        getline(cin, title);

        int pageCount = getUserInt("How many pages does it have? ");

        // set values of book
        library[libSize]->setValues(title, pageCount);

        // handle more inputs (don't ask on last loop, because redundant)
        if(libSize != numBooks - 1) {
            cout << "Read more books? (y/n) ";
            char c = ' '; // initialize with value other than y or n
            cin >> c;
            while(c != 'y' && c != 'n') { // error handling
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cout << "ERROR: Invalid input! Input must be 'y' or 'n'" << endl;
                cout << "Read more books? (y/n) ";
                cin >> c;
            }

            cin.ignore(INT_MAX, '\n');

            if(c == 'n') { // if c is given n, stop looping
                break;
            }
        }
    }

    // display books
    cout << "-------- The Library --------" << endl;
    for(int i = 0; i <= libSize; i++) {
        library[i]->display();
        delete library[i];
    }

    return 0;
}

// gets an integer from a user, providing them with a given prompt
//     This function is borrowed from my solution to HW5
int getUserInt(string prompt) {
    int input;
    cout << prompt;
    cin >> input;
    while(!cin) { // ensure valid input
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "ERROR: Invalid integer! Please input a valid integer!" << endl;
        cout << prompt;
        cin >> input;
    }

    return input;
}