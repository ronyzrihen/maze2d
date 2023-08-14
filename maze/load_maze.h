//
// Created by Rony Zrihen on 13/08/2023.
//
#include "command.h"
#include "model.h"
#include "view.h"
template<class T>
class load_maze : public command{
public:
    load_maze(view<T>* vi , model<T>* mod ):c_view(vi), c_model(mod){};
    ~load_maze(){};
    void doCommand()
    {

        string fileName;
        string mazeName;
        c_view->printToOut("Enter File Name: ");
        fileName = c_view->get_input();
        if (fileName == ""){
            fileName = c_view->get_input();
        }

        c_view->printToOut("Enter New Maze Name: ");
        mazeName = c_view->get_input();
        if (mazeName == ""){
            mazeName = c_view->get_input();
        }

        c_model->load(fileName, mazeName);



    };

private:
    view<T>* c_view;
    model<T>* c_model;
};