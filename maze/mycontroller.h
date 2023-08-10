#pragma once
#include "model.h"
#include "myview.h"
#include "command.h"
#include "controller.h"
#include <map>
#include <string>
#include "exception"
using namespace std;

class not_found : public exception{
    const char * what() const noexcept override{
        return "\nCouldn't find command in map\n";
    }
};

class mycontroller : public controller , public exception
{
public:
	mycontroller(view* vi,model* mod,map<string,command*>c_map):view_layer(vi),model_layer(mod),commands(c_map) {};
	~mycontroller(){};
	void doCommand(string com,string arg );
	void update(string com, string arg){ doCommand(com,arg);};
	

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
		throw not_found();
	}


}

