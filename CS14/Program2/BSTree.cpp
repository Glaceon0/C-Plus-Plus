#include "BSTree.h"
#include <iostream>

using namespace std;

BSTree::BSTree()
: root(NULL) { }

BSTree::~BSTree() {
  while(!empty()) {
    remove(root->getData());
  }
}

bool BSTree::empty() const {
  if(!root) {
    //cout << "True" << endl;
    return true;
  }
  return false;
}

string BSTree::smallest() const {
  string x = "";
  if(empty()) {
    return x;
  }
  //Just go left until we hit a null and then return the string
  for(Node* trav = this->root; trav != NULL; trav = trav->getLeft()) {
    x = trav->getData();
  }
  return x;
}

string BSTree::largest() const {
  string x = "";
  if(empty()) {
    return x;
  }
  //Just go right until we hit a null and then return the string
  for(Node* trav = this->root; trav != NULL; trav = trav->getRight()) {
    x = trav->getData();
  }
  return x;
}

void BSTree::insert(const string& fox) {
  //Easiest case. If the tree is empty, we set the new Node as the root of the binary tre
  if(empty()) {
    Node* leaf = new Node(fox);
    this->root = leaf;
  }
  //Else condition which has a while loop which contains three if-else statements. Either fox is less than 
  //the string which trav contains in which case we traverse down the left side, is equal to trav in which 
  //case we incremement the counter, or is greater than trav in which case we traverse down the right side
  else {
  //Initialize trav to root
    Node* trav = root;
    //Trav should essentially never be equal to NULL because we'll have returned out before then
    while(trav) {
      //A check to see why the function is not working properly
      //cout << trav->getData() << endl;
      //First condition, if less than
      if(fox < trav->getData()) {
        //Check to see if trav has a left child. If not create a new Node, connect it to trav->left and exit out
        if(!trav->getLeft()) {
          trav->addLeft(fox);
          return;
        }
        //If not, continue down the left side of the tree
        trav = trav->getLeft();
        //Another check
        //cout << trav->getData() << endl;
      }
      //Second condition, if equal to. Just increment the counter and exit out
      else if(fox == trav->getData()) {
        trav->incCounter();
        return;
      }
      //Final condition, if greater than
      else {
        //Check to see if trav has a right child. If not create a new Node, connect it to trav->right and exit out
        if(!trav->getRight()) {
          trav->addRight(fox);
          return;
        }
        //Else, continue down the right side of the tree
        trav = trav->getRight();
        //Another check
        //cout << trav->getData() << endl;
      }
    }
  }
  return;
}

//A recursive function that returns true if the string is found in the tree, and false
//if the string is not present in the BST. Will use a private helper function
bool BSTree::search(const string& fox) const {
  return search(fox, root);
}

bool BSTree::search(const string& fox, Node* trav) const {
  //cout << trav->getData() << endl;
  if(empty()) {
    return false;
  }
  else if(trav->getData() == fox) {
    return true;
  }
  else if(fox < trav->getData()) {
    //cout << "Left" << " ";
    if(!trav->getLeft()) {
      //cout << "Returned false" << endl;
      return false;
    }
    return search(fox, trav->getLeft());
  }
  else {
    //cout << "Right" << " ";
    if(!trav->getRight()) {
      //cout << "Returned false" << endl;
      return false;
    }
    return search(fox, trav->getRight()); 
  }
}

//Also a recursive function
int BSTree::height(const string& fox) const {
  //First step is to find the string using a while loop
  int count = -1;
  Node* trav = root;
  if(empty()) {
    return count;
  }
  while(trav->getData() != fox) {
    if(trav->getData() > fox) {
      trav = trav->getLeft();
    }
    else if(trav->getData() < fox) {
      trav = trav->getRight();
    }
    if(!trav) {
      return count;
    }
  }
  //At this point, the string should have either been found
  //Or we should have exited out of the function
  //Now we find the largest path and find the lenght of that path
  //We do this using a recursive function
  return height(trav, count);
}

int BSTree::height(Node* start, int count) const {
  //Base case
  if(!start) {
    return count;
  }
  //Recursive call
  int x = height(start->getLeft(), count + 1);
  int y = height(start->getRight(), count + 1);
  //Returns the largest count which indicates the largest path
  if(x >= y) {
    return x;
  }
  else {
    return y;
  }
}

