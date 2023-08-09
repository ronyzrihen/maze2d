#pragma once
#include <string>
#include "CLI.h"
#include "file.h"
#include "d2Maze.h"
#include "subject.h"
using namespace std;


class view:public subject
{
public:
	view(){};
	virtual void  maze_size(string name, int size) = 0;
	virtual void  display(d2Maze maze) = 0;
	virtual ~view()=0{};

private:

};

