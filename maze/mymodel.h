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

class mymodel:public model,public exception
{
public:
	mymodel() {};
	~mymodel(){};
	d2Maze generate_maze(string algoname, int dim, string mazename);
	//d2Maze solve();
	bool save(string, d2Maze maze);
	d2Maze load(string, string);
	void notify(string com, string arg);
	void addalgo(string name, Generator* algo);
	string what() { return "not found\n"; };
	int get_size(string name) { return files[name].size(); };
	d2Maze get_maze(string name) { return mazes[name]; };
	void attach(observer* ob);
	void detach(observer* ob);
	void add_maze(string name, d2Maze maze);
	


private:
	 map <string,file > files;
	 map<string, d2Maze> mazes;
	 map<string, Generator* > algorithms;



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
		d2Maze newMaze = algorithms[algoname]->generate_maze(dim);
		add_maze(mazename, newMaze);
        try {
            notify("generate_success", mazename);
        }catch(exception* e){
            e->what();
        }
		return newMaze;
	}
		throw mymodel().what();

}

void mymodel::notify(string command, string arg) {

	for (size_t i = 0; i < observers.size(); i++)
	{
		observers[i]->update(command, arg);
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

void mymodel::add_maze(string name, d2Maze maze) {
	if (mazes.size() == 0) {
		mazes[name] = maze;
		return;
	}
	map<string, d2Maze> ::iterator it = mazes.find(name);
	
	if (it != mazes.end()) {
		mazes[name] = maze;
		return;
	}
	
	throw mymodel().what();

}