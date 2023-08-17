#pragma once
#include "command.h"
#include "controller.h"

class exitt : public command {
public:
    exitt(controller*con):control(con) {};
    ~exitt() {};
    void doCommand() override { delete control; };
private:
    controller* control;

};