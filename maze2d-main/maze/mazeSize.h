#pragma once
#include "command.h"
#include "model.h"
#include "view.h"
#include <iostream>
#include <string>

using namespace std;
template<class T>
class mazesize :public command
{
public:
	mazesize(model<T>* mod,view<T>* vi):m_model(mod),m_view(vi) {};
	~mazesize(){};
	void doCommand();

private:
	model<T>* m_model;
	view<T>* m_view;

};

template<class T>
void mazesize<T>::doCommand(){
    m_view->printToOut("Enter Maze Name: ");
    string name = m_view->get_input();
    m_view->size(name, m_model->get_maze_size(name));

}