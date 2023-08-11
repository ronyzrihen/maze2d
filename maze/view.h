#pragma once
#include <string>
#include "d2Maze.h"
#include "subject.h"
#include <map>
#include "Cli.h"
using namespace std;


class view:public subject
{
public:
	view(){};
	virtual void  maze_size(string name, int size) = 0;
	virtual void  display(d2Maze maze) = 0;
  virtual  void initcli(map<string,command*>com)=0;
	 ~view(){};


};

