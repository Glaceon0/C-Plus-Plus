#ifndef DIV_H
#define DIV_H

#include "Base.h"
using namespace std;

class Div : public Base {
  private:
    double val1;
    double val2;
  public:
    Div(Base* a, Base* b) {
      val1 = a->evaluate();
      val2 = b->evaluate();
    }
    double evaluate() {
      return val1 / val2;
    }
};

#endif
