#pragma once
#include <iostream>
#include <string>
#include "command.h"

using namespace std;



class dir : public command
{
public:
	dir(){};
	~dir(){};
	void docommand(string name){};

private:

};


