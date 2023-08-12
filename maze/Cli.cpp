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
        for (int j = 0; j < maze.get_dim(); ++j) {
            cout << (maze.get_maze()[i][j].topWall ? "---" : "- -");
        }
        cout << "|" << endl;

        for (int j = 0; j < maze.get_dim(); ++j) {
            cout << (maze.get_maze()[i][j].leftWall ? "|" : " ");
            cout << (i == playerX && j == playerY ? "@" : i == startX && j == startY ? "s" : (i == endX - 1 && j == endY - 1 ? "e" :  " "));
            cout << (j == maze.get_dim() - 1 ? "|" : " ");
        }
        cout << endl;

//        for (int j = 0; j < maze.get_dim(); ++j) {
//            cout << (maze.get_maze()[i][j].leftWall ? "|" : " ");
//            cout << " ";
//            cout << (maze.get_maze()[i][j].rightWall ? "|" : " ");
//        }
//        cout << (maze.get_maze()[i][maze.get_dim() - 1].rightWall ? "|" : " ") << endl;
    }

    for (int j = 0; j < maze.get_dim(); ++j) {
        cout << "---";
    }
    cout << "|" << endl;
}


string Cli::get_input(){
    string line;
    getline(in,line);
    aView->set_state(line);
}
void Cli::startCli(){
string aCommand;

    for(;;){
        getline(in, aCommand);
        if(aCommand == "exit" || aCommand == "Exit"){
            return;
        }
    printcommands();
    cout << ">>>> ";
    cin >> aCommand;
    aView->set_state(aCommand);
    aView->notify();
    }

}



void Cli::addCommands(map<string,command*> com){

    //map<string,command*>::iterator it = com.begin();
    int i=0;
    for( const auto& a_com : com) {
        commands[i++] = a_com.first;
    }
    startCli();
}

void Cli::printcommands(){
    cout << "--== COMMAND LIST ==--\n";
    for(const auto& aCommand : commands){
        cout << aCommand.first << ".  " << aCommand.first << endl;
    }
}
