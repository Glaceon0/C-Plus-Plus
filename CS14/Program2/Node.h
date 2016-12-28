#ifndef NODE_H
#define NODE_H

#include <string>
#include <ostream>
using namespace std;

class Node {
  private:
    Node* left;
    Node* right;
    unsigned counter;
    string data;
  public:
    Node(string);
  //Create a bunch of accessor and mutator functions for the private variables
  //left, right, counter and data. Kind of a pain, but whatever.
  //First the accessors and their constants
    Node* getLeft() const;
    Node* getRight() const;
    unsigned getCount() const;
    const string& getData() const;
  //Next the mutator functions. Add means add left or right child
    void addLeft(const string& fox);
    void addRight(const string& fox);
    void incCounter();
    void decCounter();
    void setLeft(Node*);
    void setRight(Node*);
    void setData(Node*);
    void setCounter(Node*);
    void setCounter(unsigned);
  
};

#endif