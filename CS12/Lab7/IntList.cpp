#include <iostream>
#include "IntList.h"

using namespace std;

IntList::IntList()  : head(NULL), tail(NULL) { }

IntList::~IntList() {
  while(!empty()){
  pop_front();
  }
}

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

void IntList::display() const {
  /* If empty list, exit out of display function */
  if(empty()) {
    return;
  }
  //Since the list is not empty, print the data which the dereferenced head points to 
  cout << (*head).data;
  //Initialize a new pointer, which is assigned to the next pointer in the linked list 
  IntNode* plc_ptr = (*head).next;
  // Create a while loop that checks whether the pointer points to anything.
  // This checks to see whether it is the end of the linked list
  while(plc_ptr != NULL) {
  // Prints the dereferenced pointers data
    cout << " " << (*plc_ptr).data;
  /*Updates the memory address which the temporary pointer points to, 
  going through the list each time it goes through the while loop */
    plc_ptr = (*plc_ptr).next;
  }
  return;
}

bool IntList::empty() const {
  //The linked list is empty if the head doesn't point to any memory addres/is NULL
  if(head == NULL) {
    return true;
  }
  return false;
}

void IntList::pop_front() {
  //First check to see if the linked list is empty/if there is a first item that needs to be deleted
  if(empty()) {
    return;
  }
  //Set a temporary pointer to the next of the first item, which is the memory address of the second item
  IntNode* temp_ptr = (*head).next;
  //Delete the memory address for head
  delete head;
  //Reassign to head the memory address of what was the memory address of the second item
  head = temp_ptr;
  return;
}