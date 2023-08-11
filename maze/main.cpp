#include "dGenerator2SimpleMaze.h"
//#include "Maze2dGenerator.h"
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
    newmod.addalgo("s", gen);
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
//    newcon.doCommand("display","test1");
    newmod.get_maze("test1").move_left();
    newmod.get_maze("test1").move_left();
    newmod.get_maze("test1").move_down();
    newcon.doCommand("display","test1");
    string * moves = newmod.get_maze("test1").getPossibleMoves();
    cout << moves[0] << ", " << moves[1] << ", " << moves[2] << ", " << moves[3];

	return 0;
}
