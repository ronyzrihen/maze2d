#pragma once
#include <string>
using namespace std;



class command
{
public:
	command(){};
	virtual ~command(){};
	virtual void doCommand() = 0;
};