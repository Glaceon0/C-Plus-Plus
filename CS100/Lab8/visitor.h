#ifndef VISITOR
#define VISITOR
#include "composite.h"
#include <string>

class Op;

class Visitor
{
    public:
        Visitor() {};
        virtual void rootNode() = 0; 
        virtual void sqrNode() = 0; 
        virtual void multNode() = 0;
        virtual void subNode() = 0;
        virtual void addNode() = 0;
        virtual void opNode(Op* op) = 0;
        virtual void execute() = 0;
};


class PrintVisitor : public Visitor {
    private:
        std::string output;
    public:
        PrintVisitor();         //default Constructor
        void rootNode();                    //For visiting a root node (do nothing)
        void sqrNode();         //For visiting a square node
        void multNode();       //For visiting a multiple node
        void subNode();        //For visiting a subtraction node
        void addNode();        //For visiting an add node
        void opNode(Op * op );//For visiting a leaf node
        void execute();        //Prints all visited nodes
};

#endif