#include "WordLadder.h"
#include <iostream>
#include <string>
#include <fstream>
#include <stack>
#include <queue>
#include <list>
#include <stdexcept>

//The constructor passes in the name of the file that contains the dictionary words. In this case dictionary.txt
WordLadder::WordLadder(const string& fname) {
//Initialize an ifstream and a string variable and open the file containing the words (Remember to use c_str(). Throw a runtime error if this fails
  ifstream inFS;
  string word;
  inFS.open(fname.c_str());
  if(!inFS.is_open()) {
    throw out_of_range("Could not open input file");
  }
  //Read each word from the input file and then push_back each word into the private variable list<string> dict until reaches end of the file
  while(inFS.good()) {
    inFS >> word;
    if(word.size() != 5) {
      throw length_error("Not a five letter word");
    }
    dict.push_back(word);
  }
  //Clear input stream
  inFS.clear();
}

//Passes in two strings, the starting word, the destination, and the name of the file to which one wants to output the WordLadder
void WordLadder::outputLadder(const string& start, const string& end, const string& outputFile) {
//Check and see if start and end are both valid words. If not, throw error message and exit
//I'll create a private helper function called checkDict specified in the h file
  if(!checkDict(start) || !checkDict(end)) {
    throw range_error("Not a valid word");
  }
  ofstream onFS;
  onFS.open(outputFile.c_str());
  if(!onFS.is_open()) {
    throw invalid_argument("Could not open output file");
  }
  if(start == end) {
    onFS << start;
    return;
  }
//Create a queue of stacks and enqueue the first stack which contains the first word into the queue
//Initialize the stack  
  stack<string> lad;
//Push in the starting word
  lad.push(start);
//Initialize the queue
  queue<stack<string> > all;
//Enqueue the first stack
  all.push(lad);
//Remove the starting word from the dictionary
  takeOut(start);
//Start the process
  while(!all.empty()) {
    //Set a temporary word equal to the top of the stack of the top of the queue
    string tempWord = all.front().top();
    //Create a while loop that passes through the dictionary and checks each word to see if the word is one off
    //From the word at the top of the stack. Reason for the while loop is because the if statement deletes the word
    //From the dictionary using erase() and thus does not need for a ++it.
    list<string>::iterator it = dict.begin();
    while (it != dict.end()) {
      //Initialize a string to the word that is going to be compared
      string compare = *it;
      //Pass in both of those into the one-off function
      //If returns true, create a new stack that is a copy of the stack in the front of the queue
      //And add the word to the stack. Then push the stack into the queue. Go through the while loop again
      if(oneOff(tempWord, compare)) {
      //Erase the word from the "dictionary"
        it = dict.erase(it);
      //Create a new stack
        stack<string> add;
      //Copy the stack from the stack at the front of the queue
        add = all.front();
      //Push the new word onto the stack
        add.push(compare);
      //Push the new stack into the queue
        all.push(add);
      //If the final word is the last word, then output the final word ladder
        if(compare == end) {
          //cout << "There is a word ladder!" << endl;
      //Create a new stack to which we first output the stack at the front of the queue
          stack<string> YATTA;
      //Use a while loop to reverse the order of the stack by copying it onto another stack
          while(!add.empty()) {
            YATTA.push(add.top());
            add.pop();
          }
            while(!YATTA.empty()) {
              onFS << YATTA.top() << " ";
              YATTA.pop();
          }
          return;
        }
      }
      //If returns false, ++it; go through the while loop again
      else {
        ++it;
      }
    }
    //After this while loop ends, pop the front stack of the queue, since it has gone through the entire list of words.
    all.pop();
    //If the queue is empty, then no word ladder exists
    if(all.empty()) {
      onFS << "No Word Ladder Found!!";
      return;
    }
  }
  return;
}

bool WordLadder::checkDict(const string& word) {
//Fastest way to compare a string with a long list of strings is probably O(N) runtime
//First, create a for loop that runs through the list and compares the string passed in to the string in the lis
  list<string>::iterator it = dict.begin();
  for(it = dict.begin(); it != dict.end(); ++it) {
    if(*it == word) {
      return true;
    }
  }
  return false;
}

//Passes in two words and sees if the words are only one letter off. Returns true if yes, false if no
bool WordLadder::oneOff(const string& first, const string& compare) {
//Since we only have 5 letter words, if the counter == 4, then true
  unsigned counter = 0;
  for(unsigned f = 0; f < 5; ++f) {
//Compare at each character in the word. If they are the same, ++counter
    if(first.at(f) == compare.at(f)) {
      ++counter;
    }
  }
  if(counter == 4) {
    return true;
  }
  return false;
}

void WordLadder::takeOut(const string& word) {
  list<string>::iterator it = dict.begin();
  for(it = dict.begin(); it != dict.end(); ++it) {
    if(*it == word) {
      it = dict.erase(it);
      return;
    }
  }
  return;
}


