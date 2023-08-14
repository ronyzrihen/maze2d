//
// Created by Rony Zrihen on 13/08/2023.
//
#include "save_maze.h"

void save_maze::doCommand(){

    string mazeName, fileName ,answer;
    while (!c_model->is_maze_exist(mazeName)) {

        c_view->printToOut("Enter Maze Name: ");
        mazeName = c_view->get_input();
        if (mazeName == "") {
            mazeName = c_view->get_input();

        }
        if(!c_model->is_maze_exist(mazeName)){
            c_view->printToOut("Maze Dosen't Exist!\n");
        }


    }

     d2Maze maze = c_model->get_maze(mazeName);
    c_view->printToOut("Enter File Name :");
    fileName = c_view->get_input();
    if(fileName == ""){
        fileName = c_view->get_input();
    }
    while (c_model->is_file_exist(fileName)){

            c_view->printToOut("File already exist,\n Do you wish to override it? (y/n) ");
            answer = c_view->get_input();
            if(answer == ""){
                answer = c_view->get_input();
            }
            if(answer == "y" || answer == "yes" || answer == "Yes"){
                break;
        }
        c_view->printToOut("Enter File Name :");
        fileName = c_view->get_input();
        if(fileName == ""){
            fileName = c_view->get_input();
        }
    }

    c_model->save(fileName , maze);

}