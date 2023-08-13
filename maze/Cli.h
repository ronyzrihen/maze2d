#pragma once
#include <iostream>
#include "command.h"
#include <string>
#include <map>
#include "view.h"

using namespace std;


class Cli{
public:
    Cli(view *vi, istream & input = std::cin, ostream & output = std::cout ): aView(vi) , in(input), out(output){};
    ~Cli() {};
    void printcommands();
    void addCommands(map<string,command*>com);
    void startCli();
    string get_input();
    void printToOut(string print){out << print;};
    void maze_size(string name, int size){out << name << "size is : " << size << endl;};
    void display(d2Maze& maze) const;

	
private:
map<int ,string> commands;
istream& in;
ostream& out;
view* aView;
};



//void Cli::printcommands(){
//
//    map<int,string>::iterator it =commands.begin();
//    int i=0;
//    while(it != commands.end()) {
//        cout<<commands[i]<<endl;
//        i++;
//    }
//
//
//}