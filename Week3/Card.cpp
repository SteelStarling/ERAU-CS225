/**************************************************
 * File:      Card.cpp
 * Author:    Taylor Hancock
 * Purpose:   Learn about scopes and inline functions
 * Version:   1.0 Sep 14, 2022
 * Resources: N/A
 **************************************************/

#include <iostream>
#include <string>
using namespace std;

class Card {
  private:
    int rank;  //to make simpler Ace=11, Queen,Jack,King=10
    string suit;
  public:
    void setValues(int r = 2, string s = "Clubs") {
        suit = s;
        if(r < 2 || r > 11) {
            cout << "ERROR: Set Values only accepts ranks from 2-11!" << endl;
            rank = 2;
        } else {
            rank = r; 
        }
    }
    int getRank() { return rank; }
    void display() { cout << "Card:" << rank << " of " << suit << endl; }
};

int blackJackScore(Card card1, Card card2){
  return card1.getRank() + card2.getRank();
}

int main(void){
  Card c1, c2, c3;
  c1.setValues(10, "Hearts");
  c2.setValues(5, "Spades");
  c3.setValues();
  c1.display();
  c2.display();
  c3.display();

  cout << blackJackScore(c1, c2) << endl;

  return 0;
}