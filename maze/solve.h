#pragma once

#include "command.h"
#include "view.h"
#include "model.h"

template<class T>
class solve : public command {
public:
    solve(view<T> *vi, model<T> *mod) : c_view(vi), c_model(mod) {};

    ~solve() {};

    void doCommand() {

        c_view->printToOut("Enter maze name: ");
        string mazeName = c_view->get_input();
        if (c_model->is_maze_exist(mazeName)) {

            c_view->printToOut("Do You Wish To Solve Manually? (Y/N)");

            string answer = c_view->get_input();
            if (answer == "Y" || answer == "y" || answer == "yes" || answer == "Yes") {
                c_view->play(new d2Maze(c_model->get_maze(mazeName)));
                return;
            } else if (answer == "N" || answer == "n" || answer == "no" || answer == "No") {

                c_view->printToOut("Enter algorithm name: ");
                string algo = c_view->get_input();
                c_model->solve(algo, mazeName);
                return;


            }
            c_view->printToOut(answer + " is not a valid answer.");
            return;
        }


    };

private:
    view<T> *c_view;
    model<T> *c_model;
};