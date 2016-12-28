#ifndef VECTORCONTAINER_H
#define VECTORCONTAINER_H

#include <vector>
#include <iostream>
#include <iterator>
#include "Container.h"

class VectorContainer : public Container {
  private:
    vector<Base*> expression;
  public:
    VectorContainer() {};
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
      Base* temp = at(i);
      expression.at(i) = at(j);
      expression.at(j) = temp;
      return;
    }
    Base* at(int i) {
      return expression.at(i);
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