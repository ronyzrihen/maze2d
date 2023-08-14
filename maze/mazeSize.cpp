//
// Created by Rony Zrihen on 12/08/2023.
//
#include "mazeSize.h"


void mazesize::doCommand(){
    m_view->printToOut("Enter Maze Name: ");
    string name = m_view->get_input();
    m_view->size(name, m_model->get_maze_size(name));

}