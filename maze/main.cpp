#include "dGenerator2SimpleMaze.h"
#include "Maze2dGenerator.h"
#include "view.h"
#include "mymodel.h"
#include "mycontroller.h"
#include "mazeSize.h"
#include "display.h"
#include "generate_success.h"

using namespace std;

int main() {
    myview newvi;
    mymodel newmod;
    Generator* gen = new simpleGenerator();
    gen->measureAlgorithmTime();
    cout << "\n-----------------------------------------------\n";
    newmod.addalgo("simpGen", gen);
    map<string, command*> com;
    com["display"] = new display(&newmod, &newvi);
    com["mazesize"] = new mazesize(&newmod ,&newvi);
    com["generate_success"] = new generate_success(&newvi);
    com["generate_maze"] = new generate_maze(&newmod);

    mycontroller newcon(&newvi,&newmod,com);
    newvi.attach(&newcon);
    newmod.attach(&newcon);
    newcon.doCommand("generate_maze","test1");
    newcon.doCommand("display","test1");


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