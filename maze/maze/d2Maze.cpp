#include "d2Maze.h"
using namespace std;

d2Maze::d2Maze(int size) : m_dim(size), m_size(size), maze(size, vector<Cell>(size)) {

    int i = rand() % size;
    int j = rand() % size;
    start.set_col(i);
    start.set_row(0);
    player.set_col(i);
    player.set_row(0);
    end.set_col(j);
    end.set_row(size);
};


void d2Maze::move_up() {

    if (player.get_row() <= m_size && player.get_row() > 0 && !maze[player.get_row()][player.get_col()].topWall) {
        player.set_row(player.get_row() - 1);
    }

}

void d2Maze::move_down() {

    if (player.get_row() < m_size && player.get_row() >= 0 && !(maze[player.get_row()][player.get_col()].bottomWall)) {
        player.set_row(player.get_row() + 1);
        return;
    }
    cout << "didnt work\n";

}
void d2Maze::move_left() {

    if (player.get_col() <= m_size && player.get_col() > 0 && !maze[player.get_row()][player.get_col()].leftWall) {
        player.set_col(player.get_col() - 1);
        return;
    }
    cout << "didnt work\n";
}

void d2Maze::move_right() {

    if (player.get_col() < m_size && player.get_col() >= 0 && !maze[player.get_row()][player.get_col()].rightWall) {
        player.set_col(player.get_col() + 1);
        return;
    }
    cout << "didnt work\n";
}


vector<string> d2Maze::getPossibleMoves() {

    vector<string> dirList;
    int count = 0;
    if (!maze[player.get_row()][player.get_col()].rightWall)
        dirList.push_back("right");
    if (!maze[player.get_row()][player.get_col()].leftWall)
        dirList.push_back("left");
    if (!maze[player.get_row()][player.get_col()].topWall)
        dirList.push_back("top");
    if (!maze[player.get_row()][player.get_col()].bottomWall)
        dirList.push_back("bottom");

    return dirList;
}