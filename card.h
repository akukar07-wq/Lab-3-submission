// card.h
// Author: Akul Karnataki
// All class declarations related to defining a single card go here

#ifndef CARD_H
#define CARD_H

#include <string>
#include <iostream>
using namespace std;

class Card {
public:
    Card();                  // default constructor
    Card(char s, string n);  // constructor with suit and number/face

    bool operator>(const Card &other) const;
    bool operator<(const Card &other) const;
    bool operator==(const Card &other) const;
    friend ostream& operator<<(ostream& os, const Card& c);
    
private:
    int num;
    char suit;   
};
int charToNum(string num);
int suitNumber(char suit);


#endif

