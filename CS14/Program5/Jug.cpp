#include "Jug.h"

string NumToString(int num) {
  ostringstream ss;
  ss << num;
  return ss.str();
}

string NumToString(int num1, int num2) {
  ostringstream ss;
  ss << num1 << num2;
  return ss.str();
}

Jug::Jug(int A, int B, int N, int fjA, int fjB, int ejA, int ejB, int ApB, int BpA)
: cont_A(A), cont_B(B), goal(N), fill_A(fjA), fill_B(fjB), empty_A(ejA), empty_B(ejB), ApourB(ApB), BpourA(BpA), start(NULL) { }

Jug::~Jug() {
  for(map<string, SalTree*>::iterator it = dora.begin(); it != dora.end(); ++it) {
    SalTree* ptr = it->second;
    delete ptr;
  }
}

//solve is used to check input and find the solution if one exists
//returns -1 invalid inputs. solution set to empty string.
//returns 0 if inputs are valid but a solution does not exist. solution set to empty string.
//returns 1 if solution is found and stores solution steps in solution string.

int Jug::solve(string& solution) {
  //If statements that the set of inputs needs to satisfy. If these inputs are not satisfied, return -1
  solution = "";
  if(fill_A < 0 || fill_B < 0 || empty_A < 0 || empty_B < 0 || ApourB < 0 
    || BpourA < 0 || cont_A <= 0 || cont_A > cont_B || goal > cont_B || cont_B > 1000) {
    return -1;
  }
  //tempA is the amount of water stored in jug A and tempB is the amount stored in jug B, and tempS is the string that contains the string version of tempA and temp B
  int tempA = 0;
  int tempB = 0;
  string tempS = NumToString(tempA, tempB);
  //Create a map that stores the amount of water in jug A and jug B in string form and the pointer to the node in the tree
  //map<string, SalTree*> dora;
  //Create a root node which points to the start node in which the water contained is 0,0
  SalTree* ptr = new SalTree(tempA, tempB);
  this->start = ptr;
  //Insert this key into the map for easy finding and tracking. So that I don't have to traverse the tree everytime to check
  dora.insert(pair<string, SalTree*>(tempS, ptr));
  //cout << "(" << tempA << ", " << tempB << ")" << endl;
  SalTree* ptr1 = ptr;
  SalTree* ptr2 = ptr;
  SalTree* ptr3 = ptr;
  SalTree* ptr4 = ptr;
  SalTree* ptr5 = ptr;
  fillA(ptr, tempA, tempB, dora);
  fillB(ptr1, tempA, tempB, dora);
  emptyA(ptr2, tempA, tempB, dora);
  emptyB(ptr3, tempA, tempB, dora);
  pourAtoB(ptr4, tempA, tempB, dora);
  pourBtoA(ptr5, tempA, tempB, dora);
  tempS = NumToString(0, goal);
  if(dora.count(tempS) == 1) {
    solution = dora[tempS]->path;
    solution.append("success ");
    solution.append(NumToString(dora[tempS]->totalCost));
    return 1;
  }
  return 0;
}

