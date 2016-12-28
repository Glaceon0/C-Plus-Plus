#include <iostream>
#include "IntList.h"

using namespace std;

IntList::IntList()  : head(NULL) { }

void IntList::push_front(int value) {
  /*Creates a temporary pointer of type IntNode, assigning a memory address (block of memory) 
to temp_ptr of type IntNode and then initializing with a constructor. */
   IntNode* temp_ptr = new IntNode(value);
  /*Then we assign the current address of head (if just empty list, this is NULL) to the 
   dereferenced temporary pointer's next memory address */
   (*temp_ptr).next = this->head;
  /*Assign the memory address of temporary pointer (which points to the newly created block of memory) to head. */
   this->head = temp_ptr;
   return;
}

ostream& operator<<(ostream& out, const IntList& rhs) {
  IntNode* tempNode = rhs.head;
  out << tempNode;
  return out;
}

ostream& operator<<(ostream& out, IntNode* temp) {
  //Base case, returning nothing if list is empty
  if(temp == NULL) {
     return out;
  }
  //Last number in order to adjust the spaces
  if(temp->next == NULL) {
     out << temp->data;
     return out;
  }
  //Recursive case
  out << temp->data << " ";
  temp = temp->next;
  operator<<(out, temp);
  return out;
}

bool IntList::exists(int value) const{
  IntNode* curr = head;
  if(exists(curr, value)) {
     return true;
  }
  return false;
}

bool IntList::exists(IntNode* temp, int value) const {
  //Base case
  if(temp == NULL) {
     return false;
  }
  if(temp->data == value) {
     return true;
  }
  //Recursive case
  temp = temp->next;
  if(exists(temp, value)) {
     return true;
  }
  
  return false;
}