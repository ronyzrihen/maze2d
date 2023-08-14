#include "command.h"
#include "view.h"
#include "model.h"
using namespace std;
template<class T>
class file_size : public command{

public:
    file_size( model<T>* mod ,view<T>* vi): c_view(vi), c_model(mod){};
    ~file_size(){};
    void doCommand()
    {
        c_view->printToOut("Enter Maze Name: ");
        string name = c_view->get_input();
        c_view->size(name, c_model->get_file_size(name));
    };

private:
    view<T>* c_view;
    model<T>* c_model;


};