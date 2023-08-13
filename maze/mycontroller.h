#pragma once
#include "model.h"
#include "view.h"
#include "command.h"
#include "controller.h"
#include <map>
#include <string>
#include "exception"
#include "exceptions.h"
using namespace std;



class mycontroller : public controller
{
public:
	mycontroller(view* vi,model* mod,map<string,command*>c_map);
	~mycontroller(){};
	void doCommand(string com);
	void update(subject* sub);

private:
	view* view_layer;
	model* model_layer;
	map <string, command*>commands;
};





