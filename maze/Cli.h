#pragma once
#include <iostream>
#include "command.h"
#include <string>
#include <map>
#include "view.h"
#include <stdexcept>

using namespace std;

template<class T>
class Cli{
public:
    Cli(view<T> *vi, istream & input = std::cin, ostream & output = std::cout ): aView(vi) , in(input), out(output){};
    ~Cli() {};
    void printcommands();
    void addCommands(map<string,command*>com);
    void startCli();
    string get_input();
    void printToOut(string print){out << print;};
    void size(string name, int size){out << name << " size is : " << size << endl;};
    void display(d2Maze& maze) const;
    void display_solution(const Solution<string>* solush) const{out << "\nSOLUTION IS BEING PRINTED TO THE SCREEN!\n";};

	
private:
map<int ,string> commands;
istream& in;
ostream& out;
view<T>* aView;
};



template<class T>
void Cli<T>::display(d2Maze& maze) const {

    int playerX = maze.getPlayerPsition().get_row();
    int playerY = maze.getPlayerPsition().get_col();
    int startX = maze.getPlayerPsition().get_row();
    int startY = maze.getPlayerPsition().get_col();
    int endX = maze.getGoalPsition().get_row();
    int endY = maze.getGoalPsition().get_col();
    for (int i = 0; i < maze.get_dim(); ++i) {
        out << "|";
        for (int j = 0; j < maze.get_dim(); ++j) {
            out << (maze.get_maze()[i][j].topWall? "=====" : "=| |=");
        }
        out << "|" << endl;
        out << "|";
        for (int j = 0; j < maze.get_dim(); ++j) {
            out << ( j == 0 && maze.get_maze()[i][j].leftWall ? "  " : maze.get_maze()[i][j].leftWall ? "| " : "  ");
            out << (i == playerX && j == playerY ? "@" : (i == startX && j == startY) ? "s" : (i == endX - 1 && j == endY - 1 ? "e" :  " "));
            out << (j == maze.get_dim() - 1 ? "  |" : "  ");
        }
        out << endl;
    }
    out << "|";
    for (int j = 0; j < maze.get_dim(); ++j) {
        out <<  "=====";
    }
    out << "|" << endl;
}

template<class T>
string Cli<T>::get_input(){
    string line;
    getline(in,line,'\n');
    if (line == ""){
        getline(in,line,'\n');
    }
    return line;

}

template<class T>
void Cli<T>::startCli(){
    string aCommand;
    out << "-- Enter \"exit\" to exit --\n";
    out << "-- Enter \"list\" to see command list --\n";
    printcommands();
    for(;;){
        bool flag = false;
        out << "\n>>>> ";
        getline(in, aCommand, '\n');
        if(aCommand == ""){
            getline(in, aCommand, '\n');
        }
        if(aCommand == "exit" || aCommand == "Exit"){
            return;
        }
        if(aCommand == "list"){
            printcommands();
        }
        //in >> aCommand;
        for(auto com : commands){
            if(com.second == aCommand){
                try{
                    aView->set_state(aCommand);
                    aView->notify();
                }catch(exception* e){
                    e->what();
                }
                flag = true;
                break;
            }

        }
        if(!flag){
            out << "Command Was Not Found!";
        }
    }

}


template<class T>
void Cli<T>::addCommands(map<string,command*> com){


    int i=1;
    for( const auto& a_com : com) {
        commands[i++] = a_com.first;
    }
    startCli();
}


template<class T>
void Cli<T>::printcommands(){
    cout << "--== COMMAND LIST ==--\n";
    for(const auto& aCommand : commands){
        cout << aCommand.first << ".  " << aCommand.second << endl;
    }
}

