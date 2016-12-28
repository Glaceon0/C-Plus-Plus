#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include "Sort.h"

using namespace std;

class SelectionSort : public Sort {
  public:
    /*Constructor*/
    SelectionSort() {};
    
    void sort(Container* container) {
      int min;
      for(int i = 0; i < container->size() - 1; ++i) {
        min = i;
        for(int j = i + 1; j < container->size(); ++j) {
          if(container->at(j)->evaluate() < container->at(min)->evaluate()) {
            //cout << container->at(j)->evaluate() << " is less than " << container->at(min)->evaluate() << endl;
            min = j;
          }
        }
        container->swap(i, min);
      } 
    }
};

#endif