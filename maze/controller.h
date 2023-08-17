#pragma once
#include "model.h"
#include "myview.h"
#include "command.h"
#include <map>
#include <string>
using namespace std;


class controller :public observer
{

public:
    controller(){};
    virtual ~controller(){};
    virtual void con_generate_maze() = 0;
    virtual void con_dir() = 0;
    virtual void con_display() = 0;
    virtual void con_display_solution() = 0;
    virtual void con_file_size() = 0;
    virtual void con_load_maze() = 0;
    virtual void con_mazeSize() = 0;
    virtual void con_save_maze() = 0;
    virtual void con_solve() = 0;
    virtual void initview()=0;
    virtual void addCommand(map<string, command*>& com)=0;


private:

};

