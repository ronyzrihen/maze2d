#pragma once
#include "model.h"
#include "myview.h"
#include "command.h"
#include "controller.h"
#include <map>
#include <string>
using namespace std;


class mycontroller : public controller
{
public:
	mycontroller(view* vi,model* mod,map<string,command*>c_map):view_layer(vi),model_layer(mod),commands(c_map) {};
	~mycontroller(){};
	void doCommand(string com,string arg );
	void update(command* action,  string detail);
	

private:
	view* view_layer;
	model* model_layer;
	map <string, command*>commands;
};




void mycontroller::doCommand(string com,string arg) {
	
	std::map<string, command*>::iterator it;
	it = commands.find(com);
	if (it != commands.end()) {
	 commands[com]->doCommand(arg);
	}
	else {
		cout << "erorr\n";
	}


}



void mycontroller::update(command* action ,string detail) {

	action->doCommand(detail);
}
