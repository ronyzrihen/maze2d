#pragma once
#include <ostream>
#include <istream>
#include "command.h"
#include "controller.h"
#include <string>
#include <map>
using namespace std;


class Cli{
public:
    Cli(map<string, command *> com);
    Cli(const Cli& source){commands = source.commands;};
    ~Cli() {};
    void printcommands(){};


	
private:
map<int, string> commands;

};

Cli::Cli(map<string,command*> com){

     map<string,command*>::iterator it = com.begin();
     int i=0;
     while(it != com.end()) {
         commands[i] = it->first;
         i++;
     }
}

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