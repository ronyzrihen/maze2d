#include <string>
#include <iostream>
#include "command.h"
#include "controller.h"
#include "Solution.h"

using namespace std;

class display_solution : public command {

public:
    display_solution(controller* con) : control(con) {};
    ~display_solution() {};
    void doCommand() { control->con_display_solution(); };
private:
    controller* control;

};