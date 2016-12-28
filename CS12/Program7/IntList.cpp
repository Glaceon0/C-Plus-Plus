#include <iostream>
#include "IntList.h"

using namespace std;

IntList::IntList()  : head(NULL), tail(NULL) { }

IntList::~IntList() {
//Calls clear()  
  clear();
}

IntList::IntList(const IntList& cpy) : head(NULL), tail(NULL) {
  IntNode* ptr = cpy.head;
  if(cpy.head == NULL) {
    
  }
  else if(cpy.head == cpy.tail) {
    push_front(ptr->data);
  }
  else {
    for(ptr = cpy.head; ptr != NULL; ptr = ptr->next) {
    push_back(ptr->data);
    }
  }
}

IntList& IntList::operator=(const IntList& rhs) {
  if(this == &rhs){
    return *this;
  }
  clear();
  IntNode* ptr = rhs.head;
  if(rhs.head == NULL) {
    
  }
  else if(rhs.head == rhs.tail) {
    push_front(ptr->data);
  }
  else {
    for(ptr = rhs.head; ptr != NULL; ptr = ptr->next) {
    push_back(ptr->data);
    }
  }
  return *this; 
}

void IntList::push_front(int value) {
  /*Creates a temporary pointer of type IntNode, assigning a memory address (block of memory) 
to temp_ptr of type IntNode and then initializing with a constructor. */
  IntNode* temp_ptr = new IntNode(value);
  /*If the list is empty, the address of the temporary pointer is also going to be the tail */
  if(empty()) {
    this->tail = temp_ptr;
  }
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
  /* Check to see if my tail is properly configured 
  cout << " " << (*tail).data; */
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
  if(empty()) {
    tail = NULL;
  }
  return;
}

//Private function that is used in selection_sort function
void IntList::swap(IntNode* ptr1, IntNode* ptr2) {
  int x = (*ptr1).data;
  (*ptr1).data = (*ptr2).data;
  (*ptr2).data = x;
  return;
}

//The swap test harness was successful. The test harness works.
/*void IntList::swap_testharness() {
  swap(head, (*head).next);
  return;
}*/

void IntList::selection_sort() {
  /* There are three temporary pointers and one integer necessary for the selection_sort
  function. This basically works in the same way as the selection sort for vectors
  except with pointers. */
  // start_ptr is swapped with the swp_ptr after we determine what the smallest value in the list is
  // x is updated in the while loop to the smallest value
  // run_ptr runs through the while loop updating after each iteration
  IntNode* swap_ptr;
  IntNode* run_ptr;
  int x;
  //Initialize start_ptr to the head. This will be updated at the end of second while loop
  IntNode* start_ptr = this->head;
  //cout << "No problem yet-0" << endl;
  while(start_ptr != this->tail) {
    //Both the run_ptr and x are updated at the beginning of the second while loop
    //run_ptr is assigned to memory address for the second item in the linked list
    //x is assigned to the first value in the linked list
    //cout << "No problem yet-1" << endl;
    run_ptr = (*start_ptr).next;
    //cout << "No problem yet-2" << endl;
    x = (*start_ptr).data;
    while(run_ptr != NULL) {
      //If we find a smaller value than the first one, we update x (the value) and
      //swap_ptr (memory address of said value)
      //cout << "No problem yet-3" << endl;
      if(x > (*run_ptr).data) {
        //cout << "No problem yet-4" << endl;
        x = (*run_ptr).data;
        //There is a segmentation fault somewhere, so I'm putting cout << x in order to determine
        //whether the problem is before or after here
        //cout << x;
        swap_ptr = run_ptr;
      }
    //Update run_ptr so that the while loop does not infinite
    run_ptr = (*run_ptr).next;
    //End first while loop
    }
    //Access the swap function to swap the data of swap_ptr and start_ptr
    //FOUND THE PROBLEM THAT CAUSES THE SEGMENTATION FAULT. IF (*START_PTR).DATA/X IS THE SMALLEST VALUE
    //SWAP_PTR REMAINS UN-INITIALIZED, THUS CAUSING A SEGMENTATION FAULT
    //The answer is to implement an if statement that checks to see whether x updated from its "initialization"
    if((*start_ptr).data != x) {
      swap(swap_ptr, start_ptr);
    }
    //Update start_prt. This also updates run_ptr and start_ptr at the beginning of the while loop
    start_ptr = (*start_ptr).next;
  }
  return;
}

