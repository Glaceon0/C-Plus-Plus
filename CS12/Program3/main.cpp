#include <vector>
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

#include "Card.h"
#include "Deck.h"
using namespace std;

/* Passes in a vector Cards and returns true if any 2 Cards have the same rank.
   Otherwise returns false.
*/
bool hasPair(const vector<Card> &);


/* Passes in a vector of Cards and outputs to the stream each Card
   separated by a comma and a space, 
   with no comma, space, or newline at the end.
*/
ostream & operator<<(ostream&, const vector<Card>&);

int main() {
   string ynChoice = "";
   unsigned numChoice1 = 0;
   unsigned numChoice2 = 0;
   string filename = "";
   ofstream outFS;
   srand(2222);
   
   cout << "Do you want to output all hands to a file?(Yes/No) " << endl;
   cin >> ynChoice;
   if(ynChoice == "Yes") {
      cout << "Enter name of output file: " << endl;
      cin >> filename;
      outFS.open(filename.c_str());
      if(!outFS.is_open()) {
         cout << "Could not open file " << filename << "." << endl;
         return 1;
      }
   }
   
   cout << "Enter number of cards per hand: " << endl;
   cin >> numChoice1;
   
   cout << "Enter number of deals (simulations): " << endl;
   cin >> numChoice2;
   
   vector<Card> dealtCards(0);
   unsigned cnt = 0;
   Deck regularDeck = Deck();
   regularDeck.shuffleDeck();
   
   for(unsigned j = 0; j < numChoice2; ++j) {
      for(unsigned i = 0; i < numChoice1; ++i) {
         //cout << regularDeck.dealCard();
         dealtCards.push_back(regularDeck.dealCard());
      }
      if(hasPair(dealtCards)) {
         ++cnt;
      if(ynChoice == "Yes")
         outFS << "Found Pair!! ";
      }
      else {
         outFS << "             ";
      }
      if(ynChoice == "Yes") {
      outFS << dealtCards << endl;
      }
      dealtCards.clear();
      regularDeck.shuffleDeck();
   }
   
   //Monte Carlo method implementation
   double resultPercent = (static_cast<double> (cnt) / static_cast<double> (numChoice2)) * 100.0;
   cout << "Chances of receiving a pair in a hand of 5 cards is: " << resultPercent << endl;
   
   return 0;
}

bool hasPair(const vector<Card>& pileCards) {
   vector<int> count(13);
   int compare;
   for(unsigned g = 0; g < 13; ++g) {
      compare = g + 1;
      for(unsigned i = 0; i < pileCards.size(); ++i) {
         if(pileCards.at(i).getRank() == compare) {
            count.at(g) += 1;
         }
      }
      if(count.at(g) >= 2) {
         return true;
      }
   }
   return false;
} 

ostream & operator<<(ostream& out, const vector<Card>& pileCards) {
   unsigned size = 0;
   if(pileCards.size() > 0) {
      size = pileCards.size() - 1;
   }
   for(unsigned i = 0; i < size; ++i) {
      out << pileCards.at(i) << ", ";
   }
   out << pileCards.at(size);
   return out;
}