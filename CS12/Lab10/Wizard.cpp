#include "Character.h"
#include "Wizard.h"

#include <iostream>
#include <string>

using namespace std;

Wizard::Wizard(const string& title, double hp, double magic, int level)
: Character(WIZARD, title, hp, magic), rank(level) { }

int Wizard::getRank() const {
  return rank;
}

void Wizard::attack(Character& en) {
  double damagedealt = attackStrength;
  if(en.getType() == WIZARD) {
    Wizard& opp = dynamic_cast<Wizard&>(en);
    damagedealt = attackStrength * static_cast<double>(this->rank)/static_cast<double>(opp.getRank());
  }
  double newHealth = en.getHealth() - damagedealt;
  en.setHealth(newHealth);
  cout << "Wizard " << this->getName() << " attacks " << en.getName() << " --- POOF!!" << endl;
  cout << en.getName() << " takes " << damagedealt << " damage." << endl;
  return;
}


