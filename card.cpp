// card.cpp
// Author: Your name
// Implementation of the classes defined in card.h

#include "card.h"
#include <iostream>
#include <string>
using namespace std;

Card::Card()
{
    num = 0;
    suit = 'c';
}

Card::Card(char s, string n)
{
    num = charToNum(n);
    suit = s;
}

bool Card::operator>(const Card &other) const
{
    int suitone = suitNumber(suit);
    int suittwo = suitNumber(other.suit);
    if (suitone == suittwo)
    {
        return num > other.num;
    }
    return suitone > suittwo;
}

bool Card::operator<(const Card &other) const
{
    int suitone = suitNumber(suit);
    int suittwo = suitNumber(other.suit);
    if (suitone == suittwo)
    {
        return num < other.num;
    }
    return suitone < suittwo;
}

bool Card::operator==(const Card &other) const
{
    int suitone = suitNumber(suit);
    int suittwo = suitNumber(other.suit);
    return suitone == suittwo && num == other.num;
}

int charToNum(string num)
{
    if (num == "a")
    {
        return 1;
    }
    if (num == "j")
    {
        return 11;
    }
    if (num == "q")
    {
        return 12;
    }
    if (num == "k")
    {
        return 13;
    }
    else
    {
        return stoi(num);
    }
}

int suitNumber(char suit)
{
    if (suit == 'c')
    {
        return 1;
    }
    if (suit == 'd')
    {
        return 2;
    }
    if (suit == 's')
    {
        return 3;
    }
    if (suit == 'h')
    {
        return 4;
    }
    return 0;
}

ostream &operator<<(ostream &os, const Card &c)
{
    string str = "";
    if (c.num == 1)
    {
        str = "a";
    }
    else if (c.num == 11)
    {
        str = "j";
    }
    else if (c.num == 12)
    {
        str = "q";
    }
    else if (c.num == 13)
    {
        str = "k";
    }
    else
    {
        str = to_string(c.num);
    }
    os << c.suit << " " << str;
    return os;
}