void Jug::fillA(SalTree* ptr, int tempA, int tempB, map<string, SalTree*>& dora) {
  if(!ptr) {
    return;
  }
  else if(tempA >= 0 && tempA < cont_A) {
    //Is filling A an option? If it satisfies this if statement, then yes.
    //Since it fills to the top of the jug, we set tempA to the size of the jug
    tempA = cont_A;
    int tempCost = ptr->totalCost + this->fill_A;
    //cout << tempCost << endl;
    //Sets up the creation of a new key
    string tempS = NumToString(tempA, tempB);
    //If the key doesn't already exist in the map, we insert the new node into the tree and new key into the map
    if(dora.count(tempS) == 0) {
      ptr->cfA = new SalTree(tempA, tempB);
      dora.insert(pair<string, SalTree*>(tempS, ptr->cfA));
    }
    //Else we just link to the prior key in the tree IF THE TOTALCOST IS LOWER (HAVEN'T FIGURED OUT HOW TO DO THIS YET)
    else {
      if((dora[tempS])->totalCost > tempCost) {
        ptr->cfA = dora[tempS];
      }
      else {
        ptr->cfA = NULL;
        ptr = ptr->cfA;
        return;
      }
    }
    //Update the pointer. Generally, after this, I will have it do the other options
    ptr->cfA->path = ptr->path;
    ptr = ptr->cfA;
    ptr->path.append("fill A\n");
    ptr->totalCost = tempCost;
    //cout << "(" << tempA << ", " << tempB << ")" << endl;
    SalTree* ptr1 = ptr;
    SalTree* ptr2 = ptr;
    SalTree* ptr3 = ptr;
    SalTree* ptr4 = ptr;
    SalTree* ptr5 = ptr;
    fillA(ptr, tempA, tempB, dora);
    fillB(ptr1, tempA, tempB, dora);
    emptyA(ptr2, tempA, tempB, dora);
    emptyB(ptr3, tempA, tempB, dora);
    pourAtoB(ptr4, tempA, tempB, dora);
    pourBtoA(ptr5, tempA, tempB, dora);
  }
  else {
    ptr->cfA = NULL;
    return;
  }
}

void Jug::fillB(SalTree* ptr, int tempA, int tempB, map<string, SalTree*>& dora) {
  if(!ptr) {
    return;
  }
  else if(tempB >= 0 && tempB < cont_B) {
    //Is filling B an option? If it satisfies this if statement, then yes.
    //Since it fills to the top of the jug, we set tempA to the size of the jug
    tempB = cont_B;
    int tempCost = ptr->totalCost + this->fill_B;
    //cout << tempCost << endl;
    //Sets up the creation of a new key
    string tempS = NumToString(tempA, tempB);
    //If the key doesn't already exist in the map, we insert the new node into the tree and new key into the map
    if(dora.count(tempS) == 0) {
      ptr->cfB = new SalTree(tempA, tempB);
      dora.insert(pair<string, SalTree*>(tempS, ptr->cfB));
    }
    //Else we just link to the prior key in the tree IF THE TOTALCOST IS LOWER (HAVEN'T FIGURED OUT HOW TO DO THIS YET)
    else {
      if((dora[tempS])->totalCost > tempCost) {
        ptr->cfB = dora[tempS];
      }
      else {
        ptr->cfB = NULL;
        ptr = ptr->cfB;
        return;
      }
    }
    //Update the pointer. Generally, after this, I will have to do the other options
    ptr->cfB->path = ptr->path;
    ptr = ptr->cfB;
    ptr->totalCost = tempCost;
    ptr->path.append("fill B\n");
    //cout << "(" << tempA << ", " << tempB << ")" << endl;
    SalTree* ptr1 = ptr;
    SalTree* ptr2 = ptr;
    SalTree* ptr3 = ptr;
    SalTree* ptr4 = ptr;
    SalTree* ptr5 = ptr;
    fillA(ptr, tempA, tempB, dora);
    fillB(ptr1, tempA, tempB, dora);
    emptyA(ptr2, tempA, tempB, dora);
    emptyB(ptr3, tempA, tempB, dora);
    pourAtoB(ptr4, tempA, tempB, dora);
    pourBtoA(ptr5, tempA, tempB, dora);
  }
  else {
    ptr->cfB = NULL;
    return;
  }
}

