#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include "IntVector.h"

using namespace std;

IntVector::IntVector() : sz(0), cap(0), data(NULL) {
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


void IntVector::expand() {
  int* tempArray = new int[this->cap * 2];
  for(unsigned i = 0; i < cap; ++i) {
    tempArray[i] = data[i];
  }
  delete data;
  data = tempArray;
  cap *= 2;
  return;
}

void IntVector::expand(unsigned amount) {
  int* tempArray = new int[this->cap + amount];
  for(unsigned i = 0; i < cap; ++i) {
    tempArray[i] = data[i];
  }
  delete data;
  data = tempArray;
  cap = amount;
  return;
}

void IntVector::insert(unsigned index, int value) {
  if(index > sz) {
    throw out_of_range("IntVector::insert_range_check");
  }
  else {
    if(cap == 0) {
      expand(1);
    }
    if(sz == cap) {
      expand();
    }
    else { }
    sz += 1;
    for(unsigned i = sz - 1; i > index; --i) {
        data[i + 1] = data[i];
      }
      data[index] = value;
      
      return;
  }
}

void IntVector::erase(unsigned index) {
  if(index >= sz) {
    throw out_of_range("IntVector::erase_range_check");
  }
  else {
    for(unsigned i = index; i < sz - 1; ++i) {
      data[i] = data[i + 1];
    }
    sz -= 1;
    return;
  }
}

void IntVector::push_back(int value) {
  if(cap == 0) {
      expand(1);
    }
  else if(sz == cap) {
    expand();
  }
  data[sz] = value;
  sz += 1;
  return;
}

void IntVector::pop_back() {
  sz -= 1;
  return;
}

void IntVector::clear() {
  sz = 0;
  return;
}

int& IntVector::at(unsigned index) {
  if(index < this->sz) {
    return data[index];
  }
  else {
    throw out_of_range("IntVector::at_range_check"); 
  }
}

int& IntVector::front() {
  return data[0];
}

int& IntVector::back() {
  return data[sz - 1];
}

void IntVector::reserve(unsigned n) {
  if(n <= cap) {
    
  }
  else if(n <= 2 * cap) {
    expand();
  }
  else {
    expand(n - cap);
  }
  return;
}

void IntVector::resize(unsigned size, int value) {
  if(size <= sz) {
    sz = size;
    return;
  }
  if(size > sz) {
    if(size <= cap) {
      
    }
    else if(size > cap) {
      if(size <= 2 * cap) {
        expand();
      }
      else {
        expand(size - sz);
      }
    }
  }
  for(unsigned i = sz; i < size; ++i) {
      data[i] = value;
  }
  sz = size;
  return;
}

void IntVector::assign(unsigned n, int value) {
  if(n > 2 * cap) {
    expand(n - cap);
  }
  else if (n > cap && n <= 2 * cap) {
    expand();
  }
  for(unsigned i = 0; i < n; ++i) {
    data[i] = value; 
  }
  sz = n;
  return;
}
  
