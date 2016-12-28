#include "IntList.h"
#include "SortedSet.h"

using namespace std;

SortedSet::SortedSet() : IntList() { }

SortedSet::SortedSet(const SortedSet& cpy) : IntList(cpy) { }

SortedSet::SortedSet(const IntList& cpy) : IntList(cpy) {
  selection_sort();
  remove_duplicates();
}

SortedSet::~SortedSet() { }

bool SortedSet::in(int value) const {
  for(IntNode* ptr = this->head; ptr != NULL; ptr = ptr->next) {
    if(value == ptr->data) {
      return true;
    }
  }
  return false;
}

void SortedSet::add(int value) {
  //First case: if SortedSet is empty or if the value is less than head->data, 
  //then we utilize the old push_front function and add the value to the list
  IntNode* run_ptr = head;
  if(empty() || value < run_ptr->data) {
    IntList::push_front(value);
    return;
  }
  //run_ptr goes through the loop updating at the end of the while loop
  //Exits while loop when the data at run_ptr is greater than the value
  //Or when the run_ptr hits the last item of the linked list

  //Changing the while loop and adding a temp_ptr which stores the memory address of the IntNode
  //whose data is LESS than the value inputted
  /* temp_ptr initialized to head because if a) the value is smaller than
  the smallest value */ 
  IntNode* temp_ptr = NULL;
  for(run_ptr = head; run_ptr != NULL; run_ptr = run_ptr->next) {
    if(value == run_ptr->data) {
      return;
    } 
    else if(value > run_ptr->data) {
      temp_ptr = run_ptr;
    }
  }
  IntNode* new_ptr = new IntNode(value);
  
  if(tail == temp_ptr) {
    tail = new_ptr;
  }
  //Assign the next of the new IntNode to the IntNode that contains the data GREATER than value
  (*new_ptr).next = (*temp_ptr).next;
  //Assign the IntNode containing the value LESS than value to the IntNode containing value
  (*temp_ptr).next = new_ptr;
  //Does this process stil work if it is the last value? It does
  //Test to see if tail properly updates. CHECK
  //cout << (*tail).data << endl;
  return;   
}

void SortedSet::insert_ordered(int value) {
  add(value);
  return;
}

void SortedSet::push_back(int value) {
  add(value);
  return;
}

void SortedSet::push_front(int value) {
  add(value);
  return;
}

const SortedSet SortedSet::operator|(const SortedSet& set1) const {
  SortedSet newList(set1);
  for(IntNode* run_ptr = this->head; run_ptr != NULL; run_ptr = run_ptr->next) {
    newList.add(run_ptr->data);
  }
  return newList;
}

const SortedSet SortedSet::operator&(const SortedSet& set1) const {
  SortedSet newList;
  for(IntNode* ptr = this->head; ptr != NULL; ptr = ptr->next) {
    if(set1.in(ptr->data)) {
      newList.add(ptr->data);
    }
  }
  return newList;
}

SortedSet& SortedSet::operator|=(const SortedSet& set1) {
  SortedSet temp = *this | set1;
  *this = temp;
  return *this;
}

SortedSet& SortedSet::operator&=(const SortedSet& set1) {
  SortedSet temp = *this & set1;
  *this = temp;
  return *this;
}