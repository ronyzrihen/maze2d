#pragma once
#include <string>
using namespace std;
class file
{
public:
	file(){};
	~file(){};
	bool save(){};
	bool load(){};
	string dir(){};
	int size(string name){};

	

private:
	int f_size;
	string f_dir;
	string f_name;
};

