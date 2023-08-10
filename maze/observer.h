#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "command.h"
using namespace std;


class observer
{
public:
	observer(){};
	~observer(){};
	virtual void update(string com, string arg)=0;
private:

};


