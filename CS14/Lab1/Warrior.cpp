#include "Character.h"
#include "Warrior.h"

#include <iostream>
#include <string>

using namespace std;

Warrior::Warrior(const string& title, double hp, double might, const string& allegiance) 
: Character(WARRIOR, title, hp, might), ties(allegiance) { }

const string& Warrior::getTies() const {
  return ties;
}

void Warrior::attack(Character& en) {
  if(en.getType() == WARRIOR) {
    Warrior& opp = dynamic_cast<Warrior&>(en);
    if(opp.getTies() == this->getTies()) {
      cout << "Warrior " << this->getName() << " does not attack Warrior " << en.getName() << "." << endl;
      cout << "They share an allegiance with " << this->getTies() << "." << endl;
      return;
    }
  }
  double damagedealt = attackStrength * this->health / MAX_HEALTH;
  double newHealth = en.getHealth() - damagedealt;
  en.setHealth(newHealth);
  cout << "Warrior " << this->getName() << " attacks " << en.getName() << " --- SLASH!!" << endl;
  cout << en.getName() << " takes " << damagedealt << " damage." << endl;
  return;
}
