#pragma once
#pragma once
#include "d2Maze.h"
#include "Maze2dGenerator.h"
#include <map>
#include "file.h"
#include <string>
#include <iostream>
#include <stdexcept>
#include "subject.h"
#include "Searcher.h"
#include "Solution.h"
using namespace std;

template<class T>
class model: public subject
{
public:
	model(){};
	~model() {};
    virtual void solve(string searcherName , string mazeName) = 0 ;
	virtual int get_file_size(string name) = 0;
	virtual int get_maze_size(string name) = 0;
	virtual d2Maze& get_maze(string name) =0;
    virtual Solution<T>* get_solution(string mazeName) = 0; //TODO shared ptr//
    virtual d2Maze generate_maze(string algoname, int dim, string mazename) = 0;
    virtual bool is_maze_exist(string MazeName) = 0;
    virtual bool is_file_exist(string fileName) = 0;
    virtual bool is_alg_exist(string algName)=0;
    virtual d2Maze& load(string fileName, string mazeName) = 0;
    virtual void save(string aFile, d2Maze maze) = 0;
    virtual vector<string>get_mazes()=0;
    virtual vector<string>get_gens()=0;
    virtual vector<string>get_sols()=0;

    
};

