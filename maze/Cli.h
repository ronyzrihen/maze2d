#pragma once
#include <iostream>
#include "command.h"
#include <string>
#include <map>
#include "myview.h"
#include <stdexcept>
#include <vector>
#include "d2Maze.h"

using namespace std;


class Cli :public myview
{
public:
    Cli( istream & input = std::cin, ostream & output = std::cout ): in(input), out(output) {};
    ~Cli() {};
    void printcommands();
    void initcli(map<string,command*>com);
    void startCli();
    void play(d2Maze* maze);
    string get_input();
    void printToOut(string print){out << print;};
    void size(string name, int size){out << name << " size is : " << size << endl;};
    void display(d2Maze& maze) const;
    void display_solution(const Solution<string>* solush) const{out << "\nSOLUTION IS BEING PRINTED TO THE SCREEN!\n";};
    void printstring(vector<string>str);
	
private:
map<string ,command*> commands;
istream& in;
ostream& out;

};



