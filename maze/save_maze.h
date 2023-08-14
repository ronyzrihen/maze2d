//
// Created by Rony Zrihen on 13/08/2023.
//
#include "view.h"
#include "model.h"
#include "command.h"
#include "file.h"

class save_maze :public command {

public:
    save_maze(view* vi, model* mod):c_view(vi), c_model(mod){};
    ~save_maze(){};

    void doCommand();

private:
    view* c_view;
    model* c_model;

};