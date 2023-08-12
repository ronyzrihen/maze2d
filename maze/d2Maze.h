#pragma once
#include "pos.h"
#include "file.h"
#include <vector>
#include <iostream>



struct Cell {
	bool visited;
	bool topWall;
	bool bottomWall;
	bool leftWall;
	bool rightWall;

	Cell() : visited(false), topWall(true), bottomWall(true), leftWall(true), rightWall(true) {}
};



class d2Maze
{
public:
	d2Maze(int size);
    d2Maze(){};
	~d2Maze(){};
    void move_up();
    void move_down();
    void move_left();
    void move_right();
    pos getStartPosition()const {return start;};
    pos getGoalPsition() const {return end;};
    pos getPlayerPsition() const{return player;};
	int get_dim() const { return m_dim; };
	vector<vector<Cell> >& get_maze()  {return maze; };
    string* getPossibleMoves();
	file save_to_file(file f){};
	int get_size() { return m_size; };




private:

	vector<vector<Cell> > maze;
	int m_dim;
	pos player;
	pos end;
	pos start;
	int m_size;



};


