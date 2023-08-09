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
	~d2Maze(){};
	int move_up(int i, int j){};
	int move_down(int i, int j){};
	int move_left(int i, int j){};
	int move_right(int i, int j){};
	file save_to_file(file f);
	int get_size() { return m_size; };
	vector<vector<Cell>>& get_maze() { return maze; };
	int get_dim() { return m_dim; };
	



private:

	vector<vector<Cell>> maze;
	int m_dim;
	pos player;
	pos end;
	pos start;
	int m_size;



};



d2Maze::d2Maze(int maze_size) : m_dim(maze_size),
maze(maze_size, vector<Cell>(maze_size))
{};