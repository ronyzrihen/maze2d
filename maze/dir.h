#pragma once
#include <iostream>
#include <string>
#include "command.h"
#include "view.h"
#include "model.h"
#include <filesystem>

using namespace std;


template<class T>
class dir : public command
{
public:
    dir(view<T>* vi, model<T>* mod) :c_view(vi), c_model(mod) {};
    ~dir() {};
    void doCommand();

private:
    view<T>* c_view;
    model<T>* c_model;

};

template<class T>
void dir<T>::doCommand() {

    filesystem::path p_name;
    c_view->printToOut("Enter Path: ");
    p_name = c_view->get_input();
    if (p_name.string() == "") {
        p_name = c_view->get_input();
    }
    if (!filesystem::is_regular_file(p_name)) {

        for (auto p_file : filesystem::directory_iterator(p_name)) {

            c_view->printToOut(p_file.path().filename().string() + "\n");
        }
        return;
    }
    c_view->printToOut("\n\"" + p_name.string() + "\" is not a directory.");
}
