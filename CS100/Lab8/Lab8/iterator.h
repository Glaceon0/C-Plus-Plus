
#include "composite.h"
#ifndef ITERATOR_H
#define ITERATOR_H

#include <stack>
using namespace std;
class Base;
class Iterator
{
    protected:
        Base* self_ptr;
        Base* current_ptr;
    public:
        Iterator (Base* ptr) { this->self_ptr = ptr; current_ptr = 0;}
        virtual void first() = 0;
        virtual void next() = 0;
        virtual bool is_done() = 0;
        virtual Base* current() = 0;
};

class OperatorIterator : public Iterator
{
    public:
        OperatorIterator(Base* ptr): Iterator(ptr){};
        void first();
        void next();
        bool is_done();
        Base* current();
};

class NullIterator : public Iterator
{
    public:
        NullIterator(Base* ptr): Iterator(ptr){};
        void first();
        void next();

        bool is_done();
        Base* current();
};

class PreOrderIterator : public Iterator
{
    protected:
        stack<Iterator*> iterators;
    public:
        PreOrderIterator(Base* ptr): Iterator(ptr){};
        void first();
        void next();
        bool is_done();
        Base* current();
};

class UnaryIterator : public Iterator {
    public:
        UnaryIterator (Base* ptr) : Iterator(ptr) {};
        void first();
        void next();
        bool is_done();
        Base* current();
};

#endif