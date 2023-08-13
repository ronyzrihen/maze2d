//
// Created by Rony Zrihen on 10/08/2023.
//
#pragma once
#include "command.h"
#include "view.h"
#include <string>
#include <iostream>

using namespace std;

class generate_maze : public command{
public:
    generate_maze(model* mod) : m_model(mod){}
    ~generate_maze(){};
    void doCommand();
private:
    model* m_model;
};

class generate_success :public command{
public:
    generate_success(view* vi):m_view(vi){};
    ~generate_success(){};
    void doCommand(string name){cout << name << " was generated successfully!\n";};
private:
    view* m_view;
};

class solve_success :public command{
public:
    solve_success(view* vi):m_view(vi){};
    ~solve_success(){};
    void doCommand(string name){cout << name << " was Solved successfully!\n";};
private:
    view* m_view;
};


void generate_maze::doCommand(){
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