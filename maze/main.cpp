#include "d2Maze.h"
#include "dGenerator2SimpleMaze.h"
#include "Maze2dGenerator.h"
#include "view.h"
#include "mymodel.h"
#include "mycontroller.h"
#include "mazeSize.h"
#include "display.h"

using namespace std;

int main() {
    
     myview newvi;
     mymodel newmod;
    map <string, command*>com;
    com.emplace( "display", new display(&newmod, &newvi));
    com.emplace( "mazesize",new mazesize(&newmod ,&newvi) );
	 simpleGenerator sg;
     mycontroller newcon(&newvi,&newmod,com);
	d2Maze maze= sg.generate_maze(10);
    newcon.doCommand("display",);


	return 0;
}


void printMaze(d2Maze maze) {
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