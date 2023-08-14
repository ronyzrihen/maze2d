#include "dir.h"


void dir::doCommand() {

    filesystem::path p_name;
    c_view->printToOut("Enter Path: ");
    p_name = c_view->get_input();
    if (p_name.string() == "") {
        p_name = c_view->get_input();
    }
    if(!filesystem::is_regular_file(p_name)){

    for(auto p_file: filesystem::directory_iterator(p_name)){

        c_view->printToOut(p_file.path().filename().string() + "\n");
    }
    return;
    }
    c_view->printToOut("\n\"" + p_name.string() + "\" is not a directory.");
}