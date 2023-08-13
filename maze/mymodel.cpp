//
// Created by Rony Zrihen on 12/08/2023.
//
#include "mymodel.h"



void mymodel:: addalgo(string name, Generator* algo) {
    if (!algorithms.count(name)) {

        algorithms[name] = algo;
    }
    else {
        throw algo_not_found();
    }
}


bool mymodel::save(string name, d2Maze maze) {
    mazes[name] = maze;
    if (mazes.count(name)) {
        return true;
    }
    return false;
}


d2Maze mymodel::load(string name, string) {

    std::map<string, d2Maze>::iterator it;
    it = mazes.find(name);
    if (it != mazes.end()) {
        return mazes[name];
    }
    cout << "maze dont exsist" << endl;
}



d2Maze mymodel:: generate_maze(string algoname, int dim,string mazename) {

    std::map<string, Generator*>::iterator it;
    it = algorithms.find(algoname);
    if (it != algorithms.end()) {
        d2Maze newMaze = algorithms[algoname]->generate_maze(dim);
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
        mazes[name] = maze;
        return;
    }
    map<string, d2Maze> ::iterator it = mazes.find(name);

    if (it == mazes.end() ) {
        mazes[name] = maze;
        return;
    }

    throw not_found().what();  //todo change

}