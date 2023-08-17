//
// Created by Rony Zrihen on 13/08/2023.
//
#include "controller.h"
#include "command.h"
#include "file.h"

class save_maze :public command {

public:
    save_maze(controller* con) : control(con) {};
    ~save_maze() {};

    void doCommand() { control->con_save_maze(); };

private:
    controller* control;

};