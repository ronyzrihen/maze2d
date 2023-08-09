#pragma once
#include <iostream>
#include <string>
#include "command.h"
#include "model.h"
#include "view.h"

using namespace std;

class display :public command
{
public:
	display(model* mod, view* vi) :d_model(mod), d_view(vi) {};
	void doCommand(string name) { d_view->display(d_model->get_maze(name)); };
	~display(){};

private:
	model* d_model;
	view* d_view;

};


//void display::doCommand(string name) {
//	d_view->display(d_model->get_maze(name));
//}