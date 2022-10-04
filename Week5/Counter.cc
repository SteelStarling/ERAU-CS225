#include <iostream>
using namespace std;

class Counter {
  private:
    static int counter; 
    static int num;
  public:
    void increaseCounter();
    void decreaseCounter();
    static void setCounter(int x);
    void countDown();
    Counter() {
      num++;
      cout << "Counter " << num << " created" << endl;
    }
    ~Counter() {
      cout << "Counter " << num << " destroyed" << endl;
      num--;
    }
};

int Counter::counter = 1;
int Counter::num = 0;

void Counter::increaseCounter() {
  counter++;
}

void Counter::decreaseCounter() {
  counter--;
}

void Counter::setCounter(int x) {
  counter = x;
}

void Counter::countDown() {
  for(int i = counter; i > 0; i--) {
    cout<<i<<" ";
  }
  cout<<endl;
}

int main () {
  // Counter c;
  // c.setCounter(10);
  // c.countDown();
  // c.decreaseCounter();
  // c.countDown();
  // Counter::setCounter(4);
  // c.increaseCounter();
  // c.countDown();

  Counter c1;
  Counter c2;
  Counter c3;
  return 0;
}
