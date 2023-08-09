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
	virtual void update(command* com)=0;
private:

};


