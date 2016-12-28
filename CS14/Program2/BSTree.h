#ifndef BSTREE_H
#define BSTREE_H

#include "Node.h"
#include <string>

using namespace std;

class BSTree {
  private:
    Node* root;
  public:
    BSTree();
    ~BSTree();
    bool empty() const;
    string largest() const;
    string smallest() const;
    int height(const string&) const;
    void insert(const string&);
    //Fucntions from this point onward need to be written recursively
    void remove(const string&);
    bool search(const string&) const;
    void preOrder() const;
    void inOrder() const;
    void postOrder() const;
    
  private:
    bool search(const string&, Node*) const;
    void preOrder(Node*) const;
    void inOrder(Node*) const;
    void postOrder(Node*) const;
    int height(Node*, int) const;
    void remove(Node*, Node*, const string&);
};

#endif