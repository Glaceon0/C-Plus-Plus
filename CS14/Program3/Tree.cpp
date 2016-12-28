#include "Tree.h"
#include <iostream>
#include <algorithm>

using namespace std;

Tree::Tree() : root(NULL) {
    
}

/*Tree::~Tree() {
    removeTree(root);
}*/

//Recursive in order function. Very similar to that of BSTree
void Tree::inOrder() {
  inOrder(root);
  cout << endl;
  return;
}

//Same idea as BSTree, except one has to check if the node has another string contained
//Which one prints after traversing through everything in the m
void Tree::inOrder(Node* trav) {
  if (!trav) {
    return;
  }
  inOrder(trav->l);
  cout << trav->min << ", ";
  inOrder(trav->m);
  if (trav->max != "") {
    cout << trav->max << ", ";
  }
  inOrder(trav->r);
  return;
}

//Recursive pre-order function. Very similar to that of BSTree
void Tree::preOrder() {
  preOrder(root);
  cout << endl;
  return;
}

//Same idea as inorder, except one prints the second string after traversing through the l side
void Tree::preOrder(Node* trav) {
  if (!trav) {
    return;
  }
  cout << trav->min << ", ";
  preOrder(trav->l);
  if (trav->max != "") {
    cout << trav->max << ", ";
  }
  preOrder(trav->m);
  preOrder(trav->r);
  return;
}

//Recursive post-order function. Very similar to that of BSTree
void Tree::postOrder() {
  postOrder(root);
  cout << endl;
  return;
}

//Similar to inorder, except 
void Tree::postOrder(Node* trav) {
  if (!trav) {
    return;
  }
  //If the maxst string exists, one goes through all three children, 3 Node. 
  if (trav->max != "") {
    postOrder(trav->l);
    postOrder(trav->m);
    cout << trav->min << ", ";
    postOrder(trav->r);
    cout << trav->max << ", ";
  }
  //If the maxst string doesn't exist, we only go through the l and r child
  //Since it is a 2 Node
  else {
    postOrder(trav->l);
    postOrder(trav->r);
    cout << trav->min << ", ";
  }
}

bool Tree::search(const string& data) {
  return search(data, root);
}

Node* Tree::search(const string& data, Node* trav){
  if (!trav) {
    return 0;
  }
  //Node has two values (and thus is a 3 Node)
  if (trav->max != "") {
    if (data == trav->min || data == trav->max) {
      return trav;
    }
    else if (data < trav->min) {
      return search(data, trav->l);
    }
    else if (data < trav->max) {
      return search(data, trav->m);
    }
    return search(data,trav->r);
  }
  //Node has 1 value ( and thus is a 2 Node)
  else {
    if (data == trav->min) {
      return trav;
    }
    else if (data < trav->min) {
      return search(data, trav->l);
    }
    return search(data, trav->r);
  }
}

void Tree::insert(const string& data) {
  //This means that the Tree is empty and we insert as the root
  if (root == NULL) {
    root = new Node(data, NULL);
    return;
  }
  //If not, we find the Node to which we insert data 
  Node* leaf = findLeaf(data, root);
  //If it only has one value, we can easily insert without having to split
  if (leaf->max == "") {
    //Simple adjustments
    if (data > leaf->min) {
      leaf->max = data;
    }
    else {
      leaf->max = leaf->min;
      leaf->min = data;
    }
  }
  //If it has more than one value, we are forced to split
  else {
    split(data,leaf, NULL, NULL, NULL);
  }
  return;
}

Node* Tree::findLeaf(const string& data, Node* trav) {
  //Just a check. Means that tree is empty
  if (trav == 0) {
    return 0;
  }
  //Node contains only one value (and thus is a 2 Node)
  if (trav->max == "") {
    //Already at lowest level and thus return trav
    if (!trav->l) {
      return trav;
    }
    //Check and see whether one goes down the l or the r child
    else if(data < trav->min) {
      return findLeaf(data, trav->l);
    }
    else {
      return findLeaf(data, trav->r);
    }
  }
  //Node contains two values (and thus is a 3 Node)
  else {
    //No l node, at lowest
    if (!trav->l) {
      return trav;
    }
    else if (data < trav->min) {
      return findLeaf(data, trav->l);
    }
    else if (data < trav->max) {
      return findLeaf(data, trav->m);
    }
    else {
      return findLeaf(data, trav->r);
    }
  }
}

