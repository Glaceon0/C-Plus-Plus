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
    void display() const;
    void push_front(int);
    void pop_front();
    bool empty() const;
  private:
    IntNode* head;
    IntNode* tail;
};

#endif