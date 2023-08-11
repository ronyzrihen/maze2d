#pragma once
#include <string>
#include "Cli.h"
#include "file.h"
#include "d2Maze.h"
#include "view.h"
#include "observer.h"

using namespace std;


class myview : public view
{
public:
	myview() : cli(NULL) {};
	~myview(){};
	string dir(){};
	void display(d2Maze maze);
	void display_solution(string){};
	int file_size(file file_name){};
	void notify(string com, string arg){};
	void maze_size(string name, int size) { cout << name << "size is : " << size << endl; };
	void dir(string name,string nadir) { cout << name << "dir is : " << nadir << endl; };
	void attach(observer* ob) {observers.push_back(ob);};
	void detach(observer* ob) ;
    void initcli(map<string,command*>com){cli=new Cli(com);};
private:
    Cli* cli;
};




