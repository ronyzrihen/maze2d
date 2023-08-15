#pragma once
#include <iostream>
#include <string>
#include "command.h"
#include "model.h"
#include "view.h"

using namespace std;
template<class T>
class display :public command
{
public:
	display(model<T>* mod, view<T>* vi) :d_model(mod), d_view(vi) {};
	void doCommand();

	~display(){};

private:
	model<T>* d_model;
	view<T>* d_view;

};

template<class T>
void display<T>::doCommand(){
	d_view->printToOut("---Maze list---\n");
	d_view->printstring(d_model->get_mazes());
    d_view->printToOut("Enter Maze Name: ");
	string name = d_view->get_input();
	if (d_model->is_maze_exist(name)) {
		d_view->display( d_model->get_maze(name));
	}
	else {
		d_view->printToOut("maze not exist");
	}
    
}
