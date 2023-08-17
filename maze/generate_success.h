//
// Created by Rony Zrihen on 10/08/2023.
//
#pragma once
#include "command.h"
#include "controller.h"
#include <string>
#include <iostream>

using namespace std;

class generate_maze : public command {
public:
    generate_maze(controller* con) : control(con) {};
    ~generate_maze() {};
    void doCommand() { control->con_generate_maze(); };
private:
    controller* control;
};