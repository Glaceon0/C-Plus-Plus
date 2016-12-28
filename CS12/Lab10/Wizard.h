#ifndef WIZARD_H
#define WIZARD_H

#include "Character.h"
#include <string>

using namespace std;

class Wizard : public Character {
  public:
    Wizard(const string&, double, double, int);
    int getRank() const;
    void attack(Character&);
  private:
    int rank;
};

#endif