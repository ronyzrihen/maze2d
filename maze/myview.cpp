#include "myview.h"



void myview::display(d2Maze maze) {
    int playerX = maze.getPlayerPsition().get_row();
    int playerY = maze.getPlayerPsition().get_col();
    int startX = maze.getPlayerPsition().get_row();
    int startY = maze.getPlayerPsition().get_col();
    int endX = maze.getGoalPsition().get_row();
    int endY = maze.getGoalPsition().get_col();
    for (int i = 0; i < maze.get_dim(); ++i) {
        for (int j = 0; j < maze.get_dim(); ++j) {
            cout << (maze.get_maze()[i][j].topWall ? "===" : "| |");
        }
        cout << "|" << endl;

        for (int j = 0; j < maze.get_dim(); ++j) {
            cout << (maze.get_maze()[i][j].leftWall ? "|" : " ");
            cout << (i == playerX && j == playerY ? "@" : i == startX && j == startY ? "s" : (i == endX - 1 && j == endY - 1 ? "e" :  " "));
            cout << (j == maze.get_dim() - 1 ? "|" : " ");
        }
        cout << endl;

        for (int j = 0; j < maze.get_dim(); ++j) {
            cout << (maze.get_maze()[i][j].leftWall ? "|" : " ");
            cout << " ";
            cout << (maze.get_maze()[i][j].rightWall ? "|" : " ");
        }
        cout << (maze.get_maze()[i][maze.get_dim() - 1].rightWall ? "|" : " ") << endl;
    }

    for (int j = 0; j < maze.get_dim(); ++j) {
        cout << "===";
    }
    cout << "|" << endl;
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