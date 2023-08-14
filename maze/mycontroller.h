#pragma once
#include "model.h"
#include "view.h"
#include "command.h"
#include "controller.h"
#include <map>
#include <string>
#include "exception"
#include "exceptions.h"
using namespace std;


template<class T>
class mycontroller : public controller
{
public:
	mycontroller(view<T>* vi,model<T>* mod,map<string,command*>c_map);
	~mycontroller(){};
	void doCommand(string com);
	void update(subject* sub);

private:
	view<T>* view_layer;
	model<T>* model_layer;
	map <string, command*>commands;
};



template<class T>
mycontroller<T>::mycontroller(view<T>* vi,model<T>* mod,map<string,command*>c_map):view_layer(vi),model_layer(mod),commands(c_map){
    view_layer->attach(this);
    model_layer->attach(this);
    view_layer->initcli(c_map);
}
template<class T>
void mycontroller<T>::doCommand(string com) {

    std::map<string, command*>::iterator it;
    it = commands.find(com);
    if (it != commands.end()) {
        commands[com]->doCommand();
    }
    else {
        throw string("shit");
    }


}
template<class T>
void mycontroller<T>::update(subject* sub) {
    try {

        doCommand(sub->get_state());
    }catch(string error){
        view_layer->printToOut(sub->get_state());
    }

}




