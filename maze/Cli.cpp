//
// Created by Rony Zrihen on 11/08/2023.
//
#include "Cli.h"
#include <stdexcept>

void Cli::display(d2Maze& maze) const {

    int playerX = maze.getPlayerPsition().get_row();
    int playerY = maze.getPlayerPsition().get_col();
    int startX = maze.getPlayerPsition().get_row();
    int startY = maze.getPlayerPsition().get_col();
    int endX = maze.getGoalPsition().get_row();
    int endY = maze.getGoalPsition().get_col();
    for (int i = 0; i < maze.get_dim(); ++i) {
            out << "|";
        for (int j = 0; j < maze.get_dim(); ++j) {
            out << (maze.get_maze()[i][j].topWall? "=====" : "=| |=");
        }
        out << "|" << endl;
        out << "|";
        for (int j = 0; j < maze.get_dim(); ++j) {
            out << ( maze.get_maze()[i][j].leftWall ? "| " : "  ");
            out << (i == playerX && j == playerY ? "@" : (i == startX && j == startY) ? "s" : (i == endX - 1 && j == endY - 1 ? "e" :  " "));
            out << (j == maze.get_dim() - 1 ? "  |" : "  ");
        }
        out << endl;

//        for (int j = 0; j < maze.get_dim(); ++j) {
//            cout << (maze.get_maze()[i][j].leftWall ? "|" : " ");
//            cout << " ";
//            cout << (maze.get_maze()[i][j].rightWall ? "|" : " ");
//        }
//        cout << (maze.get_maze()[i][maze.get_dim() - 1].rightWall ? "|" : " ") << endl;
    }
        out << "|";
    for (int j = 0; j < maze.get_dim(); ++j) {
        out <<  "=====";
    }
    out << "|" << endl;
}


string Cli::get_input(){
    string line;
    getline(in,line);
    if (line == ""){
        getline(in,line);
    }
    return line;

}
void Cli::startCli(){
string aCommand;
    out << "-- Enter \"exit\" to exit --\n";
    out << "-- Enter \"list\" to see command list --\n";
    printcommands();
    for(;;){
        bool flag = false;
        out << ">>>> ";
        getline(in, aCommand);
        if(aCommand == ""){
            getline(in, aCommand);
        }
        if(aCommand == "exit" || aCommand == "Exit"){
            return;
        }
        if(aCommand == "list"){
            printcommands();
        }
    //in >> aCommand;
    for(auto com : commands){
        if(com.second == aCommand){
            try{
            aView->set_state(aCommand);
            aView->notify();
            }catch(exception* e){
                e->what();
            }
            flag = true;
            break;
        }

    }
    if(!flag){
        out << "Command Was Not Found!";
    }
    }

}



void Cli::addCommands(map<string,command*> com){


    int i=0;
    for( const auto& a_com : com) {
        commands[i++] = a_com.first;
    }
    startCli();
}

void Cli::printcommands(){
    cout << "--== COMMAND LIST ==--\n";
    for(const auto& aCommand : commands){
        cout << aCommand.first << ".  " << aCommand.second << endl;
    }
}
