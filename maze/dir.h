#pragma once
#include <iostream>
#include <string>
#include "command.h"
#include "view.h"
#include "model.h"
#include <filesystem>

using namespace std;



class dir : public command
{
public:
	dir(view* vi, model* mod):c_view(vi), c_model(mod){};
	~dir(){};
	void doCommand();

private:
    view* c_view;
    model* c_model;

};


