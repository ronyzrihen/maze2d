#pragma once
#include "d2Maze.h"
#include "Maze2dGenerator.h"
#include <map>
#include "file.h"
#include <string>
#include <iostream>
#include "model.h"
#include "command.h"
#include "exception"
#include "exceptions.h"
using namespace std;



class mymodel:public model
{
public:
	mymodel() {};
	~mymodel(){};
	d2Maze generate_maze(string algoname, int dim, string mazename);
	//d2Maze solve();
	bool save(string, d2Maze maze);
	d2Maze load(string, string);
	void addalgo(string name, Generator* algo);
	string what() { return "not found\n"; };
	int get_size(string name) { return files[name].size(); };
	d2Maze& get_maze(string name) { return mazes[name]; };
	void attach(observer* ob);
	void detach(observer* ob);
	void add_maze(string name, d2Maze maze);

    void notify(string com, string arg);
    void set_state(string aCommand){};
    string get_state(){return state;};

private:
	 map <string,file > files;
	 map<string, d2Maze> mazes;
	 map<string, Generator* > algorithms;
     string state;



};


