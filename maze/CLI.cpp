#include "CLI.h"


void Cli::display(d2Maze& maze) const {

    int playerX = maze.getPlayerPsition().get_row();
    int playerY = maze.getPlayerPsition().get_col();
    int startX = maze.getStartPosition().get_row();
    int startY = maze.getStartPosition().get_col();
    int endX = maze.getGoalPsition().get_row();
    int endY = maze.getGoalPsition().get_col();
    for (int i = 0; i < maze.get_dim(); ++i) {
        out << "|";
        for (int j = 0; j < maze.get_dim(); ++j) {
            out << (maze.get_maze()[i][j].topWall ? "=====" : "=| |=");
        }
        out << "|" << endl;
        out << "|";
        for (int j = 0; j < maze.get_dim(); ++j) {
            out << (j == 0 && maze.get_maze()[i][j].leftWall ? "  " : maze.get_maze()[i][j].leftWall ? "| " : "  ");
            if (i == playerX && j == playerY || i == playerX && j == playerY && playerX == startX && playerY == startY) {
                out << "@";
            }
            else if (i == playerX && j == playerY || i == playerX && j == playerY && playerX == endX && playerY == endY) {
                out << "@";
            }
            else if (i == startX && j == startY) {
                out << "S";
            }
            else if (i == endX && j == endY) {
                out << "E";
            }
            else {
                out << " ";
            }
            out << (j == maze.get_dim() - 1 ? "  |" : "  ");
        }
        out << endl;
    }
    out << "|";
    for (int j = 0; j < maze.get_dim(); ++j) {
        out << "=====";
    }
    out << "|" << endl;
}


string Cli::get_input() {
    string line;
    getline(in, line, '\n');
    if (line == "") {
        getline(in, line, '\n');
    }
    return line;

}


void Cli::startCli() {
    string aCommand;
    out << "-- Enter \"exit\" to exit --\n";
    out << "-- Enter \"list\" to see command list --\n";
    printcommands();
    for (;;) {
        bool flag = false;
        out << "\n>>>> ";
        getline(in, aCommand, '\n');
        if (aCommand == "") {
            getline(in, aCommand, '\n');
        }
        if (aCommand == "exit" || aCommand == "Exit") {
            return;
        }
        if (aCommand == "list") {
            printcommands();
            continue;
        }
        //in >> aCommand;
        for (auto com : commands) {
            if (com.first == aCommand) {
                try {
                    set_state(aCommand);
                    notify();
                }
                catch (exception* e) {
                    e->what();
                }
                flag = true;
                break;
            }

        }
        if (!flag) {
            out << "Command Was Not Found!";
        }
    }

}



void Cli::initcli(map<string, command*> com) {

    int i = 1;
    for (const auto& a_com : com) {
        commands[a_com.first] = a_com.second;
    }
    startCli();
}



void Cli::printcommands() {
    cout << "--== COMMAND LIST ==--\n";
    int i = 1;
    for (const auto& aCommand : commands) {
        cout << i << ".  " << aCommand.first << endl;
        i++;
    }
}




void Cli::play(d2Maze* maze) {
    display(*maze);
    out << "\nMake a move\n";
    out << "up / down / left / right\n";

    for (;;) {

        if (maze->getPlayerPsition().get_row() == maze->getGoalPsition().get_row() && maze->getPlayerPsition().get_col() == maze->getGoalPsition().get_col()) {

            out << "\nYAYY YOU DID IT!!!!\n";
            delete(maze);
            return;
        }
        out << maze->getPlayerPsition().get_row() << " " << maze->getPlayerPsition().get_col()
            << " , " << maze->getStartPosition().get_row() << " " << maze->getStartPosition().get_col() << endl;



        string move;
        out << ">>>> ";
        getline(in, move);
        if (move == "") {
            getline(in, move);
        }

        if (move == "up" || move == "Up") {
            maze->move_up();
            display(*maze);
            continue;
        }
        if (move == "down" || move == "Down") {
            maze->move_down();
            display(*maze);
            continue;
        }
        if (move == "left" || move == "Left") {
            maze->move_left();
            display(*maze);
            continue;
        }
        if (move == "right" || move == "Right") {
            maze->move_right();
            display(*maze);
            continue;
        }


    }
}




void Cli::printstring(vector<string>str) {

    vector<string>::iterator it = str.begin();

    for (it; it != str.end(); it++) {
        out << " - " + *it + "\n";
    }

}
