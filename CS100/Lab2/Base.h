#ifndef BASE_H
#define BASE_H

using namespace std;

class Base {
  public: 
  /* Constructor */
    Base() {};
  /* Pure Virtual Functions */
    virtual double evaluate() = 0;
};

#endif
