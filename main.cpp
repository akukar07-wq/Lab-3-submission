// This file should implement the game using the std::set container class
// Do not include card_list.h in this file
// This file should implement the game using a custom implementation of a BST (based on your earlier BST implementation)
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include "card.h"
#include "card_list.h"

using namespace std;

int main(int argc, char** argv){
  if(argc < 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }
  
  ifstream cardFile1 (argv[1]);
  ifstream cardFile2 (argv[2]);
  string line;

 Card_List alice;
  Card_List bob;

  string suitStr, numStr;

    while (cardFile1 >> suitStr >> numStr) 
    {
        char suit = suitStr[0];
        alice.insert(Card(suit, numStr));
    }
    cardFile1.close();

    while (cardFile2 >> suitStr >> numStr) 
    {
        char suit = suitStr[0];
        bob.insert(Card(suit, numStr));
    }
    cardFile2.close();
    playGame(alice, bob);
    cout<<endl<<endl;
    cout<<"Alice's cards:"<<endl;
    alice.printList();
    cout<<"Bob's cards:"<<endl;
    bob.printList();
    return 0;
}
