
#include "command.h"
#include "controller.h"

class load_maze : public command {
public:
    load_maze(controller* con) : control(con) {};
    ~load_maze() {};
    void doCommand() { control->con_load_maze(); };

private:
    controller* control;
};