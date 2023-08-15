#pragma once
#include <string>
#include "d2Maze.h"
#include "subject.h"
#include "Solution.h"
#include <map>

using namespace std;

template<class T>
class view : public subject
{
public:
	view(){};
    virtual void display_solution(Solution<T>* solush) = 0 ;
	virtual void  size(string name, int size) = 0;
	virtual void  display(d2Maze maze) = 0;
    virtual void initcli(map<string,command*>com)=0;
    virtual string get_input() = 0;
    virtual void printToOut(string print) = 0;
    virtual void play(d2Maze* maze) = 0 ;
	 ~view(){};


};

