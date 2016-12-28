#include <iostream>
#include <stdexcept>
#include "IntVector.h"
using namespace std;

int main() {
   cout << "First test harness for the constructors" << endl;
   IntVector testVector1();
   
   IntVector testVector2(5, 3);
   
   cout << "Test harness for the accessor functions" << endl;
   cout << "Testvector2 size is: " << testVector2.size() << endl; 
   cout <<"Testvector2 capacity is: " << testVector2.capacity() << endl;
    
   
   /*cout << "Is testvector1 empty?: ";
   if(testVector1.empty()) { 
      cout << "Yes" << endl;
   }
   else {
      cout << "No" << endl;
   }*/ 
   
   cout << "Is testvector2 empty?: ";
   if(testVector2.empty()) {
      cout << "Yes" << endl;
   }
   else {
      cout << "No" << endl;
   }
   
   cout << "Testvector1 first value is " << testVector2.front() << endl;
   cout << "Testvector2 last value is " << testVector2.back() << endl;
   
   cout << "Testvector2 3rd value is " << testVector2.at(2) << endl;
   cout << "Testvector2 7th value throws out_of_range" << testVector2.at(6) << endl;
   
   return 0;
}