void Jug::emptyA(SalTree* ptr, int tempA, int tempB, map<string, SalTree*>& dora) {
  if(!ptr) {
    return;
  }
  else if(tempA != 0) {
    //Is emptying A an option? If it satisfies this if statement, then yes.
    //Since it empties the jug, tempA = 0
    tempA = 0;
    int tempCost = ptr->totalCost + this->empty_A;
    //cout << tempCost << endl;
    //Sets up the creation of a new key
    string tempS = NumToString(tempA, tempB);
    //If the key doesn't already exist in the map, we insert the new node into the tree and new key into the map
    if(dora.count(tempS) == 0) {
      ptr->ceA = new SalTree(tempA, tempB);
      dora.insert(pair<string, SalTree*>(tempS, ptr->ceA));
    }
    //Else we just link to the prior key in the tree IF THE TOTALCOST IS LOWER (HAVEN'T FIGURED OUT HOW TO DO THIS YET)
    else {
      if((dora[tempS])->totalCost > tempCost) {
        ptr->ceA = dora[tempS];
      }
      else {
        ptr->ceA = NULL;
        ptr = ptr->ceA;
        return;
      }
    }
    //Update the pointer. Generally after this, I will do other options 
    ptr->ceA->path = ptr->path;
    ptr = ptr->ceA;
    ptr->totalCost = tempCost;
    ptr->path.append("empty A\n");
    //cout << "(" << tempA << ", " << tempB << ")" << endl;
    SalTree* ptr1 = ptr;
    SalTree* ptr2 = ptr;
    SalTree* ptr3 = ptr;
    SalTree* ptr4 = ptr;
    SalTree* ptr5 = ptr;
    fillA(ptr, tempA, tempB, dora);
    fillB(ptr1, tempA, tempB, dora);
    emptyA(ptr2, tempA, tempB, dora);
    emptyB(ptr3, tempA, tempB, dora);
    pourAtoB(ptr4, tempA, tempB, dora);
    pourBtoA(ptr5, tempA, tempB, dora);
    return;
  }
  else {
    ptr->ceA = NULL;
    return;
  }
}

void Jug::emptyB(SalTree* ptr, int tempA, int tempB, map<string, SalTree*>& dora) {
  if(!ptr) {
    return;
  }
  else if(tempB != 0) {
    //Is emptying B an option? If it satisfies this if statement, then yes.
    //Since it empties the jug, tempB = 0
    tempB = 0;
    int tempCost = ptr->totalCost + this->empty_B;
    //cout << tempCost << endl;
    //Sets up the creation of a new key
    string tempS = NumToString(tempA, tempB);
    //If the key doesn't already exist in the map, we insert the new node into the tree and new key into the map
    if(dora.count(tempS) == 0) {
      ptr->ceB = new SalTree(tempA, tempB);
      dora.insert(pair<string, SalTree*>(tempS, ptr->ceB));
    }
    //Else we just link to the prior key in the tree IF THE TOTALCOST IS LOWER (HAVEN'T FIGURED OUT HOW TO DO THIS YET)
    else {
      if((dora[tempS])->totalCost > tempCost) {
        ptr->ceB = dora[tempS];
      }
      else {
        ptr->ceB = NULL;
        ptr = ptr->ceB;
        return;
      }
    }
    //Update the pointer. Generally after this, I will do other options
    ptr->ceB->path = ptr->path;
    ptr = ptr->ceB;
    ptr->totalCost = tempCost;
    ptr->path.append("empty B\n");
    //cout << "(" << tempA << ", " << tempB << ")" << endl;
    SalTree* ptr1 = ptr;
    SalTree* ptr2 = ptr;
    SalTree* ptr3 = ptr;
    SalTree* ptr4 = ptr;
    SalTree* ptr5 = ptr;
    fillA(ptr, tempA, tempB, dora);
    fillB(ptr1, tempA, tempB, dora);
    emptyA(ptr2, tempA, tempB, dora);
    emptyB(ptr3, tempA, tempB, dora);
    pourAtoB(ptr4, tempA, tempB, dora);
    pourBtoA(ptr5, tempA, tempB, dora);
    return;
  } 
  else {
    ptr->ceB = NULL;
    return;
  }
}

