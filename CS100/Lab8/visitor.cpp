#include "visitor.h"
#include "composite.h"

using namespace std;

PrintVisitor::PrintVisitor()
{
        output = "";
}

void PrintVisitor::rootNode() 
{
    return;
}                  //For visiting a root node (do nothing)
void PrintVisitor::sqrNode() //For visiting a square node
{
        output += "^2\n";
}
void PrintVisitor::multNode() //For visiting a multiple node
{
    output += "*\n";
    
}       
void PrintVisitor::subNode()  //For visiting a subtraction node
{
    output += "-\n";
}       
void PrintVisitor::addNode() //For visiting an add node
{
    output += "+\n";
}        
void PrintVisitor::opNode( Op * op ) //For visiting a leaf node
{
    output = output + to_string(op->evaluate()) + "\n";
}
void PrintVisitor::execute() 
{
    cout << output << endl; 
}