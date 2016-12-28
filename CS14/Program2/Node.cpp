#include "Node.h"
#include <ostream>

using namespace std;

//Should I make a constructor if nothing is passed in?
Node::Node(string fox) 
: left(NULL), right(NULL), counter(1), data(fox) { }

//Four accessor functions for each of the private variables
Node* Node::getLeft() const {
  return left;
}

Node* Node::getRight() const {
  return right;
}

unsigned Node::getCount() const {
  return counter;
}

const string& Node::getData() const {
  return data;
}

//Three mutator functions. First for adding a left child, second for adding a right child
//And third for incrementing the counter
void Node::addLeft(const string& fox) {
  Node* leaf = new Node(fox);
  this->left = leaf;
  return;
}

void Node::addRight(const string& fox) {
  Node* leaf = new Node(fox);
  this->right = leaf;
  return;
}

void Node::incCounter() {
  ++counter;
  return;
}

//Four more mutator functions just for the remove function in BSTree
void Node::decCounter() {
  --counter;
  return;
}

void Node::setLeft(Node* child) {
  left = child;
  return;
}

void Node::setRight(Node* child) {
  right = child;
  return;
}

void Node::setData(Node* child) {
  data = child->data;
  return;
}

void Node::setCounter(Node* child) {
  counter = child->counter;
  return;
}

void Node::setCounter(unsigned num) {
  counter = num;
  return;
}