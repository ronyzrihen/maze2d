#pragma once
#include "d2Maze.h"
#include "Maze2dGenerator.h"
#include <map>
#include "file.h"
#include <string>
#include <iostream>
#include <stdexcept>
#include "model.h"
#include "command.h"

using namespace std;

class mymodel : public exception , public model
{
public:
	mymodel() {};
	~mymodel(){};
	d2Maze generate_maze(string algoname, int dim, string mazename);
	d2Maze solve();
	bool save(string, d2Maze maze);
	d2Maze load(string, string);
	void notify(command* com);
	void addalgo(string name, Generator* algo);
	string what() { return "not found\n"; };
	int get_size(string name){};
	d2Maze get_maze(string name){};
	void attach(observer* ob);
	void detach(observer* ob);


private:
	 map <string,file > files;
	 map<string, d2Maze> mazes;
	 map<string, Generator* > algorithms;
	 vector<observer*>observers;


};



void mymodel:: addalgo(string name, Generator* algo) {
	if (!algorithms.count(name)) {

		algorithms[name] = algo;
	}
	else {
		cout << "erorr"<<endl;
	}
}


bool mymodel::save(string name, d2Maze maze) {
	mazes[name] = maze;
	if (mazes.count(name)) {
		return true;
	}
	return false;
}


d2Maze mymodel::load(string name, string) {

	std::map<string, d2Maze>::iterator it;
	it = mazes.find(name);
	if (it != mazes.end()) {
		return mazes[name];
	}
	cout << "maze dont exsist" << endl;
}



d2Maze mymodel:: generate_maze(string algoname, int dim,string mazename) {

	std::map<string, Generator*>::iterator it;
	it = algorithms.find(algoname);
	if (it != algorithms.end()) {
		return algorithms[algoname]->generate_maze(dim);
	}
		throw mymodel().what();

}

void mymodel::notify(command* com) {

	for (size_t i = 0; i < observers.size(); i++)
	{
		observers[i]->update(com);
	}
}



void mymodel::attach(observer* ob) {

	observers.push_back(ob);
}

void mymodel::detach(observer* ob) {

	vector<observer*>::iterator it = observers.begin();

	for(it ; it < observers.end(); it++)
	{
		if (ob == *it) {
			observers.erase(it);
			return;
		}
	}
}