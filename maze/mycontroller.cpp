//
// Created by Rony Zrihen on 12/08/2023.
//
#include "mycontroller.h"



void mycontroller::doCommand(string com) {

    std::map<string, command*>::iterator it;
    it = commands.find(com);
    if (it != commands.end()) {
        commands[com]->doCommand();
    }
    else {
        throw not_found();
    }


}

void mycontroller::update(subject* sub){
try{
    doCommand(sub->get_state());
}catch(exception e){
    throw not_found();
}
}