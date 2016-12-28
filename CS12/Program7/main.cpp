#include <iostream>
#include "IntList.h"
#include "SortedSet.h"

using namespace std;

int main() {
  int userNum;
  SortedSet set1;
  /*if(newList.empty()) {
    cout << "The list is empty" << endl;
  }
  else {
    cout << "The list is not empty" << endl;
  }*/
  
  while(cin.good()) {
    cout << "Add a number to the set (Enter E to exit): " << endl;
    cin >> userNum;
    if(cin.good()) {
      set1.add(userNum);
    }
  }
  cin.clear();
  
  cout << set1 << endl;
  
  SortedSet set2;
  
  set2.push_front(3);
  set2.push_front(4);
  set2.push_back(7);
  set2.push_back(6);
  
  cout << set2 << endl;
  
  SortedSet newList;
  
  newList = set1 & set2;
  
  cout << newList << endl;
  
  SortedSet set3(set2);
  
  cout << set3 << endl;
  
  SortedSet set4 = set1 | set3;
  
  cout << set4 << endl;
  
  return 0;
}
  

  
  