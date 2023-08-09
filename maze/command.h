#pragma once
#include <string>
using namespace std;



class command
{
public:
	command(){};
	~command(){};
	virtual void doCommand(string name) = 0;
};