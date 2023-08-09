#pragma once
#include <ostream>
#include <istream>
#include "command.h"
#include "controller.h"
#include <string>
using namespace std;


class CLI
{
public:
	CLI(){};
	~CLI(){};
	void doCommand(string, controller){};

	
private:
	/*ostream out;
	istream in;
	*/

};

