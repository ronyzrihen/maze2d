#include "dGenerator2SimpleMaze.h"
#include "mymodel.h"
#include "mycontroller.h"
#include "mazeSize.h"
#include "display.h"
#include "generate_success.h"
#include "file.h"
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
    //com["generate_success"] = new generate_success(&newvi);
    com["generate_maze"] = new generate_maze(&newmod);

    mycontroller newcon(&newvi,&newmod,com);
    newvi.attach(&newcon);
    newmod.attach(&newcon);
    newcon.doCommand("generate_maze");

    pos g = newmod.get_maze("t").getGoalPsition();
    cout << g << ", ";
    g = newmod.get_maze("t").getStartPosition();
    cout << g << ", ";
    g = newmod.get_maze("t").getPlayerPsition();
    cout << g << "\n";



    vector<int> vec = newmod.get_maze("t").GetData();
    for(int num : vec){
        cout << num << " ";
    }
    cout << endl;

    file m_file(vec,"hi");
    d2Maze binaryMaze(vec);
   newmod.add_maze("hi",binaryMaze);
   newcon.doCommand("display");



//    newcon.doCommand("display");
////    newcon.doCommand("display","test1");
//    newmod.get_maze("t").move_left();
//    newmod.get_maze("t").move_left();
//    newmod.get_maze("t").move_down();
//    newcon.doCommand("display");
//    vector<string> moves = newmod.get_maze("t").getPossibleMoves();
//    for(auto move: moves){
//        cout << move << ", ";
//    }
//    cout << endl;
//    pos g = newmod.get_maze("t").getGoalPsition();
//    cout << g << ", ";
//    g = newmod.get_maze("t").getStartPosition();
//    cout << g << ", ";
//    g = newmod.get_maze("t").getPlayerPsition();
//    cout << g << "\n";

	return 0;
}
