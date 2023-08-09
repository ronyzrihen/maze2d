#pragma once
#include <iostream>
#include <string>
#include "dGenerator2SimpleMaze.h"
#include "d2Maze.h"

using namespace std;
class simpleGenerator 
{
public:
    simpleGenerator() {};
	~simpleGenerator(){};
	 d2Maze generate_maze(int maze_size) ;
     void generate(int row, int col, d2Maze& maze);


private:

};


d2Maze simpleGenerator::generate_maze(int maze_size) {

    d2Maze newmaze(maze_size);
    generate(0, 0, newmaze);

    return newmaze;

}

void simpleGenerator::generate(int row, int col, d2Maze&maze) {


    maze.get_maze()[row][col].visited = true;

    int directions[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    int dirOrder[4] = { 0, 1, 2, 3 };
    for (int i = 0; i < 4; ++i) {
        int j = rand() % 4;
        swap(dirOrder[i], dirOrder[j]);
    }

    for (int i = 0; i < 4; ++i) {
        int newRow = row + directions[dirOrder[i]][0];
        int newCol = col + directions[dirOrder[i]][1];

        if (newRow >= 0 && newRow < maze.get_dim() && newCol >= 0 && newCol < maze.get_dim() && !maze.get_maze()[newRow][newCol].visited) {
            maze.get_maze()[row][col].visited = true;

            if (dirOrder[i] == 0) {
                maze.get_maze()[row][col].topWall = false;
                maze.get_maze()[newRow][newCol].bottomWall = false;
            }
            else if (dirOrder[i] == 1) {
                maze.get_maze()[row][col].bottomWall = false;
                maze.get_maze()[newRow][newCol].topWall = false;
            }
            else if (dirOrder[i] == 2) {
                maze.get_maze()[row][col].leftWall = false;
                maze.get_maze()[newRow][newCol].rightWall = false;
            }
            else if (dirOrder[i] == 3) {
                maze.get_maze()[row][col].rightWall = false;
                maze.get_maze()[newRow][newCol].leftWall = false;
            }

            generate(newRow, newCol,maze);
        }
    }
}