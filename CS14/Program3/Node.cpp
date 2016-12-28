#include "Node.h"

Node::Node(const string& data, Node* mom)
 : min(data), max(""), l(NULL), m(NULL), r(NULL), par(mom) {
    
}
