//
// Created by Rony Zrihen on 10/08/2023.
//
#include "d2Maze.h"


d2Maze::d2Maze(int size) : m_dim(size) ,m_size(size), maze(size, vector<Cell>(size)){

    int i = rand() % size;
    int j = rand() % size;
    start.set_col(i);
    start.set_row(0);
    player.set_row(0);
    player.set_col(i);
    end.set_col(j);
    end.set_row(size-1);
};

int d2Maze::move_up(){

    if( player.get_row() < m_size && player.get_row() > 0 && !maze[player.get_row()][player.get_col()].topWall ){
        player.set_row(player.get_row()-1);
    }

}int d2Maze::move_down(){

    if(player.get_row() < m_size && player.get_row() > 0 && !maze[player.get_col()][player.get_row()].bottomWall ){
        player.set_row(player.get_row()+1);
    }

}int d2Maze::move_left(){

    if(player.get_col() < m_size && player.get_col() > 0 && !maze[player.get_row()][player.get_col()].leftWall ){
        player.set_row(player.get_col()-1);
    }

}int d2Maze::move_right(){

    if(player.get_col() < m_size && player.get_col() > 0 && !maze[player.get_row()][player.get_col()].rightWall ){
        player.set_row(player.get_col()-1);
    }

}