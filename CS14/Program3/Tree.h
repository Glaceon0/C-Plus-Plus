#ifndef __TREE_H
#define __TREE_H

#include "Node.h"

class Tree {
private:
  Node* root;

public:
  Tree( );
  //~Tree( );
  void insert(const string &);
  void preOrder( );
  void inOrder( );
  void postOrder( );
  //void remove(const string &);
  bool search (const string &);

private:
  // Add additional functions/variables here
  void preOrder(Node*);
  void inOrder(Node*);
  void postOrder(Node*);
  Node* findLeaf(const string&, Node*);
  void split(const string&, Node*, Node*, Node*, Node*);
  Node* search(const string&, Node*);
  
    
};
#endif
