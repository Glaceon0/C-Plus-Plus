#ifndef SQR_H
#define SQR_H

#include "Base.h"
using namespace std;

class Sqr : public Base {
  private:
    double val1;
  public:
    Sqr(Base* a) {
      val1 = a->evaluate();
    }
    double evaluate() {
      return val1 * val1;
    }
};

#endif
