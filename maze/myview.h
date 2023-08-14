#pragma once
#include <string>
#include "Cli.h"
#include "file.h"
#include "d2Maze.h"
#include "view.h"
#include "observer.h"
#include <stdexcept>
#include "exceptions.h"

using namespace std;


class myview : public view<string>
{
public:
	myview(istream & input = std::cin, ostream & output = std::cout): state(){ cli = new Cli(this ,input,output);};
	~myview(){delete cli;};

    void display_solution(Solution<string>* solush) {cli->display_solution(solush);};
	void display(d2Maze maze){cli->display(maze);};
	void notify();
	void size(string name, int size){cli->size(name, size);};
	void attach(observer* ob) override {observers.push_back(ob);};
    void detach(observer* ob) override;
    void initcli(map<string,command*>com){cli->addCommands(com);};
    void set_state(string aCommand);
    string get_state(){return state;};
    string get_input() override {return cli->get_input();};
    void printToOut(string print){cli->printToOut(print);};

private:
    Cli<string>* cli;
    string state;
};

