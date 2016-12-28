#ifndef ELF_H
#define ELF_H

#include "Character.h"
#include <string>

using namespace std;

class Elf : public Character {
  public:
    Elf(const string&, double, double, const string&);
    const string& getFamily() const;
    void attack(Character&);
  private:
    string family;
};

#endif