#include <iostream>
#include <stdexcept>
#include "IntVector.h"

using namespace std;

IntVector::IntVector() : sz(0), cap(0), data(NULL) {
  cout << sz << endl << cap << endl << data << endl;
  return; 
}

IntVector::IntVector(unsigned size, int value) 
: sz(size), cap(size), data(new int[sz]) { 
  for(unsigned i = 0; i < sz; ++i) {
    data[i] = value; 
  }
  return;
}

IntVector::~IntVector() {
  delete [] data;
}

unsigned IntVector::size() const {
  return sz;
}

unsigned IntVector::capacity() const {
  return cap;
}

bool IntVector::empty() const {
  if(sz == 0) {
    return true;
  }
  else {
    return false;
  }
}

const int& IntVector::at(unsigned index) const {
  if(index < this->sz) {
    return data[index];
  }
  else {
    throw out_of_range("IntVector::at_range_check"); 
  }
}

const int& IntVector::front() const {
  return data[0];
}

const int& IntVector::back() const {
  return data[sz - 1];
}



