#include <iostream>
using namespace std;

#ifndef _INTLIST_H
#define _INTLIST_H

struct IntNode {
  int data;
  IntNode* next;
  IntNode(int data) : data(data), next(NULL) {}
};

class IntList {
  public:
    IntList();
    ~IntList();
    IntList(const IntList&);
    void display() const;
    void push_front(int);
    void pop_front();
    bool empty() const;
    //void swap_testharness();
    void clear();
    IntList& operator=(const IntList& rhs);
    void push_back(int value);
    void selection_sort();
     
    void insert_ordered(int);
    void remove_duplicates();
    friend ostream& operator<<(ostream&, const IntList&);
  protected:
    IntNode* head;
    IntNode* tail;
    void swap(IntNode*, IntNode*);
};

#endif