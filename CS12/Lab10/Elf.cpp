#include "Character.h"
#include "Elf.h"

#include <iostream>
#include <string>

using namespace std;

Elf::Elf(const string& title, double hp, double might, const string& allegiance) 
: Character(ELF, title, hp, might), family(allegiance) { }

const string& Elf::getFamily() const {
  return family;
}

void Elf::attack(Character& en) {
  
  if(en.getType() == ELF) {
    Elf& opp = dynamic_cast<Elf&>(en);
    if(opp.getFamily() == this->getFamily()) {
      cout << "Elf " << this->getName() << " does not attack Elf " << en.getName() << "." << endl;
      cout << "They are both members of the " << this->getFamily() << " family." << endl;
    return;
    }
  }
  double damagedealt = attackStrength * health / MAX_HEALTH;
  double newHealth = en.getHealth() - damagedealt;
  en.setHealth(newHealth);
  cout << "Elf " << this->getName() << " shoots an arrow at " << en.getName() << " --- TWANG!!" << endl;
  cout << en.getName() << " takes " << damagedealt << " damage." << endl;
  return;
}