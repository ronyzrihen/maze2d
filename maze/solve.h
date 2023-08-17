#pragma once

#include "command.h"
#include "controller.h"


class solve : public command {
public:
    solve(controller* con) : control(con) {};

    ~solve() {};

    void doCommand() { control->con_solve(); };

private:
    controller* control;
};