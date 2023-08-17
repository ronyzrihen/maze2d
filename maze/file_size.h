#include "command.h"
#include "controller.h"
using namespace std;

class file_size : public command {

public:
    file_size(controller* con) : contorl(con) {};
    ~file_size() {};
    void doCommand() { contorl->con_file_size(); };

private:
    controller* contorl;

};