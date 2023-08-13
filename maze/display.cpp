//
// Created by Rony Zrihen on 12/08/2023.
//
#include "display.h"

void display::doCommand(){
    d_view->printToOut("Enter Maze Name: ");
    string name = d_view->get_input();

    d_view->display( d_model->get_maze(name));
   ;
}



