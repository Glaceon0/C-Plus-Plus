#ifndef __MENU_CLASS__
#define __MENU_CLASS__

#include <iostream>
#include "command.h"
#include <vector>
using namespace std;

class Menu {
private:
	int history_index;
	vector<Command*> history;
public:
	Menu() {
		history_index = -1;
	};
	void execute() {
		cout << history[history_index]->execute() << endl;
	};
	bool initialized() {
		//Return true if the history has been primed with a single op instruciton
		//This is necessary because that is the base of a calculation
		if (history_index != -1)
		{
			return true;
		}
		return false;
	};
	void add_command(Command* cmd) {
		//Adds a command to history in the appropriate posiiton (based on history_index)
		if (cmd)
		{
			if (history_index == -1 || history_index == static_cast<int> (history.size() - 1))
			{
				history.push_back(cmd);
			}
			else
			{
				history[history_index] = cmd;
			}
			history_index += 1;
		}
	};
	Command* get_command() {
		//Returns the command in history we are currently referring to (based on history_index)
		if (history_index != -1)
		{
			return history[history_index];
		}
		else return 0;
	};
	void undo() {
		//Moves to the last command in history (if possible)
		if (history_index > 0)
		{
			history_index--;
		}
		else
		{
			cout << "Error: Cannot get to previous command" << endl;
		}
	};
	void redo() {
		//Moves to the next command in history (if possible)
		unsigned i = history_index;
		if (i < history.size() - 1)
		{
			history_index++;
		}
		else
		{
			cout << "Error: Cannot get to redo command" << endl;
		}
	};
};
#endif //__MENU_CLASS__