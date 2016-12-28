#ifndef __COMMAND_CLASS__
#define __COMMAND_CLASS__

#include "composite.h"

class Command {
protected:
	Base* root;
public:
	Command() { };
	double execute() { return root->evaluate(); }
	Base* get_root() { return root; };
};

class OpCommand : public Command
{
public:
	OpCommand() { root = 0; };
	~OpCommand() {};
	OpCommand(double val1) { root = new Op(val1); }
};

class AddCommand : public Command
{
public:
	AddCommand() { root = 0; };
	~AddCommand() {};
	AddCommand(Command* val1, int val2){
		Base* newCmd = new Add(val1->get_root(), new Op(val2));
		this->root = newCmd;
	}
};

class SubCommand : public Command 
{
public:
	SubCommand() { root = 0; };
	~SubCommand() {};
	SubCommand(Command* val1, int val2)
	{
		Base* newCmd = new Sub(val1->get_root(), new Op(val2));
		this->root = newCmd;
	}
};

class MultCommand : public Command {
public:
	MultCommand() { root = 0; };
	~MultCommand() {};
	MultCommand(Command* val1, int val2)
	{
		Base* newCmd = new Mult(val1->get_root(), new Op(val2));
		root = newCmd;
	}
};

class SqrCommand : public Command 
{
	public:
		SqrCommand() { root = 0; };
	~SqrCommand() {};
	SqrCommand(Command* val1)
	{
		Base* newCmd = new Sqr(val1->get_root());
		this->root = newCmd;
	}
};
#endif //__COMMAND_CLASS__