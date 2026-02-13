#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include "card.h"
using namespace std;
void playGame(set<Card>& alice, set<Card>& bob) {
 bool foundMatch = true;


 while (foundMatch) {
     foundMatch = false;
     set<Card>::iterator it = alice.begin();
     while (it != alice.end()) {
         set<Card>::iterator found = bob.find(*it);
         if (found != bob.end()) {
             cout << "Alice picked matching card " << *it << endl;
             bob.erase(found);
             it = alice.erase(it);
             foundMatch = true;
             break;
         } else {
             ++it;
         }
     }


     if (!foundMatch) break;


     set<Card>::reverse_iterator reverse = bob.rbegin();
     while (reverse != bob.rend()) {
         set<Card>::iterator found = alice.find(*reverse);
         if (found != alice.end()) {
             cout << "Bob picked matching card " << *reverse << endl;
             alice.erase(found);
             auto norm = reverse.base();
             --norm;
             bob.erase(norm);
             foundMatch = true;
             break;
         } else {
             ++reverse;
         }
     }
 }
}


int main(int argc, char** argv){
 if(argc < 3){
   cout << "Please provide 2 file names" << endl;
   return 1;
 }
ifstream cardFile1 (argv[1]);
 ifstream cardFile2 (argv[2]);
 string line;


 set<Card> alice;
 set<Card> bob;


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
   for(set<Card>::iterator it = alice.begin(); it !=alice.end(); ++it)
   {
     cout<<*it<<endl;
   }
   cout<<endl<<endl;
   cout<<"Bob's cards:"<<endl;
   for(set<Card>::iterator it = bob.begin(); it !=bob.end(); ++it)
   {
     cout<<*it<<endl;
   }
   return 0;
}


