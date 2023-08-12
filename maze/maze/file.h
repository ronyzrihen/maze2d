#pragma once
#include <string>
using namespace std;
class file
{
public:
	file(){};
	~file(){};
	//bool save(){};
	//bool load(){};
	//string dir(){};
	int size() { return f_size; };

	

private:
	int f_size;
	string f_dir;
	string f_name;
};

