#include "HashTable.h"
#include "WordEntry.h"

#include <cmath>

/* HashTable constructor
*  input s is the size of the array
*  set s to be size
*  initialize array of lists of WordEntry
*/
HashTable::HashTable (int s) : size(s) {
  this->hashTable = new list<WordEntry> [s];
}


/* computeHash
*  return an integer based on the input string
*  used for index into the array in hash table
*  be sure to use the size of the array to 
*  ensure array index doesn't go out of bounds
*/
int HashTable::computeHash(const string& s) {
  int totalNum = 1;
  unsigned max = s.size();
  if(s.size() > 5) {
    max = 5;
  }
  for(unsigned i = 0; i < max; ++i) {
    int ascii = s.at(i);
    int adj_ascii = abs(ascii - 96);
//A check to see whether it translates
    //cout << adj_ascii;
    totalNum *= adj_ascii;
  }
  totalNum *= s.size();
  return totalNum % this->size; 
}


/* put
*  input: string word and int score to be inserted
*  First, look to see if word already exists in hash table
*   if so, addNewAppearence with the score to the WordEntry
*   if not, create a new Entry and push it on the list at the
*   appropriate array index
*/
void HashTable::put(const string& s, int score) {
  int pii = computeHash(s);
  //cout << "Check 1";
  for(list<WordEntry>::iterator it = hashTable[pii].begin(); it != hashTable[pii].end(); ++it) {
    //cout << it->getWord();
    if(it->getWord() == s) {
      it->addNewAppearance(score);
      return;
    }
  }
  WordEntry enter(s, score);
  hashTable[pii].push_back(enter);
  return;
}

/* getAverage
*  input: string word 
*  output: the result of a call to getAverage()
*          from the WordEntry
*  Must first find the WordEntry in the hash table
*  then return the average
*  If not found, return the value 2.0 (neutral result)
*/

double HashTable::getAverage(const string& s) {
  int pii = computeHash(s);
  //cout << "Check 1" << endl;
  for(list<WordEntry>::iterator it = hashTable[pii].begin(); it != hashTable[pii].end(); ++it) {
    //cout << it->getWord();
    if(it->getWord() == s) {
      return it->getAverage();
    }
  }
  return 2.0;
}

/* contains
* input: string word
* output: true if word is in the hash table
*         false if word is not in the hash table
*/
bool HashTable::contains(const string& s) {
  int pii = computeHash(s);
  //cout << "Check 1" << endl;
  for(list<WordEntry>::iterator it = hashTable[pii].begin(); it != hashTable[pii].end(); ++it) {
    //cout << it->getWord();
    if(it->getWord() == s) {
      return true;
    }
  }
  return false;
}

