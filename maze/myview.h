#pragma once
#include <string>
#include "CLI.h"
#include "file.h"
#include "d2Maze.h"
#include "view.h"

using namespace std;


class myview:public view
{
public:
	myview() {};
	~myview(){};
	string dir(){};
	void display(d2Maze maze);
	void display_solution(string){};
	int file_size(file file_name){};
	void notify(command* com){};
	void maze_size(string name, int size) { cout << name << "size is : " << size << endl; };
	void dir(string name,string nadir) { cout << name << "dir is : " << nadir << endl; };
	void attach(observer* ob) {};
	void detach(observer* ob) {};

private:
	//CLI ui;

};


