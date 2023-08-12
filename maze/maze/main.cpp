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

    newmod.addalgo("simpGen", new simpleGenerator());
    map<string, command*> com;
    com["display"] = new display(&newmod, &newvi);
    com["mazesize"] =new mazesize(&newmod ,&newvi);
	 simpleGenerator sg;
     mycontroller newcon(&newvi,&newmod,com);
	d2Maze maze= sg.generate_maze(10);
    newmod.generate_maze("simpGen", 10, "test");
    newcon.doCommand("display","test");
    pos p;
    vector<string> moves;
    p= maze.getStartPosition();
    cout << p<<endl;
    p = maze.getGoalPsition();
    cout << p<<endl;
    maze.move_right();
    p = maze.getPlayerPsition();
    cout << p<<endl; 
    moves = maze.getPossibleMoves();
    for (size_t i = 0; i < moves.size(); i++)
    {
        cout << moves[i]<<endl;
    }
    newcon.doCommand("display", "test");
	return 0;
}
