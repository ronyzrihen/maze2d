#include "myview.h"



void myview::display(d2Maze maze) {
    for (int i = 0; i < maze.get_dim(); ++i) {
        for (int j = 0; j < maze.get_dim(); ++j) {
            cout << (maze.get_maze()[i][j].topWall ? "---" : "- -");
        }
        cout << "|" << endl;

        for (int j = 0; j < maze.get_dim(); ++j) {
            cout << (maze.get_maze()[i][j].leftWall ? "|" : " ");
            cout << (i == 0 && j == 0 ? "s" : (i == maze.get_dim() - 1 && j == maze.get_dim() - 1 ? "e" : " "));
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
        cout << "---";
    }
    cout << "|" << endl;
}