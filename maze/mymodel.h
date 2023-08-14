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
	bool save(string aFile, d2Maze maze);
	d2Maze& load(string fileName, string mazeName);


	int get_file_size(string name) { return files[name]->size(); };
	int get_maze_size(string name) { return mazes[name]->get_size(); };
	d2Maze& get_maze(string name) { return *mazes[name]; };
    bool is_maze_exist(string MazeName);
    bool is_file_exist(string fileName) ;


	void addalgo(string name, Generator* algo);
	void addFile(string name, file newFile);
    void add_maze(string name, d2Maze maze);

    //observer methods
	void attach(observer* ob);
	void detach(observer* ob);
    void notify();
    void set_state(string aCommand){state = aCommand;};
    string get_state(){return state;};

private:
	 map <string,file* > files;
	 map<string, d2Maze*> mazes;
	 map<string, Generator* > generators;
	 map<string, Generator* > solvers;
     string state;



};


