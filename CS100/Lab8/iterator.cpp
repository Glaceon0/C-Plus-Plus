#include "iterator.h"

//--------------------------------------------------------------------------
// PreOrderIterator
//--------------------------------------------------------------------------
void PreOrderIterator::first()
{
    //clear iterators if it had data
    while(iterators.size() != 0)
    {
        iterators.pop();
    }
    //push the first elemnt onto the stack.
    Iterator * base = self_ptr->create_iterator();
    if(base)
    {
        base->first();
        iterators.push(base);
    }
}

void PreOrderIterator::next()
{
    Iterator * temp = iterators.top()->current()->create_iterator();
    temp->first();
    iterators.push(temp);
    
    if(!iterators.top()->is_done())
    {
        return;
    }
    while(iterators.top()->is_done() && iterators.size() > 0)
    {
        iterators.pop();
        if(iterators.size() == 0)
        {
            break;
        }
        iterators.top()->next();
    }
}

bool PreOrderIterator::is_done()
{
    if(iterators.size() == 0)
        return true;
    else
        return false;
}

//Return the current for the top iterator in the stack
Base* PreOrderIterator::current() 
{
    if(iterators.size() != 0)
    {
    return iterators.top()->current();
    }
    else
    {
        return 0;
    }
}

//--------------------------------------------------------------------------
// OperatorIterator class
//--------------------------------------------------------------------------
void OperatorIterator::first()
{
    current_ptr = self_ptr->get_left();
}

void OperatorIterator::next()
{
    if(current_ptr == self_ptr->get_left())
    {
        current_ptr = self_ptr->get_right();
    }
    else if(current_ptr == self_ptr->get_right())
    {
        current_ptr = 0;
    }
}

bool OperatorIterator::is_done()
{
    if(!current_ptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

Base* OperatorIterator::current()
{
    return current_ptr;
}

//--------------------------------------------------------------------------
// UnaryIterator Class
//--------------------------------------------------------------------------
void UnaryIterator::first()
{
   current_ptr = self_ptr->get_left();
}

void UnaryIterator::next()
{
    current_ptr = 0;
}

bool UnaryIterator::is_done()
{
    if(!current_ptr)
    {
        return true;
    }
    return false;
}

Base* UnaryIterator::current() 
{
    return current_ptr;
    //Return the current for the top iterator in the stack
}

//--------------------------------------------------------------------------
// NullIterator Class
//--------------------------------------------------------------------------
void NullIterator::first()
{
    return;   
}

void NullIterator::next()
{
    return;
}

bool NullIterator::is_done()
{
    return true;
}

Base* NullIterator::current() 
{
    return NULL;
}
