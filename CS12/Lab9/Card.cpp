#include <iostream>
#include <string>
using namespace std;

#include "Card.h"

Card::Card() {
    suit = 'c';
    rank = 2;
}

Card::Card(char letter, int number) {
    //makes things easier
    if(isupper(letter)) {
        letter = tolower(letter);
    }
    //start of by setting suit
    if(letter != 'c' && letter != 'd' && letter != 'h' && letter != 's') {
        suit = 'c';
    }
    else {
        suit = letter;
    }
    //set rank
    if(number < 1 || number > 13) {
        rank = 2;
        //cout << "Error";
    }
    else {
        rank = number; 
    }
}

char Card::getSuit() const {
    return suit;
}

int Card::getRank() const {
    return rank;
}

ostream & operator<<(ostream& out, const Card& ths) {
    string fullSuit = "";
    string royalRank = "";
    if(ths.suit == 'c') {
        fullSuit = "Clubs";
    }
    else if(ths.suit == 'd') {
        fullSuit = "Diamonds";
    }
    else if(ths.suit == 'h') {
        fullSuit = "Hearts";
    }
    else {
        fullSuit = "Spades";
    }
    if(ths.rank >= 2 && ths.rank <= 10) {
        out << ths.rank << " of " << fullSuit;
        return out;
    }
    else if(ths.rank == 11) {
        royalRank = "Jack";
    }
    else if(ths.rank == 12) {
        royalRank = "Queen";
    }
    else if(ths.rank == 13) {
        royalRank = "King";
    }
    else {
        royalRank = "Ace";
    }
    out << royalRank << " of " << fullSuit;
    return out;
}