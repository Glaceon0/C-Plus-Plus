#ifndef MULT_H
#define MULT_H

#include "Base.h"
using namespace std;

class Mult : public Base {
  private:
    double val1;
    double val2;
  public:
    Mult(Base* a, Base* b) {
      val1 = a->evaluate();
      val2 = b->evaluate();
    }
    double evaluate() {
      return val1 * val2;
    }
};

#endif
