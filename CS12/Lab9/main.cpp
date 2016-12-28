#include "Card.h"
#include "Deck.h"

#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
using namespace std;



void fillHand(vector<Card> &hand, Deck &d, unsigned handSize) {
   hand.resize(handSize);
   for (unsigned i = 0; i < hand.size(); ++i) {
      hand.at(i) = d.dealCard();
   }
}

//This is the function you implemented for PROGRAM 3
ostream & operator<<(ostream &, const vector<Card> &);

 /* Sorts the contents of v into suit order,
   i.e., all clubs first (in numerically ascending order),
   then all diamonds (in ascending order),
   then all hearts (in ascending order),
   and finally all spades (in ascending order).
   Calls mergeSort recursive function to actually sort the vector.*/
   void sortBySuit(vector<Card> &v);

   /* Uses the recursive merge sort algorithm to sort the contents
   of the vector from begin to end in suit order.
   (see above SortBySuit function for definition of suit order)
   Uses merge helper function to merge the two sorted
   halves.*/
   void mergeSort(vector<Card> &v, unsigned begin, unsigned end);

   /* Assumes all values from begin to mid are in suit order,
   (see above SortBySuit function for definition of suit order)
   and all values from mid + 1 to end are in suit order.
   Merges the two halves so that all values from begin to end
   are in suit order.*/
   void merge(vector<Card> &v, unsigned begin, unsigned mid, unsigned end);

int main() {
   vector<Card> hand;
   Deck deck;
   int handSize;
   int seed;
   cout << "Enter seed value: ";
   cin >> seed;
   cout << endl;
   cout << "Enter hand size: ";
   cin >> handSize;
   cout << endl;

   srand(seed);
   deck.shuffleDeck();
   fillHand(hand, deck, handSize);
   cout << hand << endl;
   sortBySuit(hand);
   cout << hand << endl;
   return 0;
}

ostream & operator<<(ostream& out, const vector<Card>& pileCards) {
   unsigned size = 0;
   if(pileCards.size() == 0) {
      return out;
   }
   else {
      size = pileCards.size() - 1;
      for(unsigned i = 0; i < size; ++i) {
      out << pileCards.at(i) << ", ";
      }
      out << pileCards.at(size);
      return out;
   }
}

void sortBySuit(vector<Card> &v) {
   if(v.size() <= 1) {
      return;
   }
   mergeSort(v, 0, v.size() - 1);
   return;
}


void mergeSort(vector<Card> &v, unsigned begin, unsigned end) {
   if(begin < end) {
      unsigned mid = (begin + end) / 2;
      //cout << begin << endl;
      //cout << mid << endl;
      mergeSort(v, begin, mid);
      //cout << mid + 1 << endl;
      //cout << end << endl;
      mergeSort(v, mid + 1, end);
      
      merge(v, begin, mid, end);
   }
   return;   
}

void merge(vector<Card> &v, unsigned begin, unsigned mid, unsigned end) {
   //Create a temporary vector in which we place the cards into, sorted properly
   vector<Card> tempVec;
   //Placeholder for when we recreate vector v by replacing values in
   unsigned startmerge = begin;
   //Tempmid goes through the vector while mid acts as a placeholder so that begin never exceeds mid
   unsigned tempmid = mid + 1;
   //Assign two cards which we will compare and update throughout the loops
   //Notes: Update begin or mid right after pushing back into tempVec
   //Update start1 and start2 at the beginning of each while loop
   Card start1 = v.at(begin);
   Card start2 = v.at(tempmid);
   //This while loop continues until either the left or the right partition is empty
   //Since this compares only numbers, we will never go past the end of the vector
   while(begin <= mid && tempmid <= end) {
      //Although redundant for the first time, updating at the beginning of the while loop
      //Ensures that start1 and start2 will never go out of bounds by being assigned to an index greater than what is in v
      //Use v = {3C, 4H, 4D, JH, KS} as an example
      start1 = v.at(begin);
      start2 = v.at(tempmid);
      //First round, first if statement applies because C < D, thus we push_back 3C. tempVec = {3C} begin = 1, mid = 2
      //Second round, else if statement applies because H > D, thus we push_back 4D. tempVec = {3C, 4D} begin = 1, mid = 3
      //Third round, else statement applies because H == H. 4 < J, thus we push_back 4H. tempVec = {3C, 4D, 4H} begin = 2, mid = 3
      //While loop is broken and we go onto the next while loop
      if(start1.getSuit() < start2.getSuit()) {
         tempVec.push_back(start1);
         begin += 1;
      }
      else if(start1.getSuit() > start2.getSuit()) {
         tempVec.push_back(start2);
         tempmid += 1;
      }
      //If suits are the same, compare rank
      else {
         if(start1.getRank() < start2.getRank()) {
            tempVec.push_back(start1);
            begin += 1;
         }
         else {
            tempVec.push_back(start2);
            tempmid += 1;
         }
      }
   }
   //Second and third while loop apply if the left or right partition respectively are empty
   //Same conditions as prior apply
   //Starting fourth round, begin = 2, mid = 3. Third while loop is satisfied, so we push_back JH. tempVec = {3C, 4D, 4H, JH}
   //Starting fifth round, begin = 2, mid = 4. We push_back KS. tempVec = {3C, 4D, 4H, JH, KS}
   while(begin <= mid) {
      start1 = v.at(begin);
      tempVec.push_back(start1);
      begin += 1;
   }
   while(tempmid <= end) {
      start2 = v.at(tempmid);
      tempVec.push_back(start2);
      tempmid += 1;
   }
   //Break out of all three while loops. tempVec should be properly sorted.
   for(unsigned i = 0; i < tempVec.size(); ++i) {
      v.at(i + startmerge) = tempVec.at(i);
   }
   return;
}