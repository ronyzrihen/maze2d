#pragma once
#include "command.h"
#include "model.h"
#include "view.h"
#include <iostream>
#include <string>

using namespace std;

class mazesize :public command
{
public:
	mazesize(model* mod,view* vi):m_model(mod),m_view(vi) {};
	~mazesize(){};
	void doCommand();

private:
	model* m_model;
	view* m_view;

};

