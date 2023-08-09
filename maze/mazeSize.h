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
	mazesize(model* mod,view* vi):command(),m_model(mod),m_view(vi) {};
	~mazesize(){};
	void doCommand(string name)  { m_view->maze_size(name, m_model->get_size(name)); };

private:
	model* m_model;
	view* m_view;

};