void Jug::pourAtoB(SalTree* ptr, int tempA, int tempB, map<string, SalTree*>& dora) {
  if(!ptr) {
    return;
  }
  else if(tempA != 0 && tempB != cont_B) {
    //Is pouring from A to an option? If it satisfies this statement, then yes
    //This is the hardest series of checks
    //Some math.
    if(tempA + tempB > cont_B) {
      int diff = cont_B - tempB;
      tempA -= diff;
      tempB = cont_B;
    }
    else {
      tempB += tempA;
      tempA = 0;
    }
    //Normal routine. Set up creation of a new key just like before
    int tempCost = ptr->totalCost + this->ApourB;
    //cout << tempCost << endl;
    string tempS = NumToString(tempA, tempB);
    //If the key doesn't already exist in the map, we insert the new node into the tree and new key into the map
    if(dora.count(tempS) == 0) {
      ptr->cp_AB = new SalTree(tempA, tempB);
      dora.insert(pair<string, SalTree*>(tempS, ptr->cp_AB));
    }
    //Else we just link to the prior key in the tree IF THE TOTALCOST IS LOWER (HAVEN'T FIGURED OUT HOW TO DO THIS YET)
    else {
      if((dora[tempS])->totalCost > tempCost) {
        ptr->cp_AB = dora[tempS];
      }
      else {
        ptr->cp_AB = NULL;
        ptr = ptr->cp_AB;
        return;
      }
    }
    //Update the pointer. Generally after this, I will do other options
    ptr->cp_AB->path = ptr->path;
    ptr = ptr->cp_AB;
    ptr->totalCost = tempCost;
    ptr->path.append("pour A B\n");
    //cout << "(" << tempA << ", " << tempB << ")" << endl;
    SalTree* ptr1 = ptr;
    SalTree* ptr2 = ptr;
    SalTree* ptr3 = ptr;
    SalTree* ptr4 = ptr;
    SalTree* ptr5 = ptr;
    fillA(ptr, tempA, tempB, dora);
    fillB(ptr1, tempA, tempB, dora);
    emptyA(ptr2, tempA, tempB, dora);
    emptyB(ptr3, tempA, tempB, dora);
    pourAtoB(ptr4, tempA, tempB, dora);
    pourBtoA(ptr5, tempA, tempB, dora);
    return;
  }
  else {
    ptr->cp_AB = NULL;
    return;
  }
}

void Jug::pourBtoA(SalTree* ptr, int tempA, int tempB, map<string, SalTree*>& dora) {
  if(!ptr) {
    return;
  }
  else if(tempB != 0 && tempA != cont_A) {
    //Is pouring from B to A an option? If it satisfies this statement, then yes
    //This is the hardest series of checks
    //Some math.
    if(tempB + tempA > cont_A) {
      int diff = cont_A - tempA;
      tempB -= diff;
      tempA = cont_A;
    }
    else {
      tempA += tempB;
      tempB = 0;
    }
    //Normal routine. Set up creation of a new key just like before
    int tempCost = ptr->totalCost + this->BpourA;
    //cout << tempCost << endl;
    string tempS = NumToString(tempA, tempB);
    //If the key doesn't already exist in the map, we insert the new node into the tree and new key into the map
    if(dora.count(tempS) == 0) {
      ptr->cp_BA = new SalTree(tempA, tempB);
      dora.insert(pair<string, SalTree*>(tempS, ptr->cp_BA));
    }
    //Else we just link to the prior key in the tree IF THE TOTALCOST IS LOWER (HAVEN'T FIGURED OUT HOW TO DO THIS YET)
    else {
      if((dora[tempS])->totalCost > tempCost) {
        ptr->cp_BA = dora[tempS];
      }
      else {
        ptr->cp_BA = NULL;
        ptr = ptr->cp_BA;
        return;
      }
    }
    //Update the pointer. Generally after this, I will do other options
    ptr->cp_BA->path = ptr->path;
    ptr = ptr->cp_BA;
    ptr->totalCost = tempCost;
    ptr->path.append("pour B A\n");
    //cout << "(" << tempA << ", " << tempB << ")" << endl;
    SalTree* ptr1 = ptr;
    SalTree* ptr2 = ptr;
    SalTree* ptr3 = ptr;
    SalTree* ptr4 = ptr;
    SalTree* ptr5 = ptr;
    fillA(ptr, tempA, tempB, dora);
    fillB(ptr1, tempA, tempB, dora);
    emptyA(ptr2, tempA, tempB, dora);
    emptyB(ptr3, tempA, tempB, dora);
    pourAtoB(ptr4, tempA, tempB, dora);
    pourBtoA(ptr5, tempA, tempB, dora);
    return;
  }
  else {
    ptr->cp_BA = NULL;
    return;
  }
}