#pragma once
#include <string>
#include "d2Maze.h"
#include "iostream"
#include "string"
using namespace std;


class Generator
{
public:
	Generator() {};
	~Generator(){};
	virtual d2Maze generate_maze(int maze_size)=0;
	void measureAlgorithmTime();
private:

};

