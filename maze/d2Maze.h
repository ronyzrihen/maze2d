#pragma once
#include "pos.h"
#include "file.h"
#include <vector>



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
	int move_up();
	int move_down();
	int move_left();
	int move_right();
    pos getStartPosition(){return start;};
    pos getGoalPsition(){return end;};
    pos getPlayerPsition(){return player;};
    string* getPossibleMoves(){};
	file save_to_file(file f){};
	int get_size() { return m_size; };
	vector<vector<Cell> >& get_maze() { return maze; };
	int get_dim() { return m_dim; };
	



private:

	vector<vector<Cell> > maze;
	int m_dim;
	pos player;
	pos end;
	pos start;
	int m_size;



};


