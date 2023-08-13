//
// Created by Rony Zrihen on 12/08/2023.
//
#pragma once
#include "exception"

class algo_not_found : public exception{
public:
    algo_not_found(){};
    ~algo_not_found(){};
    const char * what() const noexcept {
        cout << "\nALGORITHM NOT FOUND!\n";
    }

};class maze_not_found : public exception{
public:
    maze_not_found(){};
    ~maze_not_found(){};
    const char * what() const noexcept {
        cout << "\nMAZE NOT FOUND!\n";
    }

};

class not_found : public exception{
public:
    const char * what() const noexcept override{
        return "\nCouldn't find command in map\n";
    }
};

class update_failed : public exception{
public:
    update_failed(){};
    ~update_failed(){};
    const char * what() const noexcept override{
        cout << "\nUPDATE FAILED!\n";
    }
};