#include "dGenerator2SimpleMaze.h"
#include "mymodel.h"
#include "mycontroller.h"
#include "mazeSize.h"
#include "file_size.h"
#include "display.h"
#include "generate_success.h"
#include "file.h"
#include "save_maze.h"
#include "load_maze.h"
#include  "dir.h"
#include "Searcher.h"
#include "BFS.h"
#include "solve.h"
#include "display_solution.h"
using namespace std;

int main() {
    myview*newvi = new myview();
    mymodel* newmod = new mymodel();
    Generator* gen = new simpleGenerator();
    Searcher<string>* bfs_searcher = new BFS<string>();
   cout<< gen->measureAlgorithmTime();
    cout << "\n-----------------------------------------------\n";
    newmod->addGen("g", gen);
    newmod->addSearcher("s", bfs_searcher);
    map<string, command*> com;
    mycontroller<string> newcon(newvi,newmod);
    com["display"] = new display(&newcon);
    com["maze size"] = new mazesize(&newcon);
    com["file size"] = new file_size(&newcon);
    com["save"] = new save_maze(&newcon);
    com["load"] = new load_maze(&newcon);
    com["dir"] = new dir(&newcon);
    com["solve"] = new solve(&newcon);
    com["generate maze"] = new generate_maze(&newcon);
    com["display solush"] = new display_solution(&newcon);
    newcon.addCommand(com);
    newcon.initview();
   /* newvi->attach(&newcon);
    newmod->attach(&newcon);*/
    newcon.doCommand("generate maze");
    pos g = newmod->get_maze("t").getGoalPsition();
    cout << g << ", ";
    g = newmod->get_maze("t").getStartPosition();
    cout << g << ", ";
    g = newmod->get_maze("t").getPlayerPsition();
    cout << g << "\n";



    vector<int> vec = newmod->get_maze("t").GetData();
    for(int num : vec){
        cout << num << " ";
    }
    cout << endl;

    file m_file(vec,"hi");
    d2Maze binaryMaze(m_file.load());
    newmod->add_maze("hi",binaryMaze);
    //newcon->doCommand("display");




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
