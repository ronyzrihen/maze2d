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
using namespace std;

class model: public subject
{
public:
	model(){};
	~model() {};
	virtual int get_size(string name) = 0;
	virtual d2Maze& get_maze(string name) =0;
    virtual d2Maze generate_maze(string algoname, int dim, string mazename) = 0;

};
