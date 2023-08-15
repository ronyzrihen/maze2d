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
#include "d2MazeSearchable.h"
#include "MazeCompression.h"
using namespace std;



class mymodel:public model<string>
{
public:
	mymodel() {};
	~mymodel(){};

    Solution<string>* get_solution(string mazeName);
	d2Maze generate_maze(string algoname, int dim, string mazename);
	void save(string aFile, d2Maze maze);
	d2Maze& load(string fileName, string mazeName);
    void solve(string searcherName , string mazeName);
	int get_file_size(string name) { return files[name]->size(); };
	int get_maze_size(string name) { return mazes[name]->get_size(); };
	d2Maze& get_maze(string name) { return *mazes[name]; };
    bool is_maze_exist(string MazeName);
    bool is_file_exist(string fileName) ;
    bool is_algo_exist(string algoName);


	void addGen(string name, Generator* algo);
	void addSearcher(string name, Searcher<string>* algo);
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
	 map<string, Searcher<string>*> solvers;
	 map<string, Solution<string>*> solution_cache;
    MazeCompression compressor;

     string state;

};


