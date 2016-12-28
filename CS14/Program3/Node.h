#ifndef NODE_H
#define NODE_H

#include "string"

using namespace std;

class Node {
friend class Tree;
  public:
    Node(const string&, Node*);
  private:
    string min;
    string max;
    Node* l;
    Node* m;
    Node* r;
    Node* par;
};

#endif
    