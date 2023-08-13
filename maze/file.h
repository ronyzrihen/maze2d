#pragma once
#include <string>
#include <vector>
#include <filesystem>
#include <fstream>
using namespace std;
class file
{
public:
	file(vector<int>& maze ,string name ,filesystem::path dir = "../files/"  );

	~file(){};
	//bool save(){};
	//bool load(){};
	//string dir(){};
	int size() { return f_size; };

	

private:
	int f_size;
    filesystem::path f_dir;
	string f_name;
};

