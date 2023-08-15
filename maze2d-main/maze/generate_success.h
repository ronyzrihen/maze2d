//
// Created by Rony Zrihen on 10/08/2023.
//
#pragma once
#include "command.h"
#include "view.h"
#include <string>
#include <iostream>

using namespace std;

template<class T>
class generate_maze : public command{
public:
    generate_maze( view<T>*vi, model<T>* mod) :m_view(vi) ,m_model(mod)  {}
    ~generate_maze(){};
    void doCommand();
private:
    model<T>* m_model;
    view<T>* m_view;
};

template<class T>
void generate_maze<T>::doCommand(){
    string alg;
    string name;
    int size;
    m_view->printToOut("---Alg list---\n");
    m_view->printstring(m_model->get_gens());
    cout<< "choose algorithm: ";
    alg=m_view->get_input();
    if (m_model->is_gen_exist(alg)) {
    m_view->printToOut("enter maze name: ");
    name=m_view->get_input();
    m_view->printToOut("enter maze size: ");
    cin >> size;
    m_model->generate_maze(alg,size,name);
    }

    else {
        m_view->printToOut("algo not exist");
    }

}