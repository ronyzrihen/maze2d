#pragma once
#include "command.h"
#include "view.h"
#include "model.h"

template <class T>
class solve:public command{
public:
    solve(view<T>* vi, model<T>* mod): c_view(vi), c_model(mod) {};
    ~solve(){};

    void doCommand()
    {

    c_view->printToOut("Enter maze name: ");
    string mazeName =  c_view->get_input();

    if(c_model->is_maze_exist(mazeName)){
        c_view->printToOut("Enter algorithm name: ");
        string algo = c_view->get_input();
        c_model->solve(algo, mazeName);

    }

    };

private:
    view<T> *c_view;
    model<T>* c_model;
};