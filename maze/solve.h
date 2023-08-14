#pragma once
#include "command.h"
#include "view.h"
#include "model.h"

class solve:public command{
public:
    solve(view* vi, model* mod): c_view(vi), c_model(mod) {};
    ~solve(){};

    void doCommand() override
    {

    c_view->printToOut("Enter maze name: ");
    string mazeName =  c_view->get_input();

    if(c_model->is_maze_exist(mazeName)){
        c_view->printToOut("Enter algorithm name: ");
        string algo = c_view->get_input();
        c_model->get_searcher(algo);

    }

    };

private:
    view *c_view;
    model* c_model;
};