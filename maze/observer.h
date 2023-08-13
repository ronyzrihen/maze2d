#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "command.h"
using namespace std;

class subject;
class observer
{
public:
	observer(){};
	~observer(){};
	virtual void update(subject* sub)=0;
private:

};


