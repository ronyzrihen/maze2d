//
// Created by Rony Zrihen on 12/08/2023.
//
#include "mycontroller.h"

mycontroller::mycontroller(view* vi,model* mod,map<string,command*>c_map):view_layer(vi),model_layer(mod),commands(c_map){
    view_layer->attach(this);
    model_layer->attach(this);
    view_layer->initcli(c_map);
}

void mycontroller::doCommand(string com) {

    std::map<string, command*>::iterator it;
    it = commands.find(com);
    if (it != commands.end()) {
        commands[com]->doCommand();
    }
    else {
      throw string("shit");
    }


}

void mycontroller::update(subject* sub) {
try {

    doCommand(sub->get_state());
}catch(string error){
    view_layer->printToOut(sub->get_state());
}

}