#ifndef SORT_H
#define SORT_H

using namespace std;

class Container;

class Sort {
  public:
    /*Constructor*/
    Sort() {};
    
    /*Pure Virtual Functions*/
    virtual void sort(Container* container) = 0;
};

#endif

