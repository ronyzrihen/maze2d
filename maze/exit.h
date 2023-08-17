#pragma once
#include "command.h"
#include "controller.h"

class exitt : public command {
public:
    exitt(controller*con):control(con) {};
    ~exitt() {};
    void doCommand() override { control->con_exit(); }
private:
    controller* control;

};