void Tree::split(const string& data, Node* trav, Node* node1, Node* node2, Node* past) {
    bool check = false; 
    //When splitting a node that has "3" values, find the one that's in the m in terms of value and move it up.
    //Min will always be less than max, so just compare data with the l and r childs
    string x = data;
    if(trav->min > data) {
      x = trav->min;
    }
    else if(trav->max < data) {
      x = trav->max;
    }
    //Splitting the root is easy. Just move the m one up and make that the root and make the l and r child accordingly
    //That is the if statement
    Node* parent = NULL;
    if(trav == root) {
      parent = new Node(x, NULL);
      root = parent;
      check = true;
    }
    else {
      parent = trav->par; 
    }
    //More string comparisons
    string y = trav->min;
    string z = trav->max;
    if(x == trav->max) {
      z = data;
      y = trav->min;
    }
    else if(x == trav->min) {
      y = data;
      z = trav->max;
    }
    else {
      
    }
    //Re-establishing the children of parent
    Node* n1 = new Node(y, parent);
    Node* n2 = new Node(z, parent);
    //If the node that we are splitting is the root, just do this. However, the children for n1 and n2 have not been set yet
    if(check) {
      parent->l = n1;
      parent->r = n2;
    }
    //
    else {
      if (parent->max != "") {
        split(x,parent,n1,n2,trav);
      }
      else {
        if (x > parent->min) {
          parent->max = x;
        }
        else {
          parent->max = parent->min;
          parent->min = x;
        }
      }
      if (trav == parent->l) {
        parent->l = n1;
        parent->m = n2;
      }
      else {
        parent->m = n1;
        parent->r = n2;
      }
    }
    if (past) {
      if (past == trav->l) {
        n1->l = node1;
        n1->r = node2;
        n2->l = trav->m;
        n2->r = trav->r;
        n1->l->par = n1;
        n1->r->par = n1;
        n2->l->par = n2;
        n2->r->par = n2;
      }
      else if (past == trav->m) {
        n1->l = trav->l;
        n1->r = node1;
        n2->l = node2;
        n2->r = trav->r;
        n1->l->par = n1;
        n1->r->par = n1;
        n2->l->par = n2;
        n2->r->par = n2;
      }
      else {
        n1->l = trav->l;
        n1->r = trav->m;
        n2->l = node1;
        n2->r = node2;
        n1->l->par = n1;
        n1->r->par = n1;
        n2->l->par = n2;
        n2->r->par = n2;
      }
    }
  delete trav;
}

/*void Tree::visualizeTree(const string &outputFilename){
  ofstream outFS(outputFilename.c_str());
  if(!outFS.is_open()){
    cout << "Error" << endl;
    return;
  }
  outFS<< "Digraph G {" << endl;
  visualizeTree(outFS,root);
  outFS << "}";
  outFS.close();
  string jpgFilename = outputFilename.substr(0, outputFilename.size() - 4) + ".jpg";
  string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
  system(command.c_str());
}

void Tree::visualizeTree(ofstream& outFS, Node* n){
  if(n) {
    string parentData = "\"" + n->min;
    if(n->max != ""){
      parentData += ", " + n->max + "\"";
    }
    else {
      parentData += "\"";
    }
    outFS<<parentData << "[ label = " << parentData << "];" << endl;
      if(n->l){
        string childData = "\"" + n->l->min;
        if(n->l->max!=""){
          childData += ", " + n->l->max + "\"";
        }
        else {
          childData += "\"";
        }
        visualizeTree(outFS,n->l);
        outFS << parentData << " ->  " << childData << ";" << endl;
      }
      else if(n->m){
        string childData =  "\""+n->m->min;
        if(n->m->max!=""){
          childData += ", " + n->m->max + "\"";
        }
        else {
          childData += "\"";
        }
        visualizeTree(outFS,n->m);
        outFS<<parentData<<" ->  "<<childData<<";"<<endl;
      }
      else {
        string childData =  "\"" + n->r->min;
        if(n->r->max != ""){
          childData += ", " + n->r->max + "\"";
        }
        else {
          childData += "\"";
        }
        visualizeTree(outFS,n->r);
        outFS<<parentData<<" ->  "<<childData<<";"<<endl;
      }
  }
}
*/