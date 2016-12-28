#ifndef OP_H
#define OP_H

#include "Base.h"
using namespace std;

class Op : public Base {
  private: 
    double a;
  public: 
  /* Constructor */
    Op(double value) {
      a = value;
    }
    double evaluate() {
      return a;
    }
};

#endif
