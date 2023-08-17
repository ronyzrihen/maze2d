#pragma once
#include <iostream>
#include <string>
#include "command.h"
#include "controller.h"

using namespace std;
class display :public command
{
public:
	display(controller* con) :control(con) {};
	void doCommand() { control->con_display(); };

	~display() {};

private:
	controller* control;

};