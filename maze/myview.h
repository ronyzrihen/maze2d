#pragma once
#include <string>
#include "file.h"
#include "d2Maze.h"
#include "view.h"
#include "observer.h"
#include <stdexcept>
#include "exceptions.h"

using namespace std;


class myview : public view<string>
{
public:
	myview(): state(){ };
	~myview(){};

	void notify();
	void attach(observer* ob) override {observers.push_back(ob);};
    void detach(observer* ob) override;
    void set_state(string aCommand);
    string get_state(){return state;};
  
private:
    
    string state;
};

