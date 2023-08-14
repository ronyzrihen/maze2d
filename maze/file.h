#pragma once
#include <string>
#include <vector>
#include <filesystem>
#include <fstream>
#include "exceptions.h"
using namespace std;
class file
{
public:
	file(vector<int>& maze ,string name ,string = "../files/"  );
	~file(){};

	void save(vector<int> maze);
    vector<int> load();
	//string dir(){};
	int size() { return f_size; };

private:
	int f_size;
    string f_dir;
	string f_name;
};

