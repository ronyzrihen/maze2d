#include "myview.h"


void myview::notify(){

    for(auto elem : observers){
        try {
            elem->update(this);
        }catch(exception* e){
            throw update_failed();
        }
    }
}


void myview::set_state(string aCommand){
    state = aCommand;
}


void myview::detach(observer* ob) {

    vector<observer*>::iterator it = observers.begin();

    for(it ; it < observers.end(); it++)
    {
        if (ob == *it) {
            observers.erase(it);
            return;
        }
    }
}


//void myview::printstring(vector<string>str) {
//
//    vector<string>::iterator it = str.begin();
//
//    for (it; it != str.end(); it++) {
//        printToOut(" - " + *it + "\n");
//    }
//
//}