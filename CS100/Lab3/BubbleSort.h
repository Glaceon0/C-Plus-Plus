#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "Sort.h"

using namespace std;

class BubbleSort : public Sort {
  public:
    /*Constructor*/
    BubbleSort() {};

    void sort(Container* container) {
      for(int j = 0; j < container->size() - 1; ++j) {
        bool swapped = false;
        for(int i = 0; i < container->size() - 1; ++i) {
          if(container->at(i)->evaluate() > container->at(i + 1)->evaluate()) {
            container->swap(i, i + 1);
            swapped = true;
          }
        }
        if(!swapped) {
          return;
        }
      }
      return;
    }
};

#endif