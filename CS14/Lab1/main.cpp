//Partner 1: Salman Bana
//Partner 2: Jennifer Shin

#include <iostream>
#include <string> 
#include <vector>
#include <cstdlib>
#include <ctime>
#include <list>

using namespace std;

#include "Character.h"
#include "Warrior.h"
#include "Elf.h"
#include "Wizard.h"


int sumOfAttack(list<Character*>);

int main() {
  list<Character*> p1;
  list<Character*> p2;
  string name;
  string type;
  int attack;
    
  //Player 1: Warrior
  cout << "Player 1: Create a Warrior." << endl;
  cout << "Name of Warrior: ";
  cin >> name;
    
  cout << "How strong will your character be? (Max attack is 10)" << endl;
  cin >> attack;
  while(attack > 10) {
    cout << "Invalid attack. Input again: ";
    cin >> attack;
  }
  string allegiance;
  cout << "And to whom does he pledge his allegiance?" << endl; 
  cin >> allegiance;
  p1.push_back(new Warrior(name, 100.0, attack, allegiance));
    
  //Player 1: Elf
  cout << "Player 1: Create an Elf." << endl;
  cout << "Name of Elf: ";
  cin >> name;
    
  cout << "How strong will your character be? (Max attack is 10)" << endl;
  cin >> attack;
  while(attack > 10) {
    cout << "Invalid attack. Input again: ";
    cin >> attack;
  }
  string family;
  cout << "Player 1: And to which family does he belong?" << endl;
  cin >> family;
  p1.push_back(new Elf(name, 100.0, attack, family));
    
  //Player 1: Wizard
  cout << "Player 1: Create a Wizrd." << endl;
  cout << "Name of Wizard: ";
  cin >> name;
    
  cout << "How strong will your character be? (Max attack is 10)" << endl;
  cin >> attack;
  while(attack > 10) {
    cout << "Invalid attack. Input again: ";
    cin >> attack;
  }
  int level;
  cout << "Player 1: What level is your wizard?" << endl;
  cin >> level;
  p1.push_back(new Wizard(name, 100.0, attack, level));
    
  do {
    cout << "Player 1: Choose your character's class. (Either Elf, Warrior, or Wizard)" << endl;
    cin >> type;
        
    cout << "Player 1: Name your character" << endl;
    cin >> name;
        
    cout << "How strong will your character be? (Max attack is 10)" << endl;
    cin >> attack;
    while(attack > 10 && sumOfAttack(p1) <= 40) {
      cout << "Invalid attack. Input again: ";
      cin >> attack;
    }
    
    if(type == "Warrior") {
      cout << "And to whom does he pledge his allegiance?" << endl; 
      cin >> allegiance;
      p1.push_back(new Warrior(name, 100.0, attack, allegiance));
    }
    else if(type == "Elf") {
      cout << "Player 1: And to which family does he belong?" << endl;
      cin >> family;
      p1.push_back(new Elf(name, 100.0, attack, family));
    }
    else {
      cout << "Player 1: What level is your wizard? (Max level is 10)" << endl;
      cin >> level;
      while(level > 10) {
        cout << "Invalid level. Input again: ";
        cin >> level;
      }
      p1.push_back(new Wizard(name, 100.0, attack, level));
    }
  } while(sumOfAttack(p1) < 40);
    
  //Player 2: Warrior
  cout << "Player 2: Create a Warrior." << endl;
  cout << "Name of Warrior: ";
  cin >> name;
    
  cout << "How strong will your character be? (Max attack is 10)" << endl;
  cin >> attack;
  while(attack > 10) {
    cout << "Invalid attack. Input again: ";
    cin >> attack;
  }
  cout << "And to whom does he pledge his allegiance?" << endl; 
  cin >> allegiance;
  p2.push_back(new Warrior(name, 100.0, attack, allegiance));
    
  //Player 2: Elf
  cout << "Player 2: Create an Elf." << endl;
  cout << "Name of Elf: ";
  cin >> name;
    
  cout << "How strong will your character be? (Max attack is 10)" << endl;
  cin >> attack;
  while(attack > 10) {
    cout << "Invalid attack. Input again: ";
    cin >> attack;
  }
  cout << "Player 2: And to which family does he belong?" << endl;
  cin >> family;
  p2.push_back(new Elf(name, 100.0, attack, family));
    
  //Player 2: Wizard
  cout << "Player 1: Create a Wizrd." << endl;
  cout << "Name of Wizard: ";
  cin >> name;
    
  cout << "How strong will your character be? (Max attack is 10)" << endl;
  cin >> attack;
  while(attack > 10) {
    cout << "Invalid attack. Input again: ";
    cin >> attack;
  }
  cout << "Player 2: What level is your wizard?" << endl;
  cin >> level;
  p2.push_back(new Wizard(name, 100.0, attack, level));
    
  do {
    cout << "Player 2: Choose your character's class. (Either Elf, Warrior, or Wizard)" << endl;
    cin >> type;
        
    cout << "Player 2: Name your character" << endl;
    cin >> name;
        
    cout << "How strong will your character be? (Max attack is 10)" << endl;
    cin >> attack;
    while(attack > 10 && sumOfAttack(p2) <= 40) {
      cout << "Invalid attack. Input again: ";
      cin >> attack;
    }
    
    if(type == "Warrior") {
      cout << "And to whom does he pledge his allegiance?" << endl; 
      cin >> allegiance;
      p2.push_back(new Warrior(name, 100.0, attack, allegiance));
    }
    else if(type == "Elf") {
      cout << "Player 2: And to which family does he belong?" << endl;
      cin >> family;
      p2.push_back(new Elf(name, 100.0, attack, family));
    }
    else {
      cout << "Player 2: What level is your wizard? (Max level is 10)" << endl;
      cin >> level;
      while(level > 10) {
        cout << "Invalid level. Input again: ";
        cin >> level;
      }
      p2.push_back(new Wizard(name, 100.0, attack, level));
    }
  } while(sumOfAttack(p2) < 40);
  
  list<Character*>::iterator it1 = p1.begin();
  list<Character*>::iterator it2 = p2.begin();
  while(p1.size() > 0 && p2.size() > 0) {
    (*it1)->attack(**it2);
    if(!(*it2)->isAlive()){
      cout << (*it2)->getName() << " has fallen!" << endl;
      it2 = p2.erase(it2);
    }
    if(p2.size() == 0) {
      cout << "Congratulations! Player 1 wins!" << endl;
    }
    else { 
      (*it2)->attack(**it1);
      if(!(*it1)->isAlive()){
        cout << (*it1)->getName() << " has fallen!" << endl;
        it1 = p1.erase(it1);
      }
      if(p1.size() == 0) {
          cout << "Congratulations! Player 2 wins!" << endl;
      }
    }
  }
  return 0; 
}  

//This function adds all the characters attack strengths in a list
//Used to limit the maximum attack strength of the party to 40 in one of the do while loops above
int sumOfAttack(list<Character*> player) {
  int sum = 0;
  list<Character*>::iterator it;
  //For loop goes through the list of characters and adds their attack strengths to sum
  //Have to dereference it twice since it points to a list and not an individual character
  for(it = player.begin(); it != player.end(); ++it) {
    //getStrength function created and used since attackStrength is encapsulated
    sum += (*it)->getStrength(); 
  }
  //sum is of return type int
  return sum;
}
  