//Removes a node from the tree
void BSTree::remove(const string& fox) {
  Node* prev = NULL;
  remove(prev, root, fox);
  return;
}

//Recursive private helper function that removes the node from the tree
void BSTree::remove(Node* prev, Node* start, const string& fox) {
  //Traverse through the subtree of start
  //Create a Node* which will point to the node prior to start
  //If prev = NULL, then start == root
  while(start) {
    //If we find the string, we proceed to go through the removal process
    if(start->getData() == fox) {
      //cout << "Found it" << " ";
      //Case 1: Counter > 1, so we just decrement counter
      if(start->getCount() > 1) {
        start->decCounter();
      }
      //Case 2: The node is a leaf/has no left or right child
      else if(!start->getLeft() && !start->getRight()) {
        //This indicates that start == prev, and thus start is a root
        //cout << "Case 2" << " ";
        if(!prev) {
          root = NULL;
        }
        else if(prev->getLeft() == start) {
          prev->setLeft(NULL);
        }
        else {
          prev->setRight(NULL);
        }
        delete start;
      }
      /*//Case 3: This node has only a left child
      else if(!start->getRight()) {
        //This indicates that start is the root
        //cout << "Case 3" << " ";
        if(!prev) {
          root = start->getLeft();
        }
        //If prev is start's left child
        else if(prev->getLeft() == start) {
          prev->setLeft(start->getLeft());
        }
        //If prev is start's right child
        else {
          prev->setRight(start->getLeft());
        }
        delete start;
      }*/
      //Case 4: This node has only a right child
      else if(!start->getLeft()) {
        //cout << "Case 4" << " ";
        //This indicates that start is the root
        /*if(!prev) {
          root = start->getRight();
        }
        //If prev is start's left child
        else if(prev->getLeft() == start) {
          prev->setLeft(start->getRight());
        }
        //If prev is start's right child
        else {
          prev->setRight(start->getRight());
        }
        delete start;
      }*/
        prev = start;
        Node* next = start->getRight();
        while(next->getLeft()) {
          prev = next;
          next = next->getLeft();
        }
        //cout << prev->getData() << " ";
        //cout << next->getData() << " ";
        start->setData(next);
        start->setCounter(next);
        next->setCounter(1);
        remove(prev, start->getRight(), next->getData());
      }
      //Case 5: This node has both a left and a right child
      else {
        //Find the successor, the right-most child of the left subtree
        //Set the prev node to start
        //cout << start->getData() << " ";
        prev = start;
        Node* next = start->getLeft();
        while(next->getRight()) {
          prev = next;
          next = next->getRight();
        }
        //cout << prev->getData() << " ";
        //cout << next->getData() << " ";
        start->setData(next);
        start->setCounter(next);
        next->setCounter(1);
        remove(prev, start->getLeft(), next->getData());
      }
      return;
    }
    //If we don't find the string, continue to go through the tree
    else if(start->getData() > fox) {
      //This way, prev will be always be the parent of start
      prev = start;
      start = start->getLeft();
    }
    else {
      //Same as above
      prev = start;
      start = start->getRight();
    }
  }
  return;
}

//A recursive function that will print the function in pre-order traversal
//Will use a private helper function
void BSTree::preOrder() const {
  preOrder(root);
  cout << endl;
  return;
}

void BSTree::preOrder(Node* trav) const {
  if(!trav) {
    return;
  }
  cout << trav->getData() << "(" << trav->getCount() << ")," << " ";
  preOrder(trav->getLeft());
  preOrder(trav->getRight());
  return;
}
//A recursive function that will print the functions in order traversal
//Contains a private helper function
void BSTree::inOrder() const {
  inOrder(root);
  cout << endl;
  return;
}

void BSTree::inOrder(Node* trav) const {
  if(!trav) {
    return;
  }
  inOrder(trav->getLeft());
  cout << trav->getData() << "(" << trav->getCount() << ")," << " ";
  inOrder(trav->getRight());
  return;
}

void BSTree::postOrder() const {
  postOrder(root);
  cout << endl;
  return;
}

void BSTree::postOrder(Node* trav) const {
  if(!trav) {
    return;
  }
  postOrder(trav->getLeft());
  postOrder(trav->getRight());
  cout << trav->getData() << "(" << trav->getCount() << ")," << " ";
  return;
}

