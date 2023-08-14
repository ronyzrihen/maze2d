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
using namespace std;

//template<class T>
class model: public subject
{
public:
	model(){};
	~model() {};
//    virtual Searcher<T>* get_searcher() = 0 ;
	virtual int get_file_size(string name) = 0;
	virtual int get_maze_size(string name) = 0;
	virtual d2Maze& get_maze(string name) =0;
    virtual d2Maze generate_maze(string algoname, int dim, string mazename) = 0;
    virtual bool is_maze_exist(string MazeName) = 0;
    virtual bool is_file_exist(string fileName) = 0;
    virtual d2Maze& load(string fileName, string mazeName) = 0;
    virtual bool save(string aFile, d2Maze maze) = 0;
};

