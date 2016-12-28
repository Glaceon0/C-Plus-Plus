#include "Character.h"

#include <string> 
using namespace std;

Character::Character(CharType battleclass, const string& title, double hp, double might)
: type(battleclass), name(title), health(hp), attackStrength(might) { }

CharType Character::getType() const {
  return type;
}

int Character::getStrength() const {
  return attackStrength;
}

const string& Character::getName() const {
  return name;
}

int Character::getHealth() const {
  return static_cast<int>(health);
}

void Character::setHealth(double h) {
  health = h;
  return;
}

bool Character::isAlive() const {
  if(getHealth() > 0) {
    return true;
  }
  return false;
}



