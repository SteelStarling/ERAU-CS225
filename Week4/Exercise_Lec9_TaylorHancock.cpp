#include<iostream>
#include<string>
using namespace std;

class CS225 {
    private:
        int numStudents;
    public:
        void setInitialNum(int n) { numStudents = n;  }
        void drop() { numStudents--;  }
        int  getNum() { return numStudents; }
};

void recruiter(CS225& myClass) {
    //A recruiter comes and offers jobs to
    //2 students.  So they drop the class
    myClass.drop();
    myClass.drop();
    cout << "After recruiter, class size: " << myClass.getNum() << " students" << endl;
}

void display(CS225& myClass) {
    cout << "Class size: " << myClass.getNum() << " students" << endl;
}

CS225 combine(CS225& class1, CS225& class2) {
    CS225 combo;
    combo.setInitialNum(class1.getNum() + class2.getNum()); // combine
    return combo;
}

int main() {
    CS225 my8amClass;
    my8amClass.setInitialNum(27);
    my8amClass.drop();
    display(my8amClass);
    recruiter(my8amClass);
    display(my8amClass);
    CS225 theSuperior3pmClass;
    theSuperior3pmClass.setInitialNum(35);
    display(theSuperior3pmClass);

    CS225 combo = combine(my8amClass, theSuperior3pmClass);
    display(combo);
}
