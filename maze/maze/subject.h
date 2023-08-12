#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "observer.h"


using namespace std;

class subject
{
public:
	subject(){};
	~subject(){};
	virtual void attach(observer* ob)=0;
	virtual void detach(observer* ob)=0;
	virtual void notify(command* com) = 0;
private:

};

