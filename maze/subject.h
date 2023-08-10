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
	virtual void notify(string com, string arg) = 0;

protected:
    vector<observer*>observers;

};

