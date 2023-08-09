#pragma once
#include <string>
#include "d2Maze.h"
#include "subject.h"
using namespace std;


class view:public subject
{
public:
	view(){};
	virtual void  maze_size(string name, int size) = 0;
	virtual void  display(d2Maze maze) = 0;
	 ~view(){};

private:

};

