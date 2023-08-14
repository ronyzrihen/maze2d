//
// Created by Rony Zrihen on 12/08/2023.
//
#include "mymodel.h"



void mymodel:: addalgo(string name, Generator* algo) {
    if (!generators.count(name)) {

        generators[name] = algo;
    }
    else {
        throw algo_not_found();
    }
}


bool mymodel::save(string fileName, d2Maze maze) {

    vector<int> vec = maze.GetData();
    file* newFile = new file(vec,fileName);
    files[fileName] = newFile;

}


d2Maze& mymodel::load(string fileName, string mazeName) {

    if (is_maze_exist(mazeName)) {
        return *mazes[mazeName];
    }


    if(is_file_exist(fileName) == true){
        d2Maze newMaze(files[fileName]->load());
        add_maze(mazeName, newMaze);
        return newMaze;

    }

}



d2Maze mymodel:: generate_maze(string algoname, int dim,string mazename) {

    std::map<string, Generator*>::iterator it;
    it = generators.find(algoname);
    if (it != generators.end()) {
        d2Maze newMaze = generators[algoname]->generate_maze(dim);
        add_maze(mazename, newMaze);
        try {
            set_state("Maze " + mazename + " is ready\n");
            notify();
        }catch(exception* e){
            e->what();
        }
        return newMaze;
    }
    throw not_found(); //todo change

}

void mymodel::notify() {

    for (size_t i = 0; i < observers.size(); i++)
    {
        observers[i]->update(this);
    }
}



void mymodel::attach(observer* ob) {

    observers.push_back(ob);
}

void mymodel::detach(observer* ob) {

    vector<observer*>::iterator it = observers.begin();

    for(it ; it < observers.end(); it++)
    {
        if (ob == *it) {
            observers.erase(it);
            return;
        }
    }
}

void mymodel::add_maze(string name, d2Maze maze) {
    if (mazes.size() == 0) {
        mazes[name] = new d2Maze(maze);
        return;
    }
    map<string, d2Maze*> ::iterator it = mazes.find(name);

    if (it == mazes.end() ) {
        mazes[name] = new d2Maze(maze);
        return;
    }

    throw not_found().what();  //todo change

}

bool  mymodel::is_maze_exist(string MazeName){
    auto it = mazes.find(MazeName);
    if(it != mazes.end()){
        return true;
    }
    return false;
}

bool mymodel::is_file_exist(string fileName) {
    auto it = files.find(fileName);
    if(it != files.end()){
        return true;
    }
    return false;
}

