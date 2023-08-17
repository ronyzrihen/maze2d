#pragma once
#include "model.h"
#include "view.h"
#include "command.h"
#include "controller.h"
#include <map>
#include <string>
#include "exception"
#include "exceptions.h"
#include "exit.h"
#include <memory>
using namespace std;


template<class T>
class mycontroller : public controller
{
public:
    mycontroller(view<T>* vi, model<T>* mod);
    ~mycontroller() {};
    void doCommand(string com);
    void update(subject* sub);


    //test
    void con_generate_maze();
    void con_dir();
    void con_display();
    void con_display_solution();
    void con_file_size();
    void con_load_maze();
    void con_mazeSize();
    void con_save_maze();
    void con_solve();
    void con_exit(){};
    void addCommand(map<string, command*>com);
    void initview();
private:
	view<T>* view_layer;
	model<T>* model_layer;
	map <string, command*>commands;
};



template<class T>
mycontroller<T>::mycontroller(view<T>* vi,model<T>* mod):view_layer(vi),model_layer(mod){
    view_layer->attach(this);
    model_layer->attach(this);
    commands["exit"] = new exitt(this);
   
}
template<class T>
void mycontroller<T>::doCommand(string com) {

    std::map<string, command*>::iterator it;
    it = commands.find(com);
    if (it != commands.end()) {
        commands[com]->doCommand();
    }
    else {
        throw string("shit");
    }


}
template<class T>
void mycontroller<T>::update(subject* sub) {
    try {

        doCommand(sub->get_state());
    }catch(string error){
        view_layer->printToOut(sub->get_state());
    }

}

//test



template<class T>
void mycontroller<T>::con_generate_maze() {
    string alg;
    string name;
    int size;
    view_layer->printToOut("---Alg list---\n");
    view_layer->printstring(model_layer->get_gens());
    cout << "choose algorithm: ";
    alg = view_layer->get_input();
    if (model_layer->is_gen_exist(alg)) {
        view_layer->printToOut("enter maze name: ");
        name = view_layer->get_input();
        view_layer->printToOut("enter maze size: ");
        cin >> size;
        model_layer->generate_maze(alg, size, name);
    }
    else {
        view_layer->printToOut("algo not exist");
    }
}

template<class T>
void mycontroller<T>::con_display_solution() {
    view_layer->printToOut("Enter Maze Name: ");
    string mazeName = view_layer->get_input();

    Solution<T>* sol = model_layer->get_solution(mazeName); //TODO shared ptr
    view_layer->display_solution(sol);

}


template<class T>
void mycontroller<T>::con_display() {

    view_layer->printToOut("---Maze list---\n");
    view_layer->printstring(model_layer->get_mazes());
    view_layer->printToOut("Enter Maze Name: ");
    string name = view_layer->get_input();
    if (model_layer->is_maze_exist(name)) {
        view_layer->display(model_layer->get_maze(name));
    }
    else {
        view_layer->printToOut("maze not exist");
    }

}
template<class T>
void mycontroller<T>::con_file_size() {
    view_layer->printToOut("Enter File Name: ");
    string name = view_layer->get_input();
    if (model_layer->is_file_exist(name)) {
        view_layer->size(name, model_layer->get_file_size(name));
        return;
    }
    view_layer->printToOut("No Such File!\n");
}
template<class T>
void mycontroller<T>::con_load_maze() {

    string fileName;
    string mazeName;
    view_layer->printToOut("Enter File Name: ");
    fileName = view_layer->get_input();
    if (fileName == "") {
        fileName = view_layer->get_input();
    }

    view_layer->printToOut("Enter New Maze Name: ");
    mazeName = view_layer->get_input();
    if (mazeName == "") {
        mazeName = view_layer->get_input();
    }

    model_layer->load(fileName, mazeName);
}
template<class T>
void mycontroller<T>::con_mazeSize() {
    view_layer->printToOut("Enter Maze Name: ");
    string name = view_layer->get_input();
    view_layer->size(name, model_layer->get_maze_size(name));

}



template<class T>
void mycontroller<T>::con_save_maze() {


    string mazeName, fileName, answer;
    view_layer->printToOut("---Maze list---\n");
    view_layer->printstring(model_layer->get_mazes());
    while (!model_layer->is_maze_exist(mazeName)) {

        view_layer->printToOut("Enter Maze Name: ");
        mazeName = view_layer->get_input();
        if (mazeName == "") {
            mazeName = view_layer->get_input();

        }
        if (!model_layer->is_maze_exist(mazeName)) {
            view_layer->printToOut("Maze Dosen't Exist!\n");
        }


    }

    d2Maze maze = model_layer->get_maze(mazeName);
    view_layer->printToOut("Enter File Name :");
    fileName = view_layer->get_input();
    if (fileName == "") {
        fileName = view_layer->get_input();
    }
    while (model_layer->is_file_exist(fileName)) {

        view_layer->printToOut("File already exist,\n Do you wish to override it? (y/n) ");
        answer = view_layer->get_input();
        if (answer == "") {
            answer = view_layer->get_input();
        }
        if (answer == "y" || answer == "yes" || answer == "Yes") {
            break;
        }
        view_layer->printToOut("Enter File Name :");
        fileName = view_layer->get_input();
        if (fileName == "") {
            fileName = view_layer->get_input();
        }
    }

    model_layer->save(fileName, maze);

}
template<class T>
void mycontroller<T>::con_solve() {
    view_layer->printToOut("---Maze list---\n");
    view_layer->printstring(model_layer->get_mazes());
    view_layer->printToOut("Enter maze name: ");
    string mazeName = view_layer->get_input();


    if (model_layer->is_maze_exist(mazeName)) {

        view_layer->printToOut("Do You Wish To Solve Manually? (Y/N) ");

        string answer = view_layer->get_input();
        if (answer == "Y" || answer == "y" || answer == "yes" || answer == "Yes") {
            view_layer->play(new d2Maze(model_layer->get_maze(mazeName)));
            return;
        }
        else if (answer == "N" || answer == "n" || answer == "no" || answer == "No") {
            view_layer->printToOut("---Alg list---\n");
            view_layer->printstring(model_layer->get_sols());
            view_layer->printToOut("Enter algorithm name: ");
            string algo = view_layer->get_input();
            if (model_layer->is_sol_exist(algo)) {

                model_layer->solve(algo, mazeName);
            }
            else {
                view_layer->printToOut("algo not exist");
            }

            return;


        }
        view_layer->printToOut(answer + " is not a valid answer.");
        return;
    }
    view_layer->printToOut("maze not exist");



}

template<class T>
void mycontroller<T>::con_dir() {

    filesystem::path p_name;
        view_layer->printToOut("Enter Path: ");
    p_name = view_layer->get_input();
    if (p_name.string() == "") {
    p_name = view_layer->get_input();
    }
    if(!filesystem::is_regular_file(p_name)){
    
    for(auto p_file: filesystem::directory_iterator(p_name)){
    
        view_layer->printToOut(p_file.path().filename().string() + "\n");
    }
    return;
    }
        view_layer->printToOut("\n\"" + p_name.string() + "\" is not a directory.");
}


template<class T>
void mycontroller<T>:: addCommand(map<string,command*>com) {
    for (auto& command : com) {
        commands[command.first] = command.second;
     }

}

template<class T>
void mycontroller<T>:: initview() {

    view_layer->initcli(commands);
   
}