ostream& operator<<(ostream& out, const IntList& rhs) {
 //Copy the code from display() and use it in this function. Both functions essentially do the same thing. 
  //Refer to display() and the comments for it if confused about how the function works
  if(rhs.empty()) {
    return out;
  }
  out << rhs.head->data;
  IntNode* plc_ptr = rhs.head->next;
  while(plc_ptr != NULL) {
    out << " " << (*plc_ptr).data;
    plc_ptr = (*plc_ptr).next;
  }
  return out;
}

//This one almost seemed too easy
void IntList::push_back(int value) {
  //Check and see if the vector is empty. If it is, push_front is better for our purposes
  if(empty()) {
    push_front(value);
    return;
  }
  //If not, create a new IntNode memory address called ptr, same as in push_front
  IntNode* ptr = new IntNode(value);
  //tail->next is set to NULL prior. Set it to the memory address of this IntNode
  (*tail).next = ptr;
  //Reassign tail to the memory address of this IntNode and then return
  tail = ptr;
  return;
}

void IntList::insert_ordered(int value) {
  if(empty()) {
    push_front(value);
    return;
  }
  //run_ptr goes through the loop updating at the end of the while loop
  //Exits while loop when the data at run_ptr is greater than the value
  //Or when the run_ptr hits the last item of the linked list
  IntNode* run_ptr = head;
  //Taking the easy way out here. Setting an if loop that checks to see if the value is LESS
  //than or equal to the first number in the loop. If so, then push_front
  if(value <= (*run_ptr).data) {
    push_front(value);
    return;
  }
  //Changing the while loop and adding a temp_ptr which stores the memory address of the IntNode
  //whose data is LESS than the value inputted
  /* temp_ptr initialized to head because if a) the value is smaller than
  the smallest value */ 
  IntNode* temp_ptr = NULL;
  while(run_ptr != NULL) {
    //Updates the while loop so that no infinite loop
    if(value >= (*run_ptr).data) {
      temp_ptr = run_ptr;
      //Testing to see whether the if-statement works properly. CHECK
      //cout << (*temp_ptr).data << endl;
    }
    run_ptr = (*run_ptr).next;
  }
  //At the end of the while loop, temp_ptr points to the IntNode whose data is LESS than the value inputted
  
  //Now we create a new pointer address
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

void IntList::remove_duplicates() {
  if(head == tail) {
    return;
  }
  //Placehold pointer so that we can disattach this IntNode
  //from the list yet still have the memory address which we will delete
  //Prevents memory leak
  IntNode* deleted_ptr;
  //Works similarly to the selection_sort function
  //Set up an inner for loop with two pointers that run simultaneously through the linked list
  IntNode* aftr_ptr;
  //Checking the two numbers with the third pointer explained below
  //A third pointer is set at the beginning of the outer for loop and runs through the list after
  //The first two pointers have reached the end
  //Set bfr_ptr to the memory address of the first IntNode
  //run_ptr is dependent on bfr_ptr. Starts off as the memory address of the second IntNode
  for(IntNode* curr_ptr = head; curr_ptr != tail && curr_ptr != NULL; curr_ptr = curr_ptr->next) {
    for(IntNode* bfr_ptr = curr_ptr; bfr_ptr != tail && bfr_ptr != NULL; bfr_ptr = bfr_ptr->next) {
      aftr_ptr = bfr_ptr->next;
      //bfr_ptr starts at curr_ptr. aftr_ptr will always catch the duplicate first
      //so bfr_ptr doesn't need to check. It's just a placeholder
      if(curr_ptr->data == aftr_ptr->data) {
        //The while loop is for recurring duplicate data after the deleted one
        while(aftr_ptr != NULL && aftr_ptr->data == curr_ptr->data) {
          //Set deleted_ptr to the memory address of the IntNode that is to be deleted
          deleted_ptr = aftr_ptr;
          //Set aftr_ptr to the memory address of the next IntNode
          aftr_ptr = aftr_ptr->next;
          //Proceed to delete the IntNode
          delete deleted_ptr;
        }
        //Set the next of bfr_ptr to the memory address of aftr_ptr, thus disattaching the deleted
        //IntNode from the linked list
        bfr_ptr->next = aftr_ptr;
      }
      if(bfr_ptr->next == NULL) {
        tail = bfr_ptr;
      }
    }
  }
  return;
}

void IntList::clear() {
  while(!empty()){
  pop_front();
  }
  return;
}



