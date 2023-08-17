#pragma once
#include "command.h"
#include "controller.h"
#include <iostream>
#include <string>

using namespace std;
class mazesize :public command
{
public:
	mazesize(controller* con) : control(con) {};
	~mazesize() {};
	void doCommand() { control->con_mazeSize(); };

private:
	controller* control;

};
