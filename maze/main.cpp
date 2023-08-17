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
#include "CLI.h"
#include <memory>
using namespace std;

int main() {
    myview* newvi = new Cli();
    mymodel* newmod = new mymodel();
    Generator* gen = new simpleGenerator();
    Searcher<string>* bfs_searcher = new BFS<string>();
   cout<< gen->measureAlgorithmTime();
    cout << "\n-----------------------------------------------\n";
    newmod->addGen("g", gen);
    newmod->addSearcher("s", bfs_searcher);
    map<string,command*> com;
    controller* newcon = new mycontroller<string>(newvi, newmod);
    com["display"] = new display(newcon);
    com["maze size"] = new mazesize(newcon);
    com["file size"] = new file_size(newcon);
    com["save"] = new save_maze(newcon);
    com["load"] =new load_maze(newcon);
    com["dir"] = new dir(newcon);
    com["solve"] = new solve(newcon);
    com["generate maze"] = new generate_maze(newcon);
    com["display solush"] = new display_solution(newcon);
    newcon->addCommand(com);
    newcon->initview();

    
	return 0;
}
