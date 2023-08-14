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
    generate_maze(model<T>* mod) : m_model(mod){}
    ~generate_maze(){};
    void doCommand();
private:
    model<T>* m_model;
};

template<class T>
void generate_maze<T>::doCommand(){
    string alg;
    string name;
    int size;
    cout<< "choose algorithm: ";
    cin>>alg;
    cout<<"enter maze name: ";
    cin>>name;
    cout<<"enter maze size: ";
    cin>>size;

    m_model->generate_maze(alg,size,name);

}