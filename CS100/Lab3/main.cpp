#include <iostream>
#include "Add.h"
#include "Sub.h"
#include "Mult.h"
#include "Div.h"
#include "Sqr.h"
#include "Op.h"
#include "VectorContainer.h"
#include "ListContainer.h"
#include "BubbleSort.h"
#include "SelectionSort.h"


using namespace std;

int main() {
  Op* op7 = new Op(7);
  Op* op4 = new Op(4);
  Op* op3 = new Op(3);
  Op* op2 = new Op(2);
  Mult* A = new Mult(op7, op4);
  Add* B = new Add(A, op3);
  Sub* C = new Sub(B, op2);
  Sqr* D = new Sqr(C);
  Div* E = new Div(D, op2);
  
  VectorContainer* container = new VectorContainer();
  container->add_element(A);
  container->add_element(B);
  container->add_element(C);
  container->add_element(D);
  container->add_element(E);
  
  cout << "Container Before Sort: " << endl;
  container->print();
  
  cout << "Container After Sort: " << endl;
  container->set_sort_function(new SelectionSort());
  container->sort();
  container->print();
  
  cout << "New test case" << endl;
  Mult* F = new Mult(op7, op2);
  Add* G = new Add(F, op4);
  Div* H = new Div(G, op3);
  Sqr* I = new Sqr(H);
  
  ListContainer* container2 = new ListContainer();
  container2->add_element(F);
  container2->add_element(G);
  container2->add_element(H);
  container2->add_element(I);
  
  cout << "Container Before Sort: " << endl;
  container2->print();
  
  cout << "Container After Sort: " << endl;
  container2->set_sort_function(new BubbleSort());
  container2->sort();
  container2->print();
};
