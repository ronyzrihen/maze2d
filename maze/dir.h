#pragma once
#include <iostream>
#include <string>
#include "command.h"
#include "controller.h"

using namespace std;



class dir : public command
{
public:
	dir(controller* con) :control(con) {};
	~dir() {};
	void doCommand() { control->con_dir(); };

private:
	controller* control;

};