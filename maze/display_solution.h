#include <string>
#include <iostream>
#include "command.h"
#include "view.h"
#include "model.h"
#include "Solution.h"

using namespace std;

template<class T>
class display_solution : public command{

public:
    display_solution(view<T>* vi , model<T>* mod) : c_view(vi),c_model(mod){};
    ~display_solution(){};
    void doCommand(){

        c_view->printToOut("Enter Maze Name: ");
        string mazeName = c_view->get_input();

        Solution<T>* sol = c_model->get_solution(mazeName); //TODO shared ptr
        c_view->display_solution(sol);




    }
private:
    view<T>* c_view;
    model<T>* c_model;


};