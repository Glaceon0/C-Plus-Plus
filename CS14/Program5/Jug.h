#ifndef __JUG_H
#define __JUG_H

#include <utility>
#include <sstream>
#include <iostream>
#include <map>
using namespace std;

struct SalTree {
  SalTree* cfA;
  SalTree* cfB;
  SalTree* ceA;
  SalTree* ceB;
  SalTree* cp_AB;
  SalTree* cp_BA;
  int A;
  int B;
  int totalCost;
  string path;
  
  SalTree(int jug_A, int jug_B) : A(jug_A), B(jug_B), totalCost(0), path("") { }
  
};

class Jug {
  public:
    Jug(int,int,int,int,int,int,int,int,int);
    ~Jug();
    int solve(string&);
  private: 
    void fillA(SalTree*, int, int, map<string, SalTree*>&);
    void fillB(SalTree*, int, int, map<string, SalTree*>&);
    void emptyA(SalTree*, int, int, map<string, SalTree*>&);
    void emptyB(SalTree*, int, int, map<string, SalTree*>&);
    void pourAtoB(SalTree*, int, int, map<string, SalTree*>&);
    void pourBtoA(SalTree*, int, int, map<string, SalTree*>&);
  private:
    //The 6 costs and the root of the tree
    int cont_A;
    int cont_B;
    int goal;
    int fill_A;
    int fill_B;
    int empty_A;
    int empty_B;
    int ApourB;
    int BpourA;
    SalTree* start;
    map<string, SalTree*> dora;
};

#endif