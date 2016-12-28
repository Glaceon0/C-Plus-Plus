#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

#include "Card.h"
#include "Deck.h"

Deck::Deck() {
   Card aCard;
   char cardSuit = 's';
   for(unsigned i = 13; i >= 1; --i) {
      aCard = Card(cardSuit, i);
      theDeck.push_back(aCard);
   }
   cardSuit = 'h';
   for(unsigned i = 13; i >= 1; --i) {
      aCard = Card(cardSuit, i);
      theDeck.push_back(aCard);
   }
   cardSuit = 'd';
   for(unsigned i = 13; i >= 1; --i) {
      aCard = Card(cardSuit, i);
      theDeck.push_back(aCard);
   }
   cardSuit = 'c';
   for(unsigned i = 13; i >= 1; --i) {
      aCard = Card(cardSuit, i);
      theDeck.push_back(aCard);
   }
}

Card Deck::dealCard() {
   dealtCards.push_back(theDeck.back());
   theDeck.pop_back();
   return dealtCards.back();
}

void Deck::shuffleDeck() {
   Card last;
   //cout << dealtCards.size() << endl;
   for(unsigned i = 0; i < dealtCards.size(); ++i) {
      last = dealtCards.at(dealtCards.size() - (i + 1));
      theDeck.push_back(last);
   }
   dealtCards.clear();
   random_shuffle(theDeck.begin(), theDeck.end());
   return;
}

unsigned Deck::deckSize() const {
   return theDeck.size();
}