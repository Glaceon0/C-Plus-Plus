#ifndef WARRIOR_H
#define WARRIOR_H

#include "Character.h"
#include <string>

using namespace std;

class Warrior : public Character {
  public:
    Warrior(const string&, double, double, const string&);
    const string& getTies() const;
    void attack(Character&);
  private:
    string ties;
};

#endif