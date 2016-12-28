#ifndef LISTCONTAINER_H
#define LISTCONTAINER_H

#include <list>
#include <iterator>
#include <iostream>
#include "Container.h"

class ListContainer : public Container {
  private:
    list<Base*> expression;
  public:
    ListContainer() {};
    void add_element(Base* element) {
      expression.push_back(element);
      return;
    }
    void print() {
      for(int i = 0; i < size(); ++i) {
        cout << at(i)->evaluate() << " ";
      }
      cout << endl;
      return;
    }
    void swap(int i, int j){
      Base* temp1 = at(i);
      list<Base*>::iterator index1 = expression.begin();
      advance(index1, i);
      *index1 = at(j); 
      list<Base*>::iterator index2 = expression.begin();
      advance(index2, j);
      *index2 = temp1;
      return;
    }
    Base* at(int i) {
      list<Base*>::iterator index = expression.begin();
      advance(index, i);
      return *index;
    }
    int size() {
      return expression.size();
    }
    void sort() {
      sort_function->sort(this);
      return;
    }
};

#endif
